/*
 选择、插入、气泡排序
 说明选择排序（Selection sort）、插入排序（Insertion sort）与气泡排序（Bubble sort）这三个
 排序方式是初学排序所必须知道的三个基本排序方式，它们由于速度不快而不实用（平均与最
 快的时间复杂度都是O(n2)）， 然而它们排序的方式确是值得观察与探讨的。
 解法
 选择排序
 将要排序的对象分作两部份，一个是已排序的，一个是未排序的，从后端未排序部份选择一个
 最小值，并放入前端已排序部份的最后一个，例如：
 排序前：70 80 31 37 10 1 48 60 33 80
 [1] 80 31 37 10 70 48 60 33 80 选出最小值1
 [1 10] 31 37 80 70 48 60 33 80 选出最小值10
 [1 10 31] 37 80 70 48 60 33 80 选出最小值31
 [1 10 31 33] 80 70 48 60 37 80 ......
 [1 10 31 33 37] 70 48 60 80 80 ......
 [1 10 31 33 37 48] 70 60 80 80 ......
 [1 10 31 33 37 48 60] 70 80 80 ......
 [1 10 31 33 37 48 60 70] 80 80 ......
 [1 10 31 33 37 48 60 70 80] 80 ......
 插入排序
 像是玩朴克一样，我们将牌分作两堆，每次从后面一堆的牌抽出最前端的牌，然后插入前面一
 堆牌的适当位置，例如：
 排序前：92 77 67 8 6 84 55 85 43 67
 [77 92] 67 8 6 84 55 85 43 67 将77插入92前
 [67 77 92] 8 6 84 55 85 43 67 将67插入77前
 [8 67 77 92] 6 84 55 85 43 67 将8插入67前
 [6 8 67 77 92] 84 55 85 43 67 将6插入8前
 [6 8 67 77 84 92] 55 85 43 67 将84插入92前
 [6 8 55 67 77 84 92] 85 43 67 将55插入67前
 [6 8 55 67 77 84 85 92] 43 67 ......
 [6 8 43 55 67 77 84 85 92] 67 ......
 [6 8 43 55 67 67 77 84 85 92] ......
 气泡排序法
 顾名思义，就是排序时，最大的元素会如同气泡一样移至右端，其利用比较相邻元素的方法，
 将大的元素交换至右端，所以大的元素会不断的往右移动，直到适当的位置为止。
 基本的气泡排序法可以利用旗标的方式稍微减少一些比较的时间，当寻访完阵列后都没有发生
 任何的交换动作，表示排序已经完成，而无需再进行之后的回圈比较与交换动作，例如：
 排序前：95 27 90 49 80 58 6 9 18 50
 27 90 49 80 58 6 9 18 50 [95] 95浮出
 27 49 80 58 6 9 18 50 [90 95] 90浮出
 27 49 58 6 9 18 50 [80 90 95] 80浮出
 27 49 6 9 18 50 [58 80 90 95] ......
 27 6 9 18 49 [50 58 80 90 95] ......
 6 9 18 27 [49 50 58 80 90 95] ......
 6 9 18 [27 49 50 58 80 90 95] 由于接下来不会再发生交换动作，排序提早结束
 在上面的例子当中，还加入了一个观念，就是当进行至i与i+1时没有交换的动作，表示接下来的
 i+2至n已经排序完毕，这也增进了气泡排序的效率。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
void selsort(int[]); // 选择排序
void insort(int[]); // 插入排序
void bubsort(int[]); // 气泡排序
int main(void) {
    int number[MAX] = {0};
    int i;
    srand(time(NULL));
    printf("排序前：");
    for(i = 0; i < MAX; i++) {
        number[i] = rand() % 100;
        printf("%d ", number[i]);
    }
    printf("\n请选择排序方式：\n");
    printf("(1)选择排序\n(2)插入排序\n(3)气泡排序\n:");
    scanf("%d", &i);
    switch(i) {
        case 1:
            selsort(number); break;
        case 2:
            insort(number); break;
        case 3:
            bubsort(number); break;
        default:
            printf("选项错误(1..3)\n");
    }
    return 0;
}
void selsort(int number[]) {
    int i, j, k, m;
    for(i = 0; i < MAX-1; i++) {
        m = i;
        for(j = i+1; j < MAX; j++)
            if(number[j] < number[m])
                m = j;
        if( i != m)
            SWAP(number[i], number[m])
            printf("第%d 次排序：", i+1);
        for(k = 0; k < MAX; k++)
            printf("%d ", number[k]);
        printf("\n");
    }
}
void insort(int number[]) {
    int i, j, k, tmp;
    for(j = 1; j < MAX; j++) {
        tmp = number[j];
        i = j - 1;
        while(tmp < number[i]) {
            number[i+1] = number[i];
            i--;
            if(i == -1)
                break;
        }
        number[i+1] = tmp;
        printf("第%d 次排序：", j);
        for(k = 0; k < MAX; k++)
            printf("%d ", number[k]);
        printf("\n");
    }
}
void bubsort(int number[]) {
    int i, j, k, flag = 1;
    for(i = 0; i < MAX-1 && flag == 1; i++) {
        flag = 0;
        for(j = 0; j < MAX-i-1; j++) {
            if(number[j+1] < number[j]) {
                SWAP(number[j+1], number[j]);
                flag = 1;
            }
        }
        printf("第%d 次排序：", i+1);
        for(k = 0; k < MAX; k++)
            printf("%d ", number[k]);
        printf("\n");
    }
}

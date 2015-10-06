/*
 Shell排序法-
 改良的插入排序
 说明
 插入排序法由未排序的后半部前端取出一个值，插入已排序前半部的适当位置，概念简单但速
 度不快。
 排序要加快的基本原则之一，是让后一次的排序进行时，尽量利用前一次排序后的结果，以加
 快排序的速度，Shell排序法即是基于此一概念来改良插入排序法。
 解法
 Shell排序法最初是D.L Shell于1959所提出，假设要排序的元素有n个，则每次进行插入排序时
 并不是所有的元素同时进行时，而是取一段间隔。
 Shell首先将间隔设定为n/2，然后跳跃进行插入排序，再来将间隔n/4，跳跃进行排序动作，再来
 间隔设定为n/8、n/16，直到间隔为1之后的最后一次排序终止，由于上一次的排序动作都会将
 固定间隔内的元素排序好，所以当间隔越来越小时，某些元素位于正确位置的机率越高，因此
 最后几次的排序动作将可以大幅减低。
 举个例子来说，假设有一未排序的数字如右：89 12 65 97 61 81 27 2 61 98
 数字的总数共有10个，所以第一次我们将间隔设定为10 / 2 = 5，此时我们对间隔为5的数字进行
 排序，如下所示：
 画线连结的部份表示要一起进行排序的部份，再来将间隔设定为5 / 2的商，也就是2，则第二
 次的插入排序对象如下所示：
 再来间隔设定为2 / 2 = 1，此时就是单纯的插入排序了，由于大部份的元素都已大致排序过了，
 所以最后一次的插入排序几乎没作什么排序动作了：
 将间隔设定为n / 2是D.L Shell最初所提出，在教科书中使用这个间隔比较好说明，然而Shell排
 序法的关键在于间隔的选定，例如Sedgewick证明选用以下的间隔可以加快Shell排序法的速度：
 其中4*(2j)2 + 3*(2j) + 1不可超过元素总数n值，使用上式找出j后代入4*(2j)2 + 3*(2j) + 1求得第一
 个间隔，然后将2j除以2代入求得第二个间隔，再来依此类推。
 后来还有人证明有其它的间隔选定法可以将Shell排序法的速度再加快；另外Shell排序法的概念
 也可以用来改良气泡排序法。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
void shellsort(int[]);
int main(void) {
    int number[MAX] = {0};
    int i;
    srand(time(NULL));
    printf("排序前：");
    for(i = 0; i < MAX; i++) {
        number[i] = rand() % 100;
        printf("%d ", number[i]);
    }
    shellsort(number);
    return 0;
}
void shellsort(int number[]) {
    int i, j, k, gap, t;
    gap = MAX / 2;
    while(gap > 0) {
        for(k = 0; k < gap; k++) {
            for(i = k+gap; i < MAX; i+=gap) {
                for(j = i - gap; j >= k; j-=gap) {
                    if(number[j] > number[j+gap]) {
                        SWAP(number[j], number[j+gap]);
                    }
                    else
                        break;
                }
            }
        }
        printf("\ngap = %d：", gap);
        for(i = 0; i < MAX; i++)
            printf("%d ", number[i]);
        printf("\n");
        gap /= 2;
    }
}

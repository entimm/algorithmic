/*
 快速排序法（一）
 说明快速排序法（quick sort）是目前所公认最快的排序方法之一（视解题的对象而定），虽然
 快速排序法在最差状况下可以达O(n2)，但是在多数的情况下，快速排序法的效率表现是相当不
 错的。
 快速排序法的基本精神是在数列中找出适当的轴心，然后将数列一分为二，分别对左边与右边
 数列进行排序，而影响快速排序法效率的正是轴心的选择。
 这边所介绍的第一个快速排序法版本，是在多数的教科书上所提及的版本，因为它最容易理解，
 也最符合轴心分割与左右进行排序的概念，适合对初学者进行讲解。
 解法这边所介绍的快速演算如下：将最左边的数设定为轴，并记录其值为s
 廻圈处理：
 令索引i 从数列左方往右方找，直到找到大于s 的数
 令索引j 从数列左右方往左方找，直到找到小于s 的数
 如果i >= j，则离开回圈
 如果i < j，则交换索引i与j两处的值
 将左侧的轴与j 进行交换
 对轴左边进行递回
 对轴右边进行递回
 透过以下演算法，则轴左边的值都会小于s，轴右边的值都会大于s，如此再对轴左右两边进行
 递回，就可以对完成排序的目的，例如下面的实例，*表示要交换的数，[]表示轴：
 [41] 24 76* 11 45 64 21 69 19 36*
 [41] 24 36 11 45* 64 21 69 19* 76
 [41] 24 36 11 19 64* 21* 69 45 76
 [41] 24 36 11 19 21 64 69 45 76
 21 24 36 11 19 [41] 64 69 45 76
 在上面的例子中，41左边的值都比它小，而右边的值都比它大，如此左右再进行递回至排序完
 成。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
void quicksort(int[], int, int);
int main(void) {
    int number[MAX] = {0};
    int i, num;
    srand(time(NULL));
    printf("排序前：");
    for(i = 0; i < MAX; i++) {
        number[i] = rand() % 100;
        printf("%d ", number[i]);
    }
    quicksort(number, 0, MAX-1);
    printf("\n排序后：");
    for(i = 0; i < MAX; i++)
        printf("%d ", number[i]);
    printf("\n");
    return 0;
}
void quicksort(int number[], int left, int right) {
    int i, j, s;
    if(left < right) {
        s = number[left];
        i = left;
        j = right + 1;
        while(1) {
            // 向右找
            while(i + 1 < number.length && number[++i] < s) ;
            // 向左找
            while(j -1 > -1 && number[--j] > s) ;
            if(i >= j)
                break;
            SWAP(number[i], number[j]);
        }
        number[left] = number[j];
        number[j] = s;
        quicksort(number, left, j-1); // 对左边进行递回
        quicksort(number, j+1, right); // 对右边进行递回
    }
}
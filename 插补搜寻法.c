/*
 插补搜寻法
 说明
 如果却搜寻的资料分布平均的话，可以使用插补（Interpolation）搜寻法来进行搜寻，在搜寻
 的对象大于500时，插补搜寻法会比二分搜寻法来的快速。
 解法
 插补搜寻法是以资料分布的近似直线来作比例运算，以求出中间的索引并进行资料比对，如果
 取出的值小于要寻找的值，则提高下界，如果取出的值大于要寻找的值，则降低下界，如此不
 断的减少搜寻的范围，所以其本原则与二分搜寻法是相同的，至于中间值的寻找是透过比例运
 算，如下所示，其中K是指定要寻找的对象， 而m则是可能的索引值：

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
void quicksort(int[], int, int);
int intsrch(int[], int);
int main(void) {
    int number[MAX] = {0};
    int i, find;
    srand(time(NULL));
    for(i = 0; i < MAX; i++) {
        number[i] = rand() % 100;
    }
    quicksort(number, 0, MAX-1);
    printf("数列：");
    for(i = 0; i < MAX; i++)
        printf("%d ", number[i]);
    printf("\n输入寻找对象：");
    scanf("%d", &find);
    if((i = intsrch(number, find)) >= 0)
        printf("找到数字于索引%d ", i);
    else
        printf("\n找不到指定数");
    printf("\n");
    return 0;
}
int intsrch(int number[], int find) {
    int low, mid, upper;
    low = 0;
    upper = MAX - 1;
    while(low <= upper) {
        mid = (upper-low)*
        (find-number[low])/(number[upper]-number[low])
        + low;
        if(mid < low || mid > upper)
            return -1;
        if(find < number[mid])
            upper = mid - 1;
        else if(find > number[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
void quicksort(int number[], int left, int right) {
    int i, j, k, s;
    if(left < right) {
        s = number[(left+right)/2];
        i = left - 1;
        j = right + 1;
        while(1) {
            while(number[++i] < s) ; // 向右找
            while(number[--j] > s) ; // 向左找
            if(i >= j)
                break;
            SWAP(number[i], number[j]);
        }
        quicksort(number, left, i-1); // 对左边进行递回
        quicksort(number, j+1, right); // 对右边进行递回
    }
}

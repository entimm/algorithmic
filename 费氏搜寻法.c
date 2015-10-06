/*
 费氏搜寻法
 说明
 二分搜寻法每次搜寻时，都会将搜寻区间分为一半，所以其搜寻时间为O(log(2)n)，log(2)表示
 以2为底的log值，这边要介绍的费氏搜寻，其利用费氏数列作为间隔来搜寻下一个数，所以区
 间收敛的速度更快，搜寻时间为O(logn)。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
void createfib(void); // 建立费氏数列
int findx(int, int); // 找x值
int fibsearch(int[], int); // 费氏搜寻
void quicksort(int[], int, int); // 快速排序
int Fib[MAX] = {-999};
int main(void) {
    int number[MAX] = {0};
    int i, find;
    srand(time(NULL));
    for(i = 1; i <= MAX; i++) {
        number[i] = rand() % 100;
    }
    quicksort(number, 1, MAX);
    printf("数列：");
    for(i = 1; i <= MAX; i++)
        printf("%d ", number[i]);
    printf("\n输入寻找对象：");
    scanf("%d", &find);
    if((i = fibsearch(number, find)) >= 0)
        printf("找到数字于索引%d ", i);
    else
        printf("\n找不到指定数");
    printf("\n");
    return 0;
}
// 建立费氏数列
void createfib(void) {
    int i;
    Fib[0] = 0;
    Fib[1] = 1;
    for(i = 2; i < MAX; i++)
        Fib[i] = Fib[i-1] + Fib[i-2];
}
// 找x 值
int findx(int n, int find) {
    int i = 0;
    while(Fib[i] <= n)
        i++;
    i--;
    return i;
}
// 费式搜寻
int fibsearch(int number[], int find) {
    int i, x, m;
    createfib();
    x = findx(MAX+1,find);
    m = MAX - Fib[x];
    printf("\nx = %d, m = %d, Fib[x] = %d\n\n",
           x, m, Fib[x]);
    x--;
    i = x;
    if(number[i] < find)
        i += m;
    while(Fib[x] > 0) {
        if(number[i] < find)
            i += Fib[--x];
        else if(number[i] > find)
            i -= Fib[--x];
        else
            return i;
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

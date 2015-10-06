/*
 最大公因数、最小公倍数、因式分解
 说明最大公因数使用辗转相除法来求，最小公倍数则由这个公式来求：
 GCD * LCM = 两数乘积
 解法最大公因数可以使用递回与非递回求解，因式分解基本上就是使用小于输入数的数值当
 作除数，去除以输入数值，如果可以整除就视为因数，要比较快的解法就是求出小于该数的所
 有质数，并试试看是不是可以整除，求质数的问题是另一个课题，请参考Eratosthenes 筛选求
 质数。
*/

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int m, n, r;
    int s;
    printf("输入两数：");
    scanf("%d %d", &m, &n);
    s = m * n;
    while(n != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    printf("GCD：%d\n", m);
    printf("LCM：%d\n", s/m);
    return 0;
}


//因式分解
//C（不用质数表）
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int i, n;
    printf("请输入整数：");
    scanf("%d", &n);
    printf("%d = ", n);
    for(i = 2; i * i <= n;) {
        if(n % i == 0) {
            printf("%d * ", i);
            n /= i;
        }
        else
            i++;
    }
    printf("%d\n", n);
    return 0;
}


//C（使用质数表）
#include <stdio.h>
#include <stdlib.h>
#define N 1000
int prime(int*); // 求质数表
void factor(int*, int); // 求factor
int main(void) {
    int ptable[N+1] = {0};
    int count, i, temp;
    count = prime(ptable);
    printf("请输入一数：");
    scanf("%d", &temp);
    factor(ptable, temp);
    printf("\n");
    return 0;
}
int prime(int* pNum) {
    int i, j;
    int prime[N+1];
    for(i = 2; i <= N; i++)
        prime[i] = 1;
    for(i = 2; i*i <= N; i++) {
        if(prime[i] == 1) {
            for(j = 2*i; j <= N; j++) {
                if(j % i == 0)
                    prime[j] = 0;
            }
        }
    }
    for(i = 2, j = 0; i < N; i++) {
        if(prime[i] == 1)
            pNum[j++] = i;
    }
    return j;
}
void factor(int* table, int num) {
    int i;
    for(i = 0; table[i] * table[i] <= num;) {
        if(num % table[i] == 0) {
            printf("%d * ", table[i]);
            num /= table[i];
        }
        else
            i++;
    }
    printf("%d\n", num);
}

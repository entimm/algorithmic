/*
 阿姆斯壮数
 说明
 在三位的整数中，例如153可以满足13 + 53 + 33 = 153，这样的数称之为Armstrong数，试写出一
 程式找出所有的三位数Armstrong数。
 解法
 Armstrong数的寻找，其实就是在问如何将一个数字分解为个位数、十位数、百位数......，这只
 要使用除法与余数运算就可以了，例如输入input为abc，则：
 a = input / 100
 b = (input%100) / 10
 c = input % 10
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
int main(void) {
    int a, b, c;
    int input;
    printf("寻找Armstrong数：\n");
    for(input = 100; input <= 999; input++) {
        a = input / 100;
        b = (input % 100) / 10;
        c = input % 10;
        if(a*a*a + b*b*b + c*c*c == input)
            printf("%d ", input);
    }
    printf("\n");
    return 0;
}

/*
 中序式转后序式（前序式）
 说明
 平常所使用的运算式，主要是将运算元放在运算子的两旁，例如a+b/d这样的式子，这称
 之为中序（Infix）表示式，对于人类来说，这样的式子很容易理解，但由于电脑执行指令时是
 有顺序的，遇到中序表示式时，无法直接进行运算，而必须进一步判断运算的先后顺序，所以
 必须将中序表示式转换为另一种表示方法。
 可以将中序表示式转换为后序（Postfix）表示式，后序表示式又称之为逆向波兰表示式（Reverse
 polish notation），它是由波兰的数学家卢卡谢维奇提出，例如(a+b)*(c+d)这个式子，表示为后序
 表示式时是ab+cd+*。
 解法
 用手算的方式来计算后序式相当的简单，将运算子两旁的运算元依先后顺序全括号起来，
 然后将所有的右括号取代为左边最接近的运算子（从最内层括号开始），最后去掉所有的左括号
 就可以完成后序表示式，例如：
 a+b*d+c/d => ((a+(b*d))+(c/d)) -> bd*+cd/+
 如果要用程式来进行中序转后序，则必须使用堆叠，演算法很简单，直接叙述的话就是使用回
 圈，取出中序式的字元，遇运算元直接输出，堆叠运算子与左括号， ISP>ICP的话直接输出堆
 叠中的运算子，遇右括号输出堆叠中的运算子至左括号。
 如果要将中序式转为前序式，则在读取中序式时是由后往前读取，而左右括号的处理方式相反，
 其余不变，但输出之前必须先置入堆叠，待转换完成后再将堆叠中的值由上往下读出，如此就
 是前序表示式。
*/

#include <stdio.h>
#include <stdlib.h>
int postfix(char*); // 中序转后序
int priority(char); // 决定运算子优先顺序
int main(void) {
    char input[80];
    printf("输入中序运算式：");
    scanf("%s", input);
    postfix(input);
    return 0;
}
int postfix(char* infix) {
    int i = 0, top = 0;
    char stack[80] = {'\0'};
    char op;
    while(1) {
        op = infix[i];
        switch(op) {
            case '\0':
                while(top > 0) {
                    printf("%c", stack[top]);
                    top--;
                }
                printf("\n");
                return 0;
                // 运算子堆叠
            case '(':
                if(top < (sizeof(stack) / sizeof(char))) {
                    top++;
                    stack[top] = op;
                }
                break;
            case '+': case '-': case '*': case '/':
                while(priority(stack[top]) >= priority(op)) {
                    printf("%c", stack[top]);
                    top--;
                }
                // 存入堆叠
                if(top < (sizeof(stack) / sizeof(char))) {
                    top++;
                    stack[top] = op;
                }
                break;
                // 遇) 输出至(
            case ')':
                while(stack[top] != '(') {
                    printf("%c", stack[top]);
                    top--;
                }
                top--; // 不输出(
                break;
                // 运算元直接输出
            default:
                printf("%c", op);
                break;
        }
        i++;
    }
}
int priority(char op) {
    int p;
    switch(op) {
        case '+': case '-':
            p = 1;
            break;
        case '*': case '/':
            p = 2;
            break;
        default:
            p = 0;
            break;
    }
    return p;
}
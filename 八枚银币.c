/*
 八枚银币
 说明现有八枚银币a b c d e f g h，已知其中一枚是假币，其重量不同于真币，但不知是较轻或
 较重，如何使用天平以最少的比较次数，决定出哪枚是假币，并得知假币比真币较轻或较重。
 解法单就求假币的问题是不难，但问题限制使用最少的比较次数，所以我们不能以单纯的回
 圈比较来求解，我们可以使用决策树（decision tree），使用分析与树状图来协助求解。一个简单
 的状况是这样的，我们比较a+b+c与d+e+f ，如果相等，则假币必是g或h，我们先比较g或h哪个
 较重，如果g较重，再与a比较（a是真币），如果g等于a，则g为真币，则h为假币，由于h比g轻
 而g是真币，则h假币的重量比真币轻。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void compare(int[], int, int, int);
void eightcoins(int[]);
int main(void) {
    int coins[8] = {0};
    int i;
    srand(time(NULL));
    for(i = 0; i < 8; i++)
        coins[i] = 10;
    printf("\n输入假币重量(比10大或小)：");
    scanf("%d", &i);
    coins[rand() % 8] = i;
    eightcoins(coins);
    printf("\n\n列出所有钱币重量：");
    for(i = 0; i < 8; i++)
        printf("%d ", coins[i]);
    printf("\n");
    return 0;
}
void compare(int coins[], int i, int j, int k) {
    if(coins[i] > coins[k])
        printf("\n假币%d 较重", i+1);
    else
        printf("\n假币%d 较轻", j+1);
}
void eightcoins(int coins[]) {
    if(coins[0]+coins[1]+coins[2] ==
       coins[3]+coins[4]+coins[5]) {
        if(coins[6] > coins[7])
            compare(coins, 6, 7, 0);
        else
            compare(coins, 7, 6, 0);
    }
    else if(coins[0]+coins[1]+coins[2] >
            coins[3]+coins[4]+coins[5]) {
        if(coins[0]+coins[3] == coins[1]+coins[4])
            compare(coins, 2, 5, 0);
        else if(coins[0]+coins[3] > coins[1]+coins[4])
            compare(coins, 0, 4, 1);
        if(coins[0]+coins[3] < coins[1]+coins[4])
            compare(coins, 1, 3, 0);
    }
    else if(coins[0]+coins[1]+coins[2] <
            coins[3]+coins[4]+coins[5]) {
        if(coins[0]+coins[3] == coins[1]+coins[4])
            compare(coins, 5, 2, 0);
        else if(coins[0]+coins[3] > coins[1]+coins[4])
            compare(coins, 3, 1, 0);
        if(coins[0]+coins[3] < coins[1]+coins[4])
            compare(coins, 4, 0, 1);
    }
}

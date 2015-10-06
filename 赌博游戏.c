/*
 Craps
 赌博游戏
 说明一个简单的赌博游戏，游戏规则如下：玩家掷两个骰子，点数为1到6，如果第一次点数
 和为7或11，则玩家胜，如果点数和为2、3或12，则玩家输，如果和为其它点数，则记录第一
 次的点数和，然后继续掷骰，直至点数和等于第一次掷出的点数和，则玩家胜，如果在这之前
 掷出了点数和为7，则玩家输。
 解法规则看来有些复杂，但是其实只要使用switch配合if条件判断来撰写即可，小心不要弄
 错胜负顺序即可。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WON 0
#define LOST 1
#define CONTINUE 2
int rollDice() {
    return (rand() % 6) + (rand() % 6) + 2;
}
int main(void) {
    int firstRoll = 1;
    int gameStatus = CONTINUE;
    int die1, die2, sumOfDice;
    int firstPoint = 0;
    char c;
    srand(time(0));
    printf("Craps赌博游戏，按Enter键开始游戏****");
    while(1) {
        getchar();
        if(firstRoll) {
            sumOfDice = rollDice();
            printf("\n玩家掷出点数和：%d\n", sumOfDice);
            switch(sumOfDice) {
                case 7: case 11:
                    gameStatus = WON; break;
                case 2: case 3: case 12:
                    gameStatus = LOST; break;
                default:
                    firstRoll = 0;
                    gameStatus = CONTINUE;
                    firstPoint = sumOfDice;
                    break;
            }
        }
        else {
            sumOfDice = rollDice();
            printf("\n玩家掷出点数和：%d\n", sumOfDice);
            if(sumOfDice == firstPoint)
                gameStatus = WON;
            else if(sumOfDice == 7)
                gameStatus = LOST;
        }
        if(gameStatus == CONTINUE)
            puts("未分胜负，再掷一次****\n");
        else {
            if(gameStatus == WON)
                puts("玩家胜");
            else
                puts("玩家输");
            printf("再玩一次？");
            scanf("%c", &c);
            if(c == 'n') {
                puts("游戏结束");
                break;
            }
            firstRoll = 1;
        }
    }
    return 0;
}

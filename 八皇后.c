/*
 八皇后
 说明西洋棋中的皇后可以直线前进，吃掉遇到的所有棋子，如果棋盘上有八个皇后，则这八
 个皇后如何相安无事的放置在棋盘上，1970年与1971年， E.W.Dijkstra与N.Wirth曾经用这个问
 题来讲解程式设计之技巧。
 解法关于棋盘的问题，都可以用递回求解，然而如何减少递回的次数？在八个皇后的问题中，
 不必要所有的格子都检查过，例如若某列检查过，该该列的其它格子就不用再检查了，这个方
 法称为分支修剪。
 */
#include <stdio.h>
#include <stdlib.h>
#define N 8
int column[N+1]; // 同栏是否有皇后，1表示有
int rup[2*N+1]; // 右上至左下是否有皇后
int lup[2*N+1]; // 左上至右下是否有皇后
int queen[N+1] = {0};
int num; // 解答编号
void backtrack(int); // 递回求解
int main(void) {
    int i;
    num = 0;
    for(i = 1; i <= N; i++)
        column[i] = 1;
    for(i = 1; i <= 2*N; i++)
        rup[i] = lup[i] = 1;
    backtrack(1);
    return 0;
}
void showAnswer() {
    int x, y;
    printf("\n解答%d\n", ++num);
    for(y = 1; y <= N; y++) {
        for(x = 1; x <= N; x++) {
            if(queen[y] == x) {
                printf(" Q");
            }
            else {
                printf(" .");
            }
        }
        printf("\n");
    }
}
void backtrack(int i) {
    int j;
    if(i > N) {
        showAnswer();
    }
    else {
        for(j = 1; j <= N; j++) {
            if(column[j] == 1 &&
               rup[i+j] == 1 && lup[i-j+N] == 1) {
                queen[i] = j;
                // 设定为占用
                column[j] = rup[i+j] = lup[i-j+N] = 0;
                backtrack(i+1);
                column[j] = rup[i+j] = lup[i-j+N] = 1;
            }
        }
    }
}

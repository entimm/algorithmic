/*
三色棋
说明
三色旗的问题最早由E.W.Dijkstra所提出，他所使用的用语为Dutch Nation Flag
 (Dijkstra为荷兰人)，而多数的作者则使用Three-Color Flag来称之。
假设有一条绳子，上面有红、白、蓝三种颜色的旗子，起初绳子上的旗子颜色并没有顺序，您
希望将之分类，并排列为蓝、白、红的顺序，要如何移动次数才会最少，注意您只能在绳子上
进行这个动作，而且一次只能调换两个旗子。
解法
在一条绳子上移动，在程式中也就意味只能使用一个阵列，而不使用其它的阵列来作辅助，问
题的解法很简单，您可以自己想像一下在移动旗子，从绳子开头进行，遇到蓝色往前移，遇到
白色留在中间，遇到红色往后移，如下所示：
只是要让移动次数最少的话，就要有些技巧：
如果图中W所在的位置为白色，则W+1，表示未处理的部份移至至白色群组。
如果W部份为蓝色，则B与W的元素对调，而B与W必须各+1，表示两个群组都多了一个元素。
如果W所在的位置是红色，则将W与R交换，但R要减1，表示未处理的部份减1。
注意B、W、R并不是三色旗的个数，它们只是一个移动的指标；什幺时候移动结束呢？一开始
时未处理的R指标会是等于旗子的总数，当R的索引数减至少于W的索引数时，表示接下来的旗
子就都是红色了，此时就可以结束移动，如下所示：
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLUE 'b'
#define WHITE 'w'
#define RED 'r'
#define SWAP(x, y) { char temp; \
temp = color[x]; \
color[x] = color[y]; \
color[y] = temp; }
int main() {
    char color[] = {'r', 'w', 'b', 'w', 'w',
        'b', 'r', 'b', 'w', 'r', '\0'};
    int wFlag = 0;
    int bFlag = 0;
    int rFlag = strlen(color) - 1;
    int i;
    for(i = 0; i < strlen(color); i++)
        printf("%c ", color[i]);
    printf("\n");
    while(wFlag <= rFlag) {
        if(color[wFlag] == WHITE)
            wFlag++;
        else if(color[wFlag] == BLUE) {
            SWAP(bFlag, wFlag);
            bFlag++; wFlag++;
        }
        else {
            while(wFlag < rFlag && color[rFlag] == RED)
                rFlag--;
            SWAP(rFlag, wFlag);
            rFlag--;
        }
    }
    for(i = 0; i < strlen(color); i++)
        printf("%c ", color[i]);
    printf("\n");
    return 0;
}

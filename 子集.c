/*
 假设有个集合拥有m个元素，任意的从集合中取出n个元素，则这n个元素所形成的可能子集有
 那些？
 解法
 假设有5个元素的集点，取出3个元素的可能子集如下：
 {1 2 3}、{1 2 4 }、{1 2 5}、{1 3 4}、{1 3 5}、{1 4 5}、{2 3 4}、{2 3 5}、{2 4 5}、
 {3 4 5}
 这些子集已经使用字典顺序排列，如此才可以观察出一些规则：
 如果最右一个元素小于m，则如同码表一样的不断加1
 如果右边一位已至最大值，则加1的位置往左移
 每次加1的位置往左移后，必须重新调整右边的元素为递减顺序
 所以关键点就在于哪一个位置必须进行加1的动作，到底是最右一个位置要加1？还是其它的位
 置？
 在实际撰写程式时，可以使用一个变数positon来记录加1的位置，position的初值设定为n-1，
 因为我们要使用阵列，而最右边的索引值为最大的n-1，在position位置的值若小于m就不断加
 1，如果大于m了，position就减1，也就是往左移一个位置；由于位置左移后，右边的元素会经
 过调整，所以我们必须检查最右边的元素是否小于m，如果是，则position调整回n-1，如果不
 是，则positon维持不变。
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main(void) {
    int set[MAX];
    int m, n, position;
    int i;
    printf("输入集合个数m：");
    scanf("%d", &m);
    printf("输入取出元素n：");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        set[i] = i + 1;
    // 显示第一个集合
    for(i = 0; i < n; i++)
        printf("%d ", set[i]);
    putchar('\n');
    position = n - 1;
    while(1) {
        if(set[n-1] == m)
            position--;
        else
            position = n - 1;
        set[position]++;
        // 调整右边元素
        for(i = position + 1; i < n; i++)
            set[i] = set[i-1] + 1;
        for(i = 0; i < n; i++)
            printf("%d ", set[i]);
        putchar('\n');
        if(set[0] >= m - n + 1)
            break;
    }
    return 0;
}

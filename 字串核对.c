/*
 字串核对
 说明今日的一些高阶程式语言对于字串的处理支援越来越强大（例如Java、Perl等），不过字
 串搜寻本身仍是个值得探讨的课题，在这边以Boyer- Moore法来说明如何进行字串说明，这个
 方法快且原理简洁易懂。
 解法字串搜寻本身不难，使用暴力法也可以求解，但如何快速搜寻字串就不简单了，传统的
 字串搜寻是从关键字与字串的开头开始比对，例如Knuth-Morris-Pratt 演算法字串搜寻，这个
 方法也不错，不过要花时间在公式计算上；Boyer-Moore字串核对改由关键字的后面开始核对字
 串，并制作前进表，如果比对不符合则依前进表中的值前进至下一个核对处，假设是p好了，然
 后比对字串中p-n+1至p的值是否与关键字相同。
 如果关键字中有重复出现的字元，则前进值就会有两个以上的值，此时则取前进值较小的值，
 如此就不会跳过可能的位置，例如texture这个关键字，t的前进值应该取后面的3而不是取前面的
 7。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void table(char*); // 建立前进表
int search(int, char*, char*); // 搜寻关键字
void substring(char*, char*, int, int); // 取出子字串
int skip[256];
int main(void) {
    char str_input[80];
    char str_key[80];
    char tmp[80] = {'\0'};
    int m, n, p;
    printf("请输入字串：");
    gets(str_input);
    printf("请输入搜寻关键字：");
    gets(str_key);
    m = strlen(str_input); // 计算字串长度
    n = strlen(str_key);
    table(str_key);
    p = search(n-1, str_input, str_key);
    while(p != -1) {
        substring(str_input, tmp, p, m);
        printf("%s\n", tmp);
        p = search(p+n+1, str_input, str_key);
    }
    printf("\n");
    return 0;
}
void table(char *key) {
    int k, n;
    n = strlen(key);
    for(k = 0; k <= 255; k++)
        skip[k] = n;
    for(k = 0; k < n - 1; k++)
        skip[key[k]] = n - k - 1;
}
int search(int p, char* input, char* key) {
    int i, m, n;
    char tmp[80] = {'\0'};
    m = strlen(input);
    n = strlen(key);
    while(p < m) {
        substring(input, tmp, p-n+1, p);
        if(!strcmp(tmp, key)) // 比较两字串是否相同
            return p-n+1;
        p += skip[input[p]];
    }
    return -1;
}
void substring(char *text, char* tmp, int s, int e) {
    int i, j;
    for(i = s, j = 0; i <= e; i++, j++)
        mp[j] = text[i];
    tmp[j] = '\0';
}

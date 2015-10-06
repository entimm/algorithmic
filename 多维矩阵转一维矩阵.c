/*
 多维矩阵转一维矩阵
 说明
 有的时候，为了运算方便或资料储存的空间问题，使用一维阵列会比二维或多维阵列来得方便，
 例如上三角矩阵、下三角矩阵或对角矩阵，使用一维阵列会比使用二维阵列来得节省空间。
 解法
 以二维阵列转一维阵列为例，索引值由0开始，在由二维阵列转一维阵列时，我们有两种方式：
 「以列（Row）为主」或「以行（Column）为主」。由于C/C++、Java等的记忆体配置方式都是
 以列为主，所以您可能会比较熟悉前者（Fortran的记忆体配置方式是以行为主）。
 以列为主的二维阵列要转为一维阵列时，是将二维阵列由上往下一列一列读入一维阵列，此时
 索引的对应公式如下所示，其中row与column是二维阵列索引，loc表示对应的一维阵列索引：
 loc = column + row*行数
 以行为主的二维阵列要转为一维阵列时，是将二维阵列由左往右一行一行读入一维阵列，此时
 索引的对应公式如下所示：
 loc = row + column*列数
 公式的推导您画图看看就知道了，如果是三维阵列，则公式如下所示，其中i（个数u1）、j（个
 数u2）、k（个数u3）分别表示三维阵列的三个索引：
 以列为主：loc = i*u2*u3 + j*u3 + k
 以行为主：loc = k*u1*u2 + j*u1 + i
 更高维度的可以自行依此类推，但通常更高维度的建议使用其它资料结构（例如物件包装）会
 比较具体，也不易搞错。
 在C/C++中若使用到指标时，会遇到指标运算与记忆体空间位址的处理问题，此时也是用到这
 边的公式，不过必须在每一个项上乘上资料型态的记忆体大小。
*/

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int arr1[3][4] = {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    int arr2[12] = {0};
    int row, column, i;
    printf("原二维资料：\n");
    for(row = 0; row < 3; row++) {
        for(column = 0; column < 4; column++) {
            printf("%4d", arr1[row][column]);
        }
        printf("\n");
    }
    printf("\n以列为主：");
    for(row = 0; row < 3; row++) {
        for(column = 0; column < 4; column++) {
            i = column + row * 4;
            arr2[i] = arr1[row][column];
        }
    }
    for(i = 0; i < 12; i++)
        printf("%d ", arr2[i]);
    printf("\n以行为主：");
    for(row = 0; row < 3; row++) {
        for(column = 0; column < 4; column++) {
            i = row + column * 3;
            arr2[i] = arr1[row][column];
        }
    }
    for(i = 0; i < 12; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    return 0;
}

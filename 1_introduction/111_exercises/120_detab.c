/**
 * 制表符终止位可以看成excel单元格之间的竖线。
 * 当在填充单元格时，输入了制表符（tab）时，会自动跳到下一个单元格的起始位置，如果没有填充满当前单元格，会用空格填充。
 * 如果填满了单元格也没有遇到制表符，会自动跳到下一个单元格的起始位置。
 * 例如：
 * 单元格宽度是8， 如果输入了“abc"后，输入了制表符，会自动跳到第二个单元格的起始位置，也就是第9个位置，期间用6个空格填充。
 * 如果输入了“a”后，输入了制表符，会自动跳到第二个单元格的起始位置，也就是第9个位置，期间用7个空格填充。
*/
#include <stdio.h>
#define TABINC 4    // tab increment size

/*replace tabs with the proper number of blanks*/
int main()
{
    int c, nb, pos;
    nb = 0; // number of blanks necessary
    pos = 1; // position of character in line
    while ((c = getchar()) != EOF){
        if (c == '\t'){
            nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0){
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n'){
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}
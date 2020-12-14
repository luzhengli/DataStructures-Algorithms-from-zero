#include <stdio.h>
#include <string.h>
int PuSuPiPei(char s[], char sub[]);
int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char sub[] = "l00";
    printf("The index of substring is: %d", PuSuPiPei(s, sub));
    return 0;
}

int PuSuPiPei(char s[], char sub[])
{
    /* 串朴素匹配算法：返回模式串在主串中的位置，若匹配失败，则返回-1
     * s：主串
     * sub：子串/模式串
     */
    int k, i, j; // k: 指向主串中子串的指针 i: 主串中子串字符的指针 j: 子串字符的指针
    i = 0;
    k = j = 0;

    while (s[i] != '\0' && sub[j] != '\0')
    {
        if (s[i] != sub[j])
        {
            ++k;
            i = k;
            j = 0;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    if (j == strlen(sub))
    {
        return k;
    }
    else
    {
        return -1;
    }
}
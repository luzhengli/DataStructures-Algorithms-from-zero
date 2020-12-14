#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool SubString(char sub[], char s[], int start, int len1, int len2);
int StrCompare(char s1[], char s2[]);
int SubIndex(char sub[], int len1, char s[], int len2);
int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char sub[10];
    SubString(sub, s, 3, 2, strlen(s));
    puts(sub);
    int index = SubIndex(sub, strlen(sub), s, strlen(s));
    printf("The index of subString in main String is: %d", index);
    return 0;
}

bool SubString(char sub[], char s[], int start, int len1, int len2) // 从主串s中找到从索引start开始的 长度为len的子串
{
    /*
     * sub：子串
     * s：主串
     * start：子串的位置
     * len1：子串的长度
     * len2：主串的长度
    */
    if (len1 + start <= len2)
    {
        int i;
        for (i = start; i < start + len1; i++)
        {
            sub[i - start] = s[i];
        }
        sub[i - start] = '\0';
        return true;
    }
    else
    {
        return false;
    }
}

int StrCompare(char s1[], char s2[]) // s1>s2返回正数；s1<s2返回负数 s1=s2返回0
{
    int i;
    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
    }
    return '\0' - s2[i]; // '\0' 的ASCII码为0
}

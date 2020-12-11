#include <stdio.h>
#include <stdbool.h>
bool SubString(char sub[], char s[], int start, int len);
int StrCompare(char s1[], char s2[]);
int SubIndex(char sub[], int len, char s);
int main(int argc, char const *argv[])
{

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
    if()
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

int SubIndex(char sub[], int len1, char s, int len2) // 返回子串在主串中的下标
{
    /*
    * sub：子串
    * len1：子串长度
    * s：主串
    * len2：主串长度
    */

    // 从位置i开始（i=0,1,2...），在主串中找到与子串sub相同长度的子串temp
    // 比较temp是否与sub相等，如果相等，返回i
    // 返回-1 表示找不到该子串
    char temp[50];
    int i;
    for (i = 0; i + len1 < len2; i++)
    {
        SubString(temp, s, i, len1);
        if (StrCompare(sub, temp) == 0)
        {
            return i;
        }
    }
    return -1;
}
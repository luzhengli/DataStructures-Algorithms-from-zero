#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{

    return 0;
}

int KMP(char s[], char sub[], int next[])
{
    int i, j;
    while (s[i] != '\0' && sub[j] != '\0')
    {
        if (j == 0 || s[i] == sub[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    int len = strlen(sub);
    if (j == len)
    {
        return i - len;
    }
    else
    {
        -1;
    }
}

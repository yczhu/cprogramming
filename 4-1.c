//strrindex(char s[], char t[]) can find the position of the rightmost occurence of t in s, -1 if there is none



#include <stdio.h>

int strrindex(char s[], char t[]);

int main()
{
    char s[] = "saaaaadfaavb";
    char t[] = "a";
    printf("index: %d\n", strrindex(s, t));
    return 0;
}


int strrindex(char s[], char t[])
{
    int i, j, k, max;
    max = -1;

    for (i=0; s[i] != '\0';i++)
    {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k >0 && t[k] == '\0')
        {
            printf("%d\n", i);
            max = i;
        }
    }
    return max;
} 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]);
int expandable(char s1, char s2);

int main()
{

char *s[] = { "a-z-", "z-a-", "-1-6-",
                    "a-ee-a", "a-R-L", "1-9-1",
                    "5-5", "a-b-c", "a-0", "0-a",  NULL };
     int i = 0;
     
      while ( s[i] ) {
          char result[100];
           
           /*  Expand and print the next string in our array s[]  */
                      
           expand(result, s[i]);
           printf("Unexpanded: %s\n", s[i]);
           printf("Expanded  : %s\n", result);
           ++i;}
    return 0;
}

//expand shorthand notations s2 like a-z into equivalent complete lists
//abc...xyz in s1
void expand(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int len = strlen(s2);
    while (i < len)
    {
        if ((s2[i] == '-') && (i != 0) && (i != len-1))
        {
            if(expandable(s2[i-1], s2[i+1]))
            {
                if (s2[i-1] < s2 [i+1])
                {
                    for (char c = s2[i-1]+1; c < s2[i+1];c++, j++)
                    {
                        s1[j] = c;
                    }
                    i++;
                }
                else
                {
                    for (char c = s2[i-1]-1; c > s2[i+1]; c--, j++)
                    {
                        s1[j] = c;
                    }
                    i++;
                } 
            }
            else
            {
                printf("Unexpandable!\n");
                s1[j++] = s2[i++];
            }
        }
        else
            s1[j++] = s2[i++];
    }
    s1[j] = '\0';

}

int expandable(char s1, char s2)
{
    if (isdigit(s1) && isdigit(s2))
        return 1;
    else if (islower(s1) && islower(s2))
        return 1;
    else if (isupper(s1) && isupper(s2))
        return 1;
    else
        return 0;
}

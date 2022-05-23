#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int findTriple(char input[100])
{
    int i = 0;
    int cnt=0;
    for (i = 0; i<strlen(input)-2;i++)
    {
        if (input[i]==input[i+1] && input[i+1] == input[i+2])
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    char str[100];
    scanf("%s", str);
    printf("%i", findTriple(str));
    return 0;
}

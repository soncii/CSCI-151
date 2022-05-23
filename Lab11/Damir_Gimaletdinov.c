#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int stringLength(char str[100])
{
    int i=0;
    while (str[i]!='\0')
    {
        i++;
    }
    return i;
}
void stringLower(char str[100])
{
    int i = 0;
    while(str[i]!='\0')
    {
        int temp = str[i];
        if (temp>=65 && temp<=90)
        {
            temp = temp +32;
        }
        str[i]=temp;
        i++;
    }
}
void stringUpper(char str[100])
{
    int i = 0;
    while(str[i]!='\0')
    {
        int temp = str[i];
        if (temp>=97 && temp<=122)
        {
            temp = temp -32;
        }
        str[i]=temp;
        i++;
    }
}

int main()
{
    printf("==========================================\n");
printf("== TASK 1: ==\n");
printf("==========================================\n");

char str[100]="Some string";
printf("Testing stringLength(%s): %i\n",str,stringLength(str));
printf("Testing stringLower(%s): ",str);
stringLower(str);
printf("%s\n", str);
printf("Testing stringUpper(%s): ",str);
stringUpper(str);
printf("%s\n", str);
    return 0;
}

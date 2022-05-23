#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void squarify(char *str)
{
    int len =strlen(str);
    int i=0,j;
    int N;
    for (i=1; i*i<len; i++)
    {
    }
    N=i;
    char fin[N][N];
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            if ((i*N)+(j) < len)
            {
                if (j==0)
                {
                    fin[i][j]=*(str+i*N);
                }
                else
                {
                    fin[i][j]=*(str+(i*N)+j);
                }
            }
            else
            {
                fin[i][j]='-';
            }
        }
    }
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            printf("%c ", fin[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Damir Gimaletdinov\n");
    printf("ID=201965238\n");
    printf("Section 1\n");
    printf("Please enter a string consisting of letters: ");
    char s[100];
    scanf("%s",s);
    squarify(s);
    return 0;
}

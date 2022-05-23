#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i,j,sum=0;
    printf("Please provide x: ");
    scanf("%i", &x);
    int a[x][x];
    int cnt=0;

    for ( i=0; i<x; i++)
    {
        for ( j=0; j<x; j++)
        {
            cnt++;
            a[i][j]=cnt;
        }
    }

    for ( i=0; i<x; i++)
    {
        for ( j=0; j<x; j++)
        {
            if (a[i][j]>=a[j][i])
            {
                a[j][i]=a[i][j];
            }
        }
    }

    for ( i=0; i<x; i++)
    {
        for ( j=0; j<x; j++)
        {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }

    for (i=0; i<x; i++)
    {
        sum = sum+a[i][i];
    }
    printf("%i",sum);
    return 0;
}

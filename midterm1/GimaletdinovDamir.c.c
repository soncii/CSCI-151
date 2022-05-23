#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter integer n: ");
    scanf("%i", &n);
    int cnt=0;
    int i,j;
    for ( i=0; i<n; i++)
    {
        if (i%2==0)
        {
            cnt=0;
        }
        else
        {
            cnt=1;
        }
        for( j=0; j<i+1; j++)
        {
            if (cnt % 2 ==0)
            {
                printf("0");

            }
            else
            {
                printf("1");
            }
            cnt++;
        }

        printf("\n");

    }
    return 0;
}

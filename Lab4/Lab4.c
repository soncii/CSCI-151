#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("==========================================\n");
    printf("== TASK 1: ==\n");
    printf("==========================================\n");
    int n, i=1;
    do
    {
        printf("Please provide some number bigger than 0: ");
        scanf("%d", &n);
        while (i<=n)
        {
            int j=1;
            while(j <= i)
            {
                printf("* ");
                ++j;
            }
            i++;
            printf("\n");
        }
        i=1;
    }
    while (n != 0);
    printf("\nProgram had to terminate\n");


    printf("==========================================\n");
    printf("== TASK 2: ==\n");
    printf("==========================================\n");

    int k,j;
    do
    {
        printf("Please provide some number greater than 0: ");
        scanf("%d", &n);
        i=n/2;
        int g=n;


        while(g>0)
        {
            k=g;
            j=1;
            while(k>1)
            {
                printf(" ");
                k-=1;
            }
            while (j<=n-g+1)
            {
                printf("* ");
                j++;
            }
            printf("\n");
            g--;
        }
    }
    while(n!=0);
    printf("Program had to terminate\n");



    printf("==========================================\n");
    printf("== TASK 3: ==\n");
    printf("==========================================\n");
    do
    {
        printf("Provide some number: ");
        scanf("%d", &n);
        if(n!=0)
        {


            int i=1,res=1;
            while (i<= n)
            {
                res= res*i;
                i++;

            }
            printf("The factorial of %d is %d\n", n, res);

        }
    }
    while (n>0);
    printf("Done");

    return 0;
}


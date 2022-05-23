#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("==========================================\n");
    printf("== TASK 1: ==\n");
    printf("==========================================\n");

    char ch;
    int asc;
    while((asc != 81 && asc != 113))
    {
        ch=getchar();
        asc = ch;
        if (asc == 81 || asc == 113)
        {
            printf("Bye./n");
        }
        else if (asc>47 && asc <58)
        {
            printf("The entered character is a digit.\n");
        }
        else if(asc>64 && asc<91)
        {
            printf("The entered character is a letter.\n");
        }
        else if(asc>96 && asc<123)
        {
            printf("The entered character is a letter.\n");
        }
        else
        {
            printf("Not character nor letter\n");

        }
    }



    printf("\n==========================================\n");
    printf("== TASK 2: ==\n");
    printf("==========================================\n");
    int s, c;
    do
    {
        printf("Provide Cost price: ");
        scanf("%i", &c);
        printf("Provide Sell price: ");
        scanf("%i", &s);
        int r = s-c;
        if (s<0 || c<0)
        {
            printf("Incorrect values\n");
        }
        else if(r>0)
        {
            printf("Ur profit: %i\n", r);
        }
        else if (r<0)
        {
            printf("Ur loss: %i\n", r);
        }
        else if(r==0)
        {
            printf("U didn't lose or profit anything\n");
        }

    }
    while(s!=0 || c!=0);
    printf("Program stopped");


    printf("\n==========================================\n");
    printf("== TASK 4: ==\n");
    printf("==========================================\n");

    int n;
    int i;
    scanf("%i",&n);
    for (i=0; i<=n; i++)
    {
        printf("the square of %4i is %7i\n", i, i*i);
    }

    printf("\n==========================================\n");
    printf("== TASK 3: ==\n");
    printf("==========================================\n");



    int Acnt=0;
    int Zcnt=0;
    do
    {
        ch = getchar();
        if (ch=='z')
        {
            Zcnt++;
        }
        else if (ch=='a')
        {
            Acnt++;
        }
    }
    while (ch != '\n');

    printf("\nNumber of a is %i\n", Acnt);
      printf("Number of z is %i\n", Zcnt);

    return 0;

}

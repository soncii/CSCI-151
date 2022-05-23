#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Fib(int n)
{
    if (n==2 || n==1)
    {
        return 1;
    }
    else return (Fib(n-1)+Fib(n-2));
}
typedef struct
{
    char firstname[20];
    char secondname[20];
    char gender;
    int yearOfStudy;
    int studStatus;

} UndStudent;
UndStudent inc(UndStudent n)
{
    if (n.yearOfStudy>=4)
    {
        n.studStatus=0;
    }
    else n.yearOfStudy+=1;
    return n;
}
int main()
{
    printf("==========================================\n");
    printf("== TASK 1: ==\n");
    printf("==========================================\n");
    int n;
    while(n>0)
    {
        printf("Please provide the number: ");
        scanf("%i",&n);
        if (n>0)
        {
            printf("Result of Fibonacci sequence for %ith value is: %i", n, Fib(n));
        }
        else printf("Bye!");
        printf("\n");
    }

    printf("==========================================\n");
    printf("== TASK 2: ==\n");
    printf("==========================================\n");
    UndStudent Anna;
    strcpy(Anna.firstname, "Anna");
    strcpy(Anna.secondname, "Smith");
    Anna.gender='f';
    Anna.yearOfStudy=3;
    Anna.studStatus=1;
    printf("Before the update\n");
    if (Anna.studStatus == 1)
    {
        printf("%s %s, %c, %i Year of Undergraduate Study", Anna.firstname, Anna.secondname, Anna.gender, Anna.yearOfStudy);
    }
    else
    {
        printf("Not a student: %s %s, %c", Anna.firstname, Anna.secondname, Anna.gender);
    }
    printf("\n");
    Anna=inc(Anna);
    printf("After the update\n");
    if (Anna.studStatus == 1)
    {
        printf("%s %s, %c, %i Year of Undergraduate Study", Anna.firstname, Anna.secondname, Anna.gender, Anna.yearOfStudy);
    }
    else
    {
        printf("Not a student: %s %s, %c", Anna.firstname, Anna.secondname, Anna.gender);
    }

    UndStudent Colin;
    strcpy(Colin.firstname, "Colin");
    strcpy(Colin.secondname, "Smith");
    Colin.gender='m';
    Colin.yearOfStudy=4;
    Colin.studStatus=1;
    printf("\n\nAnother Person:\nBefore the update\n");
    if (Colin.studStatus == 1)
    {
        printf("%s %s, %c, %i Year of Undergraduate Study", Colin.firstname, Colin.secondname, Colin.gender, Colin.yearOfStudy);
    }
    else
    {
        printf("Not a student: %s %s, %c", Colin.firstname, Colin.secondname, Colin.gender);
    }
    printf("\n");
    Colin=inc(Colin);
    printf("After the update\n");
    if (Colin.studStatus == 1)
    {
        printf("%s %s, %c, %i Year of Undergraduate Study", Colin.firstname, Colin.secondname, Colin.gender, Colin.yearOfStudy);
    }
    else
    {
        printf("Not a student: %s %s, %c", Colin.firstname, Colin.secondname, Colin.gender);
    }
    return 0;

}

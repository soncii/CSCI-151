#include <stdio.h>
#include <stdlib.h>

#include <time.h>
int Factorial(int n)
{

    int result =1,i;

    for ( i = 1; i<=n; i++)
    {
        result=result *i;
    }
    return result;
}
void fibonacci(int n, int arr[n])
{
    arr[1]=1;
    arr[2]=1;
    int i;
    for (i=3; i<=n; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];

    }

}
void printFibs(int n, int arr[n])
{

    int i;
    for (i=1; i<=n; i++)
    {
        printf("%i ", arr[i]);

    }

}
typedef struct
{
    int r, g, b;
} Color;
typedef struct
{
    int x, y;
} Coords;
typedef struct
{
    Color color;
    Coords point1;
    Coords point2;
} LineSegment;
typedef struct
{
    LineSegment Line[3];
} Triangle;
typedef struct
{
    char ID[10];

    int Age;

    int Year;
    char deg[8];
    float GPA;
    char Gender;

} Student;
int main()
{
    printf("==========================================\n");
    printf("== TASK 1: ==\n");
    printf("==========================================\n");
    Triangle T1;
    T1.Line[0].color.r=255;
    T1.Line[0].color.g=255;
    T1.Line[0].color.b=255;
    T1.Line[1].color.r=255;
    T1.Line[1].color.b=0;
    T1.Line[1].color.g=0;
    T1.Line[2].color.g=0;
    T1.Line[2].color.b=0;
    T1.Line[2].color.r=0;

    T1.Line[0].point1.x=3;
    T1.Line[0].point2.x=7;
    T1.Line[0].point1.y=9;
    T1.Line[0].point2.y=5;

    T1.Line[1].point1.x=7;
    T1.Line[1].point1.y=5;
    T1.Line[1].point2.x=2;
    T1.Line[1].point2.y=2;

    T1.Line[2].point1.x=2;
    T1.Line[2].point1.y=2;
    T1.Line[2].point2.x=3;
    T1.Line[2].point2.y=9;
    int i;
    for(i=0; i<3; i++)
    {
        printf("Triangle %i: coordinates: x1=%i y1=%i x2=%i y2=%i, r=%i, g=%i, b=%i\n", i+1, T1.Line[i].point1.x,T1.Line[i].point1.y,T1.Line[i].point2.x, T1.Line[i].point2.y, T1.Line[i].color.r, T1.Line[i].color.g, T1.Line[i].color.b);
    }
    printf("==========================================\n");
    printf("== TASK 2: ==\n");
    printf("==========================================\n");
    srand ( time(NULL) );
    Student CSCI151[400];


    for (i=0; i<400; i++)
    {
        int gendernum = rand()%2;
        if (gendernum==1)
        {
            CSCI151[i].Gender='m';
        }
        else
        {
            CSCI151[i].Gender='f';
        }
        CSCI151[i].Age = rand()%4+18;
        sprintf(CSCI151[i].deg, "Bachelor");
        CSCI151[i].Year = rand()%3+1;
        CSCI151[i].GPA = rand()%5;
        long int IDnum = rand()%1000000+2022*1000000;
        sprintf(CSCI151[i].ID, "%li",IDnum);

        printf("S%i: ID:%s; Gender:%c; Age:%i; Deg:%s; Year:%i; GPA:%f;\n", i, CSCI151[i].ID, CSCI151[i].Gender, CSCI151[i].Age, CSCI151[i].deg, CSCI151[i].Year, CSCI151[i].GPA);
    }

    printf("==========================================\n");
    printf("== TASK 3: ==\n");
    printf("==========================================\n");
    printf("Factorial & Fibonacci: Please provide the input: ");
    int n;
    scanf("%i",&n);
    printf("Result of factorial for %i: %i",n, Factorial(n));
    int arr[n];
    fibonacci(n, arr);
    printf("\nFibbonacci Sequence: ");
    printFibs(n, arr);
    return 0;

}

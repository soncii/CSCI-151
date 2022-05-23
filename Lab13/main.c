#include <stdio.h>
#include <stdlib.h>
void reverse (int size, int arr[])
{
    int i;
    int *parr[size];
    int temp;
    for (i=0; i<size; i++)
    {
        parr[i]=&arr[i];
    }
    for (i=0; i<size/2; i++)
    {
        temp = *(parr[size-i]);
        int temp2 = *(parr[i]);
        *(parr[size-i]) = temp2;
        *(parr[i]) = temp;
    }

}
typedef struct
{
    char firstname[20];
    char secondname[20];
    char gender;
    int yearOfStudy;
    int studStatus;

} UndStudent;
void inc(UndStudent *n)
{
    if ((*n).yearOfStudy>=4)
    {
        (*n).studStatus=0;
    }
    else (*n).yearOfStudy+=1;
}
int main()
{
    int size = 4;
    int arr_num[size];
    int i;

    for (i=0; i<size; i++)
    {
        arr_num[i]=i+1;
    }
    printf("===========Original Array==========\n");
    for (i=0; i<size; i++)
    {
        printf("%i", arr_num[i]);
    }
    reverse(size,arr_num);
    printf("\n===========Reversed Array==========\n");
    for (i=0; i<size; i++)
    {
        printf("%i", arr_num[i]);
    }

    printf("\n==========================================\n");
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
    inc(&Anna);
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
    inc(&Colin);
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

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("==========================================\n");
    printf("== TASK 1: ==\n");
    printf("==========================================\n");
    FILE *infile;
    FILE *outfile;
    infile  = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");


    char word[81];
    int i;
    int sum=0;
    int j=0;
    int cnt=0;
    char num[4];
    do
    {
        fscanf(infile, "%s", word);
        for (i=0; word[i]!='\0'; i++)
        {
            int asc = word[i];

            if (asc>47 && asc <58)
            {
                num[j]=word[i];
                j++;
                int asctemp = word[i+1];
                if ( asctemp<48 ||  asctemp>57)
                {
                    i++;
                    j=0;
                    cnt++;
                    int num = atoi( word);
                    sum=sum+num;
                    printf("%i. there is an int values %i\n", cnt, num);
                    fprintf(outfile, "%i. there is an int values %i\n", cnt, num);

                }
            }
        }

    }

    while (!feof(infile));

    printf("The sum of numbers is %d", sum);
    fprintf(outfile, "The sum of numbers is %d", sum);

    fclose(infile);
    fclose(outfile);

    printf("\n==========================================\n");
    printf("== TASK 2: ==\n");
    printf("==========================================\n");
    int arr1[1000], arr2[1000], res[1000];
    int n;
    printf("Please provide the size of the array: ");
    scanf("%i", &n);
    printf("\nStarting to fill the array\n");
    for (i=0; i<n; i++)
    {
        printf("%i. enter the value to the nums1[%i] array\n", i+1, i);
        scanf("%i", &arr1[i]);
    }
    for (i=0; i<n; i++)
    {

        printf("%i. enter the value to the nums2[%i] array\n", i+1, i);
        scanf("%i", &arr2[i]);
    }
    for (i=0; i<n; i++)
    {
        res[i]=arr1[i]-arr2[i];
    }
    printf("Finding the result\n");
    for (i=0; i<n; i++)
    {
        printf("%i. nums1[%i] - nums2[%i]: result[%i] = %i \n", i+1,i,i,i,res[i]);
    }
    return 0;
}

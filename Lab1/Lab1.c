#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("==========================================\n");
    printf("== TASK 1: ==\n");
    printf("==========================================\n");

    double usd_total = 100;
    double kzt = 434.53, eur = 90, rub = 78.19;
    printf("100.000000 dollars converted to KZT: %lf Tenge \n", usd_total*kzt);
    printf("100.000000 dollars converted to EUR: %lf Euros \n", usd_total*eur);
    printf("100.000000 dollars converted to RUB: %lf Rubles \n", usd_total*rub);


    printf("==========================================\n");
    printf("== TASK 2: ==\n");
    printf("==========================================\n");

    int days;
    printf("Please provide the number of days: ");
    scanf("%d", &days);
    printf("%d", days);
    int years = days/365;
    days = days % 365;
    int weeks = days/7;
    days = days%7;
    printf("\n Years: %d", years);
    printf("\n Weeks: %d", weeks);
    printf("\n Days: %d", days);

    printf("==========================================\n");
    printf("== TASK 3: ==\n");
    printf("==========================================\n");
    int first,second;
    printf("Please enter the first value: ");
    scanf("%d", &first);
    printf("Please enter the second value: ");
    scanf("%d", &second);
    printf("Original val1: %d", first);
    printf(" Octal: %o ", first);
    printf("Hexadecimal: %x \n", first);

    printf("Original val2: %d", second);
    printf(" Octal: %o ", second);
    printf("Hexadecimal: %x \n", second);

    printf("==========================================\n");
    printf("== TASK 4: ==\n");
    printf("==========================================\n");
    double degr, rad;
    printf("Please provide some angle value between 0 and 360: ");
    scanf("%lf", &degr);
    rad = degr*M_PI/180;
    printf("COS(%lf) = ", degr);
    printf("%lf", cos(rad));

    printf("\nSIN(%lf) = ", degr);
    printf("%lf", sin(rad));

    printf("\nTAN(%lf) = ", degr);
    printf("%lf", tan(rad));

    printf("\nATAN(%lf) = ", degr);
    printf("%lf", atan(rad));

    return 0;


}

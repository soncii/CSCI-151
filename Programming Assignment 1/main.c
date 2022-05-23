#include <stdio.h>

int main( void )
{

    // Change the following three lines
    char name[50] = "Damir Gimaletdinov"; // your name and surname
    int id = 201965238; // your student id
    int section = 1; // your lecture section (1 or 2)
    ///////////////////////////////////

    printf("%s, %d, Lecture Section %d\n\n", name, id, section);

    printf("-------------------------------------\n");
    printf("--------------- TASK 1 --------------\n");
    printf("-------------------------------------\n");

    // Your code should start after this line

    int days[365];
    FILE *infile;
    FILE *outfile;
    infile  = fopen("input.txt", "r"); //file initialization and opening;

    char word[81];
    int i,j=0, cnt=0;
    do
    {
        fscanf(infile, "%i ", &days[cnt]);
        fscanf(infile,"%s ",word);

        cnt++;

        /*fscanf(infile, "%s", word);
          int asc = word[0];
          if (asc>47 && asc <58) //checking if it is a integer
          {
              days[cnt]=0;
              int wordcounter =0;
              while(asc>47 && asc <58 ) //counts number of digits in the number
              {
                  wordcounter++;
                  asc = word[wordcounter];
              }
              for (j=wordcounter-1; j>=0; j--) // cycle for char to int conversion
              {
                  int ten1 = 1; //variable for 1,10,100 multiplyier
                  for (x=0; x<(wordcounter-j-1); x++)
                  {
                      ten1= ten1*10;
                  }
                  int tempnum = (word[j]-'0'); //temporary variable for storing digit
                  days[cnt]=days[cnt]+tempnum*ten1;
              }
              cnt++;
          }*/

    }
    while (!feof(infile));

    for (i = 0; i< cnt; i++)
    {
        printf("%i ", days[i]);
    }
    printf("\n");
    int d;
    int isinFile=0;
    scanf("%i",&d);
    for (i = 0; i< cnt; i++)
    {
        if (days[i]==d)
        {
            isinFile=1;
            printf("It exists in the file!");
        }
    }
    if  (d<1 || d>365)
    {
        printf("Not within the limits!");
    }
    fclose(infile);
    if(d>0 && d<366) //checking if d is in range
    {
        if(isinFile==0) //checking if d is not in file
        {
            outfile = fopen("input.txt", "a"); //opening file to write
            fprintf(outfile,"\n");//starting from the new file
            int wd = d % 7;//wd variable for weekday
            if (wd == 0) //seven conditions for 7 weekdays
            {
                printf("It is Friday, ");//printing to the console
                fprintf(outfile, "%i Fri",d );//printing to the file
            }

            if (wd == 1)
            {
                printf("It is Saturday, ");
                fprintf(outfile, "%i Sat",d );
            }

            if (wd == 2)
            {
                printf("It is Sunday, ");
                fprintf(outfile, "%i Sun",d );
            }
            if (wd == 3)
            {
                printf("It is Monday, ");
                fprintf(outfile, "%i Mon",d );
            }
            if (wd == 4)
            {
                printf("It is Tuesday, ");
                fprintf(outfile, "%i Tue",d );
            }
            if (wd == 5)
            {
                printf("It is Wednesday, ");
                fprintf(outfile, "%i Wed",d );
            }
            if (wd == 6)
            {
                printf("It is Thursday, ");
                fprintf(outfile, "%i Thu",d );
            }



            if (d>0 && d<32) // checking the range of days in the month for 12 month. the ranges of d were calculated by hand
            {
                printf("January ");
                if(d>0 && d<10) //if day is one digit adding 0 in the beginning
                {
                    printf("0%i",d);
                }
                else printf("%i",d);
            }
            else if(d>31 && d<60)
            {
                d=d-31;//finding the day in the month  31 is the number of days in the previous month
                printf("February ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);
            }
            else if (d>59 && d<91)
            {
                d=d-31-28;
                printf("March ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>90 && d<121)
            {
                d=d-31-28-31;
                printf("April ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>120 && d<152)
            {
                d=d-31-28-31-30;
                printf("May ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>151 && d<182)
            {
                d=d-31-28-31-30-31;
                printf("June ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>181 && d<213)
            {
                d=d-31-28-31-30-31-30;
                printf("July ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>212 && d<244)
            {
                d=d-31-28-31-30-31-30-31;
                printf("August ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>243 && d<274)
            {
                d=d-31-28-31-30-31-30-31-31;
                printf("September ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>273 && d<305)
            {
                d=d-31-28-31-30-31-30-31-31-30;
                printf("October ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>304 && d<335)
            {
                d=d-31-28-31-30-31-30-31-31-30-31;
                printf("November ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            else if (d>334 && d<366)
            {
                d=d-31-28-31-30-31-30-31-31-30-31-30;
                printf("December ");
                if(d>0 && d<10)
                {
                    printf("0%i",d);
                }
                else printf("%i",d);

            }
            fclose(outfile);

        }
    }
    printf("\n");
    printf("-------------------------------------\n");
    printf("--------------- TASK 2 --------------\n");
    printf("-------------------------------------\n");


    infile  = fopen("corrupted_chess.txt", "r"); //opening the file
    char general[1000][20]; //our main array
    int numcnt;
    i = 0;
    int z;
    int ten;
    int score=0;
     int rank = 0,prevmax=0;

    do //reading from the file
    {
        fscanf(infile, "%s", general[i]);
        i = i+1;
    }
    while (!feof(infile));
    int gcnt=i; //gcnt = number of records in the general array
    j =0;
    int k;
    int max=0, indexmax=0;
    scanf("%i", &k);//reading value of k
    while (k>0 || prevmax==max) //
    {
        max=0, indexmax=0;
        for (i=0; i<gcnt; i++)
        {
            int asc = general[i][0]; //storing ascii value of first digit/character
            if (asc>47 && asc <58)//checking if it is a score by checking the first character number or not
            {
                score =0, j=0; //clearing variables
                while(asc>47 && asc <58)//cycle for counting number of digits in the integer
                {
                    j++;
                    asc = general[i][j]; //reassigning ascii value of the next digit so the it can exit the loop
                }
                numcnt = j-1; // storing the index of last digit in the variable numcnt
                for (j=numcnt; j>=0; j--) //going through the subarray of integer from the last digit
                {
                    ten=1;
                    for (z=0; z<(numcnt-j); z++) //cycle for calculating power of ten
                    {
                        ten=ten*10;
                    }
                    int litlenum =(general[i][j]-'0'); //assigning current digit to int variable
                    score = score+litlenum*ten; //converting the char array into one int variable by multiplying the current digit by power of ten
                }

                if (score>max) //checking if the current number bigger than maximum(simple maximum search)
                {
                    max = score; //storing newmaximum value
                    indexmax = i; //storing the index of maximum value
                }

            }
        }
        general[indexmax][0]='b';//excluding the maximum number from the next iteration
        if (k>0 || prevmax ==max) //checking if the last number has the same rank
        {
            if(max !=prevmax)
            {
                rank++;
                printf("%i ", rank);
                prevmax = max;
                k--; //decreasing loop iterator if we go to the lower rank
            }
            else
            {
                printf("%i ", rank);
            }
            if (indexmax ==0) //special condition if the score is the first element in the file
            {
                printf("%s", general[1]);
            }
            else if(indexmax %2 ==1) //checking if the player is given first
            {
                printf("%s", general[indexmax-1]); //printing playernumber
            }
            else if(indexmax %2 ==0) //checking if the score is given first
            {
                printf("%s", general[indexmax+1]);//printing playernumber
            }
            printf(" %i\n", max); //printing the score
        }

    }
    return 0;
}

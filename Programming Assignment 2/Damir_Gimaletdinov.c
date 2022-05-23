#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
    int year;
    int month;
    int day;
} Date; //creation of Date structure
typedef struct
{
    int hours;
    int mins;
    int secs;
} Time; //creation of Time structure
typedef struct
{
    float temp;
    float pres;
    float humid;
} Readings; //creation of Reading structure
typedef struct
{
    char deviceid[15];
    Date dt;
    Time tm;
    Readings readings;
} MeteoData; //creation of MeteoData structure
typedef struct
{
    float avg_temp;
    float min_temp;
    Time min_temp_time;
    float max_temp;
    Time max_temp_time;
} stats; //creation of Stats structure
double time_interval(Time t1, Time t2)
{
    if (t1.hours != 0 )//usual case when the time difference is not between 00 and 23
    {
        return (t1.hours-t2.hours)*3600+(t1.mins-t2.mins)*60+t1.secs-t2.secs;

    }
    else
    {
        if (t2.hours == 23) // special case when the time difference is 00 and 23
        {
            return (t1.hours+24-t2.hours)*3600+(t1.mins-t2.mins)*60+t1.secs-t2.secs;
        }
        else //usual case
            return (t1.hours-t2.hours)*3600+(t1.mins-t2.mins)*60+t1.secs-t2.secs;
    }
}
stats calc_temp(MeteoData Records[], int lines)
{
    int i=0;
    float sum=0;
    for (i=0; i<lines; i++)
    {
        sum=Records[i].readings.temp+sum;//finding the sum of temperatures
    }
    float avg = sum/lines;//finding the average by dividing sum by number of records
    float min = 1000;// initializing min vairable with big value so that it can save up the first reading
    Time mint;//initializing mint Time type variable to store the time of min temperature
    for (i=0; i<lines; i++)
    {
        float tempor = Records[i].readings.temp;//saving the value of current row's temperature in a temporary variable so its easier to work with the value
        if (tempor < min) //comparing current row's temperature with current min
        {
            min = tempor;//overriding min with the current temperature
            mint = Records[i].tm;//saving the time when min occured
        }
    }
    float max = 0;
    Time maxt;
    for (i=0; i<lines; i++)
    {
        float tempor = Records[i].readings.temp; //saving the value of current row's temperature in a temporary variable so its easier to work with the value
        if (tempor > max)//comparing current row's temperature with current max
        {
            max = tempor; //comparing current row's temperature with current max
            maxt = Records[i].tm;////saving the time when max occured
        }
    }
    stats Stats;//creating a stats variable where we will store the values that are calculated and which we will later return to the main function
    Stats.avg_temp = avg;//storing the values
    Stats.min_temp = min;
    Stats.min_temp_time = mint;
    Stats.max_temp_time = maxt;
    Stats.max_temp = max;
    return Stats;
}


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
    printf("-------------------------------------\n\n\n");

    // Your code should start after this line

    srand(time(NULL));
    int i,j;
    int moves[8][2] = {{1, 2}, {2, 1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };//creation of array of possible moves
    printf("Enter the board size: ");
    int n;
    scanf("%i",&n);
    int b[n+1][n+1];//numerical representation of board
    char d[n+1][n+1];//user representation of board with A, - and C
    int x,y;//current coordinates

    do
    {
        printf("Please enter coordinate x: ");
        scanf("%i", &x);
        printf("Please enter coordinate y: ");
        scanf("%i", &y);
        if (((x<1 || x>n)||(y<1 || y>n)))//condition for correct input
        {
            printf("The values should be in the range 1<x<%i and 1<y<%i. \n",n,n);
        }
    }
    while ((x<1 ||x>n)||(y<1 || y>n)); //cycle for assurance of coordinates lying within the range
    for (i=n; i>0; i--)//cycle is created so the last row is considered to be the first
    {
        for (j=1; j<n+1; j++)
        {
            b[i][j]=0;
            if (i==x && j==y)//printing the initial board
            {
                printf("A ");
                d[i][j]='A';//filing the user interface array

            }
            else
            {
                printf("- ");
                d[i][j]='-';//filing the user interface array
            }
        }
        printf("\n");
    }
    int end=0;//variable that checks if there are available turns
    int k;
    while (end!=1)
    {
        end=1;
        for ( k=0; k<8; k++)
        {
            if (moves[k][0]+x<=n && moves[k][1]+y<=n && moves[k][0]+x>=1 && moves[k][1]+y>=1) //checking if possible move lies within the field
            {
                if (b[moves[k][0]+x][moves[k][1]+y] == 0)//checking if the cell has not been visited before
                {
                    end=0;//means there is a free cell where horse can go
                    break;
                }
            }
        }
        if (end==0)//if there is free turn and game is continuing
        {
            int turn=0;//variable to check the finding of the turn
            int a;
            while (turn!=1)//cycle is done until the turn if found
            {
                a = rand() % 8;//random move is initialized
                if (moves[a][0]+x<=n && moves[a][1]+y<=n && moves[a][0]+x>=1 && moves[a][1]+y>=1) //checking if possible move lies within the field
                {
                    if (b[moves[a][0]+x][moves[a][1]+y] == 0) //checking if the cell has not been visited before
                    {
                        turn=1;//finish the cycle
                        b[moves[a][0]+x][moves[a][1]+y]=1;//remember that the cell is visited
                        d[moves[a][0]+x][moves[a][1]+y]='C';//mark the cell as current
                        x=moves[a][0]+x;//remember the current x coordinate
                        y=moves[a][1]+y;//remember the current y coordinate
                    }
                }
            }
            for (i=n; i>=1; i--)
            {
                for (j=1; j<n+1; j++)
                {
                    printf("%c ",d[i][j]);//display the board after the turn
                }
                printf("\n");
            }
            printf("\n");
            d[x][y]='A';//mark the cell as already visited
        }
    }
    printf("No more legal moves!\n");
    for (i=n; i>=1; i--)//printing the final state of board
    {
        for (j=1; j<n+1; j++)
        {
            printf("%c ",d[i][j]);//display the board after the turn
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
    printf("--------------- TASK 2 --------------\n");
    printf("-------------------------------------\n\n");
    FILE *infile;

    infile  = fopen("weather.csv", "r");//reading from the file
    MeteoData Records[1100];//creating the main array of meteodata
    char tempor[1001][100];//temporary string where we will store one line of data
    int iter=0;//size of array
    fgets(tempor[iter+1], 500, infile);//reading the first line so we skip it
    do
    {
        //clearing the the previous line
        fgets(tempor[iter+1], 500, infile);	//reading the line
        int i=0;//iterator through the line
        while(tempor[iter+1][i]!= ',')//reading device id until ,
        {
            Records[iter].deviceid[i]=tempor[iter+1][i];
            i++;
        }
        i++;//skipping
        int j=0;
        char num[10];//temporary num string which we will later convert to the number
        while(tempor[iter+1][i]!= '-')//reading year until -
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        Records[iter].dt.year = atoi(num);// converting array of characters to integer and saving it
        memset(num, 0, sizeof(num));//clearing number string
        i++;
        j=0;//iterator for num string
        while(tempor[iter+1][i]!= '-')//reading month until -
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        Records[iter].dt.month = atoi(num);// converting array of characters to integer and saving it
        memset(num, 0, sizeof(num));
        i++;
        j=0;
        while(tempor[iter+1][i]!= ' ') //reading day until space
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        Records[iter].dt.day = atoi(num);// converting array of characters to integer and saving it
        memset(num, 0, sizeof(num));//clearing number string
        i++;
        j=0;
        while(tempor[iter+1][i]!= ':')//reading hours until :
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        Records[iter].tm.hours = atoi(num);
        memset(num, 0, sizeof(num));
        i++;
        j=0;
        while(tempor[iter+1][i]!= ':') //reading minutes until :
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        Records[iter].tm.mins = atoi(num);
        memset(num, 0, sizeof(num));
        i++;
        j=0;
        while(tempor[iter+1][i]!= ',')//reading seconds until ,
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        Records[iter].tm.secs = atoi(num);
        memset(num, 0, sizeof(num));
        i++;
        j=0;
        while(tempor[iter+1][i]!= ',') //reading temperature until ,
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        Records[iter].readings.temp = atof(num);
        memset(num, 0, sizeof(num));
        j=0;
        i++;
        while(tempor[iter+1][i]!= ',')//reading pressure until ,
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        j=0;
        i++;
        Records[iter].readings.pres = atof(num);
        memset(num, 0, sizeof(num));
        while(tempor[iter+1][i]!= '\n')//reading humidity until the end of line
        {
            num[j]=tempor[iter+1][i];
            i++;
            j++;
        }
        Records[iter].readings.humid = atof(num);
        memset(num, 0, sizeof(num));
        iter++;
    }
    while (!feof(infile));
    fclose(infile);//closing the file
    iter--;//removing the last iteration since it is the end of file
    double sum=0;
    for (i=0; i<iter-1; i++)
    {
        sum=time_interval(Records[i].tm, Records[i+1].tm)+sum;//summing up the time intervals
    }
    double averagetime = sum/(iter-1);//finding the average
    printf("The average time interval is %f\n", averagetime);
    stats Stats =calc_temp(Records, iter);//creating a stats type variable that will store the result of a calc_temp function
    printf("average temperature: %f\n", Stats.avg_temp);//printing the resultsa
    printf("minimal temperature: %f\n", Stats.min_temp);
    printf("time of minimum temperature: %i:%i:%i\n", Stats.min_temp_time.hours,Stats.min_temp_time.mins,Stats.min_temp_time.secs);
    printf("maximum temperature: %f\n", Stats.max_temp);
    printf("time of maximum temperature: %i:%i:%i\n", Stats.max_temp_time.hours,Stats.max_temp_time.mins,Stats.max_temp_time.secs);
    return 0;
}

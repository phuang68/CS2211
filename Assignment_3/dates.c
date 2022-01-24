#include <stdio.h>
#include <ctype.h>
//C99
//Author:Bryan Huang
/*Short Description: this is a c program that returns the latest date by multiple date inputs
*/
/*
  Write a C program named dates.c that determines which of the entered dates comes later on the
calendar. The user may enter any number of dates. The user will enter 0/0/0 to indicate that no
more dates will be entered.
  Dates will be entered in the mm/dd/yy format where mm is a two digit month number (1 to 12), dd
is a two digit day of the month (1 to 31) and yy is a two digit year (00 to 99). You should print an
error if an invalid date is entered (does not follow the format or out of the given ranges) and ask
the user for a new date (do not exit).
  The user is allowed to input a one digit number (they do not need to pad it with a zero). For
example 3/6/8, 3/6/08, 3/6/18, 3/16/18, and 03/06/08 are all valid dates. When outputting,
the latest date, you should always pad the day, month and year to ensure they are two digits. For
example, 3/6/8 should be output as 03/06/08.
  You do not have to check that the number of days are correct for a given month. For example,
you can consider 2/31/18 to be a valid date (February has 28 days). However, the number of days
must be in the range 1 to 31. The same date maybe input multiple times.
  If the user does not input any dates before entering 0/0/0 an error should be displayed and the
program should exit with a non-zero exit status. Otherwise the exit status should be zero.
*/

int main(){
	int m1=0;
	int d1=0;
	int y1=0;
	int  m,d,y,r;
	printf("Enter a date (mm/dd/yy): ");
	if(scanf("%d/%d/%d",&m1,&d1,&y1)!=3){
		printf("mon=%d,day=%d,year=%d\n",m1,d1,y1);
		//check if the input date is valid 
		printf("Error: Invalid date format!\n");
		while(getchar()!='\n');
		} 
	else if(m1==0&&d1==0&&y1==0){//check if the input date is 0/0/0
                printf("Error: At least one date must be input!\n");
                return 1;
        	}
	else if( m1 < 0 || m1 > 12){//check if the input month of date is valid,and set it to 0/0/0;
		printf("Error: Invalid month number!\n");
		printf("%d",m1);
		d1=0;
		m1=0;
		y1=0;
		}
	else if( d1 < 0 || d1 > 31 ){//check if the input day of date is valid and if not set it to 0/0/0
		printf("Error: Invalid day number!\n");
		d1=0;
		m1=0;
		y1=0;
		}
	else if( y1 < 0 || y1 > 99 ){//check if the input year of date is valid,if not set it to 0/0/0
		printf("Error: Invalid year number!\n");
		d1=0;
		m1=0;
		y1=0;
		}
	while(1){//do another time of input
	printf("Enter a date (mm/dd/yy): ");
        printf("mon=%d,day=%d,year=%d",m,d,y);
	if(scanf("%d/%d/%d",&m,&d,&y)!=3){
                //check if the input date is valid
                printf("Error: Invalid date format!\n");
                while(getchar()!='\n');
                printf("mon=%d,day=%d,year=%d\n",m,d,y);
                continue;
                }        
	else if( m == 0 && d == 0 && y == 0 ){
                if(m1 == 0 && d1 == 0 && y1 == 0 || m1<=0 || d1<=0 || y1 <= 0|| m1>12 || y1 > 99 || d1 >31){
                printf("Error: At least one date must be input!\n");
                break;
                }
                else{
                printf("%2.2d/%2.2d/%2.2d is the latest date\n",m1,d1,y1);
                break;
                }
                }
        else if( m < 0 || m > 13){
                printf("Error: Invalid month number!\n");
                continue;
		}
        else if( d < 0 || d > 31 ){
                printf("Error: Invalid day number!\n");
		continue;
                }
        else if( y < 0 || y > 99 ){
                printf("Error: Invalid year number!\n");
		continue;
                }
	//This condition check if the input date is the lastest,if yes,store it in the first input date
	if( y > y1 ){//if the input year is latest year,set the date to the input date
		y1 = y;
		m1 = m;
		d1 = d;
		}
	else if( m >  m1 ){//if the input year is the same,and input month is later,set the date to the input date
		m1 = m;
		d1 = d;
		}
	else if( d > d1 ){//if the input year and month are the same,and input day is later,set the date to the input date
		d1 = d;
		}
	}//if the second time input of date is not 0/0/0	
	return 0;
}

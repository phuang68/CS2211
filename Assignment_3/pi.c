#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//C99
//Author:Bryan Huang
/*Short Description: this is a c program that calculate pi
*/
double estimate_pi(long long n){
	double x,y,r;//declare the two variable to stored randomly generated number
	int p=0;//count number of points inside the shaded quadrant
	
	//generate points n times
	for(int i = 0; i < n ; i++){
	x=(double)(rand()%10001)/10000;//generate random number bwtween 0 and 1 and assign it to x and y
	y=(double)(rand()%10001)/10000;//same as above
	//Check if the generated number is inside the quarant
	if((x*x)+(y*y) <= 1)
		p++;
	}
	
	//calculate the ratio of the points inside the circle and total generated points
	r=(double)p/n;
	//and return the estimated pi
	return 4*r;
}

int main(){
	long long n;//declare input times;
	double p,m,sd,sum1,sum2;//declare variables to store pi.mean,standard deviation and sums of value and of squre value
	
	//read repetition time N
	printf("Input execution times: ");
	scanf("%d",&n);
	
	//validating the value of N,if it's invalid print error message and exit
	if(n <= 0){
		printf("Invalid Input!\n");
		return 1;
	}
	
	//Generate estimated pi for 10 times
	for(int i = 1 ; i <= 10 ; i++){
	p=estimate_pi(n);
	printf("The %d generated pi is: %f\n",i,estimate_pi(n));
	sum1+=p;//the sum1 will store the summary of generated pi
	sum2+=(p*p);//the sum2 will store the summary of geerated pi times itself
	}

	m=sum1/10;//it will calculate the average of pi
	sd=sqrt(sum2/10-m*m);//it will calculate the standard deviation
	printf("The mean value is %.10f and the standard deviation is %.10f\n",m,sd);
	return 0;	
}

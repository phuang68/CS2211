#include <stdio.h>
#include <stdlib.h>
//C99
//Author:Bryan Huang
//Short Description: this is a c program that takes input phone number and return a format based on the format choice

int main(){
	int num,a,b,c;//declare integer variable num to take the input,and split the number in the three parts to use later in printing options
	char op;//declare option character variable to store the character input
	printf("Input Phone Number: ");
	int r=scanf("%d",&num);
	if(num<1000000000||r!=1){//if the input is character or smaller than 10 digits,it will return a error message.
	printf("Error: Invalid Phone Number!\n");
	}
	else
	{
	a = (num/10000000);//it takes the first three digits of the valid num
	b = (num - a*10000000)/10000;//it takes the second three digits of the valid num
	c = (num - (num/10000)*10000);//it takes the last four digits of the number
	printf("Format Options:\n");
	printf("A) Local\n");
	printf("B) Domestic\n");
	printf("C) International\n");
	printf("D) Odd\n");
	printf("Input Option: ");
	getchar();//cancel the previous input
	scanf("%c",&op);//take in the option input and assign it to op variable
	if(op == 'A' || op == 'a')
		printf("%3d%4d\n",b,c);//print out the form of last seven number
	else if(op == 'B' || op == 'b')
		printf("(%3d)%3d-%4d\n",a,b,c);//print out in the form of (xxx)-xxx-xxxx
	else if(op == 'C' || op == 'c')	
		//print out in the form of +1-xxx-xxx-xxxx if op is c or C
		printf("+1-%3d-%3d-%4d\n",a,b,c);
	else if(op == 'D' || op == 'd')
		//print out in the form of 0xxx 0xxx xxxx if op is d or D
		printf("0%3d\t0%3d\t%4d\n",a,b,c);
	else
		//print out the error message if the option is not any character above
		printf("Invalid Option!\n");	
	}
	return 0;
}

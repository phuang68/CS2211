#include <stdio.h>
#include <stdlib.h>
//C99
//Author:Bryan Huang
//Short Description: this is a c program that takes input amount and determines the smallest number of $20, $10, $5, $2, and
//$1 bills or coins necessary to pay a dollar amount

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies,int *lonnies){
	//counting how much twenties is needed
	*twenties=dollars/20;
	dollars=dollars-*twenties*20;
        printf("you need at least %d twenties",*twenties);
	//counting how much tens is needed
	*tens=dollars/10;
	dollars=dollars-*tens*10;
	printf(",%d ten(s)",*tens);
	//counting how much fives is needed
	*fives=dollars/5;
	dollars=dollars-*fives*5;
	printf(",%d five(s)",*tens);
	//counting how much toonies is needed
	*toonies=dollars/2;
	dollars=dollars-*toonies*2;
	printf(",%d toonie(s)",*toonies);
	//counting how much lonnies is needed
	*lonnies=dollars;
	printf(",%d lonnie(s)!\n",*lonnies);
}

//main function to test pay_amount function

int main(){
	int total,tw,te,fi,to,lo;//Declaring variables of total amount of money,twenties,tens,fives,toonies,loonies
	printf("Input amount of money to be paid: ");
	int r = scanf("%d",&total);
	if(total<0||r!=1){//checking if the input is less than 0 or other types
	printf("The input is invalid!\n");
	return 1;
	}
	printf("For total amount of %d,",total);
	pay_amount(total,&tw,&te,&fi,&to,&lo);
	return 0;
}

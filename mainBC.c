#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions_BC.h"

int main(){
	int choice;

	printf("FOR Normal operations --> 1\nFor infix evaluation --> 2\n");
	printf("Enter your choice --> ");
	scanf("%d",&choice);

	switch(choice){
		case 1 : 
			char n1[1000];
			char n2[1000];
			
			printf("\nEnter the first number --> \n");
			fgets(n1,1000,stdin);
			
			printf("\nEnter the second number --> \n");
			fgets(n2,1000,stdin);

			calc_ll(n1,n2);
			break;
		case 2 : 
			infix_eval();
			break;
		default : 
			printf("INVALID");
			break;
	}
	printf("\n");
}



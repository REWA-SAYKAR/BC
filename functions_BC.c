#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions_BC.h"


struct node *reversell(struct node *head){
	if(head == NULL || head->link == NULL){
		return head;
	}
	struct node *newhead = reversell(head -> link);
	struct node *head_next = head -> link;
	head_next -> link = head;
	head -> link = NULL;
	return newhead;
}

//function to print reversed ll
struct node *print_reversell(struct node *head){
	if(head == NULL){
		return 0;
	}
	print_reversell(head->link);

	printf("%d",head->data);

}

//function to print ll
void printfll(struct node *head){
        struct node *ptr;
        ptr=head;
        while(ptr!=NULL){
                printf("%d",ptr->data);
                ptr=ptr->link;
        }
}

struct node *init_ll(struct node *head_n, int data_n){
	struct node *ptr_n;
	ptr_n = (struct node*)malloc(sizeof(struct node));
	ptr_n -> data = data_n;
	ptr_n -> link = NULL;
	head_n = ptr_n;
	return head_n;
}

//now function to insert a node at the end of the ll
struct node *insert_at_end(struct node *head, int data_n){
	struct node *ptr;
	struct node *newnode=NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data_n;
	newnode->link = NULL;        
	ptr=head;
	while(ptr->link!=NULL){
		ptr=ptr->link;
	}

	ptr->link = newnode;
	return head;
}

struct node *insert(struct node *head, int data){
	if(head == NULL){
		head = init_ll(head , data);
	}
	else{
		head = insert_at_end(head , data);
	}
	return head;
}

struct node * add_ll(struct node *head_n1, struct node *head_n2){
	int value;
	int carry = 0;//which is going to be value/10
	int sum;//which is going to be value%10

	struct node *ptr_n1 = head_n1;
	struct node *ptr_n2 = head_n2;
	
	//creating linked list for storing answer
	struct node *head_ans = NULL;

	while(ptr_n1 && ptr_n2){
		value = carry + (ptr_n1 -> data) + (ptr_n2 -> data);
		carry = value/10;
		sum = value%10;
		head_ans = insert(head_ans , sum);
		ptr_n1 = ptr_n1->link;
		ptr_n2 = ptr_n2->link;
	}
	while(ptr_n1){
                value = carry + (ptr_n1 -> data);
                carry = value/10;
                sum = value%10;
                head_ans = insert(head_ans , sum);
                ptr_n1 = ptr_n1->link;
        }
	while(ptr_n2){
		value = carry + (ptr_n2 -> data);
                carry = value/10;
                sum = value%10;
                head_ans = insert(head_ans , sum);
                ptr_n2 = ptr_n2->link;
        }
	if(carry){
		head_ans = insert(head_ans,carry);
	}

	return head_ans;      

}



struct node *sub_ll(struct node *head_n1, struct node *head_n2){
        int borrow = 0;
	int diff;

	if(head_n2 == NULL){
                return head_n1;
        }
	struct node *ptr_n1 = head_n1;
	struct node *ptr_n2 = head_n2;

	//making linked list for answer
	struct node *head_ans = NULL;

	while(ptr_n1 != NULL){
		diff = borrow + (ptr_n1 -> data) - (ptr_n2 != NULL ? (ptr_n2 -> data) : 0);
		if(diff < 0){
			borrow = -1;
			diff += 10;
		}
		else{
			borrow = 0;
		}
		head_ans = insert(head_ans , diff);
		ptr_n1 = ptr_n1 -> link;
		if(ptr_n2 != NULL){
			ptr_n2 = ptr_n2 -> link;
		}
	}
	return head_ans;
}

long long mul_ll(struct node *head_n1, struct node *head_n2){
	long long int n1 = 0, n2 = 0;
	long long int mod = 1000000007;//for lmit
	struct node *ptr_n1 = head_n1;
	struct node *ptr_n2 = head_n2;

	while(ptr_n1 != NULL){
		n1 = (n1*10+(ptr_n1 -> data))%mod;
		ptr_n1 = ptr_n1 -> link;
	}
	while(ptr_n2 != NULL){
		n2 = (n2*10+(ptr_n2 -> data))%mod;
		ptr_n2 = ptr_n2 -> link;
	}
	return (n1*n2)%mod;
}

void div_ll(struct node *head_n1, struct node *head_n2){
        printf("Under construction\n");
}

void calc_ll(char n1[],char n2[]){
        int ch;
	//char n1[1000];
        //char n2[1000];
	
	printf("For addition --> 1\nFor subtraction --> 2\nFor multiplication --> 3\nFor division --> 4\n");

	
        printf("Enter the first number :\n");
        fgets(n1,1000,stdin);
	printf("Enter the second number :\n");
	fgets(n2,1000,stdin);
	
	//creating the linked list of n1
        struct node *head_n1 = NULL;	       	

        for(int i=strlen(n1)-2;i>=0;i--){
		head_n1 = insert(head_n1,((n1[i]) - '0'));
	}

	//printf("\nThe first number is --> \n");
	//printfll(head_n1);


	//creating the linked list of n2
	struct node *head_n2 = NULL;

        for(int i=strlen(n2)-2;i>=0;i--){
                head_n2 = insert(head_n2,((n2[i]) - '0'));
        }

        //printf("\nThe second number is --> \n");
        //printfll(head_n2);

	printf("\nEnter your choice of operation --> \n");
	scanf("%d",&ch);
	struct node *head_ans;
	switch(ch){
		case 1 : 
			head_ans = add_ll(head_n1, head_n2);
			printf("The addition is --> \n");
			print_reversell(head_ans);
			break;
		case 2 : 
			head_ans = sub_ll(head_n1, head_n2);
			printf("The subtraction is --> \n");
			print_reversell(head_ans);
			break;
		case 3 : 
			printf("\nThe multiplication is --> \n");
			printf("%lld",mul_ll(head_n1,head_n2));
			break;
		case 4 : 
			div_ll(head_n1,head_n2);
			break;
		default : 
			printf("Invalid");
			break;
	}        
	
        printf("\n");
}

void infix_eval(){
	printf("Under construction");
}


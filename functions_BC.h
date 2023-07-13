#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//creating the node
struct node{
        int data;
        struct node *link;
};

struct node *reversell(struct node *head);
struct node *print_reversell(struct node *head);
void printfll(struct node *head);
struct node *insert_at_end(struct node *head, int data_n);
struct node *insert(struct node *head, int data);
struct node *add_ll(struct node *head_n1, struct node *head_n2);
struct node *sub_ll(struct node *head_n1, struct node *head_n2);
long long mul_ll(struct node *head_n1, struct node *head_n2);
void div_ll(struct node *head_n1, struct node *head_n2);
struct node *init_ll(struct node *head_n, int data_n);

void calc_ll(char n1[], char n2[]);

void infix_eval();

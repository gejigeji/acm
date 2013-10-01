#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node{
	int d;
	struct node *link;
};

struct node *top = NULL
void push(int);
int pop();
void display();
void main(){
	int item,ch;
	clrscr();
	while(1)
	{
		printf("Linked list implementation of a stack\n");
		printf("1.Push......\n");
		printf("2.Pop.......\n");
		printf("3.Display...\n");
		printf("4.Exit......\n");
		printf("Enter your choice(1..4) ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter the item to be")
		}
	}
}
#include<stdio.h>
#include<stdio.h>
unsigned int far *ptr;
void (*p) (void);
void f1();
void f2();
void main(){
	clrscr();
	f1();
	f2();
	printf("\nback to main...");
	exit(1);
}

void f1(){
	ptr=(unsigned int far *) MK_FP ( _SS, _SP +2);
	printf("\n%d", *ptr);

	p = (void (*)()) MK_FP (_CS, *ptr);
	(*p)();
	printf("\nI am f1() function");
}

void f2(){
	printf("\nI am f2() function");
}
#include <stdio.h>
#include <string.h>

#define LEN 30002
#define WID 5
void refresh(int (*Tran)[WID],int head, int tail){
	int add_num;
	int new_head,new_tail;
	add_num=Tran[tail][2]+1;
	new_head=Tran[tail][3];
	new_tail=Tran[head][4];
	do{
		Tran[head][2]=Tran[head][2]+add_num;
		Tran[head][3]=new_head;
		head=Tran[head][1];
	}while(head!=0);
	do{
		Tran[tail][4]=new_tail;
		tail=Tran[tail][0];
	}while(tail!=0);
}

void add(int (*Tran)[WID],int M1,int M2){
	int head,tail;
	if(Tran[M1][3]==0) Tran[M1][3]=M1;
	if(Tran[M1][4]==0) Tran[M1][4]=M1;
	if(Tran[M2][3]==0) Tran[M2][3]=M2;
	if(Tran[M2][4]==0) Tran[M2][4]=M2;
	head=Tran[M1][3];
	tail=Tran[M2][4];
	Tran[head][0]=tail;
	Tran[tail][1]=head;
	refresh(Tran,head,tail);
}

void main(){
	int M;
	int i=0;
	int num;
	char S[2];
	int M1,M2,C;
	int Tran[LEN][WID]={0};
	scanf("%d",&M);
	while(i<M && scanf("%s",S)!=EOF){
		if(S[0]=='M'){
			scanf("%d %d",&M1,&M2);
			add(Tran,M1,M2);
		}
		else{
			scanf("%d",&C);
			//num=cal_num(Tran,C);
			num=Tran[C][2];
			printf("%d\n",num);
		}
		i++;
	}
}

#include <stdio.h>
#include <string.h>

#define LONG 30002
#define WIDE 3
struct lenfath{
	int len;
	int fath;
};

struct lenfath getoriginalfather(int (*tran)[WIDE], int v){
	struct lenfath S_ff;
	if(tran[v][0]==0){
		S_ff.len=0;
		S_ff.fath=v;
		return S_ff;
	}
	else{
		S_ff=getoriginalfather(tran,tran[v][0]);
		tran[v][0]=S_ff.fath;
		tran[v][2]=S_ff.len+tran[v][2];
		S_ff.len=tran[v][2];
		return S_ff;
	}
}

void Union(int (*tran)[WIDE],int x,int y){
	int fx, fy;
	int add_lenth;
	struct lenfath S_fx, S_fy;
	S_fx = getoriginalfather(tran,x);
	S_fy = getoriginalfather(tran,y);
	fx = S_fx.fath;
	fy = S_fy.fath;
	if(fy!=fx){
		tran[fx][0]=fy;
		//link fx to fy
		tran[fx][2]=tran[fy][1]+1;
		//tran[fy][1] means the original length of fy -1
		//tran[fx][2] means the the length of fy that fx needs to add
		tran[fy][1]=tran[fy][1]+tran[fx][1]+1;
		//update the length of fy -1
	}
}

int main(){
	int tran[LONG][WIDE]={0};
	char S[2];
	int i=0;
	int M1,M2,C;
	int num;
	int temp;
	int M;
	struct lenfath S_main;
	scanf("%d",&M);
	while(i<M && scanf("%s",S)!=EOF){
		if(S[0]=='M') {
			scanf("%d %d",&M1,&M2);
			Union(tran,M1,M2);
		}
		else{
			scanf("%d",&C);
			S_main=getoriginalfather(tran,C);
			printf("%d\n",S_main.len);
		}
		i++;
	}
	return 0;
}

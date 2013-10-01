/* WA */
#include<stdio.h>
#include<string.h>

int cal(int a){
	int i,b;
	for(i=0;i<5;i++){
		if((a%10)>0)
			b++;
		a=a/10;
	}
	return 5-b;
}


void main(){
	int N;
	int temp,i,a,j;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		temp=0;
		for(j=0;j<5;j++){
			scanf("%d",&a);
			temp=temp+cal(a);
		}
	if(temp%2==0)
		printf("lose\n");
	else
	  	printf("win\n");
	}
}

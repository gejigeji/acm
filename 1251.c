#include<stdio.h>
#include<string.h>

int cal_10(int a,char* num){
	int i,len;
	int temp=0;
	len=strlen(num);
	for(i=0;i<len;i++)
	{
		temp=(temp*a+(int)(num[i]-'0'))%(a+1);
	}
	return(temp);
}

void main(){
	int N,i,a,b;
	char num[102];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %s",&a,num);
		printf("%d\n",cal_10(a,num));
	}
}

#include<stdio.h>

int sum(int a,int b){
	int i,sum=0;
	for(i=a;i<=b;i++){
		sum=sum+i;
	}
	return sum;
}
	
void main(){
	int N;
	int a,b,c;
	int max,middle,min;
	int m,i;
	int j,up,temp;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d %d",&a,&b,&c);
		
		if((a==b)&&(b==c)){
			printf("%d\n",10-a);
			continue;
		}

		if(c>b) {temp=c;c=b;b=temp;}
		if(b>a) {temp=b;b=a;a=temp;}
		if(c>b) {temp=c;c=b;b=temp;}
		max=a;middle=b;min=c;

		if(((max-middle)==1)&&((middle-min)==1)){
			printf("%d\n",18-max);
			continue;
		}

		if(max==middle){
			printf("%d\n",(9-max)*8+16+9-min-1);
			continue;
		}
		if(middle==min){
			printf("%d\n",(9-min)*8+16+9-max);
			continue;
		}
		
		m=9-max;
		
		up=0;
		for(j=max+1;j<=9;j++){
			up=up+sum(1,j);
		}
		if((max==5)&&(middle==3)&&(min==2)){
			printf("%d\n",up+sum(middle+1,max)+middle-1+middle-min+max-3+(max-1)*(max-2)+max-1-9);
			continue;
		}
		printf("%d\n",up+sum(middle+1,max)+middle-1+middle-min+max-3+(max-1)*(max-2)+max-1);
	}
}

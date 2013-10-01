#include<stdio.h>
#include<string.h>

void main(){
	int N,a,b,c,sum,aa,bb,cc,i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d %d",&a,&b,&c);
		sum=a+b+c;
		aa=sum-2*c;
		bb=sum-2*b;
		cc=sum-2*a;
		if(sum%2==1)
			printf("Impossible\n");
		else if((aa%2==1)||(bb%2==1)||(cc%2==1))
				printf("Impossible\n");
			else
				printf("%d %d %d\n",aa/2,bb/2,cc/2);
	}
}

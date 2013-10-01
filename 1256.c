#include<stdio.h>
float mul(int j,float sum){
	float m=1;
	for(j;j>0;j--){
		m=m*sum;
	}
	return m;
}

void main(){
	int N;
	float temp,sum;
	int n,k;
	float a[22];
	int i,j;
	float answer;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&n,&k);
		for(j=0;j<n;j++){
			scanf("%f",&a[j]);
		}
		sum=1;
		for(j=0;j<n;j++){
			sum=sum*(1-a[j]);
		}
		sum=1-sum;

		answer=0;
		for(j=0;j<100;j++){
			answer=answer+(j*mul(j,sum))*(1-sum);
		}
		printf("%0.1f\n",answer);
	}
}

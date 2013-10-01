//TIME LIMIT EXCEEDED
/*
#include <stdio.h>

float sum(float N){
    float a=0,temp;
    float i;
    for(i=1;i<N+1;i++){
	a=a+1.0/i;
    }
    a=a*0.5+0.5;
    return a;
    }

void main(){
    float answer,N;
    while(scanf("%f",&N)!=EOF){
        answer=sum(N);
		printf("%0.2f\n",answer);
    }
}
*/


#include <stdio.h>
#include <string.h>

float answer[1000001]={0};
void main(){
    int N;
    int i;
    answer[0]=1;
    for(i=1;i<1000001;i++) answer[i]=answer[i-1]+1.0/(2*(i+1));

    while(scanf("%d",&N)!=EOF){
 	printf("%0.2f\n",answer[N-1]);
    }
}


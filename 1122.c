#include <stdio.h>
#include <string.h>

void main(){
	int N,i;
	char s1[100],s2[100];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		if(scanf("%s %s",s1,s2)!=EOF){
			printf("%s%s\n",s1,s2);
		}
	}
}	

#include <stdio.h>
#include <string.h>

int transform(char* nchar,int len){
	int i,n=0;
	for(i=0;i<len;i++)
		n=n*10+(nchar[i]-'0');
	return n;
}

void  main(){
	int i,j,N,n,m,len;
    long temp,answer;
	char nchar[102];
	scanf("%d",&N);
	for(i=0;i<N;i++){
        temp=1;answer=0;
		scanf("%s %d",nchar,&m);
		len=strlen(nchar);
		if(len>=7) n=m;
		else if(transform(nchar,len)>m) n=m;
		else n=transform(nchar,len);
		
		for(j=1;j<=n;j++){
			answer=(answer+temp)%m;
			temp=temp*(j+1)%m;
		}

		answer=(answer+1)%m;
		printf("%ld\n",answer);
	}
	exit (0);
}

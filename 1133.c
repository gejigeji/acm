#include <stdio.h>
#include <string.h>

void main(){
	int i,nn,mm;
	int flag;
	char a[100];
	while(1){
		i=0;
		nn=0;
		mm=0;
		flag=0;
		if(scanf("%s",a)==EOF) break;
		for(i=0;i<strlen(a);i++){
			if(a[i]=='(') nn++;
			if(a[i]==')') mm++;
			if(nn<mm) {
				flag=1;
				break;
			}
		}
		if((flag==1||nn!=mm)){
			printf("NO\n");
		}
		else if(nn==mm){
			printf("YES\n");
		}

	}
}

/* TLE */
#include<stdio.h>
#include<string.h>

void main(){
	char a[1000002];
	char c[1000002];
	char* b;
	int i;
	int len_a;
	int len_new;
	int flag;
	int index;
	int len_already;
	int len_b;
	int temp;
	while(scanf("%s",a)!=EOF){
		flag=0;
		strcpy(c,a);
		b=c;
		b++;
		flag=0;
		len_a=strlen(a);
		len_b=len_a-1;
		len_already=0;
		while(len_b>len_already){
			len_new=len_b;
			printf("len_b=%d\n",len_b);
			for(len_new;len_new>0;len_new--){
				printf("len_new=%d\n",len_new);
				index=len_a-len_new;
				i=0;
				while(a[index]==b[i]&&index<len_a){
					i++;
					index++;
				}
				if(index==len_a){
					temp=i;
					i--;
					while(a[i]==b[i]&&i>-1){
						i--;
					}
					if(i==-1){
						printf("success!\n");
						flag=1;
						len_already=temp;
						break;
					}
				}
			}
			b=b+1;
			len_b=strlen(b);
		}
		
		if(flag<1)
			printf("No\n");
		if(flag==1){
			a[len_already]='\0';
			printf("%s\n",a);
		}
	}
}




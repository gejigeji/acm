#include<stdio.h>
void makeheap(int *, int);
void restoredown(int, int *, int);
void main(){
	int a[20];
	int n;
	int i;
	n = 5;
	a[1]=23;
	a[2]=1;
	a[3]=45;
	a[4]=89;
	a[5]=2;
	makeheap(a,n);
	printf("Heap :\n");
	for(i=1;i<=n;i++)
		printf("%d\t", a[i]);
}

void makeheap(int *a, int n){
	int i;
	for(i = n/2;i >=1;i--)
		restoredown(i,a,n);
}

void restoredown(int p, int *a,int n){
	int i,v;
	v=a[p];
	while(p <= n/2){
		i = 2*p;
		if((i<n) && (a[i] <a[i+1]))
			i++;
		if(v >= a[i])
			break;
		a[p] = a[i];
		p=i;
	}
	a[p]=v;
}
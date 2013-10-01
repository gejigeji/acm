#include<stdio.h>

int isTri(int a,int b,int c){
	if(a < b+c) return 1;
	else return 0;
}

void swap(int *a, int *b){
	int tmp;
	printf("swap\n");
	tmp = *a; *a= *b; *b = tmp;
}

void quick_sort(int a[], int left, int right){
	printf("%d %d\n",left,right);
	int i = left+ 1, j = right;
	int key = a[left];
	int p;
	if (left >= right) return;
	while(1){
		while (a[j] > key) j--;
		while (a[i] < key&&i<j) i++;
		if (i>=j) break;
		swap(&a[i], &a[j]);
		if(a[i]==key) j--;
		else i++;
	}

	//printf("%d %d %d %d\n",i,j,a[i],a[j]);
	swap(&a[left],&a[j]);
	for(p=0;p<10;p++){
		printf("%d ",a[p]);
	}
	printf("\n");
	
	if(left < i-1) quick_sort(a, left, i-1);
	if(j+1 < right) quick_sort(a, j+1, right);
}

int main(void){
	int n,i;
	int max;
	int a[1000002]={0};
	while(scanf("%d",&n)!=EOF){
		max=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quick_sort(a, 0, n-1);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
	}

	i = n-1;
	while(1){
		if(isTri(a[i],a[i-1],a[i-2])){
			max = a[i]+a[i-1]+a[i-2];
			break;
		}
		i--;
	} 
	printf("%d\n",max);
}
	return 0;
}
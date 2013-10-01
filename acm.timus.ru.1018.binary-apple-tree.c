#include<stdio.c>

int which_is_root(int **);
int is_in_tree(int, int, int *);
 
void main(){
	int N,Q;
	int i;
	int a,b,n,root;
	int tree[200]={0};
	int treearray[200][3];
	scanf("%d",&N);
	scanf("%d",&Q);
	for(i=0;i<N-1;i++){
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&n);
		treearray[i][0]=a;
		treearray[i][1]=b;
		treearray[i][2]=n;
	}
	root = which_is_root(treearray);
	for(i=1;i<N;i++){
		if(i==1){
			tree[1]==root;
			if (treearray[0][0]==root)
				tree[2]==treearray[0][1];
			else
				tree[2]==treearray[0][0];
		}
		if(is_in_tree(treearray[i][0],i,tree)){
			start=
			end=
		}


	}


}

int which_is_root(int **p){
	int a1,b1,a2,b2;
	a1=p[0][0];
	b1=p[0][1];
	a2=p[1][0];
	b2=p[1][1];
	if(a1==a2 || a1==b2) return a1;
	else if(b1==a2 || b1==b2) return b1;
}

int is_in_tree(int a,int i,int * tree){
	int j;
	for(j=1;j<i;j++){
		if(a==tree[j]) return 1;
	}
	return 0;
}
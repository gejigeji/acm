#include<stdio.h>
#include<malloc.h>

struct tree{
	int data;
	int depth;
	int applenums;
	struct tree *left;
	struct tree *right;
};
struct node{
	struct tree *treenode;
	int num;
	struct node *next;
};
struct tree * create(struct tree * root, int t){
	if(root==NULL){
		root=(struct tree *)malloc(sizeof(struct tree));
		root->data=t;
		root->depth=1;
		root->applenums=0;
		root->left=NULL;
		root->right=NULL;
		return(root);
	}
}

void display(struct tree *root){
	printf("\n");
	if(root){
		printf("data is %d,depth is %d\n",root->data,root->depth);
		display(root->left);
		display(root->right);
	}
}

struct tree * if_in_link(struct node *link,int start){
	struct node *temp=link;
	do{
		if(temp->treenode->data==start){
			temp->num++;
			return temp->treenode;
		}
		temp=temp->next;
	}while(temp!=NULL);
	return(NULL);
}
void displaylink(struct node*link){
	struct node *p=link;
	printf("the link is    ");
	while(p!=NULL){
		printf("%d ---",p->treenode->data);
		p=p->next;
	};
	printf(" end\n");
}
struct node* addlink(struct node* link,struct tree *addtemp){
	struct node *p=link;
	struct node *temp=NULL;
	if(p->num>=2) {
		temp=link;
		link=link->next;
		free(temp);
		p=link;
		}
	while(p->next!=NULL){
		if(p->next->num>=2){
			temp=p->next;
			p->next=p->next->next;
			free(temp);
		}
		p=p->next;
	}
	temp=(struct node*)malloc(sizeof(struct node));
	temp->treenode=addtemp;
	temp->num=0;
	temp->next=NULL;
	p->next=temp;
	return(link);
}


struct node* addnode(struct tree *addplace,int data,int applenums,struct node * link){
	struct tree *temp;
	temp=(struct tree *)malloc(sizeof(struct tree));
	temp->data=data;
	temp->depth=addplace->depth+1;
	temp->applenums=applenums;
	temp->left=NULL;
	temp->right=NULL;
	if(addplace->right==NULL){
		addplace->right=temp;
	}
	else if(addplace->left==NULL)
		addplace->left=temp;
		else
			printf("ERROE\n");
	return(addlink(link,temp));

}

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

int arraymax(int *every){
	int temp=every[0];
	int i=0;
	while(every[i]>=0){
		temp = max(every[i],temp);
		i++;
	}
	return temp;
}

int most(struct tree *father, int Q){
	int i;
	int allpossible[101]={-1};
	if(father->right==NULL && father->left==NULL) return 0;
	if(Q > 0){
		if(father->right==NULL) return most(father->left,Q-1)+father->left->applenums;
		if(father->left==NULL) return most(father->right,Q-1)+father->right->applenums;
		allpossible[Q]=most(father->right,Q-1)+father->right->applenums;
		allpossible[0]=most(father->left,Q-1)+father->left->applenums;
		for(i=1;i<Q;i++){
			allpossible[i]=most(father->right,i-1)+father->right->applenums+most(father->left,Q-i-1)+father->left->applenums;
		}
		return arraymax(allpossible);

	}
	else
		return 0;
}


void main(){
	struct tree *root=NULL;
	struct tree *addplace=NULL;
	struct node *link=NULL;
	int start, end, applenums;
	int N,Q,i;
	scanf("%d %d",&N,&Q);
	if(Q>=N) Q=N-1;
	root=create(root,1);
	link=(struct node*)malloc(sizeof(struct node));
    link->treenode = root;
    link->num = 0;
    link->next = NULL;
	for(i=0;i<N-1;i++){
   		scanf("%d %d %d",&start,&end,&applenums);
    	if(addplace=if_in_link(link,start)){
        	link=addnode(addplace,end,applenums,link);
    	}
    	else if(addplace=if_in_link(link,end)){
        	link=addnode(addplace,start,applenums,link);
    	}
	}

	printf("%d\n",most(root, Q));
}

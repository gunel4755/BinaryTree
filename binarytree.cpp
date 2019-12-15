#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node BTREE;

BTREE *new_node(int data){
	BTREE *p=(BTREE*)malloc(sizeof(BTREE));
	p->data = data;
	p->left=NULL;
	p->right=NULL;
	return p;
}

BTREE *insert(BTREE *root, int key){
	if(root != NULL){
		if(key < root->data){
			root->left = insert(root->left,key);
		}
		else{
			root->right= insert(root->right,key);
		}
	}
	else{
		root= new_node(key);
	}
	return root;
}

void inorder(BTREE *root){
	if(root !=NULL){
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}
void preorder(BTREE *root){
	if(root !=NULL){
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(BTREE *root){
	if(root !=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->data);
	}
}

int nodeSize(BTREE *root){
	if(root == NULL){
		return 0;
	}
	else{
		return nodeSize(root->left)+1+nodeSize(root->right);
	}
}

int nodeHeight(BTREE *root){
	if(root==NULL)
		return -1;
	else{
		int left_height, right_height;
		left_height= nodeHeight(root->left);
		right_height= nodeHeight(root->right);
		if(left_height < right_height){
			return right_height+1;
		}
		else
			return left_height+1;
	}
}

main(){
	
	BTREE *myTree=NULL;
	myTree= insert(myTree,10);
	myTree= insert(myTree,14);
	myTree= insert(myTree,0);
	myTree= insert(myTree,34);
	myTree= insert(myTree,5);
	myTree= insert(myTree,4);
	myTree= insert(myTree,25);
	
	myTree= insert(myTree,3);
	
	inorder(myTree);
	printf("\n**********\n");
	preorder(myTree);	
	printf("\n**********\n");
	postorder(myTree);
	
	printf("\n node size: %d",nodeSize(myTree));
	printf("\n Tree Height: %d",nodeHeight(myTree));
}





#include<bits/stdc++.h>

using namespace std;

struct Node{

	Node *left,*right;
	int key;
};

Node *newNode(int key){
	Node *node =new Node;
	node->key=key;
	node->left=node->right=NULL;
	return node;
}

Node *LevelOrderInsert(int arr[],int n){
	Node *root=NULL;
		root=newNode(arr[0]);
	queue <Node *> q;
		q.push(root);
	int i=1;
	while(!q.empty())
	{	Node *p=q.front();
		q.pop();
		if(i<n)
			{
				p->left=newNode(arr[i++]);
				q.push(p->left);
			}
		if(i<n)
		{
			p->right=newNode(arr[i++]);
			q.push(p->right);
		}
	}

	return root;

}

void Inorder(Node *node)
{
	if(node==NULL)
		return;
	Inorder(node->left);
	cout<<node->key<<" ";
	Inorder(node->right);
}

int main(){
	int n;
	Node *root=NULL;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++){
		
		cin>>arr[i];
	}
	root=LevelOrderInsert(arr,n);

	Inorder(root);
	return 0;

}
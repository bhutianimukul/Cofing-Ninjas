
#include<iostream>
#include<limits.h>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;
Node<int> * takeInput(){
		  Node <int>*root=NULL;
		  int data;
		  cout<<"Enter rootData\n";
		  cin>>data;



		  if(data==-1) return NULL;
		  root=new Node<int>(data);
		  Node<int> *leftChild=takeInput();
		  Node<int> *rightChild=takeInput();
		  root->left=leftChild;
		  root->right=rightChild;
		  return root;
}
Node<int> * takeInputLevel(){
		  int data;
		  cout<<"Enter root  data ";
		  cin>>data;
		  Node<int> *root=NULL;
		  if(data!=-1){
					 root=new Node<int>(data);}
		  queue<Node<int>*> pending;
		  pending.push(root);
		  while(pending.size()!=0){
					 Node <int> *parent=pending.front();
					 pending.pop();
					 int leftData, rightData;
					 Node<int> *leftChild=NULL;
					 Node<int> *rightChild=NULL;
					 cout<<"Enter left child of "<<parent->data;
					 cin>>leftData;
					 if(leftData!=-1) {leftChild=new Node<int>(leftData);
								parent->left=leftChild;
								pending.push(leftChild);
					 }
					 cout<<"Enter right child of "<<parent->data;
					 cin>>rightData;
					 if(rightData!=-1) {rightChild=new Node<int>(rightData);
								parent->right=rightChild;
								pending.push(rightChild);
					 }
		  }
		  return root;}





		  void print(Node<int> * root){
					 if(root==NULL) return ;
					 cout<<" "<<root->data<<":";
					 if(root->left) cout<<" L"<<root->left->data;
					 if(root->right) cout<<" R:"<<root->right->data;
					 cout<<"\n";
					 print(root->left);
					 print(root->right);

		  }
int countNodes(Node<int> *root){

		  if(root==NULL) return 0;
		  return countNodes(root->left)+countNodes(root->right)+1;
}

bool searchNode(Node<int> *root, int data){
		  if(root==NULL) return false;
		  if(root->data==data) return true;
		  bool leftans=searchNode(root->left, data);
		  bool rightans=searchNode(root->right, data);
		  return leftans||rightans;


}
int height(Node<int> *root){
		  if(root==NULL) return 0;
		  int leftheight=height(root->left);
		  int rightheight=height(root->right);
		  return max(leftheight, rightheight)+1;

}
void mirror(Node <int>* &root){
		  if(root==NULL) return ;
		  if(root->left==NULL && root->right==NULL) return ;
		  else if(root->left==NULL) { root->left=root->right;
					 root->right=NULL;}

		  else if(root->right==NULL) { root->right=root->left;
					 root->left=NULL;}
		  else{
					 Node<int> * temp=root->right;
					 root->right=root->left;
					 root->left=temp;
		  }
		  mirror(root->left);
		  mirror(root->right);



}


Node<int> *helperTree(int post[] , int *in , int postS , int postE , int inS , int inE){
		  if(inS>inE) return NULL;
		  int rootData=post[postE];
		  Node<int> *root=new Node<int>(rootData);
		  int index=-1;
		  for(int i=inS;i<=inE;i++){

					 if(in[i]==rootData) {index=i; break;}}
		  int LInE=index-1;
		  int RInS=index+1;
		  int LInS=inS;
		  int RInE=inE;

		  int RPostE=postE-1;
		  int LPostS=postS;
		  int LPostE=LPostS-LInS+LInE;
		  int RPostS=LPostE+1;
		  root->left=helperTree(post, in , LPostS, LPostE, LInS, LInE);
		  root->right=helperTree(post, in , RPostS, RPostE , RInS, RInE);
		  return root;



}
Node<int> *buildTree(int post[] , int in[] , int n){
		  return helperTree(post, in ,0 ,n-1, 0 , n-1); 
}

pair<int,int > heightDiameter(Node<int> *root){
		  if(root==NULL) {
					 pair<int,int> p;
					 p.first=0;
					 p.second=0;
					 return p;

		  }
		  pair<int, int> leftAns=heightDiameter(root->left);
		  pair<int,int> rightAns=heightDiameter(root->right);
		  int leftD=leftAns.second;
		  int leftH=leftAns.first;
		  int rightD=rightAns.second;
		  int rightH=rightAns.first;

		  int height=1+max(leftH, rightH);
		  int diameter=max((leftH+rightH), max(leftD,rightD));
		  pair<int, int> p;
		  p.first=height;
		  p.second=diameter;
		  return p;


}
 pair<int, int> MaxMin(Node<int> * root){

if(root==NULL) {
pair<int , int> p;
p.first=INT_MIN;
p.second=INT_MAX;
return p;
}
if(root->left==NULL && root->right==NULL) {
pair<int,int> p;
p.first=root->data;
p.second=root->data;

}
pair<int , int> leftAns=MaxMin(root->left);
pair<int,int> rightAns=MaxMin(root->right);
int leftMax=leftAns.first;
int leftMin=leftAns.second;
int rightMax=rightAns.first;
int rightMin=rightAns.second;

int maxVal=max(max(leftMax,rightMax), root->data);
int minVal=min(min(leftMin, rightMin), root->data);
pair<int, int> p2;
p2.first=maxVal;
p2.second=minVal;
return p2;


 }
 Node<int> * removeLeaves(Node<int>*root){
 	if(root==NULL) return NULL;
 	if(root->left==NULL && root->right==NULL){
 		delete root;
 		return NULL;
	 }
	 else{
	 	Node <int>* l=removeLeaves(root->left);
	 	Node<int>*r=removeLeaves(root->right);
	 	root->left=l;
	 	root->right=r;
	 	
	 }
	 return root;
 }
int main(){
		  Node <int> *root=NULL;
		  //int post[]={8 ,4 ,5 ,2 ,6, 7, 3, 1};
		  //int in[]={ 4 ,8, 2, 5, 1, 6, 3, 7};
		  //root=buildTree(post, in , 8);
		  root=takeInputLevel();
//		  pair<int, int>p=MaxMin(root);
//
//		  cout<<"\nMax"<<p.first;
//		  cout<<"\nMin"<<p.second;
		  cout<<"\n";
		  print(root);
//root=removeLeaves(root);
//cout<<"\n";
//print(root);
		  // cout<<"\n";
		  // mirror(root);

		  // cout<<"\n";
		  //		  print(root);


		  int x;
		  //cin>>x;
		  //cout<<" search"<<searchNode(root,x);

		  //cout<<"\n" <<countNodes(root);
		  //cout<<"\nheight"<<height(root);

}

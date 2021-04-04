#include<iostream>
#include"BinaryTreeNode.h"
using namespace std;
class BST{
		  Node<int> * root;
		  Node<int> *deleteData(Node<int>*node ,int data){
					 if(node==NULL) return NULL;
					 if(node->data>data){
								node->left=deleteData(node->left, data);
								return node;
					 }else if(node->data<data){node->right=deleteData(node->right, data);
					 return node;
					 }else{
								//case 1 leaf node
								if(node->left==NULL && node->right==NULL) {
										  delete node;
										  return NULL;
								}else if(node->left==NULL){
										  // right will be root
										  Node<int> * temp=node->right;
										  node->right=NULL;
										  delete node;

										  return temp;

								}else if(node->right==NULL){

										  Node<int> * temp=node->left;
										  node->left=NULL;
										  delete node;
										  return temp;
								}
								else{
										  // to replace root it has both left and right 
										  // checking min  or inorder succesor
										  Node<int> * minNode=node->right;
										  while(minNode->left!=NULL) minNode=minNode->left;
										  int min=minNode->data;

										  node->data=min;
										  node->right=deleteData(node->right, min);
										  return node;
								}
					 }
					 
		  }
		  public:
		  BST(){
					 root=NULL;
		  }
		  ~BST(){
					 delete root;
		  }
		  void deleteData(int data){
					 deleteData(root, data);
		  }
		  private:
		  Node <int> * inserthelp(Node<int> * node, int data){
					 if(node==NULL){
								Node<int> *a=new Node<int>(data);
								return a;
					 }
					 if(node->data>data){
								node->left=inserthelp(root->left, data);

					 }else{
								node->right=inserthelp(root->right,data);}
					 return node;
		  }

		  public:
		  void insert(int data){
					 root=inserthelp(root, data);

		  }
		  private:
		  bool hasData(Node<int> *root, int data){
					 if(root==NULL) return false;
					 if(root->data==data) return true;
					 else if (root->data>data){
								return hasData(root->left, data);

					 }else{
								return hasData(root->right, data);
					 }
					 return false;
		  }
		  public: 

		  bool hasData(int data){

					 return hasData(root, data);}
};

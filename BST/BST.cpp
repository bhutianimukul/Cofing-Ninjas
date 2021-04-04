#include<tuple>
#include<limits.h>
#include<iostream>
#include<queue>
using namespace std;
class LLNode{
		  public:
					 int data;
					 LLNode *next;
};

template<typename T>
class Node{
		  public:
					 T data;
					 Node<int>* left;
					 Node <int>*right;
					 Node(int d){
								data=d;
								left=NULL;
								right=NULL;

					 }
					 ~Node(){
								delete left;
								delete right;}
};
void print(Node<int>* root){
		  if(root==NULL) return ;
		  cout<<root->data<<":";
		  if(root->left) cout<<"L"<<root->left->data;
		  if(root->right) cout<<"R"<<root->right->data;
		  cout<<"\n";
		  print(root->left);
		  print(root->right);
}
Node<int> * takeInputLevel(){
		  int data;
		  cout<<"Enter Root Data"<<" \n";
		  cin>>data;
		  Node<int> *root=NULL;
		  if(data!=-1){
					 root=new Node<int>(data);
		  }
		  queue<Node<int>*>q;
		  q.push(root);
		  while(q.size()!=0){
					 Node<int> *parent=q.front();
					 q.pop();
					 Node<int> *lchild=NULL, *rchild=NULL;
					 int ldata, rdata;
					 cout<<"\nENTER LCHILD OF "<<parent->data;
					 cin>>ldata;
					 if(ldata!=-1){
								lchild=new Node<int>(ldata);
								parent->left=lchild;
								q.push(lchild);
					 }
					 cout<<"\nENTER RCHILD OF "<<parent->data;
					 cin>>rdata;
					 if(rdata!=-1){
								rchild=new Node<int>(rdata);
								parent->right=rchild;
								q.push(rchild);
					 }
		  }
		  return root;
}

Node<int> * search(Node<int> *root, int data) {
		  if(root==NULL) return new Node<int>(-1);

		  Node<int> * res=NULL;
		  if(root->data==data) return root;
		  else if(data>root->data) {
					 res=search(root->right,data);

		  }else{
					 res=search(root->left, data);}
		  return res;
}


void range(Node<int>*root , int k1, int k2){
		  if(root==NULL) return ;
		  if(root->data>=k1 && root->data<=k2){
					 cout<<root->data<<" ";
		  }
		  if(k1>=root->data){
					 range(root->right,k1,k2);}
		  else if(k2<=root->data){
					 range(root->left, k1 , k2);}
		  else{
					 range(root->left, k1 , k2);
					 range(root->right, k1, k2);}
}

tuple<int, int , bool> isBST(Node<int> *root){
		  if(root==NULL){
					 tuple<int, int, bool> a;
					 a=make_tuple(INT_MIN,INT_MAX,true);
					 return a;
		  }
		  tuple<int , int , bool> l=isBST(root->left);
		  tuple<int, int , bool> r=isBST(root->right);
		  int minimum=min(root->data, min(get<1>(l), get<1> (r)));
		  int maximum=max(root->data, max(get<0> (l) , get<0> (r)));
		  bool check=(root->data>get<0>(l)) && (root->data<=get<1> (r)) &&
					 get<2> (l) ==true && get<2> (r)==true;
		  tuple <int , int, bool> res;
		  res=make_tuple(maximum, minimum , check);
		  return res;








}
bool isBST2(Node<int> *root, int max , int min){
		  if(root==NULL) return true;
		  if(root->data < min || root->data>max) return false;

		  bool leftcheck=isBST2(root->left, root->data-1, min);
		  bool rightcheck=isBST2(root->right, max, root->data);
		  return leftcheck && rightcheck;






}
LLNode * BSTtoLL(Node<int> * root){
		  if(root==NULL) return NULL;
		  LLNode *leftHead=BSTtoLL(root->left);
		  LLNode *rightHead=BSTtoLL(root->right);
		  LLNode *head=new LLNode();
		  head->data=root->data;
		  if(leftHead==NULL){ leftHead=head;}
		  else{
					 LLNode * temp=leftHead;
					 while(temp->next!=NULL){
								temp=temp->next;}
					 temp->next=head;
		  }
		  head->next=rightHead;



		  return leftHead;
}
pair<LLNode *, LLNode *> BSTtoLL2(Node<int> *root){

		  if(root==NULL){
					 pair<LLNode *, LLNode*> p;
					 p.first=NULL;
					 p.second=NULL;
					 return p;
		  }
		  pair<LLNode *,LLNode *>l =BSTtoLL2(root->left);
		  pair<LLNode * , LLNode *> r=BSTtoLL2(root->right);
		  LLNode *leftHead=l.first;

		  LLNode *rightHead=r.first;
		  LLNode *lefttail=l.second;
		  LLNode *righttail=r.second;

		  LLNode *temp=new LLNode();
		  temp->data=root->data;
		  if(leftHead==NULL){ leftHead=temp;
					 temp->next=rightHead;
		  }
		  else{
					 lefttail->next=temp;
					 temp->next=rightHead;

		  }
		  if(righttail==NULL) righttail=temp;
		  pair<LLNode *, LLNode *> ans;
		  ans.first=leftHead;
		  ans.second=righttail;




		  return ans;


}
void PRINTLL(LLNode * head){
		  while(head!=NULL){
					 cout<<"\t"<<head->data<<"\t";
					 head=head->next;
		  }}






















vector<int> * RootToNode(Node <int> * root, int  temp){
		  if(root==NULL) return NULL;
		  if(root->data==temp){
					 vector<int> *v=new vector<int> ();
					 v->push_back(root->data);
					 return v;
		  }
		  vector<int> * left=RootToNode(root->left, temp);
		  if(left) {
					 left->push_back(root->data);
					 return left;
		  }
		  vector<int> *right=RootToNode(root->right , temp);
		  if(right) {
					 right->push_back(root->data);
					 return right;


		  }else return NULL;
		 
}

int main(){


		  Node<int> *root=takeInputLevel();
		  print(root);

		  int k1, k2;
		  //cin>>k1>>k2;
		  //range(root,k1, k2); 
		  //cout<<"\t "<<root->data;

		  //tuple<int, int,bool> t=isBST(root);
		  //cout<<get<2> (t);
		  //cout<<isBST2(root, INT_MAX , INT_MIN);

		  //pair<LLNode * , LLNode*> p=BSTtoLL2(root);
		  //PRINTLL(p.first);
		  vector<int> * v=RootToNode(root, 2);
		  for(int i=0;i<v->size();i++){
					 cout<<v->at(i)<<"  ";
		  }
		  delete v;


}



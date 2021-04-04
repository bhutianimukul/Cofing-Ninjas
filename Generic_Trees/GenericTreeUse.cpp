#include<iostream>
#include "GenericTree.cpp"
#include<queue>
using namespace std;
TreeNode <int>* takeInputLevel(){
		  int rootData;
		  cout<<"Enter Root Data";
		  cin>>rootData;
		  TreeNode<int> * root=new TreeNode<int>(rootData);
		  queue<TreeNode<int>*>pendingNodes;
		  pendingNodes.push(root);
		  while(pendingNodes.size()!=0){
					 TreeNode<int> *front =pendingNodes.front();
					 pendingNodes.pop();
					 cout<<" Enter no. of children of"<<front->data;
					 int n;
					 cin>>n;
					 for(int i=0;i<n;i++){
								int childData;
								cout<<"enter "<<i<<"th child of "<<front->data<<"\n";
								cin>>childData;
								if(childData!=-1){
										  TreeNode<int> *child=new TreeNode<int>(childData);
										  pendingNodes.push(child);
										  front->children.push_back(child);}
					 }

		  }

		  return root;
}
TreeNode<int> * takeInput(){
		  TreeNode<int> * root;
		  cout<<"Enter root's data\n";
		  int rootData;
		  cin>>rootData;
		  root=new TreeNode<int> (rootData);
		  cout<<"Enter no. of children of "<<rootData;
		  int n;
		  cin>>n;
		  for(int i=0;i<n;i++){
					 TreeNode<int> * temp=takeInput();
					 root->children.push_back(temp);
		  }
		  return root;}
		  void Bfs(TreeNode<int> *root){
					 cout<<root->data<<" ";
					 queue<TreeNode<int> *> pending ;
					 pending.push(root);
					 while(pending.size()!=0){
								TreeNode<int>*parent=pending.front();
								pending.pop();
								for(int i=0;i<parent->children.size();i++){
										  cout<<parent->children[i]->data<<" ";
										  pending.push(parent->children[i]);
								}
					 }




		  }

int countNodes(TreeNode <int>*root){
		  int t=0;
		  for(int i=0;i<root->children.size();i++){
					 t=t+countNodes(root->children[i]);
		  }
		  return t+1;




}
int sumOfNodes(TreeNode <int> * root){
		  int sum=0;
		  for(int i=0;i<root->children.size();i++){
					 sum+=sumOfNodes(root->children[i]);

		  }
		  return sum+root->data;

}
int MaxNode(TreeNode <int> * root){
		  int max=-1;
		  for(int i=0;i<root->children.size();i++){
					 int max1=MaxNode(root->children[i]);
					 if(max1>max) max=max1;;
		  }
		  if(max<root->data) return root->data;
		  return max;


}

int height(TreeNode<int> * root){
		  int heightVar=0;
		  for(int i=0;i<root->children.size();i++){
					 int height1=height(root->children[i]);
					 heightVar=max(height1, heightVar);
		  }
		  return heightVar+1;
}

int countLeaf(TreeNode<int>* root){
		  if(root==NULL) return 0;
		  if(root->children.size()==0) return 1;
		  int count=0;
		  for(int i=0;i<root->children.size();i++){

					 count=count+countLeaf(root->children[i]);
		  }
		  return count;

}
void postorder(TreeNode<int> * root){
		  for(int i=0;i<root->children.size();i++){
					 postorder(root->children[i]);}
		  cout<<root->data<< " ";

}
void print(TreeNode<int> *root)
{

		  if(root==NULL) return;
		  cout<<root->data<<":";
		  for(int i=0;i<root->children.size();i++){
					 cout<<root->children[i]->data<<",";

		  }
		  cout<<"\n";

		  for(int i=0;i<root->children.size();i++){
					 print(root->children.at(i));
		  }
}
bool contains(TreeNode <int> *root, int data){
		  bool flag=false;
		  if(root->data==data) return true;
		  for(int i=0;i<root->children.size();i++){
					 flag=contains(root->children[i], data);
		  }
		  return flag;


}
int countGreat(TreeNode<int> *root , int data){
		  if(root->data>data) return 1;
		  int count=0;
		  for(int i=0;i<root->children.size();i++){
					 count+=countGreat(root->children[i],data);
		  }return count;
}
TreeNode<int> * maxSumNode(TreeNode<int>*root){
		  int rootSum=0;
		  TreeNode<int> * ans=root;
		  for(int i=0;i<root->children.size();i++){
					 rootSum=rootSum+root->children[i]->data;}
		  for(int i=0;i<root->children.size();i++){
					 TreeNode<int> * temp=maxSumNode(root->children[i]);
					 int xSum=temp->data;
					 for(int j=0;j<temp->children.size();j++){
								xSum+=temp->children[j]->data;
					 }
					 if(xSum>rootSum){ ans=temp;

								rootSum=xSum;

								//cout<<"XSUM"<<xSum<<" \t"<<"rootSum"<<rootSum<<"\n";}

		  }

}
return ans;
}



bool identical(TreeNode<int> * node1, TreeNode<int>* node2){
		  if(node1->data!=node2->data) return false;
		  if(node1->children.size()!=node2->children.size()) return false;
		  bool ans;
		  for(int i=0;i<node1->children.size();i++){
					 ans=identical(node1->children[i], node2->children[i]);
					 if(ans==false) return false;
		  }
		  return true;
}
TreeNode<int> * nextLarger(TreeNode <int> * root , int data){

		  TreeNode<int>* ans=nullptr;
		  if(root->data>data) {
					 ans=root;}
		  for(int i=0;i<root->children.size();i++){
					 TreeNode<int> *temp=nextLarger(root->children[i], data);
					 if(ans==NULL){
								if(temp!=NULL && temp->data>data){ ans=temp;}}else{
										  if(temp!=NULL&& temp->data>data && temp->data < ans->data) ans=temp;
								}}
		  return ans;


}
TreeNode<int> *secondLargest(TreeNode<int> *root){



}


void helper(TreeNode<int>* &root,
					 int depth){
		  root->data = depth;
		  for (int i = 0;
								i < root->children.size(); i++) {

					 helper(root->children[i], depth + 1);
		  }
}
void replaceDepth(TreeNode<int>*& root)
{
		  helper(root, 0);
}





int main(){
		  TreeNode<int> * root=takeInputLevel();
		  int x;
		  cin>>x;
		  TreeNode <int>*temp=nextLarger(root, x);
		  cout<<"   "<<temp->data;

}

#include<iostream>
using namespace std;
template <typename T>
class Node{
		  public:
					 int data;
					 Node<T> *next;
					 Node(int data){

								this->data=data;
								next=nullptr;}

};
template <typename T>
class Queue{
		  Node <T> * head;
		  Node <T> *tail;
		  int size;
		  public: 
		  Queue(){
					 head=nullptr;
					 tail=nullptr;
					 size=0;
		  }
		  void enqueue(T data){ 
					 Node<T> * temp=new Node<T>(data);
					 if(size==0) {
								head=temp;
								tail=head;
								size++;
					 }else{
								tail->next=temp;
								tail=temp;
								size++;
					 }
		  }
		  T dequeue()
		  {
					 if(size==0) {
								cout<<"empty"; return 0 ;}
					 Node<T> * temp=head;
					 T val=temp->data;
					 head=head->next;
					 delete(temp);
					 size--;
					 if(size==0) {
								head=NULL;
								tail=NULL;}
					 return val;}
		  T front(){
					 if(head==NULL){ cout<<"empty"; return 0;}
					 return head->data;
		  }
		  int getSize(){
					 return size;

		  }
};

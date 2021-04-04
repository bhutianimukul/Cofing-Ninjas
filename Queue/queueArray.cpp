#include<iostream>
using namespace std;
template <typename T>
class QueueArray{
		  int nextIndex;
		  int frontIndex;
		  T *data;
		  int size;
		  int capacity;
		  public: 

		  QueueArray(int s){
					 data=new T[s];
					 nextIndex=-1;
					 frontIndex=-1;
					 size=0;
					 capacity=s;
		  }
		  void enqueue(T x){
					 if(size==0 && capacity!=0) frontIndex=0;
					 if(size==capacity){
								cout<<"Full\n";
							int j=0;
							T *newData=new int[2*capacity];
							for(int i=frontIndex; i<capacity;i++){
							newData[j]=data[i]; j++ ;}
							for(int i=0;i<frontIndex;i++){
							newData[j] ; j++;}
delete[] data;

data=newData;
frontIndex=0;
nextIndex=capacity-1;
capacity=capacity*2;
					 }

					 nextIndex=(nextIndex+1)%capacity;
					 data[nextIndex]=x;
					 size++;

		  }
		  T dequeue(){
					 if(size==0) {
								cout<<"EMPTY\n";
								return 0;}
					 int val=data[frontIndex];
					 frontIndex=(frontIndex+1)%capacity;
					 size--;
					 if(size==0) {
								frontIndex=-1;
								nextIndex=-1;}
					 return val;
		  }
		  T front(){
					 if(size>0) return data[frontIndex];
					 return 0;
		  }
		  int getSize(){
					 return size;}

};



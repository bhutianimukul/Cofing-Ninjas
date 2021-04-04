//min priority queue 
#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue{
		  vector<int> arr;
		  public:
		  PriorityQueue(){

		  }
		  //is empty
		  //insert
		  //size
		  //remove
		  //get min
		  bool isEmpty(){
					 return arr.size()==0;
		  }
		  int getSize(){
					 return arr.size();
		  }
		  int getMin(){
					 if(isEmpty()) return 0;
					 return arr[0];}
		  void insert(int data){
					 arr.push_back(data);
					 // up heapify
					 int childIndex=arr.size()-1; // after inserting new element  index of inserted node
					 while(childIndex>0){
								int parentIndex=(childIndex-1)/2;

								if(arr[parentIndex]>arr[childIndex]){
										  int temp=arr[childIndex];
										  arr[childIndex]=arr[parentIndex];
										  arr[parentIndex]=temp;
								}else{
										  break;}
								childIndex=parentIndex;
					 }



		  }

		  int  removeMin(){
					 int ans=arr[0];
					 arr[0]=arr[arr.size()-1];
					 arr.pop_back();
					 //down heapify
					 int parentIndex=0;
								int leftChild=2*parentIndex+1;
								int rightChild=2*parentIndex+2;
								int minIndex=parentIndex;
								while(leftChild<arr.size()){
								if(arr[leftChild]<arr[minIndex]){
								minIndex=leftChild;}
							if(rightChild<arr.size() && arr[rightChild]<arr[minIndex]){
							minIndex=rightChild;}
							if(parentIndex==minIndex) break;
										  int temp=arr[minIndex];
										  arr[minIndex]=arr[parentIndex];
										  arr[parentIndex]=temp;
										  parentIndex=minIndex;

								leftChild=2*parentIndex+1;
							rightChild=2*parentIndex+2;
								
					 }
					 return ans;
		  }


};

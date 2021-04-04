#include<iostream>
using namespace std;
void inPlaceHeapSort(int *input, int n){

		  for(int i=1;i<n;i++){


					 int childIndex=i; // after inserting new element  index of inserted node
					 while(childIndex>0){
								int parentIndex=(childIndex-1)/2;

								if(input[parentIndex]>input[childIndex]){
										  int temp=input[childIndex];
										  input[childIndex]=input[parentIndex];
										  input[parentIndex]=temp;
								}else{
										  break;}
								childIndex=parentIndex;
					 }
		  }

		  int size=n;
		  while(size>1){
		  cout<<"\n";
					 int temp=input[size-1];
					 input[size-1]=input[0];
					 input[0]=temp;
					 //down heapify
					 size--;
					 int parentIndex=0;
					 int leftChild=2*parentIndex+1;
					 int rightChild=2*parentIndex+2;
					 int minIndex=parentIndex;
					 while(leftChild<size){
								if(input[leftChild]<input[minIndex]){
										  minIndex=leftChild;}
								if(rightChild<size && input[rightChild]<input[minIndex]){
										  minIndex=rightChild;}
								if(parentIndex==minIndex) break;
								int temp=input[minIndex];
								input[minIndex]=input[parentIndex];
								input[parentIndex]=temp;
								parentIndex=minIndex;

								leftChild=2*parentIndex+1;
								rightChild=2*parentIndex+2;

					 }


		  }
}
int main(){
		  int input[]={5,1,2,0,8};
		  
		  inPlaceHeapSort(input, 5);

		  for(int i=0;i<5;i++){
					 cout<<input[i]<<"\t";}
}

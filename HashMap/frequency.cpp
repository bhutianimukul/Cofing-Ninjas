#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int freq(int * arr,int n){
		  unordered_map<char, int > map;
		  for(int i=0;i<n;i++){
					 map[arr[i]]++;
		  }
		  int maxCount=-1;
		  int maxval=-1;
		  for(int i=0;i<n;i++){
					 if(map[arr[i]]>maxCount){
								maxCount=map[arr[i]];
								maxval=arr[i];

					 }
		  }
		  return maxval;
}

int main(){
		  int arr[]={ 2, 2 , 3, 2, 2 ,5,4,1,3};
		  cout<<freq(arr, 9);
		  


}


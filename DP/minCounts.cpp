#include<iostream>
#include<cmath>
#include<climits>
using namespace std;


int minCounts(int n){
		  if(n==1) return 1;
		  int ans=INT_MAX;
		  for(int i=1;i<=sqrt(n);i++){
					 if(i*i==n){
								return 1;}
					 int x=minCounts(n-i*i);
					 ans=min(ans, x);
		  }
		  return ans+1;
}
int helper(int n , int arr[]){
		  if(n==1) return 1;
		  if(arr[n]!=-1){
					 return arr[n];
		  }
		  int ans=INT_MAX;
		  for(int i=1;i<=sqrt(n);i++){
					 if(i*i==n) {
								arr[n]=1;
								return arr[n];
					 }
					 int x=helper(n-i*i,arr);
					 ans=min(ans, n);
					 arr[i]=ans+1;
					 

		  }

		  return ans+1;}
		  int minCountsMemo(int n){
					 int *arr=new int[n+1];
					 for(int i=0;i<=n;i++){
								arr[i]=-1;}
					 return helper(n, arr);


		  }
int main(){
		  int n;
		  cin>>n;
		  cout<<minCountsMemo(n);


}

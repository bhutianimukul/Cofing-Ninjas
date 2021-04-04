#include<iostream>
#include<cstring>
using namespace std;

int helper(int *arr , int n ){
		  if(n<=0) return 0;
		  int x=arr[0]+helper(arr+2, n-2);
		  int y=helper(arr+1, n-1);
		  return max(x,y);


}
int helperMemo(int*arr , int n , int *output){
		  if(n<=0) return 0;
		  if(output[n]!=-1) return output[n];
		  int x=arr[0]+helper(arr+2, n-2);
		  int y=helper(arr+1, n-1);
		  int    ans=output[n]= max(x,y);
		  return ans;    

}
int helperDP(int *arr, int n){
		  int dp[n];
		  dp[0]=arr[0];
		  dp[1]=max(arr[0],arr[1]);
		  for(int i=2;i<n;i++){
					 int x=dp[i-2]+arr[i];// include current
					 int y=dp[i-1]; //donot include current
					 dp[i]=max(x, y);
		  }
		  return dp[n-1];




}
// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n) {
		  int output[n+1];
		  memset(output,-1, sizeof(output));
		  // return helper(arr,n);
		  return helperDP(arr, n );
}
int main(){
		  int arr[]={5,10,15,100 };
		  int n=4;
		  cout<<findMaxSum(arr, n);


}

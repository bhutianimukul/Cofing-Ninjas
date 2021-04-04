#include<iostream>
#include<cstring>
using namespace std;
int knapsackRec(int *weights, int *values, int n , int W){
if(n==0|| W<=0) return 0;
if(W<weights[0]) return knapsackRec(weights+1, values+1 , n-1, W);

int x=knapsackRec(weights+1, values+1, n-1, W);
int y=values[0]+knapsackRec(weights+1, values+1, n-1, W-weights[0]);
return max(x, y);



}
int helperMemo(int *weights , int *values, int n , int W , int **output){
if(n==0|| W==0) return 0;
if(output[n][W]!=-1) return output[n][W];
if(W<weights[n-1]) {
int ans=output[n][W]=helperMemo(weights, values , n-1, W,output);
return ans;
}
int x=helperMemo(weights , values , n-1, W,output);
int y=helperMemo(weights, values , n-1, W-weights[n-1],output)+values[n-1];
int ans=output[n][W]=max(x, y);
return ans;



}
int knapsackMemo(int *weights, int *values , int n , int W){
int **output=new int*[n+1];
for(int i=0;i<=n;i++){
output[i]=new int[W+1];
for(int j=0;j<=W;j++){
output[i][j]=-1;
}
}
return helperMemo(weights , values , n , W , output);

}
int knapsackDP(int *weight , int *values, int n , int W){
int dp[n+1][W+1];
memset(dp , -1, sizeof(dp));
for(int i=0;i<=n;i++){
for(int j=0;j<=W;j++){
if(i==0||j==0) dp[i][j]=0;
}}

for(int i=1;i<=n;i++){
for(int j=1;j<=W;j++){
if(j<weight[i-1]){
dp[i][j]=dp[i-1][j]; // take previous batsman scores
}
else {
int x=dp[i-1][j];
int y = dp[i-1][j-weight[i-1]]+values[i-1];
dp[i][j]=max(x,y);

}


}}
return dp[n][W];









}
int main(){
int n ;
int weights[]={ 5 ,1 , 8, 9 , 2};
int values[]={ 4, 10 , 2, 3, 1 };
int W=15;
cout<<knapsackRec(weights, values , 5, W);
cout<<"\n"<<knapsackMemo(weights , values , 5 , W);
cout<<"\n"<<knapsackDP(weights, values , 5 , W);

}

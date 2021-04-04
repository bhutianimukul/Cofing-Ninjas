#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;


int minSteps(int n){
if(n<=1) return 0;
int ans=minSteps(n-1);
int count2=INT_MAX;
int count1=INT_MAX;
if(n%2==0){
count1=minSteps(n/2);
}
if(n%3==0){
count2=minSteps(n/3);}

return min(ans, min(count1, count2))+1;


}
int helper(int n , int arr[]){
if(n<=0) return -1;
if(arr[n]!=-1) {
return arr[n];}
int x,y=INT_MAX , z=INT_MAX;
x=helper(n-1, arr);
if(n%2==0) y=helper(n/2, arr);
if(n%3==0) z=helper(n/3,arr);
arr[n]=min(x, min(z, y))+1;
return arr[n];
}


int minStepsMemo(int n){
int *arr=new int[n+1];
for(int i=0;i<n+1;i++){
arr[i]=-1;}
return helper(n, arr);

}
int minStepsDp(int n){
int *arr=new int [n+1];
arr[0]=0;
arr[1]=0;
for(int i=2;i<=n;i++){
int x=arr[i-1];
int y=INT_MAX;
int z=INT_MAX;
if(i%2==0) y=arr[i/2];
if(i%3==0) z=arr[i/3];
arr[i]=min(x, min(y,z))+1;


}
return arr[n];
}

int main(){
int n;
cin>>n;
cout<<minStepsDp(n);

}

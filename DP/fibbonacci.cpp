#include<iostream>
using namespace std;

int dpFib(int n){

int* arr=new int[n+1];
arr[0]=0;
arr[1]=1;
for(int i=2;i<=n;i++){
arr[i]=arr[i-1]+arr[i-2];
}
return arr[n];
}

int helper(int n , int *arr){
if(n<=1) return n;
if(arr[n]!=-1)
{ return arr[n];}
else {
arr[n]= helper(n-1, arr) +helper(n-2, arr);
return arr[n];
}


}
int fib(int n){
int* arr=new int[n+1];
for(int i=0;i<n+1;i++){
arr[i]=-1;
}
return helper(n , arr);




}
int main(){
int n;
cin>>n;
cout<<dpFib(n);


}

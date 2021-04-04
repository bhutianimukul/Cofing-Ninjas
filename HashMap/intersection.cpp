#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> intersection(int arr[],int arr1[],int m ,int n){
vector<int> output;
unordered_map<int, int> map;
for(int i=0;i<m;i++){
if(map.count(arr[i])>0){
continue;
}
map[arr[i]]++;
}
for(int i=0;i<n;i++){

if(map.count(arr1[i])>0){
output.push_back(arr1[i]);
continue;}
}



return output;
}

int main(){

int arr[]={ 2, 6, 1,2};
int arr2[]={1 ,2, 3, 4, 2};


vector<int> v=intersection(arr,arr2, 4, 5);
for(int x:v){
cout<<x<<":";
}


}


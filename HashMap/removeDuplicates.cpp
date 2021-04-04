#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> remove(int arr[],int n){
vector<int> output;
unordered_map<int, bool> map;
for(int i=0;i<n;i++){
if(map.count(arr[i])>0){
continue;
}
map[arr[i]]=true;
output.push_back(arr[i]);
}
return output;
}

int main(){
int arr[]={ 1, 2 , 3, 2, 1 ,5,4,1,3};
vector<int> v=remove(arr, 9);
for(int x:v){
cout<<x<<":";
}


}

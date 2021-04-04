#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int  pairSum(int arr[],int n){
int count=0;
unordered_map<int, int> map;
for(int i=0;i<n;i++){

map[arr[i]]++;
}
for(int i=0;i<n;i++){
if(map.count(-arr[i])>0) {
count++;
map.erase(arr[i]);
}

}
return count;

}

int main(){
int arr[]={ 2, 1, -2, 2, 3};
cout<<pairSum(arr, 5);
//cout<<v.first;
//cout<<"\t"<<v.second;


}


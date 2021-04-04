#include<iostream>
#include "Bstuse.cpp"
using namespace std;
int main(){

BST b;
b.insert(20);
b.insert(30);
b.deleteData(20);
cout<<b.hasData(20);
//cout<<"\n"<<b.hasData(10);
}

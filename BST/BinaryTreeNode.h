#include<iostream>
using namespace std;
template <typename T>
class Node{
public:
T data;
Node<int> *left;
Node <int> *right;
Node(T data){
this->data=data;
left=NULL;
right==NULL;
}
~Node(){
delete left;
delete right;
}
};

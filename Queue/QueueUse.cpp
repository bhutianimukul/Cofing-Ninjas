#include<iostream>
#include "QueueLL.cpp"
using namespace std;
int main(){
Queue <int> q;
q.enqueue(10);
cout<< q.getSize();
cout<<q.front()<<" ";
cout<<q.dequeue()<<" ";
//cout<<q.getSize()<<" size ";

cout<<q.dequeue();
}

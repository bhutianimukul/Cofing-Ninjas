#include<iostream>
#include"PriorityQueue.h"
using namespace std;
int main(){
PriorityQueue pq;
pq.insert(100);
pq.insert(10);

pq.insert(15);
pq.insert(4);
pq.insert(17);
pq.insert(21);

pq.insert(67);
cout<<"\n"<<pq.removeMin();
cout<<" \n"<<pq.getMin();
cout<<"\n"<<pq.removeMin();
cout<<"\n"<<pq.getMin();
/*
cout<<pq.getSize()<<"\n";
cout<<" "<<pq.getMin()<<"\n";
cout<<pq.isEmpty()<<"\n";
while(!pq.isEmpty()){
cout<<pq.removeMin()<<" ";
}
*/






}

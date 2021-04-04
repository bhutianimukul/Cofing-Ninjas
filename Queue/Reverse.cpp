#include<iostream>
#include<queue>
using namespace std;
queue<int> reverse(queue<int> q){
if(q.size()==0){
return q;
}
int top=q.front();
q.pop();
q=reverse(q);
q.push(top);
return q;

}
int main(){
queue<int> q;
for(int i=1;i<5;i++){
q.push(i);
}
cout<<q.front()<<" ";
queue<int>q1 =reverse(q);
//cout<<q1.front()<<" ";
while(!q1.empty()){

cout<<q1.front()<< " ";
q1.pop();}
}

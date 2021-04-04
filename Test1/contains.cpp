#include<iostream>
using namespace std;


bool contains(string s , string t){
if( t.size()==0) return true;
if(s.size()==0 && t.size()!=0 ) return false;
if(s[0]==t[0]){
bool b=contains(s.substr(1) , t.substr(1));
return b;
}else{
return contains(s.substr(1) ,  t);
}
return false;



}
int main(){
string s , t;
cout<<"Enter s";
cin>>s;
cout<<"Enter t";
cin>>t;
cout<<contains(s, t);


}

#include<iostream>
#include<cstring>
using namespace std;
string getHash(string s){
string hash;
	for(int i=0;i<s.length();i++){
hash=hash+s[i];
	}
	return hash;
}
bool rabin(string text , string pat){
int n =text.length();
int m =pat.length();
string res_hash=getHash(pat);
string window;
for(int i=0;i<m;i++){
 window=window+text[i];
}
string new_hash=getHash(window);
for(int i=m;i<n;i++ ){
	if(res_hash.compare(new_hash)==0){
		return true;
	}else{

		window=window.substr(1);
		window+text[i];
		new_hash=getHash(window);
	}
}

return false;
}
int main(){
string text="hello";
string pat="el";
cout<<rabin(text , pat);


}
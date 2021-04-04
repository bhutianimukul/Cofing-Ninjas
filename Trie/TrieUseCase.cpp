#include<iostream>
#include"TrieNode.h"
using namespace std;
class Trie{
		  TrieNode *root;
		  public:
		  Trie(){
					 root=new TrieNode('\0');}
		  private:
		  void helper(TrieNode *root,string c){
					 if(c.size()==0){
								root->isTerminal=true;
								return ;
					 }
					 int index=c[0]-'a';
					 TrieNode *child;
					 if(root->children[index]!=NULL){
								child=root->children[index];
					 }
					 else{
								child=new TrieNode(c[0]);
								root->children[index]=child;
					 }
					 insert(child, c.substr(1));

		  }
		  public:
		  void insert(string c){
					 helper(root, c);}

					bool search(TrieNode*root, string word){
					  if(word.size()==0){
if(root->isLeaf==false) return false;
return true;
					}
int index=word[0]-'a';
//not same
if(root->children[index]==NULL){
return false;}
else{
TrieNode *child=root->children[index];
return search(child, word.substr(1));
}
	}
  void deleteHelper(TrieNode *root, string s){
if(s.size()==0){
root->isTerminal=false;
return ;
}
int index=s[0]-'a';
TrieNode *child;
if(root->children[index]!=NULL){
child=root->children[index];
deleteHelper(child , s.substr(1));

}else{
return ;}



}

	void delete(string s){
deletehelper(root , string s);
	}

};

#include<iostream>
using namespace std;
class TrieNode{
		  public:
					 char data;
					 Trienode ** children;
					 bool isTerminal;
					 TrieNode(char c){
								data=c;
								isTerminal=false;
								children=new TrieNode *[26];
for(int i=0;i<26;i++) children[i]=NULL;
					 }

};

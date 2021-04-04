#include <bits/stdc++.h>
#include<string>
#include<climits>
using namespace std;
int lcsBrute(string s , string t, int m , int n){
	if(m==0 || n==0) return 0;
	if(s[m-1]==t[n-1]){
		return 1+lcsBrute(s, t, m-1, n-1);
	}else{
		return max(lcsBrute(s,t,m, n-1),lcsBrute(s,t, m-1,n));
	}


}
int helper_memo(string s , string t , int m , int n,int ** output){
	if(m<=0|| n<=0) return 0;
	if(output[m][n]!=-1) return output[m][n];
	if(s[m-1]==t[n-1]){
		int a=1+helper_memo(s, t,m-1,n-1,output );
		output[m][n]=a;
	}else{
		int x=helper_memo(s, t , m-1, n, output);
		int y=helper_memo(s,t,m, n-1,output);
		output[m][n] =max(x,y);
		return output[m][n];
	}

}
int lcsMemo(string s , string t , int m , int n){
	int **output=new int *[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			output[i][j]=-1;
		}
	}
//	memset(output, -1, sizeof(output));
	return helper_memo(s,t, m , n , output);
	
}
int helper_dp(string s , string t , int m , int n,int **output){
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0|| j==0) output[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==t[j-1]){
				output[i][j]=1+output[i-1][j-1];
			}else{
				int a=output[i][j-1];
				int b=output[i-1][j];
				output[i][j]=max(a,b);
			}
		}
	}
	return output[m][n];
}
int lcsDP(string s , string t , int m , int n){
		int **output=new int *[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			output[i][j]=-1;
		}
	}
		return helper_dp(s,t, m , n , output);
	
}

int main(){


	string s,t;
	cin>>s;
	cin>>t;
//	cout<<lcsBrute(s , t , s.length(), t.length()); 
	cout<<lcsDP(s , t , s.length(), t.length()); 
}

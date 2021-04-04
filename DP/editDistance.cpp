#include<iostream>
#include<cstring>
using namespace std;

int output[101][101];
int helper(string s , string t , int m,int n ){
		  if(m<=0 || n<=0) return max(m , n);
		  if(s[m-1]==s[n-1]){
					 return helper(s,t, m-1,n-1);
		  }else{
					 int x=1+helper(s, t , m-1,n); //insert
					 int y=1+helper(s, t, m , n-1);// remove
					 int z=1+helper(s,t , m-1,n-1);// replace
					 return min(x,min(y,z));
		  }

}


int helperMemo(string s , string t , int m , int n ){

		  if(m==0 || n==0) return max(m , n);


		  if(output[m][n]!=-1) return output[m][n];
		  int ans;
		  if(s[m-1]==t[n-1]){
					 ans= helper(s,t, m-1,n-1);
					 output[m][n]=ans;
					 return ans;

		  }else{
					 int x=1+helper(s, t , m-1,n); //insert
					 int y=1+helper(s, t, m , n-1);// remove
					 int z=1+helper(s,t , m-1,n-1);// replace
					 int ans= min(x,min(y,z));
					 output[m][n]=ans;
					 return ans;
		  }





}
int helperDP(string s , string t, int m , int n){
		  int dp[m+1][n+1];
		  for(int i=0;i<=m;i++){

					 for(int j=0;j<=n;j++){
								if(i==0|| j==0) {
										  dp[i][j]=max(i, j);
								}
					 }
		  }
		  for(int i=1;i<=m;i++){
					 for(int j=1;j<=n;j++){
								if(s[i-1]==t[j-1]){
										  dp[i][j]=dp[i-1][j-1];
								}else{
										  int x=1+dp[i-1][j];
										  int y=1+dp[i][j-1];
										  int z=1+dp[i-1][j-1];
										  dp[i][j]=min(x,min(y,z));
								}

					 }
		  }return dp[m][n];




}


int editDistance(string s, string t) {
		  int m =s.length()+1;
		  int n =t.length()+1;
		  // int **output=new int *[m];
		  // for(int i=0;i<m;i++){
		  //     output[i]=new int[n];
		  //     for(int j=0;j<n;j++){
		  //         output[i][j]=-1;
		  //     }
		  // }
		  memset(output, -1, sizeof(output));
		  return helperDP(s, t , m-1,n-1);


}
int main(){
		  string s;
		  string t;
		  cin>>s;
		  cin>>t;
		  cout<<editDistance(s,t);



}

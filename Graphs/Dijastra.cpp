#include<iostream>
#include<climits>
using namespace std;
int getMin(bool *visited, int *cost , int n){
int minVertex=-1;
for(int i=0;i<n;i++){
if(visited[i]==false &&(minVertex==-1||  cost[i]<cost[minVertex])){
minVertex=i;}}
return minVertex;

}
void dijastraFun(int **adj , int n , int e){
		  bool *visited=new bool[n];
		  int *cost=new int[n];
		  for(int i=0;i<n;i++) {visited[i]=false;
					 cost[i]=INT_MAX;}
		  cost[0]=0;
		  for(int i=0;i<n-1;i++){
					 int min=getMin(visited, cost , n);
					 visited[min]=true;
					 for(int j=0;j<n;j++){
										  if(adj[min][j]!=0 && visited[j]==false){
													 int dist=adj[min][j]+cost[min];
													 if(dist<cost[j]){
																cost[j]=dist; } }	}
		  }

		  for(int i=0;i<n;i++){
cout<<"\n"<<i<<":"<<cost[i];
		  }
		 
}
int main(){
		  int n , e;
		  cin>>n>>e;
		  int **adj=new int*[n];
		  for(int i=0;i<n;i++){
					 adj[i]=new int[n];
					 for(int j=0;j<n;j++){
								adj[i][j]=0;
					 }
		  }
		  for(int i=0;i<e;i++){
					 int v1,v2,c;
					 cin>>v1>>v2>>c;
					 adj[v1][v2]=c;
					 adj[v2][v1]=c;
		  }
		  dijastraFun(adj , n ,e);
		  for(int i=0;i<n;i++){
		  delete[]adj[i];}
		  delete[] adj;

}

#include<iostream>
#include<climits>
using namespace std;
int getMin(int *weight, bool *visited, int n){

		  int minVertex=-1;
		  for(int i=0;i<n;i++){
					 if(visited[i]==false){
				if(minVertex==-1) minVertex=i;
				else if(weight[i]<weight[minVertex]){
				minVertex=i;}
					 }
		  }return minVertex;

}
int primMst(int **graph, int n , int e){
		  bool *visited=new bool[n];
		  int *parent=new int[n];
		  int *weight=new int[n];
		  for(int i=0;i<n;i++){
					 weight[i]=INT_MAX;
					 visited[i]=false;
		  }
		  // for source node;
		  parent[0]=-1;
		  weight[0]=0;
		  for(int i=0;i<n;i++){
					 int minVertex=getMin(weight,visited, n);
	//				 cout<<minVertex<<"\n";
					 visited[minVertex]=true;
					 for(int j=0;j<n;j++){
								if(graph[minVertex][j]!=0 && visited[j]==false){
										  if(weight[j] > graph[minVertex][j]){
													 weight[j]=graph[minVertex][j];
													 parent[j]=minVertex;
										  }

								}
					 }

		  }
		  int sum=0;
for(int i=0;i<n;i++){
sum+=weight[i];}
return sum;
}
int main(){
		  int n;
		  int e;
		  cin>>n>>e;
		  int **graph=new int *[n];
		  for(int i=0;i<n;i++){
					 graph[i]=new int[n];
					 for(int j=0;j<n;j++){
								graph[i][j]=0;}}
		  for(int i=0;i<e;i++){
					 int v1,v2, c;
					 cin>>v1>>v2>>c;
					 graph[v1][v2]=c;
					 graph[v2][v1]=c;
		  }


		  cout<<primMst(graph,  n , e);
		  for(int i=0;i<n;i++){
					 delete []graph[i];}
		  delete[] graph;


}

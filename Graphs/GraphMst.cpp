#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
		  public:
					 int source;
					 int dest;
					 int cost;
					 /*	 Edge(int s ,int  d,int  c){
							 source=s;
							 dest=d;
							 cost=c;
							 }*/
};

bool compare(Edge e1, Edge e2){
		  if(e1.cost<e2.cost) return true;
		  return false;
}
int getParent(int source , int *output){
		  if(output[source]==source) return source;
		  return getParent(output[source], output);


}
int kruskal(Edge *arr, int n,int E){
		  Edge *output=new Edge[n-1];
		  int  *parent=new int[n];
		  for(int j=0;j<n;j++){
					 parent[j]=j;
		  }
		  sort(arr, arr+E, compare);
		  int count=0;
		  int i=0;
		  while(count!=n-1){
					 Edge temp=arr[i];
					 i++;
					 int sourceParent=getParent(temp.source , parent);
					 int destParent=getParent(temp.dest, parent);
					 if(sourceParent!=destParent){
								output[count]=temp;
								count++;
								parent[temp.source]=temp.dest;
					 }

		  }
		  int minCost=0;
		  for(int i=0;i<n-1;i++){
					 Edge e=arr[i];
					 minCost+=e.cost;
		  }


		  return minCost;

}
int main(){
		  int n;
		  int e;
		  cin>>n>>e;
		  Edge *arr=new Edge[e];
		  for(int i=0;i<e;i++){
					 int s,d,c;
					 cin>>s>>d>>c;
					 //Edge e(s,d,c);
					 Edge e;
					 e.source=s;
					 e.dest=d;
					 e.cost=c;
					 arr[i]=e;
		  }
		  cout<<"kruskal mst cost"<<kruskal(arr,  n ,e); 

}

#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
void print(int **edges, int n,int sv,bool *visited){
		  cout<<sv<<"\n";
		  visited[sv]=true;
		  for(int i=0;i<n;i++){
					 if(i==sv) continue;
					 if(edges[sv][i]){
								if(visited[i]){
										  continue;
								}
								print(edges, n , i, visited);

					 }
		  }}

void BFSprint(int **edges, int n , int sv, bool *visited){

		  queue<int> q;
		  q.push(sv);
		  visited[sv]=true;
		  while(q.size()!=0){
					 int parent=q.front();
					 q.pop();
					 cout<<parent<<"\n";

					 for(int i=0;i<n;i++){
								if(i==parent) continue;
								if(edges[parent][i]==1){
										  if(!visited[i]){
													 q.push(i);
													 visited[i]=true;
										  }

								}

					 }


		  }



}




void BFS(int **edges, int n){

		  bool *visited=new bool[n];
		  for(int i=0;i<n;i++){

					 visited[i]=false;}
		  for(int i=0;i<n;i++){
					 if(!visited[i]){
								BFSprint(edges, n, i,visited); }
		  }
		  delete [] visited;
}
void DFS(int **edges, int n){

		  bool *visited=new bool[n];
		  for(int i=0;i<n;i++){
					 visited[i]=false;}
		  for(int i=0;i<n;i++){
					 if(!visited[i]){
								print(edges, n , i, visited);}}
		  delete[] visited;
}

bool hasPath(int **edges , int sv ,int end , int n){
		  if(edges[sv][end]==1) return true;
		  bool *visited=new bool[n];
		  for(int i=0;i<n;i++){

					 visited[i]=false;}



		  queue<int> q;
		  q.push(sv);
		  visited[sv]=true;
		  while(q.size()!=0){
					 int parent=q.front();
					 q.pop();
					 for(int i=0;i<n;i++){
								if(i==parent) continue;
								if(edges[parent][i]==1){
										  if(!visited[i]){
													 if(i==end) return true;
													 q.push(i);
													 visited[i]=true;
										  }

								}

					 }


		  }

		  return false;

}

bool isConnected(int **edges, int n, int sv){
bool *visited=new bool[n];
visited[sv]=true;
queue <int> q;
q.push(sv);
while(q.size()!=0){
int parent=q.front();
q.pop();
for(int i=0;i<n;i++){
if(edges[parent][i]==1 && visited[i]==false){
	q.push(i);
	visited[i]=true;
}

}


}
for(int i=0;i<n;i++){
	if(visited[i]==false) return false;
}
return true;
}
vector<int> *getPathBfs(int **edges, int n , int sv,int end){

bool *visited=new bool[n];
visited[sv]=true;
queue <int> q;
bool done=false;
q.push(sv);
unordered_map<int, int> parent_map;
while(q.size()!=0){
int parent=q.front();
q.pop();
for(int i=0;i<n;i++){
if(edges[parent][i]==1 && visited[i]==false){
	q.push(i);
	parent_map[i]=parent;
	visited[i]=true;
if(i==end){
	done=true;
	break;
}
}
}
}
if(done){
vector<int> *ans=new vector<int>();
int current=end;
ans->push_back(current);
while(current!=sv){
current=parent_map[current];
ans->push_back(current);


}


return ans;

}




return NULL;
}
vector<int> * getPathDfs(int **edges , int n , int sv, int end, bool *visited){

	if(sv==end){
		vector <int>* v=new vector<int>();
		v->push_back(sv);
		return v;
	}
visited[sv]=true;

for(int i=0;i<n;i++){
	if(i==sv) continue;
if(edges[sv][i] && visited[i]!=true){
      vector <int>*temp=getPathDfs(edges, n , i, end, visited);
      
      if(temp!=NULL){
      	temp->push_back(sv);
      	return temp;
}
      }
      

}
return NULL;
}/*	  visited[sv]=true;
		  for(int i=0;i<n;i++){
					 if(i==sv) continue;
					 if(edges[sv][i]){
								if(visited[i]){
										  continue;
								}
								print(edges, n , i, visited);

					 }
		  }}

*/



int main(){
		  int n;
		  int e;
		  cin>>n>>e;
		  int ** edges=new int *[n];
		  for(int i=0;i<n;i++){
					 edges[i]=new int[n];
					 for(int j=0;j<n;j++){
								edges[i][j]=0;
					 }
		  }
		  for(int i=0;i<e;i++){
					 int f,s;
					 cin>>f>>s;
					 edges[f][s]=1;
					 edges[s][f]=1;
		  }
		  int v1, v2;
		  cin>>v1>>v2;
		  // BFS(edges, n);
		  //  cout<<"\n"<<DFS<<"\n";
		  // cout<<"*********************************\n";
		  //  DFS(edges, n);
		  bool *visited=new bool[n];
		 vector<int> *v=getPathDfs(edges,n, v1,v2,visited);
		 if(v==NULL) {
		 	cout<<"EMPTY";
		 	
		 }else{
		 for(int i=0;i<v->size();i++){
 	
cout<<"\n"<<v->at(i)<<"\n";
		 }
}}

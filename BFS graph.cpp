#include<iostream>
#include<queue>
using namespace std;

void printBFS(int** edges,int n, int sv, bool* visited){
	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv]=true;
	while(!pendingVertices.empty()){
		int currentVertex=pendingVertices.front();
		pendingVertices.pop();
		cout<<currentVertex<<" ";
		for(int i=0;i<n;i++){
			if(i==currentVertex){
				continue;
			}
			if(edges[currentVertex][i]==1 && !visited[i]){
				pendingVertices.push(i);
				visited[i]=true;
			}
		}
	}
}


void BFS(int** edges, int n){
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printBFS(edges,n,i,visited);
		}
	}
	delete [] visited;
}


int main(){
	int n,e;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	cin>>e;
	int** edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	cout<<"Enter the edges: "<<endl;
	for(int i=0;i<e;i++){
		int first,second;
		cout<<"Edge "<<i+1<<": ";
		cin>>first>>second;
		edges[first][second]=1;
		edges[second][first]=1;
	}
	cout<<"BFS: "<<endl;
	BFS(edges,n);
	
	
	return 0;
}

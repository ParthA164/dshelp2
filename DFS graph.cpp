#include<iostream>
#include<queue>
using namespace std;



void printDFS(int**edges, int n, int sv, bool* visited){
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i]==1 && !visited[i]){
			printDFS(edges,n,i,visited);
		}
	}
}

void DFS(int** edges, int n ){
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printDFS(edges,n,i,visited);
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
	cout<<"DFS: "<<endl;
	DFS(edges,n);
	
	
	return 0;
}

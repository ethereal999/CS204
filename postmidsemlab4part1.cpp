#include <bits/stdc++.h> 
using namespace std;


void adde(vector<int> l[],int u,int v){
      l[u].push_back(v);
      l[v].push_back(u); 
 }
bool isbipartite(vector<int> l[],int i ,vector<int> &color,vector<bool> &visited){
     for (int y : l[i]){
         
     	if(visited[y]==false){
              visited[y]=true;
              color[y]=(!color[i]);
             if(!isbipartite(l,y,color,visited)){
             	return false;
             } 

     }
     else if(color[y] == color[i]){
     	return false;
     }
     }

     return true;
     
   
}
int main(){
     int n,m;
     cin>>n>>m;
     vector<int> color(n+1);
     vector<int> adj[n+1];
     vector<bool> visited(n+1);
     for (int i = 0; i < m; i++)
     {
     	int tempv,tempu;
     	cin>>tempv>>tempu;
     	adde(adj,tempv,tempu);

     }

    visited[1] = true;
    color[1] = 0;
    if(isbipartite(adj,1,color,visited)){
    	cout<<"YES"<<endl;
    }
    else{
    	cout<<"NO"<<endl;
    }
 


}
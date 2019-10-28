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
void pseudo(vector<int> l[],int u ,int v,int p ){
	l[u].push_back(p);
	l[p].push_back(u);
	l[p].push_back(v);
	l[v].push_back(p);

}

int main(){
     int n,m;
     cin>>n>>m;
     vector<int> color(2*n+1);
     vector<int> adj[2*n+1];
     vector<bool> visited(2*n+1);
     int p = n+1;
     for (int i = 0; i < m; i++)
     {
     	int tempv,tempu,weight;
     	cin>>tempv>>tempu>>weight;
     	if(weight%2==1){
     	adde(adj,tempv,tempu);
         }
        else{
           pseudo(adj,tempv,tempu,p);
           p++;
        } 
     }

    visited[1] = true;
    color[1] = 0;
    if(isbipartite(adj,1,color,visited)){
    	cout<<"NO"<<endl;
    }
    else{
    	cout<<"YES"<<endl;
    }
 


}

/* given no. of vertices and no. of edges
   check whether undirected graph has cycles or not

*/
#include <iostream>

#include <bits/stdc++.h>
using namespace std;


void adde(vector<int>L[],int p,int q){
 L[p].push_back(q);
 L[q].push_back(p);
}
int isc( vector<int> adj[],int u,vector<int> visited,int p){
     visited[u]=1;
     vector<int>::iterator i;
     for( i = adj[u].begin(); i != adj[u].end(); ++i)
    {

        if (!visited[*i])
        {
           if (isc(adj,*i, visited, u))
              return 1;
        }


        else if (*i != p)
           return 1;
    }
    return 0;

}
int iscyclic(vector<int> adj[],int n,vector<int> visited){

   for(int i=0;i<n;i++){
    visited[i]=0;
   }
   for(int u=0;u<n;u++){
    if(!visited[u]){
        if(isc(adj,u,visited,-1)){
            return 1;
        }
    }
   }
   return 0;



}
int main()
{

          int n,m;
          cin>>n>>m;
          vector<int> adj[n];
vector<int> visited(n);
    for(int i=0;i<m;i++ ){
        int l,k;
        cin>>l>>k;
        adde(adj,l,k);
    }
     if(iscyclic(adj,n,visited))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;



}

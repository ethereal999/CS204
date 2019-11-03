#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;
/*
What is Minimum Spanning Tree?
Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected and undirected graph is a spanning tree with weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.
How many edges does a minimum spanning tree has?
A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.
Question:
Given a Graph, with weighted edges, find the total cost of the minimal spanning tree
*/
// ****KRUSKAL'S ALGO****
/*
1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
If cycle is not formed, include this edge. Else, discard it.
3. Repeat step#2 until there are (V-1) edges in the spanning tree.
INPUT:
First line contains two space separated integers(n,n)  Then m lines follow, each line has 3 space separated integers  x,y , weight.
OUTPUT:
Print the min weight of the spanning tree.
CONTRAINTS:
2<=n<=10^4
1<=m<=10^5
1<=x,y<=n
1<=weight<=1000
*/




int find_s(ll arr[], ll x){
	if(x!=arr[x]){
		arr[x]=find_s(arr,arr[x]);
	}
	return arr[x];
}
void union_r(ll arr[],ll rank_m[],int a,int b){
	int p=find_s(arr,a);
	int q=find_s(arr,b);
	if(p!=q){
		if(rank_m[p]<rank_m[q]){
                swap(p,q);
		}
		arr[q]=p;
		if(rank_m[p]==rank_m[q]){
			rank_m[p]++;
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector< pair<ll,pair<ll,ll> > > temp;
	int x,y,w;
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		temp.push_back({w,{x,y}});
	}
	sort(temp.begin(),temp.end());
	ll arr[n+1],rank_m[n+1];
	ll ans=0;
	for(int i=0;i<n+1;i++){
		arr[i]=i; //make-set
		rank_m[i]=0;
	}
	for(int i=0;i<temp.size();i++){
		int leader_1 = find_s(arr,temp[i].second.first);
		int leader_2 = find_s(arr,temp[i].second.second);
		if(leader_1!=leader_2){ //only add edge if in different components (no cyle should be made)
			ans += temp[i].first;
			union_r(arr,rank_m,temp[i].second.first,temp[i].second.second);
		}
	}
	cout<<ans;
	return 0;
}

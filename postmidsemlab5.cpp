
#include <iostream>
#include <bits/stdc++.h>

#define ll long long int
using namespace std;

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
	int x,y;
	ll w;
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		temp.push_back({w,{x,y}});
	}
	sort(temp.begin(),temp.end());
	reverse(temp.begin(),temp.end());
	ll arr[n+1],rank_m[n+1];
	ll ans=1;
	for(int i=0;i<n+1;i++){
		arr[i]=i; 
		rank_m[i]=0;
	}
	for(int i=0;i<temp.size();i++){
		int leader_1 = find_s(arr,temp[i].second.first);
		int leader_2 = find_s(arr,temp[i].second.second);
		if(leader_1!=leader_2){ 
			ans =(ans*temp[i].first)%(1000000007);
			union_r(arr,rank_m,temp[i].second.first,temp[i].second.second);
		}
	}
	cout<<ans<<endl;
	return 0;
}

/* 
4 5 
1 2 47776
1 4 565465
4 2 1654
4 3 643543
2 3 254543
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   int mat[n][m];
   int visited[n][m];
   vector<pair<int,int>> p;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

        cin>>mat[i][j];
        visited[i][j]=0;
        if(mat[i][j]){
            p.push_back({i,j});
        }
    }
   }
   int len=p.size();
   int nisland=0;
   for(int i=0;i<len;i++){
       vector<pair<int,int>> v;
       int x=p[i].first;
       int y=p[i].second;
       if(visited[x][y]==0){
        nisland++;
        v.push_back({x,y});
        while(!v.empty()){
            pair<int,int> val;
            val = v.back();
            v.pop_back();
            int p=val.first;
            int q=val.second;
            visited[p][q]=1;
        if(p-1>=0 && mat[p-1][q] && !visited[p-1][q])v.push_back({p-1,q});

        if(p+1<n && mat[p+1][q] && !visited[p+1][q]){v.push_back({p+1,q});
        }
        if(q-1>=0 && mat[p][q-1] && !visited[p][q-1]){v.push_back({p,q-1});
        }
        if(q+1<m && mat[p][q+1] && !visited[p][q+1]){v.push_back({p,q+1});
        }
       }
   }

}
cout<<nisland<<endl;

}

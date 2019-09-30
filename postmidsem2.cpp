#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define lli long long int
#define f first
#define s second
using namespace std;


bool compe(pair <lli,lli> &a,pair <lli,lli> &b){
      return a.f < b.f || (a.f == b.f && a.s < b.s);

}
bool cw(pair <lli,lli> &a,pair <lli,lli> &b,pair <lli,lli> &c){
      return a.f*(b.s-c.s) + b.f*(c.s-a.s) + c.f*(a.s-b.s) < 0;
}
bool ccw(pair <lli,lli> &a,pair <lli,lli> &b,pair <lli,lli> &c){
      return a.f*(b.s-c.s) + b.f*(c.s-a.s) + c.f*(a.s-b.s) > 0;
}

void convex_hull (vector< pair <lli,lli> > &a){
      if(a.size()==1){
        return;
      }
  sort(a.begin(), a.end(),&compe);
     pair <lli,lli>  p1;
     pair <lli,lli>  p2;
     p1 = a[0];
     p2 = a[a.size()-1];
     vector<pair <lli,lli> > up,down;
     up.push_back(p1);
     down.push_back(p1);
     for(lli i =1 ; i< a.size();i++){

       if(i == a.size()-1 || cw(p1,a[i],p2)){
         while(up.size()>=2 && !cw(up[up.size()-2],up[up.size()-1],a[i])){
           up.pop_back();
         }
           up.push_back(a[i]);
       }
       if(i == a.size()-1 || ccw(p1,a[i],p2)){
         while(down.size()>=2 && !ccw(down[down.size()-2],down[down.size()-1],a[i])){
           down.pop_back();
         }
           down.push_back(a[i]);
       }
       }
       a.clear();
       for (lli i = 0; i < up.size(); i++)
        a.push_back(up[i]);
       for (lli i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);

     }


int main()
{
    lli t;
    cin>>t;
    vector< pair <lli,lli> > point;
    for(lli i=0;i<t;i++){
        lli x,y;
        cin>>x>>y;
        point.push_back({x,y});

    }
    convex_hull(point);
    for(lli i=0;i<point.size();i++){
       cout<< point[i].f << " "<<point[i].s <<endl;
    }


}


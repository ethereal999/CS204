#include <bits/stdc++.h>
#include <set>
using namespace std;



int main(){
	int n;
	string a,b,c;
	std::vector<string> v;
    set<string> s;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a;
    	s.insert(a);
    	v.push_back(a);

    }
    for(int i=0;i<n;i++){
    	b=v[i];
    	reverse(v[i].begin(),v[i].end());
    	c=v[i];
    	if(b==c){
    		continue;
    	}
    	if(s.find(c)!=s.end()){
    		cout<<"YES"<<endl;
    		return 0;
    	}

    }
    cout<<"NO"<<endl;
    return 0;
   
}

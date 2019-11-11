#include <bits/stdc++.h>
#include <set>
typedef long long int lli ;
using namespace std;


/*
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
*/

const int m = 1e7 + 19;
static bool hsh[m][4];
lli p[4];
int main()
{
    
    p[0] = 53;
    p[1] = 389;
    p[2] = 769;
    p[3] = 1543;
    lli n;
    cin >> n;
    string a, t, temp;
    lli table[105][4];
    memset(table, 1, sizeof(table));
   for(int j=0;j<4;j++)
    {
        for (int i = 1; i <= 100; i++)
        {
            table[i][j] = ((table[i - 1][j] % m) * p[j]) % m;
        }
    }
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        v.push_back(a);
        lli s_z = lli(a.size());
        for(int j=0;j<4;j++)
        {
            lli h = 0;
            for(int k=0;k<s_z;k++)
            {
                if ('a' <= a[k] && a[k] <= 'z')
                    h = (h + (lli(a[k] - 'a' + 1) * table[k][j]) % m) % m;
                else
                    h = (h + (lli(a[k] - 'A' + 27) * table[k][j]) % m) % m;
            }
            hsh[h][j] = true;
        }
    }
    for(int i=0;i<n;i++)
    {
        temp = v[i];
        reverse(v[i].begin(),v[i].end());
        t = v[i];
        if (temp == t)
            continue;
        lli st = t.size();
        int flag = 1;
        for(int j=0;j<4;j++)
        {
            lli hv= 0;
            for(int k=0;k<st;k++)
            {
                if ('a' <= t[k] && t[k] <= 'z')
                    hv = (hv + (lli(t[k] - 'a' + 1) * table[k][j]) % m) % m;
                else
                    hv = (hv + (lli(t[k] - 'A' + 27) * table[k][j]) % m) % m;
            }
            if (hsh[hv][j] == false)
                flag = 0;
        }
        if (flag == 1)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
/*
5
abc
cab
aaa
bccccccc
cba
*/

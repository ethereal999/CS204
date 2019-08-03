#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

string add(string s1,string s2){

string s3,s4,an;
   int mx=max(s1.length(),s2.length());
int mi=min(s1.length(),s2.length());
   int ans[mx+1]={0};
   int ans1[mx+1]={0};
   for(int i=0;i<s1.length();i++){
    s3[i]=s1[s1.length()-1-i];
}
 for(int i=0;i<s2.length();i++){
    s4[i]=s2[s2.length()-1-i];
}

int r=0;
int m=0;
for(int i=0;i<mi;i++){
     m=r+(s3[i]-'0')+(s4[i]-'0');
    if(m>=10){
   ans1[i]=(m%10);
   r=m/10;
}
else{
  ans1[i]=m;

  r=0;
}



}
if(s1.length()==s2.length()){
 ans1[mx]=r; 
}
else if(s1.length()>s2.length()){
  for(int i=mi;i<mx;i++){
     m=r+(s3[i]-'0');
    if(m>=10){
   ans1[i]=(m%10);
   r=m/10;
}
else{
  ans1[i]=m;

  r=0;
}


}
}
else {
  for(int i=mi;i<mx;i++){
     m=r+(s4[i]-'0');
    if(m>=10){
   ans1[i]=(m%10);
   r=m/10;
}
else{
  ans1[i]=m;

  r=0;
}


}
}

for(int i=0;i<mx+1;i++){
     ans[i]=ans1[mx-i];
 
    
}

for(int i=0;i<mx+1;i++){
  an += to_string(ans[i]);    
 
    
}
if(an[0]=='0'){
 an.erase(an.begin());
}
return an;
}



string comp(string s2,int mx){
string g,g1;
for(int i=0;i<mx+1;i++){
   g.append("9");

  }
g[0]='0';
for(int i=0;i<s2.length();i++){
   g[mx-i]=(9-(s2[s2.length()-i-1]-'0'))+'0';

  }


  int a1[mx+1]={0};

  int carry=0;
    int m=((g[mx]-'0')+1);
     a1[mx]=m%10;
    carry=m/10;
  for(int i=mx-1;i>=0;i--){
    
  int temp=((g[i]-'0')+carry);
     a1[i]=temp%10;
     carry=temp/10;
   


  }


for(int i=0;i<mx+1;i++){
 
   g1+=to_string(a1[i]);
}
if(g1[0]=='0'){
 g1.erase(g1.begin());
}
return g1;





}



int main(){ 
   int t;
   cin>>t;
   while(t>0){
    string s1,s2;
   cin>>s1>>s2;
   string temp1,temp2;
   
   int maxx=max(s1.length(),s2.length());
int mi=min(s1.length(),s2.length());
 
temp1=comp(s2,maxx);

temp2=add(s1,temp1);
maxx = max(temp1.length(),s1.length());

if(temp2.length()>maxx){
   temp2.erase(temp2.begin());
   cout<<temp2<<endl;
}
else{
   temp2=comp(temp2,maxx);
   cout<<"-"<<temp2<<endl;
}

t--;
   }


}

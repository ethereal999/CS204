#include <bits/stdc++.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
   string s3,s4;
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
if(ans[0]==0){
 for(int i=1;i<mx+1;i++){
  cout<<ans[i];
       
 
    
}
}
else{
for(int i=0;i<mx+1;i++){
  cout<<ans[i];
       
 
    
}
}



}

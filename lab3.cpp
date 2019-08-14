#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;


bool checkP(string str){

  stack<char>s;
  char x;
for(int i=0;i<str.length();i++){
 if(str[i]=='(' || str[i]=='<' || str[i]=='[' || str[i]=='{'){
     s.push(str[i]);
 }
 if(s.empty()){
return false;
}

switch(str[i]){
case ')': x=s.top();

          if (x=='('){
          s.pop();

          }
           else{return false;}
           break;

case '}': x=s.top();

          if (x=='{'){s.pop();
           }
            else{return false;}

           break;

case ']': x=s.top();

          if (x=='['){s.pop();
          }
          else{return false;}
           break;

case '>': x=s.top();

          if (x=='<'){s.pop();
          }
           else{return false;}
           break;

}
if(str[i]=='|'){
if(s.top() == '(' || s.top() == '{' || s.top() == '<' || s.top() == '{'){
    s.push(str[i]);
}
else s.pop();
}
}
return s.empty();
}



int main()
{
    int n;
    cin>>n;
    string ans[n];
    for(int i=0;i<n;i++){
    ans[i] = "";
    string str;
    cin>>str;

     if(checkP(str)){
       ans[i]="YES";
     }
     else{
     ans[i]="NO";
     }

}
  for(int i=0;i<n;i++){

     cout<<ans[i]<<endl;
  }
}


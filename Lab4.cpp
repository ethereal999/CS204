#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;


struct node{
 struct node* left;
 struct node* right;
 string s;

};

int checkpre(char c){
  if(c=='^'){
   return 3;
  }
  else if (c=='*' || c=='/'){
    return 2;
  }
  else if(c=='+' || c=='-')
   { return 1;
  }
  else{return -1;}


}

struct node* newNode(string str){
   struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->s=str;

    return temp;

}

struct node* createtree(string s){
        stack<char> st1;
        stack<struct node*> st2;
        for(int i=0;i<s.length();i++){

          if(s[i]>='0' && s[i]<='9'){
             int temp=0;
             int j=i;
             while(s[j]>='0' && s[j]<='9'){
                temp=temp*10 + (s[j]-'0');
                j++;

             }
             string t=to_string(temp);
           struct node* t1= newNode(t);

           st2.push(t1);
            i=j-1;
            }

          else if(s[i]=='('){
           st1.push(s[i]);
          }
          else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='^' || s[i]=='/'){
           if(st1.empty()==1){

            st1.push(s[i]);


           }
           else {
                if(s[i]=='^' && st1.top()=='^'){
                 st1.push(s[i]);
              }

           else if(checkpre(s[i])>checkpre(st1.top())){
                 st1.push(s[i]);

            }
            else {
               while(st1.empty()==0){
              if(checkpre(s[i])<=checkpre(st1.top())){
                string var=" ";
                var[0]=st1.top();
                st1.pop();
                struct node* t1=newNode(var);
                t1->right=st2.top();
                st2.pop();
               if(st2.empty()==1){
                   struct node* un=newNode("0");

                   t1->left =un;
                }
                else{
                t1->left=st2.top();
                st2.pop();



              }

                 st2.push(t1);

              }
              }
              st1.push(s[i]);
            }
          }
          }
          else if(s[i]==')'){

          while(st1.top()!='('){
                string var=" ";
                var[0]=st1.top();
                st1.pop();
                struct node* t1=newNode(var);
                t1->right=st2.top();
                st2.pop();
                if(st2.empty()==1){
                   struct node* un=newNode("0");

                   t1->left =un;
                }
                else{
                t1->left=st2.top();
                st2.pop();



              }
              st2.push(t1);
              }
              st1.pop();


          }
          }


                while(st1.empty()!=1){
                 string var=" ";
                var[0]=st1.top();
                st1.pop();
                struct node* t1=newNode(var);
                t1->right=st2.top();
                st2.pop();
                if(st2.empty()==1){
                   struct node* un=newNode("0");

                   t1->left =un;
                }
                else{
                t1->left=st2.top();
                st2.pop();



              }

                 st2.push(t1);

              }



         return st2.top();


        }

   int eval(struct node* root){

       if (root==NULL)
        {return -1;}


    if (!root->left && !root->right)
        {return stoi(root->s);}


    int l_val = eval(root->left);


    int r_val = eval(root->right);

    string str=root->s;

    if (str[0]=='+')
        return l_val+r_val;

    if (str[0]=='-')
        return l_val-r_val;

    if (str[0]=='*')
        return l_val*r_val;

    if (str[0]=='/')
        return l_val/r_val;
    if (str[0]=='^')
        return pow(l_val,r_val);

    return -1;
   }






int main()
{
       int n;
         cin>>n;
      vector<int> ans;

    for(int i=0;i<n;i++){
      int l,t;
     cin>>t;
  for(int j=0;j<t;j++) {
    string s;
    cin>>s;
    int l=eval(createtree(s));
    ans.push_back(l);


}

}
 for(int p=0;p<ans.size();p++){
   cout<<ans[p]<<endl;
}
    return 0;
}


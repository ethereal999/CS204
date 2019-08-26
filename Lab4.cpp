#include <iostream>
#include <stack>
#include <bits/stdc++.h>
#include <map>
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

struct node* createtree(string s, map<string,int> *m1){
        stack<char> st1;
        stack<struct node*> st2;

        int checkcon=0;



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
        if(checkcon==0){
           checkcon=-1;
        }
           st2.push(t1);
            i=j-1;
            }

          else if(s[i]=='('){
            checkcon=0;
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
                if(checkcon==0){
                  checkcon=1;
                }
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
                else if(checkcon==1){
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
          else{
                     int p=i;
                     string tmp;
               for(p=i;p<s.length();p++){
                   if(!(s[p]>='a' && s[p]<='z' || s[p]>='A' && s[p]<='Z')){
                           break;
                   }
                   else{
                    tmp.push_back(s[p]);

                   }

               }





                    auto itr= (*m1).find(tmp);


                     if(itr== (*m1).end()){
                             return NULL;
                                                }
                        else {
                        string temp= to_string(itr->second);
                        struct node* t1= newNode(temp);

                        st2.push(t1);

                        i=p-1;

                    }


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
        {return INT_MAX;}


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

    return  -1;
   }






int main()
{
       int n;
         cin>>n;
      vector<int> ans;

    for(int i=0;i<n;i++){
      int l,t;
     cin>>t;
     map<string , int> m2;
  for(int j=0;j<t;j++) {
    string s;
    cin>>s;
    int flag=0;

    for(int k=0;k<s.length();k++){
        if(s[k]=='='){
            flag=1;
            string subs1,subs2;
            subs1= s.substr(0,k);
            subs2= s.substr(k+1,s.length());
            auto it = m2.find(subs1);
            if(it== m2.end()){
                if(eval(createtree(subs2,&m2))==INT_MAX){
                        ans.push_back(INT_MAX);
                }
                else{
                m2[subs1]=eval(createtree(subs2,&m2));
            }
            }
            else{

                if(eval(createtree(subs2,&m2))==INT_MAX){
                        ans.push_back(INT_MAX);
                }
                else{
                it->second = eval(createtree(subs2,&m2));
            }
}
        }



    }
    if(flag ==0){
                int l=eval(createtree(s,&m2));
                ans.push_back(l);
        }






}

}
 for(int p=0;p<ans.size();p++){
     if(ans[p]==INT_MAX){cout<<"CANT BE EVALUATED"<<endl;}
     else{
   cout<<ans[p]<<endl;

     }
     }

    return 0;
}



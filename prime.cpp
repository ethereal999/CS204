#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long int n1;
    cin>>n1;
    long long int n= sqrt(n1);
    int flag=0;
    if(n1==0 || n1==1){        cout<<"Given number is not prime"<<endl;}

    else{for(long long int i=2;i<=n;i++){
        if(n1%i==0){
            flag=1;
        }
    }

    if(flag==1){
        cout<<"Given number is not prime"<<endl;
    }
    else{
        cout<<"Given number is prime"<<endl;
    }
    }
}

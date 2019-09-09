#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Compare(string X, string Y)
{
    string XY = X.append(Y);

    string YX = Y.append(X);

 	if (XY > YX)
 	{
 		return 1;
 	}
 	else
 	{
 		return 0;
 	}

}



void merge(string arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
   
    string L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (Compare(R[j],L[i])== 1) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort( string arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}


int main(){
     int t;
     cin>>t;
      string output[t];
      int flag=0;
  for(flag =0;flag<t;flag++){
 
    int n;
    cin>>n;
    
  string s[n];
  for(int i=0;i<n;i++){
     cin>>s[i];
  
  }
  mergeSort(s,0,n-1);
  string temp= "";
  for(int i=n-1;i>=0;i--){
  temp+=s[i];
}
   output[flag]=temp;
  
  
}

   for(int j=0;j<t;j++){
    cout<<output[j]<<endl;
}
} 

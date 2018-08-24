/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    int j=n-1;
    int i;
    while((n-j)<=n)
    { 
      i=1;
      while(i<=n)
      {  
        if(i<=j)
          cout<<" ";
        else
          cout<<"#";
        i++;
      }
      cout<<endl;
      j--;
    }
    return 0;
}


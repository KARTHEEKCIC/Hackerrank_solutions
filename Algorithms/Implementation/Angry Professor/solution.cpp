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
    int t, count[10];
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, k;
        count[i]=0;
        cin >> n >> k;
        int a[1000];
        for(int j = 0;j < n;j++)
           cin >> a[j];
        for(int l=0;l<n;l++)
           { if(a[l]<=0)
               count[i]++; }
            if(count[i]>=k)
              cout<<"NO"<<endl;
            else
              cout<<"YES"<<endl; }
    return 0;
}


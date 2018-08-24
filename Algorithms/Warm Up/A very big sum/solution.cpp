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
    unsigned long arr[n];
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    unsigned long sum=0;
    for(int i=0;i<n;i++)
      sum+=arr[i];
    cout<<sum;
    return 0;
}


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
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    float sum1=0, sum2=0, sum3=0;
    for(int i=0;i<n;i++)
    {  
      if(arr[i]<0)
        sum1++;
      if(arr[i]>0)
        sum2++;
      if(arr[i]==0)
        sum3++;
    }
    cout<<sum2/n<<endl<<sum1/n<<endl<<sum3/n;
    return 0;
}


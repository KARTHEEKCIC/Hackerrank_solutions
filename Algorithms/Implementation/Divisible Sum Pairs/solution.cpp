/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k, count=0;
    cin >> n >> k;
    int a[100];
    for(int i = 0;i < n;i++){
       cin >> a[i];
    }
    for(int j=0;j<n;j++)
      {  for(int l=j+1;l<n;l++)
         if((a[j]+a[l])%k==0)
          count++; }
    cout<<count;
    return 0;
}


/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }
    int apple_count=0, orange_count=0;
    for(int i=0;i<m;i++)
    {
      if(s<=(apple[i]+a) && (apple[i]+a)<=t)
        apple_count++;
    }
    for(int i=0;i<n;i++)
    {
      if(s<=(orange[i]+b) && (orange[i]+b)<=t)
        orange_count++;
    }
    cout<<apple_count;
    cout<<endl<<orange_count;
    return 0;
}


/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    int alice_count=0, bob_count=0;
    if(a0>b0)
      alice_count++;
    else if(a0<b0)
           bob_count++;
    if(a1>b1)
      alice_count++;
    else if(a1<b1)
          bob_count++;
    if(a2>b2)
      alice_count++;
    else if(a2<b2)
          bob_count++;
    cout<<alice_count<<" "<<bob_count;
    return 0;
}


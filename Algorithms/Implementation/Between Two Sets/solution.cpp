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

using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0;b_i < m;b_i++){
       cin >> b[b_i];
    }
    int largest, smallest, count=0;
    int flag=0;
    largest=a[0];
    smallest=b[0];
    for(int i=0 ;i<n;i++)
      if(largest<a[i])
        largest=a[i];
    for(int i=0 ;i<m;i++)
      if(smallest>b[i])
        smallest=b[i];
    if(smallest==largest)
    {
      for(int i=0;i<n;i++)
        if(largest%a[i]!=0)
        { flag++;
          break;
        }
     if(flag==0)
      for(int i=0;i<m;i++)
        if(b[i]%smallest!=0)
          break;
    }
    else if(smallest<largest){}
         else {
    for(int i=largest;i<=smallest;i++)
    {   flag=0;
      for(int j=0;j<n;j++)
      { if(i%a[j]!=0)
        { flag++;
          break;
        }
      }
     if(flag==0)
     { for(int j=0;j<m;j++)
       { if(b[j]%i!=0)
         { 
           flag++;
           break;
         }
       }
      if(flag==0)
       count++; 
     }
    }
    }
    cout<<count;
    system("pause");
    return 0;
}


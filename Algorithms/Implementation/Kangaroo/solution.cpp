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
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    if(v1==v2)
    { cout<<"NO";
      return 0;
    }
    float n=((float)(x1-x2)/(float)(v2-v1))+1;
    int n1=((x1-x2)/(v2-v1))+1;
    if(n>0 && (n-n1)==0)
      cout<<"YES";
    else cout<<"NO";
    return 0;
}


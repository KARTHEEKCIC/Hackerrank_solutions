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
    vector<int> h(26);
    for(int h_i = 0;h_i < 26;h_i++){
       cin >> h[h_i];
    }
    char word[10];
    cin >> word;
    int n1=strlen(word);
    int largest=0;
    for(int i=0 ; word[i]!='\0';i++)
    { 
      if(h[word[i]-97]>largest)
        largest=h[word[i]-97];
    }
    int width=n1*1;
    cout<<(width*largest);
    return 0;
}


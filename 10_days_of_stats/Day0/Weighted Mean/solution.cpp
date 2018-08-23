#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int obs[n];
    int w;
    float num = 0, denum = 0;
    for(int i=0 ; i<n ; i++) {
        cin>>obs[i];
    }
    for(int i=0 ; i<n ; i++) {
        cin>>w;
        num+=obs[i]*w;
        denum+=w;
    }
    float result = num/denum;
    cout<< std::fixed << std::setprecision(1) << result;
    return 0;
}


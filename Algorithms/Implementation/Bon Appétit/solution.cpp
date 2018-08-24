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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, k, sum=0;
    int A[100000];
    cin>>n>>k;
    for(int i=0;i<n;i++)
     {   cin>>A[i];
         if(i!=k)
         sum+=A[i]; }
    int bcharged;
    cin>>bcharged;
    if(bcharged==(sum/2))
        cout<<"Bon Appetit";
    else
        cout<<bcharged-(sum/2);
    return 0;
}


/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    long int a;
    long int b;
    long int c;
    long int d;
    long int e;
    cin >> a >> b >> c >> d >> e;
    long int sum;
    sum=a+b+c+d+e;
    long int largest=a, smallest=a;
    if(b>largest)
      largest = b;
    if(c>largest)
      largest=c;
    if(d>largest)
      largest=d;
    if(e>largest)
      largest=e;
    if(b<smallest)
      smallest = b;
    if(c<smallest)
      smallest=c;
    if(d<smallest)
      smallest=d;
    if(e<smallest)
      smallest=e;
    cout<<sum-largest<<" "<<sum-smallest;
    return 0;
}


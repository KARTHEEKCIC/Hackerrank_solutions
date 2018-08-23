#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// start and end are the indices of the starting and ending position in the obs list
int median(int obs[], int start, int end) {
    int median;
    int n = end-start+1;
    if(n%2 == 0) {
        median = (obs[start+n/2] + obs[start+n/2-1])/2;
    } else {
        median = obs[start+n/2];
    }
    return median;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int obs[n];
    for(int i=0 ; i<n ; i++) {
        cin>>obs[i];
    }
    sort(obs,obs+n);
    int q1,q2,q3;
    q2 = median(obs,0,n-1);
    q1 = median(obs,0,n/2-1);
    if(n%2==0){
        q3 = median(obs,n/2,n-1);
    } else {
        
        q3 = median(obs,n/2+1,n-1);
    }
    
    cout<<q1<<endl<<q2<<endl<<q3;
    return 0;
}


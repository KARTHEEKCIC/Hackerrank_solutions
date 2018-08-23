#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    float arr[n];
    float sum = 0, mean, mode, median;
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr, arr+n);
    
    // now let us calculate the median
    if(n%2 == 0) {
        median = (arr[n/2] + arr[n/2-1])/2;
    } else {
        median = arr[n/2];
    }
    
    // calculating the mean 
    mean = sum/n;
    
    //calculating the mode
    mode = arr[0];
    long mode_count = 1;
    long temp = arr[0], temp_count=1;
    for(int i=1 ; i<n ; i++) {
        if(arr[i] != temp) {
            if(temp_count > mode_count) {
                mode = temp;
                mode_count = temp_count;
            }
            temp = arr[i];
            temp_count = 1;
        } else {
            temp_count++;
        }
    }
    
    // now print the results
    cout<<mean<<endl<<median<<endl<<mode;
    return 0;
}


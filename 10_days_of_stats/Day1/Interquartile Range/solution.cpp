#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int find_quartile(int n, int start, int end, int obs[], int cumm_freq[], int &st) {
    int q=0;
    int length = (end-start+1);
    for(int i=st ; i<n ; i++) {
        st = i;
        if(cumm_freq[i] >= start+(length+1)/2) {
            q+=obs[i];
            if(length%2 == 0) {
                if(cumm_freq[i] == start+(length+1)/2) {
                    q+=obs[i+1];
                } else {
                    q+=obs[i];
                }
            q/=2;
            }
            break;
        }
    }
    return q;
}

void swap(int arr[], int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort(int arr[], int n, int freq[]) {
    for(int i=n-1 ; i>=1 ; i--) {
        for(int j=0 ; j<i; j++) {
            if(arr[j]>arr[j+1]){
                swap(arr,j,j+1);
                swap(freq,j,j+1);
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int obs[n];
    int freq[n];
    int cumm_freq[n];
    for(int i=0 ; i<n ; i++) {
        cin>>obs[i];
    }
    for(int i=0 ; i<n ; i++) {
        cin>>freq[i];
    }
    sort(obs,n,freq);
    cumm_freq[0] = freq[0];
    for(int i=1 ; i<n ; i++) {
        cumm_freq[i] = cumm_freq[i-1]+freq[i];
    }
    int q1, q3, start = 0;
    // will work for both even and odd number of data points
    q1 = find_quartile(n,0,cumm_freq[n-1]/2-1,obs,cumm_freq,start);
    q3 = find_quartile(n,(cumm_freq[n-1]+1)/2,cumm_freq[n-1]-1,obs,cumm_freq,start);
    cout<<setprecision(1)<<std::fixed<<float(q3-q1);
    return 0;
}


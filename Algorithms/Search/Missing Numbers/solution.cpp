/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include<iostream>

using namespace std;

#define MAX 10001

int main() {
	int n, m;
	int A[MAX] = {};
	cin>>n;
	for(int i=0 ; i<n ; i++) {
		int value;
		cin>>value;
		A[value-1]--;
	}	
	cin>>m;
	for(int i=0 ; i<m ; i++) {
		int value;
		cin>>value;
		A[value-1]++;
	}
	
	for(int i=0 ; i<MAX ; i++) {
		if(A[i]>0) {
			cout<<i+1<<" ";
		}
	}
	return 0;
}


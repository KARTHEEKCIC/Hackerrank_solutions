/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include<iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	int A[n];
	for(int i=0 ; i<n ; i++) {
		cin>>A[i];
	}
	int max = A[0]; 
	for(int i=0; i<n ; i++) {
		if(A[i]>max) {
			max = A[i];
		}
	}

	int count = 0;
	for( int i=0; i <n ; i++) {
		if(max == A[i]) {
			count++;
		}
	}
	
	cout<<count;
	return 0;
}

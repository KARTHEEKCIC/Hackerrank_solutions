/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include<iostream>

using namespace std;

int InsertionSort(int n, int arr[]) {
	int t;
	int count = 0;
	for(int i=1 ; i<n ; i++) {
		if(arr[i]<arr[i-1]) {
			for(int j=i ; j>=0 && arr[j]<arr[j-1] ; j--) {
				t = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = t;	
				count++;
			}
		}
	}
	return count;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i<n ; i++) {
		cin>>arr[i];
	}
	cout<<InsertionSort(n,arr);
	return 0;
}


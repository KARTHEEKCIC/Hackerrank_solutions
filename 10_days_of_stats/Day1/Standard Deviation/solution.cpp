#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	int n;
	cin>>n;
	long arr[n];
	float mean = 0;
	for(int i=0; i<n ; i++) {
		cin>>arr[i];
		mean+=arr[i];
	}
	mean/=n;
	// find the standard deviation
	float sd = 0;
	for(int i=0 ; i<n ; i++) {
		sd+=(arr[i]-mean)*(arr[i]-mean);
	}
	sd/=n;
	sd = sqrt(sd);
	cout<<setprecision(1)<<fixed<<sd;
	return 0;
}

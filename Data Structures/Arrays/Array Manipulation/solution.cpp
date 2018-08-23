#include<iostream>

using namespace std;

typedef long long LL;

int main() {

	LL n, m;
	cin>>n>>m;
	LL arr[n] = {};
	LL max = 0;
	for(LL i=0 ; i<m ; i++) {
		LL a,b,k;
		cin>>a>>b>>k;
		for(LL j=a-1 ; j<b ; j++) {
			arr[j]+=k;
			if(arr[j]>max) {
				max = arr[j];
			}
		}
	}
	cout<<max;
	return 0;
}

/**
    @Author B Kartheek Reddy
    @Hackerrank hackerrank.com/KARTHEEK04
 **/

#include<iostream>

using namespace std;

int main() {
	int q;
	cin>>q;
	char Arr[10000];
	char Arr1[] = "hackerrank";
	bool status[q];
	for(int i=0; i<q ; i++) {
		int j = 0;
		cin>>Arr;
		status[i] = 0;
		for(int k=0 ; Arr[k]!='\0' ; k++) {
			if(Arr[k] == Arr1[j]) {
				j++;
				if(j == 10) {
					status[i] = 1;
					break;
				}
			}
		}
	}

	for(int i=0 ; i<q ; i++) {
		if(status[i] == 1) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

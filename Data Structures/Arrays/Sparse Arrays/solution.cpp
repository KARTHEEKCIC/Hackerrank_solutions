#include "iostream"
#include "cstring"

using namespace std;

int main() {
	int n;
	cin>>n;
	char S[n][20];
	for(int i=0 ; i<n ; i++) {
		cin>>S[i];
	}
	int q;
	int count = 0;
	cin>>q;
	for(int j=0 ; j<q ; j++) {
		char str[20];
		cin>>str;
		count = 0;
		for(int i=0 ; i<n ; i++) {
			if(strcmp(str,S[i]) == 0) {
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
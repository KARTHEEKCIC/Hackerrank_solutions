#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int fact(int x) {
	if(x == 0) {
		return 1;
	}
	return x-- * fact(x);
}

int main() {
	// Probability of child being a boy = 1.09/1+1.09 = 1.09/2.09.
	// Let us assume having a boy is a success.
	// We need to find P(x>=3) and n=6.

	// Initialize the variables
	int n = 6;
	double ps = 1.09/2.09, qs = 1-ps;
	
	// So P(x>=3) = 1-P(x<=2)
	double p = 0;
	for(int i=0 ; i<=2 ; i++) {
		p+=(fact(n)/(fact(i)*fact(n-i)))*pow(ps,i)*pow(qs,n-i);
	}
	p=1-p;
	cout<<fixed<<setprecision(3)<<p;
	return 0;
}

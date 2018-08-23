#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int fact(int x) {
	if(x == 0) {
		return 1;
	}
	return x--*fact(x);
}

int main() {
	// Size of the batch pistons is 10.
	// 12 % of the pistons are diffective.
	// Defective piston denotes success.
	int n=10;
	float ps=0.12, p=0;
	for(int i=0 ; i<=2 ; i++) {
		p+=(fact(n)/(fact(n-i)*fact(i)))*pow(ps,i)*pow(1-ps,n-i);
	}
	float p1 = (1-p) + (fact(n)/(fact(n-2)*fact(2)))*pow(ps,2)*pow(1-ps,n-2);
	cout<<fixed<<setprecision(3)<<p<<endl;
	cout<<fixed<<setprecision(3)<<p1<<endl;
	return 0;
}	

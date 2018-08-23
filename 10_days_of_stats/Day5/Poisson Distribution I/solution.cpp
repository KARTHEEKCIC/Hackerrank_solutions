#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int fact(int x) {
	if(x == 0) 
		return 1;
	return x--*fact(x);
}

int main() {
	// Average value = 2.5
	// Number of success = 5
	float lambda=2.5;
	int k=5;
	float p = pow(lambda,k)*exp(-1*lambda)/fact(k);
	cout<<fixed<<setprecision(3)<<p<<endl;
	return 0;
}


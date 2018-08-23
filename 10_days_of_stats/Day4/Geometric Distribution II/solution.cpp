#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	// Probability of getting a defect is 1/3
	// No of trials is 5
	int n=5;
	float ps=1.0/3, p=0;
	for(int i=1 ; i<=n ; i++) {
		p+=pow(1-ps,i-1)*ps;
	}
	cout<<fixed<<setprecision(3)<<p<<endl;
	return 0;
}


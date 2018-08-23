#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	// Mean for machine A = 0.88
	// Mean for machine B = 1.55
	float lambda1=0.88, lambda2=1.55;
	float costA, costB;
	costA = 160+40*(lambda1+pow(lambda1,2));
	costB = 128+40*(lambda2+pow(lambda2,2));
	cout<<fixed<<setprecision(3)<<costA<<endl;
	cout<<fixed<<setprecision(3)<<costB<<endl;
	return 0;
}


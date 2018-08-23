#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
	
int main() {
	double mean=500, sd=80, z=1.96;
	int n=100;
	// We need to find the 95 % confidence interval of mean
	double ans1 = z*sd/sqrt(n) + mean;
	double ans2 = -1*z*sd/sqrt(n) + mean;
	cout<<fixed<<setprecision(2)<<ans2<<endl;
	cout<<fixed<<setprecision(2)<<ans1<<endl;
	return 0;
}




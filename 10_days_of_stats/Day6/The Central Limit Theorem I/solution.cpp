#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// source: https://stackoverflow.com/questions/457408/is-there-an-easily-available-implementation-of-erf-for-python
// For calculating cummulative probability.
// Error is less than 1.5*10^-7.
double erf(double x) {
	// Using Horner's method
	
	// Defining constants
	double a1 =  0.254829592;
    double a2 = -0.284496736;
   	double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;
	
	// Saving the sign of the input
	int sign = 1;
	if(x<0) {
		sign = -1; 
	}
	x = abs(x);

	double t = 1.0/(1.0 + p*x);
	double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);
	return sign*y; // as erf(-x) = -erf(x)
}

// This function provides cummulative probability 
// P(X<x) given x>0 for a normal distribution.
double Normal_probab(double x, double mean, double sd) {
	return 1.0/2*(1+erf((x-mean)/(sd*sqrt(2))));
}
	
int main() {
	double mean=205, sd=15, max_weight = 9800;
	int n=49;
	double ans = Normal_probab(max_weight,n*mean,sqrt(n)*sd);
	cout<<fixed<<setprecision(4)<<ans<<endl;
	return 0;
}



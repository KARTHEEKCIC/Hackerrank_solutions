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
	double ans1, ans2;
	double mean=20, sd=2;
	
	// Part 1
	// We need to find the probability that 
	// car can be assembled in less than 19.5 hours
	double t=19.5; 
	ans1 = Normal_probab(t,mean,sd);
	
	// Part 2
	// We need to find the probability that
	// car can ve assembled in between 20 and 22 hours
	double t1=20, t2=22;
	ans2 = Normal_probab(t2,mean,sd) - Normal_probab(t1,mean,sd);
	cout<<fixed<<setprecision(3)<<ans1<<endl;
	cout<<fixed<<setprecision(3)<<ans2<<endl; 
	return 0;
}


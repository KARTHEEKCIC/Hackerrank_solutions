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
	double ans1, ans2, ans3;
	double mean=70, sd=10;
	
	double g1=80, g2=60;
	// Part 1
	// P(percentage of students having grades > 80) 
	ans1 = (1 - Normal_probab(g1,mean,sd))*100;
	
	// Part 2
	// P(percentage of students having grades >= 60)
	ans2 = (1 - Normal_probab(g2,mean,sd))*100;

	// Part 3
	// P(percentage of students having grades < 60)
	ans3 = Normal_probab(g2,mean,sd)*100;

	cout<<fixed<<setprecision(2)<<ans1<<endl;
	cout<<fixed<<setprecision(2)<<ans2<<endl; 
	cout<<fixed<<setprecision(2)<<ans3<<endl;
	return 0;
}


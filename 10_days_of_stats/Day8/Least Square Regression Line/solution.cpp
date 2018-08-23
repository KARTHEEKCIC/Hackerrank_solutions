#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double pearson_coeff(double meanX, double meanY, double varX, double varY, double X[], double Y[], int n) {
	// Calculating pearson correlation coefficient
	double coeff=0;
	for(int i=0 ; i<n ; i++) {
		coeff+=(X[i]-meanX)*(Y[i]-meanY)/(n*sqrt(varX)*sqrt(varY));
	}
	return coeff;
}

int main() {
	int n=5;

	double X[n], Y[n], meanX=0, meanY=0;

	// Taking input and calculating mean simultaneously.
	for(int i=0 ; i<n ; i++) {
		cin>>X[i]>>Y[i];
		meanX+=X[i];
		meanY+=Y[i];
	}
	meanX/=n;
	meanY/=n;

	// Calculating variance of X and Y
	double varX=0, varY=0;
	for(int i=0 ; i<n ; i++) {
		varX+=pow(X[i]-meanX,2);
		varY+=pow(Y[i]-meanY,2);
	}
	varX/=n;
	varY/=n;

	double p_coeff = pearson_coeff(meanX,meanY,varX,varY,X,Y,n);
	
	double b = p_coeff*sqrt(varY)/sqrt(varX);
	double a = meanY - b*meanX;

	// We need to find the grades of stats when grades in maths are 80
	double x = 80;
	double y = a + b*x;
	cout<<fixed<<setprecision(3)<<y<<endl;

	return 0;
}

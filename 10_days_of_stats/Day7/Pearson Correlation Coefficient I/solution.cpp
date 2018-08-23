#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin>>n;
	double X[n], Y[n], meanX=0, meanY=0;

	// Taking input and calculating mean simultaneously.
	for(int i=0 ; i<n ; i++) {
		cin>>X[i];
		meanX+=X[i];
	}
	meanX/=n;
	for(int i=0 ; i<n ; i++) {
		cin>>Y[i];
		meanY+=Y[i];
	}
	meanY/=n;

	// Calculating variance of X and Y
	double varX=0, varY=0;
	for(int i=0 ; i<n ; i++) {
		varX+=pow(X[i]-meanX,2);
		varY+=pow(Y[i]-meanY,2);
	}
	varX/=n;
	varY/=n;

	// Calculating pearson correlation coefficient
	double coeff=0;
	for(int i=0 ; i<n ; i++) {
		coeff+=(X[i]-meanX)*(Y[i]-meanY)/(n*sqrt(varX)*sqrt(varY));
	}
	cout<<fixed<<setprecision(3)<<coeff<<endl;
	return 0;
}

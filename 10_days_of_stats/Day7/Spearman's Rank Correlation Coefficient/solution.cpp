#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct Data {
	double X, Y;
	int rX, rY;
};

bool X_comp(Data d1, Data d2) {
	return d1.X<d2.X;
}

bool Y_comp(Data d1, Data d2) {
	return d1.Y<d2.Y;
}

int main() {
	int n;
	cin>>n;
	Data d[n];
	for(int i=0 ; i<n ; i++) {
		cin>>d[i].X;
		d[i].rX=0;
	}
	for(int i=0 ; i<n ; i++) {
		cin>>d[i].Y;
		d[i].rY=0;
	}
	
	sort(d,d+n,X_comp);

	for(int i=0 ; i<n ; i++) {
		d[i].rX = i+1;
	}
	
	sort(d,d+n,Y_comp);

	for(int i=0 ; i<n ; i++) {
		d[i].rY = i+1;
	}

	double sp_rank=0;

	for(int i=0 ; i<n ; i++) {
		sp_rank+=pow(d[i].rX-d[i].rY,2);
	}
	
	sp_rank = 1-(6*sp_rank/((n)*(pow(n,2)-1)));
	cout<<fixed<<setprecision(3)<<sp_rank<<endl;
	return 0;
}

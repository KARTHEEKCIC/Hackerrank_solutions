#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector< vector<double> > matrix;

// Function to transpose the given matrix 
matrix transpose(matrix &mat, int r, int c) {
	matrix tmat;
	for(int i=0 ; i<c ; i++) {
		vector<double> temp;
		for(int j=0 ; j<r ; j++) {
			temp.push_back(mat[j][i]);
		}
		tmat.push_back(temp);
	}
	return tmat;
}



// Function to calculate the cofactor of the given element of the square matrix
// Note the input matrix is transformed into the cofactor. So input matrix will be changed.
void get_cofactor(matrix &temp, int r, int c, int n) {
	temp.erase(temp.begin()+r);
	for(int i=0 ; i<n-1 ; i++) {
		temp[i].erase(temp[i].begin()+c);
	}
}

// Function to calculate the determinant of the given square matrix
double det(matrix &mat, int n) {
	if(n == 1) {
		return mat[0][0];
	}
	double sum = 0;
	int sign = -1;
	matrix temp;
	for(int i=0 ; i<n ; i++) {
		temp = mat;
		get_cofactor(temp,0,i,n);
		sum+=pow(-1,0+i)*mat[0][i]*det(temp,n-1);
	}
	return sum;
}

// Function to find the adjoint of the given matrix
matrix adj(matrix mat, int n) {
	matrix temp;
	matrix result;
	int sign = -1;
	for(int i=0 ; i<n ; i++) {
		std::vector<double> container;
		for(int j=0 ; j<n ; j++) {
			temp = mat;
			get_cofactor(temp,i,j,n);
			container.push_back(pow(sign,i+j)*det(temp,n-1));
		}
		result.push_back(container);
	}
	return transpose(result,n,n);
}

// Function to calculate the product of two matrix
matrix mat_mul(matrix &A, matrix &B, int r, int c, int c1) {
	matrix C;
	double sum=0;
	for(int i=0 ; i<r ; i++) {
		vector<double> temp;
		for(int k=0 ; k<c1 ; k++) {
			sum=0;
			for(int j=0 ; j<c ; j++) {
				sum+=A[i][j]*B[j][k];
			}
			temp.push_back(sum);
		}
		C.push_back(temp);
	}
	cout<<"end"<<endl;
	return C;
}

// Function to calculate the inverse of square matrix
matrix inv(matrix A, int n) {
	cout<<"entered"<<endl;
	double determinant = det(A,n);
	cout<<"entered"<<endl;
	A = adj(A,n);
	cout<<"entered"<<endl;
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			A[i][j] = A[i][j]/determinant;
		}
	}
	return A;
}

// An efficient and simple algorithm for matrix inversion
// Source: http://www.irma-international.org/viewtitle/41011/

// Step 1: Let p = 0, d = 1;
// Step 2: p<-p+1
// Step 3:	If a[p][p]==0 then cannot calculate inverse, go to step 10.
// Step 4: 	d = d*a[p][p]
// Step 5: Calculate the new elements of the pivot row by: 
//			a[p][j] = a[p][j]/a[p][p] for j = 1..n and j!=p
// Step 6: Calculate the new elements of the pivot column by: 
//			a[i][p] = -a[i][p]/a[p][p] for i = 1..n and i!=p
// Step 7: Calculate the rest of the new elements by: 
//			a[i][j] = a[i][j]+a[p][j]*a[i][p] for i=1...n and j=1..n and i,j!=p
// Step 8: Calculate the new value of the current pivot location: 
//			a[p][p] = 1/a[p][p]
// Step 9: If p < n  go to step 2 (n the dimension of the matrix A).
// Step 10: Stop. If inverse exists- A contains the inverse and d is the determinant.
double inverse(matrix &mat, int n) {
	int p=0;
	double d=1.0, pivot;
	while(p<n) {
		pivot = mat[p][p];
		d = d*pivot;
		if (fabs(pivot) < 1e-5)	return 0;
		for(int i=0 ; i<n ; i++) {
			if(i!=p) {
				mat[p][i] = mat[p][i]/pivot;
				mat[i][p] = -1*mat[i][p]/pivot;
			}
		}
		for(int i=0 ; i<n ; i++) {
			if(i!=p) {
				for(int j=0 ; j<n ; j++) {
					if(j!=p) {
						mat[i][j] = mat[i][j] + mat[p][j]*mat[i][p];
					}
				}
			}
		}
		mat[p][p] = 1/pivot;
		p++;
	}
	return d;
}

inverser(matrix mat, int n) {
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			mat[i][j]
		}
	}
}

int main() {
	int n;
	cin>>n;
	matrix x;
	double input;
	for(int i=0 ; i<n ; i++) {
		vector<double> temp;
		for(int j=0 ; j<n ; j++) {
			cin>>input;
			temp.push_back(input);
		}
		x.push_back(temp);
	}
	// // Taking input from the user
	// int m, n;
	// cin>>m>>n;
	// matrix train_features;
	// double input;
	// // cout<<"Enter the inputt"<<endl;
	// for(int i=0 ; i<n ; i++) {
	// 	vector<double> inp;
	// 	for(int j=0 ; j<m+1 ; j++) {
	// 		if(j==0) {
	// 			inp.push_back(1);
	// 		}
	// 		cin>>input;
	// 		inp.push_back(input);
	// 	}
	// 	train_features.push_back(inp);
	// }
	// int q;
	// cin>>q;
	// matrix test_features;
	// for(int i=0 ; i<q ; i++) {
	// 	vector<double> inp;	
	// 	for(int j=0 ; j<m ; j++) {
	// 		if(j==0) {
	// 			inp.push_back(1);
	// 		}
	// 		cin>>input;
	// 		inp.push_back(input);
	// 	}
	// 	test_features.push_back(inp);
	// }

	// cout<<"Now starting calculation"<<endl;

	// // Data preprocessing
	// // Seperating the output y and features from the train_features matrix
	// matrix Y;
	// for(int i=0 ; i<n ; i++) {
	// 	vector<double> temp;
	// 	temp.push_back(train_features[i][m+1]);
	// 	Y.push_back(temp);
	// }
	// cout<<"test"<<endl;
	// // So as result is B=(X'X)^-1*X'Y.
	// matrix train_features_transpose = transpose(train_features,n,m+1);
	// cout<<"test"<<endl;
	// matrix out1 = mat_mul(train_features_transpose,train_features,m+1,n,m+1); //X'X
	// inverse(out1,m+1); //(X'X)^-1 
	// cout<<"test"<<endl;
	// matrix out2 = mat_mul(train_features_transpose,Y,m+1,n,1); // X'Y
	// matrix B = mat_mul(out1,out2,m+1,m+1,1); // We have got the final values of the constants or parameters

	// // Now let us test the data
	// matrix result = mat_mul(test_features,B,q,m+1,1);

	// cout<<"B"<<endl;
	// for(int i=0 ; i<m+1 ; i++) {
	// 	cout<<B[i][0]<<endl;
	// }
	// cout<<"end"<<endl;

	// // Printing out the result
	// for(int i=0 ; i<q ; i++) {
	// 	cout<<result[i][0]<<endl;
	// }

	// matrix X = adj(train_features,n);

	double d=inverse(x,n);
	cout<<d<<endl;
	// x = inv(x,n);
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

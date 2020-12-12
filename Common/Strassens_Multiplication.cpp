#include <iostream>
using namespace std;

// Fucntion to initialize 2-D Array
int** initialize(int n) {
    int** temp = new int*[n];
    for(int i=0; i<n; i++)
        temp[i] = new int[n];
    return temp;
}

// Function to add two 2-D Arrays
int** add(int **A, int **B, int N) {
	int **C = initialize(N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) C[i][j] = A[i][j] + B[i][j];
	}
	return C;
};

// Function to Subtract two 2-D Arrays
int** subtract(int **A, int **B, int N) {
	int **C = initialize(N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) C[i][j] = A[i][j] - B[i][j];
	}
	return C;
};

// Function to multiply two 2-D Arrays
int** multiply(int **A, int **B, int N) {
	int **C = initialize(N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			C[i][j] = 0;
			for(int k=0; k<N; k++) C[i][j] += A[i][k] * B[k][j];
		}
	}
	return C;
};

// Strassen's Multiplication
int** strassen(int *A[], int *B[], int N) {
	int **C = initialize(N);
	if(N == 1) {
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	else {
		int z = N/2;
		int **a = initialize(z);
		int **b = initialize(z);
		int **c = initialize(z);
		int **d = initialize(z);
		int **e = initialize(z);
		int **f = initialize(z);
		int **g = initialize(z);
		int **h = initialize(z);

		// Submatrices
		for(int i=0; i<z; i++) {
			for(int j=0; j<z; j++) {
				a[i][j] = A[i][j];
				b[i][j] = A[i][z + j];
				c[i][j] = A[z + i][j];
				d[i][j] = A[z + i][z + j];

				e[i][j] = B[i][j];
				f[i][j] = B[i][z + j];
				g[i][j] = B[z + i][j];
				h[i][j] = B[z + i][z + j];
			}
		}

		// Applying Strassen's Formula
		int **p0 = multiply(a, subtract(f, h, z), z);
		int **p1 = multiply(add(a, b, z), h, z);
		int **p2 = multiply(add(c, d, z), e, z);
		int **p3 = multiply(d, subtract(g, e, z), z);
		int **p4 = multiply(add(a, d, z), add(e, h, z), z);
		int **p5 = multiply(subtract(b, d, z), add(g, h, z), z);
		int **p6 = multiply(subtract(a, c, z), add(e, f, z), z);

		// Find sub-matrix C
		int **c11 = subtract(add(add(p3, p4, z), p5, z), p1, z);
		int **c12 = add(p0, p1, z);
		int **c21 = add(p2, p3, z);
		int **c22 = subtract(add(p0, p4, z), add(p2, p6, z), z);

		// Combine into C
		for(int i=0; i<z; i++) {
			for(int j=0; j<z; j++) {
				C[i][j] = c11[i][j];
				C[i][z + j] = c12[i][j];
				C[z + i][j] = c21[i][j];
				C[z + i][z + j] = c22[i][j];
			}
		}
		return C;
	}
};

int main() {

	// For a 2x2 matrix
	// int A[2][2], B[2][2], C[2][2], p[7];
	// cout<<"\nEnter the elements in A : ";
  	// for(int i=0; i<2; i++) {
	// 	cin>>A[i][0]>>A[i][1];
  	// }

	// cout<<"\nEnter the elements in B : ";
	// for(int i=0; i<2; i++) {
	// 	cin>>B[i][0]>>B[i][1];
	// }

	// p[0] = A[0][0] * (B[0][1] - B[1][1]);
	// p[1] = (A[0][0] + A[0][1]) * B[1][1];
	// p[2] = (A[1][0] + A[1][1]) * B[0][0];
	// p[3] = A[1][1] * (B[1][0] - B[0][0]);
	// p[4] = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
	// p[5] = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
	// p[6] = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

	// C[0][0] = p[4] + p[3] - p[1] + p[5];
	// C[0][1] = p[0] + p[1];
	// C[1][0] = p[2] + p[3];
	// C[1][1] = p[0] + p[4] - p[2] - p[6];

	// cout<<"\nThe Resultant matrix C is : \n";
	// for(int i=0; i<2; i++) {
	// 	cout<<C[i][0]<<" "<<C[i][1]<<endl;
	// }

	// For a general matrix 
	int N;
	cout<<"Enter the order of matrix : ";
	cin>>N;
	int **A = initialize(N);
	int **B = initialize(N);
	int **C = initialize(N);
  
	cout<<"\nEnter the elements in A : ";
  	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>A[i][j];
  	}

	cout<<"\nEnter the elements in B : ";
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>B[i][j];
	}

	C = strassen(A, B, N);
	cout<<"\nResultant Matrix is \n";
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cout<<C[i][j]<<" ";
		cout<<endl;
	}
}

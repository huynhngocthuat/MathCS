
#include <iostream>
#include <math.h>
using namespace std;
#define SIZE 100
void matrix_in(float matrix[][SIZE], int n)
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << "matrix[" << i << "][" << j << "] = ";
      cin >> matrix[i][j];
    }
  }
}
void matrix_out(float matrix[][SIZE], int n)
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j <n; j++){
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void eigenValues(float matrix[][SIZE], float eigenValueMatrix[][SIZE], int n) {
  float b = -matrix[0][0] + -matrix[1][1];
  float c = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  float delta = b*b - 4*c;
  eigenValueMatrix[0][0] = (-b + sqrt(delta))/2;
  eigenValueMatrix[0][1] = (-b - sqrt(delta))/2;
}

void eigenVectors(float matrix[][SIZE], float eigenValueMatrix[][SIZE], float eigenVector_1[][SIZE], float eigenVector_2[][SIZE], int n) {
  float transferMatrix[SIZE][SIZE];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) { 
      for(int k = 0; k < n; k++) {
        if(j == k) {
          transferMatrix[j][j] = matrix[j][j] - eigenValueMatrix[0][i];
        }
        else transferMatrix[j][k] = matrix[j][k];
      }
    }

    if(i == 0) {
      eigenVector_1[0][0] = 1;
      eigenVector_1[1][0] = (transferMatrix[1][0] * (transferMatrix[0][1] - 1)) / transferMatrix[1][1] - transferMatrix[0][0];
    }
    else {
      eigenVector_2[0][0] = 1;
      eigenVector_2[1][0] = (transferMatrix[1][0] * (transferMatrix[0][1] - 1)) / transferMatrix[1][1] - transferMatrix[0][0];
    }
  }
}

void matrixQ(float matrix_V[][SIZE], float eigenVector_1[][SIZE], float eigenVector_2[][SIZE], int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(j == 0) {
        matrix_V[i][j] = eigenVector_1[i][0];
      }
      else matrix_V[i][j] = eigenVector_2[i][0];
    }
  }
}

void diagonal(float matrixDiagonal[][SIZE], float eigenValueMatrix[][SIZE], int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) {
        matrixDiagonal[i][j] = eigenValueMatrix[0][i];
      }
      else matrixDiagonal[i][j] = 0;
    }
  }
}

void transpose(float matrix[][SIZE], int n) {
  float b[100][100];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      b[i][j] = matrix[i][j];
    }
  }
  for(int i = 0; i < n-1; i++) {
    for(int j = i + 1; j < n; j++) {
      float t = b[i][j];
      b[i][j] = b[j][i];
      b[j][i] = t;
    }
  }
  matrix_out(b,n);
}

int main() {
  float matrix[SIZE][SIZE], eigenValueMatrix[SIZE][SIZE], eigenVector_1[SIZE][SIZE], eigenVector_2[SIZE][SIZE], matrix_Q[SIZE][SIZE], matrixDiagonal[SIZE][SIZE];
  int n;
  cout<<"nhap n: ";
  cin>>n;
  matrix_in(matrix, n);
  matrix_out(matrix, n);
  eigenValues(matrix, eigenValueMatrix, 2);
  cout << "Value-1: " << eigenValueMatrix[0][0] << endl;
  cout << "Value-2: " << eigenValueMatrix[0][1] << endl;
  eigenVectors(matrix, eigenValueMatrix, eigenVector_1, eigenVector_2, n);
  cout << "Eigen Vector 1: ";
  for(int i = 0; i < n; i++){
      cout << eigenVector_1[i][0] << "\t";
  }
  cout << endl << "Eigen Vector 2: ";
  for(int i = 0; i < n; i++){
      cout << eigenVector_2[i][0] << "\t";
  }
  cout << endl <<  << endl"Matrix Q:" << endl;
  matrixQ(matrix_Q, eigenVector_1, eigenVector_2, n);
  matrix_out(matrix_Q, n);
  cout << "Matrix diagonal:" << endl;
  diagonal(matrixDiagonal, eigenValueMatrix, n);
  matrix_out(matrixDiagonal, n);
  cout<<"Matrix Q^T: " << endl;
  transpose(matrix_Q, n);
}
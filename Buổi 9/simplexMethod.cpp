#include <iostream>
using namespace std;

bool checkDK(float A[][100], float B[], float C[], int colA, int rowA, float delta[], int x[]) {
  int flag = 1;
  for(int i = 0; i < colA; i++) {
      if(delta[i] > 0) {
        flag = 0;
        for(int j = 0; j < rowA; j++) {
          if(A[j][i] > 0) {
            flag = 0;
            break;
          }
        }
      }
    }
    if(flag == 1) {
      float fmin = 0;
      for(int i = 0; i < rowA; i++) {
        fmin += B[i]*C[x[i]];
      }
      cout<<"fmin: "<<fmin<<endl;
      float heso[colA];
      for(int i = 0; i < colA; i++) {
        heso[i] = 0;
      }
      cout<<"Nghiệm tìm được: ";
      for(int i = 0; i < rowA; i++) {
        heso[x[i]] = B[i];
      }
      for(int i = 0; i < colA; i++) {
        cout << heso[i] << " ";
      }
      return false;
    }
    return true;
}

void changeMatrixA(float Aold[][100], float B[], int row, int col, int colA, int rowA, float delta[], int x[]) {
  float Anew[rowA][colA];
  for(int i = 0; i < rowA; i++) {
    for(int j = 0; j < colA; j++) {
      if(i == row) {
        Anew[row][j] = Aold[i][j] / Aold[row][col];
      }
      else {
        Anew[i][j] = Aold[i][j] - ((Aold[row][j] * Aold[i][col]) / Aold[row][col]);
      }
    } 
  }
  float Bnew[rowA];
  for(int i = 0; i < rowA; i++) {
    if(i == row) {
      Bnew[i] = B[row] / Aold[row][col];
    }
    else {
      Bnew[i] = B[i] - (B[row] * Aold[i][col] / Aold[row][col]);
    }
  }

  for(int i = 0; i < rowA; i++) {
    B[i] = Bnew[i];
  }

  for(int i = 0; i < rowA; i++) {
    for(int j = 0; j < colA; j++) {
      Aold[i][j] = Anew[i][j];
    }
  }
}

void findAnCB(float A[][100], int colA, int rowSizeA, float delta[], int X[], float B[]) {

  int indexMax = -1;
  float max = 0;
  for(int i = 0; i < colA; i++) {
    if(max < delta[i]) {
      max = delta[i];
      indexMax = i;
    }
  }

  int indexMin = -1;
  float min = 100;
  for(int i = 0; i < rowSizeA; i++) {
    if(A[i][indexMax] > 0 && min > (B[i] / A[i][indexMax])) {
      min = B[i] / A[i][indexMax];
      indexMin = i;
    }
  }

  X[indexMin] =  indexMax;
  changeMatrixA( A, B, indexMin, indexMax, colA, rowSizeA, delta, X);
}


int main() {

  int colA=4;  
  int rowA = 2; 

  float C[]= {-5, -8, 0, 0};  
  float B[]={1, 2}; 
  float A[][100] = {  
    { 1, 2, 1, 0},
    { 1, 1, 0, 1},
  };

  int x[] = {2, 3};
       
  int loop = 1;
  while(true) {
    cout << endl;
    cout << "   **Bảng số** "<< loop++ << endl;
    float delta[colA + 1];
    for(int i = 0; i < colA; i++) {
      delta[i] = -C[i];
      for(int j = 0; j < rowA; j++) {
        delta[i] += A[j][i] * C[(x[j])];
      }
    }
    cout<<"Delta: ";
    for(int i = 0; i < colA; i++) {
      cout << delta[i] << "  ";
    }

    cout << endl;
    cout << "Hệ số của ẩn cơ bản: " << endl;
    for(int i = 0; i < rowA; i++) {
      cout <<"\tx" << x[i]+1 << " = " << C[x[i]] << endl;
    }

    cout<<"Phương án tối ưu: "<<endl;
    for(int i = 0; i < rowA; i++) {
      cout << "\t" << B[i] << endl;
    }

    cout<<"Ma trận có được: "<<endl;
    for(int i = 0; i < rowA; i++) {
      cout << "\t";
      for(int j = 0; j < colA; j++) {
        cout << A[i][j] << " ";
      }
      cout<<endl;
    } 

    if(!checkDK(A, B, C, colA, rowA, delta, x)){break;};
    findAnCB(A, colA, rowA, delta, x, B);
  }
}
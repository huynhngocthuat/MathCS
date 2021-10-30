
// #include <iostream>
// #include<math.h>
// using namespace std;
// #define SIZE 100
// void matrix_in(int matrix[][SIZE], int n)
// {
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < n; j++){
//       cout << "matrix[" << i << "][" << j << "] = ";
//       cin >> matrix[i][j];
//     }
//   }
// }
// void matrix_out(int matrix[][SIZE], int n)
// {
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < n; j++){
//       cout << matrix[i][j] << "  ";
//     }
//     cout << endl;
//   }
// }

// int d = 0;
// int determinant(int matrix[][SIZE], int n) // Công thức laplace
// {
//     int subi, subj;
//     int submatrix[SIZE][SIZE];  
//     if (n == 2) 
//     {
//         return( (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
//     }
//     else
//     {  
//         for(int c = 0; c < n; c++)
//         {  
//             subi = 0;  
//             for(int i = 1; i < n; i++)
//             {  
//                 subj = 0;
//                 for(int j = 0; j < n; j++)
//                 {    
//                     if (j == c)
//                     {
//                         continue;
//                     }
//                     submatrix[subi][subj] = matrix[i][j];
//                     subj++;
//                 }
//                 subi++;
//             }
//         d = d + (pow(-1 ,c) * matrix[0][c] * determinant(submatrix, n -1));
//         }
//     }
    
//     return d;
// }

// int main()
// {
//   int n;
//   int matrix[SIZE][SIZE];
//   float inv[SIZE][SIZE];
//   cout << "Nhập n = ";
//   cin >> n;
//   matrix_in(matrix, n);
//   matrix_out(matrix, n);
//   cout << determinant(matrix, n);
//   return 0;
// }
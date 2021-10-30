// #include <iostream>
// #include<math.h>
// using namespace std;
// #define SIZE 100
// float ratio;
// void matrix_in(float matrix[][SIZE], int n)
// {
//   for(int i = 1; i <= n; i++){
//     for(int j = 1; j <= n; j++){
//       cout << "matrix[" << i << "][" << j << "] = ";
//       cin >> matrix[i][j];
//     }
//   }
// }
// void matrix_out(float matrix[][SIZE], int n)
// {
//   for(int i = 1; i <= n; i++){
//     for(int j = 1; j <=n; j++){
//       cout << matrix[i][j] << "\t";
//     }
//     cout << endl;
//   }
// }
// void inverse(float inv[][SIZE], int n)
// {
//   for(int i=1;i<=n;i++)
// 		 {
// 			  for(int j=1;j<=n;j++)
// 			  {
// 				   if(i==j)
// 				   {
// 				    	inv[i][j+n] = 1;
// 				   }
// 				   else
// 				   {
// 				    	inv[i][j+n] = 0;
// 				   }
// 			  }
// 		 }

// 		 for(int i=1;i<=n;i++)
// 		 {
// 			  if(inv[i][i] == 0.0)
// 			  {
// 				   cout<<"Mathematical Error!";
// 				   exit(0);
// 			  }
// 			  for(int j=1;j<=n;j++)
// 			  {
// 				   if(i!=j)
// 				   {
// 					    ratio = inv[j][i]/inv[i][i];
// 					    for(int k=1;k<=2*n;k++)
// 					    {
// 					     	inv[j][k] = inv[j][k] - ratio*inv[i][k];
// 					    }
// 				   }
// 			  }
// 		 }
// 		 for(int i=1;i<=n;i++)
// 		 {
// 			  for(int j=n+1;j<=2*n;j++)
// 			  {
// 			   	inv[i][j] = inv[i][j]/inv[i][i];
// 			  }
// 		 }
//   cout << "Inverse matrix : " << endl;
//   for(int i = 1; i <= n; i++){
//     for(int j = n+1; j <= 2*n; j++){
//       cout << inv[i][j] << "\t";
//     }
//     cout << endl;
//   }   
// }

// int main()
// {
//   int n;
//   float matrix[SIZE][SIZE];
//   cout << "Nhập n = ";
//   cin >> n;
//   matrix_in(matrix, n);
//   cout << "Matrix : " << endl;
//   matrix_out(matrix, n);
//   inverse(matrix, n);
//   return 0;
// }
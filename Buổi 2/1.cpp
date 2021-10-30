// #include <iostream>
// using namespace std;

// int dongdu(int a, int m, int n)
// {
//   if(m==0){
//     return 1;
//   }
//   if(m%2==0){
//     return dongdu(a, m/2, n)*dongdu(a, m/2, n);
//   }else {
//     return a*dongdu(a, m-1, n)%n;
//   }
// }
// int main()
// {
//   int a,m,n;
//   cout << "Nhap a = ";
//   cin >> a;
//   cout << "Nhap m = ";
//   cin >> m;
//   cout << "Nhap n = ";
//   cin >> n;
//   cout << dongdu(a, m, n);
//   return 0;
// }
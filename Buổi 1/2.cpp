#include<iostream>
using namespace std;
bool shh(int n){
    int sum = 0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0) 
            sum+=i;
    }
    if(sum==n) return true; 
    return false;
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    for(int i = 1; i <= n; i++){
    	if(shh(i)){
    		cout << i ;
        cout<< "\n";
		}
    	}
    return 0;
}
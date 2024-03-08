#include <iostream>

using namespace std ; 
unsigned long long a ; 
int x ; 
int main(){
cin >> a ;
x = a % 9 ; 
if (x != 0){
cout << a % 9 ;
}else{
	cout << 9 ; 
}
}


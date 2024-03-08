#include <iostream> 

using namespace std ; 
int A[100] ; 
int flag , a , b , i ; 
int main(){
cin >> a >> b ;
flag = 1 , i = 0 ;
a++  ; 
for(; a < b ; ++a ){
	for(int x = 2 ; x < a ; x++ ) {
		if(a % x == 0){
			flag = 0 ;
		}
	}
	if(flag){
		A[i] = a ;
	       i++ ; 	
	}
	flag = 1 ; 
 }
if( A[0] != 0 ){
for(int j = 0 ; j < i-1 ; j++){
	cout << A[j] << "," ; 
}
cout << A[i-1] ; 
}
}
 

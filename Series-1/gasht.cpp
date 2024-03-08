#include <iostream> 
#include <string> 
using namespace std ; 
string s1,s2 ;
int A[123] ; 
int B[123] ;
int flag = 1 ; 
// IN THE NAME OF GOD
// Biyaim bar asas code ascii gharar bedim dakhel khone ha va baad meghdar in do array ro moghayese konim harkodom
int main(){
	getline(cin,s1);
	getline(cin,s2);
for(int i = 0 ; i <= s1.length() ; i++ ) {
	A[(int)s1[i]]++ ;	
}

for(int i = 0 ; i <= s2.length() ; i++ ) {
	B[(int)s2[i]]++ ;	
}
int min1 = 1000000 ; 
for(int i = 32 ; i <= 123 ; i++ ) {
			if((A[i] == 0 )&&(B[i] != 0)){
				flag = 0 ; 
			//red flag 
			}

	if((A[i] != 0 )&&(B[i] != 0)){
	//	cout << "I am in the loop";
		if(A[i] >= B[i]){
			if((A[i]/B[i]) < min1 ){
			min1= min(A[i]/B[i],min1);
			}
		}else{
			flag =0 ; 
		}
	}	
}
 
 
//32 is the ascii code of space and 123 is also for 'z'
/* 
for(int i = 32 ; i <= 123 ; i++ ) {
	cout << i << A[i] << B[i] << '\n' ; 	
}
*/
if(flag){
cout << min1; 
}else{
	cout << 0 ; 
}
}
int min(int x , int y){
	if(x >= y ){
		return y ; 
	}else{
		return x ;
	}
}

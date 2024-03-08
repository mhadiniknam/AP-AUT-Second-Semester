#include <iostream>
#include <stack>
#include <string>
using namespace std; 

int main(){
stack<int> inn ; 
stack<int> out ; 
string s ;
cin >> s ; 
char t ; 
for(int i = 0 ; i <= s.length() ; i++ ) 
{
	inn.push(s[i]) ; 
}
for(int j = 0 ; j <  s.length() ; j++ ){
	while(
       	= inn.top() ;
	 inn.pop() ;
		  j++ ;
		 inn.pop(); 
	  
	  out.push(t) ; 
}
 
for(int k = 0 ; k <= out.size() ; k++){
cout << (char)out.top() ;
out.pop() ; 
}
}

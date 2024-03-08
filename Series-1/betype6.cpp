#include <iostream>
#include <string> 
using namespace std;

int main(){
string s1 , s2 ; 
cin >> s1 ; 
s2 = "=" ; 
//int found = s1.find(s2);
	// this function will return -1 if can not find the location of = 
	//
	int x ; 
while((x = s1.find(s2)) != (-1)){
	if(x == 0){
		s1.erase(0,1);
	}else{
	s1.erase((x-1),2);
}}

cout << s1 ; 

}

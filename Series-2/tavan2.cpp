#include <iostream> 
#include <string>
#include <algorithm>
using namespace std ; 
string s1,s2 ; 
int main(){
	cin >> s1 ;
	cin >> s2 ; 
	if(s1 > s2 ) {
		swap(s1 ,s2);
	}
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int len1 = s1.length(); 
	int len2 = s2.length();
	char * chararray = &s2[0] ; 
	for(int i = 0 ; i < len1 ; ++i){
		char x = ((char)((int)(chararray[i]-'0')+(int)(s1[i]-'0'))+'0'); 
//		s2.replace(i,1,x);
//cout <<(int) x ; 

		if((int)chararray[i] <= (int) '9'){
chararray[i] = x ;
		}else{
		x = (char) ((int)x - 10);
		chararray[i] = x ; 
		chararray[i+1] = (char)((int) chararray[i] + 1);
		}
	}
       	/*
	for(int i = 0 ; i < len1 ; ++i){
		if((int)chararray[i] > (int) '9'){
			
		}
	}
	*/
	s2 = chararray ;
	reverse(s2.begin(),s2.end());
	cout << s2 ; 

	return 0 ;
}

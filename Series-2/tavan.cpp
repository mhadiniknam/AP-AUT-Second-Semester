#include <iostream> 
#include <string>

using namespace std;
string s1 , s2 ; 

class BigNumber{
	private : 
string s ; 
int len = s.length();

	public:
BigNumber(string s1 , string s2){
	this.s = s ; 
}

string adder(BigNumber c1){
	string s1 = s
	string s2 = c2.s;
	int len1 = len ; 
	int len2 = c2.len ; 
if(s1.size() > s2.size()){
swap(s1,s2);
}
s1.reverse(s1.begin(),s1.end()) ; 
s2.reverse(s2.begin(),s2.end()) ; 
// now s2 > s1 
// At the first we add the number together without adding the carry
for(int i = 0 ; i <= len; ++i){
	s2.replace(i,1,(s1[i]-'0')+(s2[i]-'0'));
}	

for(int i = 0 ; i <= len1 ; ++i){
	if((s2[i]-'0') > '9'){
		// YEAH We have a carry 
		s2.replace(i,1,(char)((int)s2[i]-10));
		s2.replace(i+1,1,(char)((int)s2[i+1]+1));
}
}

s2.reverse(s2.begin(),s2.end());
cout << s2 ; 
}
};
int main(){
cin >> s1 ;
cin >> s2;
BigNumber(s1) ;
BigNumber(s2) ;
s1.

}

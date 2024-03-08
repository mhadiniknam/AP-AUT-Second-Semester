#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigNum
{
public:
    string number ;
};

BigNum add(BigNum firstInp, BigNum secondInp)
{
    if (firstInp.number.size() < secondInp.number.size())
    {
        swap(firstInp, secondInp);
    }
    BigNum result;
    int carry = 0;
    for (int i = 0; i < firstInp.number.size() ; i++)
    {
        int firstInpDigit = firstInp.number[i] - '0';
        int secondInpDigit = 0;
        if (i < secondInp.number.size()){
            secondInpDigit = secondInp.number[i] - '0';
        }
        int sum = firstInpDigit + secondInpDigit + carry;
        carry = sum / 10;
        result.number += char(sum % 10 + '0');
    }
    if (carry > 0)
    {// Here it seems that we append the carry
        result.number += char(carry + '0');
    }
    return result;
}
BigNum multiply(BigNum firstInp, BigNum secondInp)
{	
	BigNum result;
        result.number = "0" ; 
	BigNum one ; 
	one.number = "1" ;
	BigNum i ;
	int res = 1; 	
	for(i.number = "0" ; res = secondInp.number.compare(i.number) ;i = add(i,one)){
		result = add(result ,firstInp) ;
	}
	return result;
}

BigNum tavan(BigNum firstInp , BigNum secondInp)
{// second number is tavan 
 	BigNum result = firstInp ; 
	BigNum one ; 
	one.number = "1" ;
	BigNum i ;
	int res = 1; 	
	for(i.number = "1" ; res = secondInp.number.compare(i.number) ;i = add(i,one)){
		result = multiply(result ,firstInp) ;
	}
	return result;

}
BigNum subtract(BigNum firstInp , BigNum secondInp){
//---------------- the first number MUST be greater than second----------------------//
//The "compare()" method can do not work correctly in some special cases like 10 and 2 
//to fix this problem we add another if for comparing the size of them  
    BigNum result , temp; 
   // result = firstInp ;
    reverse(firstInp.number.begin(), firstInp.number.end());
    reverse(secondInp.number.begin(), secondInp.number.end());
    int carry = 0 , minusflag = 0 ;
    if(firstInp.number.size() < secondInp.number.size()){ 
	temp.number = firstInp.number ; 
	firstInp.number = secondInp.number ; 
	secondInp.number = temp.number ;
       minusflag = 1 ;	
    }else if(firstInp.number.size() == secondInp.number.size()){ 
    if(firstInp.number.compare(secondInp.number) < 0 ){
		temp.number = firstInp.number ; 
	firstInp.number = secondInp.number ; 
	secondInp.number = temp.number ;
       minusflag = 1;	
    }
   }
        reverse(firstInp.number.begin(), firstInp.number.end());
    reverse(secondInp.number.begin(), secondInp.number.end());
    for(int i = 0; i < firstInp.number.size() ; i++)
    {
        int firstInpDigit = firstInp.number[i] - '0';
        int secondInpDigit = 0;
	// in khat braye ine ke as ye ja be baad ma dige yek addademon chizi nadare khlase
        if (i < secondInp.number.size()){
            secondInpDigit = secondInp.number[i] - '0';
        }

	int sub = (firstInpDigit - secondInpDigit) - carry ; 

//	cout << firstInpDigit << secondInpDigit << '\n'; 
	if(i != (firstInp.number.size()-1) ){
		if(sub < 0 ){
			carry = 1 ; 
			result.number += char((sub + 10) + '0' ); 
			//cout << "1" << sub << '\n' ;
		}else{
			carry = 0 ; 
			result.number += char(sub + '0' );
			//cout << "2" << sub << '\n' ; 
		}
	}else{
			if(sub > 0 ) {
			result.number += char(sub + '0' ) ;
			}
	}
}
 if(firstInp.number.compare(secondInp.number) == 0 ){
	 result.number += char('0') ; 
 }
if(minusflag){
result.number += '-' ; 
}
    return result;
}
int main()
{
    BigNum firstInp, secondInp;
    cin >> firstInp.number >> secondInp.number;
    reverse(firstInp.number.begin(), firstInp.number.end());
    reverse(secondInp.number.begin(), secondInp.number.end());

    /*
    BigNum answer = add(firstInp, secondInp);
    BigNum ans = multiply(firstInp, secondInp);
    BigNum ans1 = tavan(firstInp, secondInp);
    BigNum ans2 = subtract(firstInp, secondInp);

    reverse(ans.number.begin(), ans.number.end());
    reverse(answer.number.begin(), answer.number.end());
    reverse(ans1.number.begin(), ans1.number.end());
    reverse(ans2.number.begin(), ans2.number.end());

    cout << answer.number << '\n' ;
    cout << ans.number << '\n' ; 
    cout << ans1.number << '\n' ;
    cout << ans2.number ;
    */
    BigNum ab = tavan(firstInp, secondInp);
    BigNum ba = tavan(secondInp,firstInp);
    BigNum ans = subtract(ab,ba);
    reverse(ans.number.begin(), ans.number.end());
    cout << ans.number ; 
}

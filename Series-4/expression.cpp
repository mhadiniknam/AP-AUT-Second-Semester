#include <iostream>  
#include <string>  
#include <vector>

using namespace std; 
struct frac{
	int num ; 
	int den ; 
	int row ; 
	int col ; 
};
struct kasr{
	int s ; 
	int e ; 
	int len = e - s ;
       // location 
       	int row ;// (s+e)/2 
	int col ;
};
struct operation {
	int type ;// 1 for + / 0 for *
	int row  ;
	int col  ;
};
vector<struct frac> adad ; 
vector<struct kasr> khat ;
vector<struct operation> ops ; 
	// In soal yek khosh tartibi khasi daresh hast : inke kasr ha ba tol kamtar bayad zod tar hesab beshan
	// aval az hame jaye kasr haro bedast biyarim : yani massalan khat felan character + tol kasr 
	// midoni engar ke ma bayad ye derakht operation ha ro besazim .
	// hame adad dar ebteda yek struct hastan ka fagh
	//
	// be nazar miyad bayad hame adad ro be form frac bebarim atraf on ada : jelo tar ya aghab taresh ro chack konim ke aya * ya jam dare ? 
	// ba komak mokhtasat baraye on check mikonim aya nazdik tarin  kasr dar bala ya payinesh vojod dare ya na
	//
	// aval benazaram check kone ke kasr 
	// va baadesh amaliyat taghsim ro anjam midim 
	// javanbesh ro be mokhtasat on kasr montaghel miknoim  
	// shoro in kar bayad az koja bashe ? 
	// mitonim vectoremon ro sort konim bakomak row ke gharar dare . 
	// az har addadi ke dar ertefa balatear bod 
	int A[20] ; 
int main(){
	int x ;
	cin >> x ; 
	string = ""; 
	for(int i = 0 ; i < x ; ++i){
		getline(s, cin); 
		int c =  0 ;

		// we do find the things in a line
		for(int j = 0 ; j < s.size() ; ++j ) {
			if((int) s[j] != 32 ){
				if(!flag){
					A[c] = j ; 
					c++ ;
					// inja in frac eshkal dare bayad ye chizi bashe ke barhasb noeshon joda kone .
					flag = 1; 
				}
		}else{
			if(flag){
					A[c] = j ; 
					c++ ; 
					flag = 0 ; 
				}
			}	
		}
		// so WE need an end Point ......................
		// now c is the length of the stuff in the line 

		// hala inja bayad on string ro ye martabe dige analyse konim 
		//bayad addad ascii ro check koni 
		// age ke ascii + va * bod bezarish toye struct operation
		// age ke ascii adad bod mire toye struct frac 
		// age ke ascii - bod bayad bere toye struct kasr
	for(int k = 0 ; k < c ;++k){
		if((int)s[A[k]] == 45 ){
			struct kasr a ; 
			a.s = A[k] ;
			a.e = A[k+1] ;
			a.len = A[k+1] - A[k] + 1;
			a.row = (a.s + a.e)/2 ; 
			a.column = i ; 
			ops.push_back(a) ; 
		}
		if((int)s[A[k]] >= 48 && ((int)s[A[k]] <= 57){
			struct frac a ; 
			string buf = s.substr(A[k] , A[k+1] - A[k] +1;  
			a.num = stoi(buf);
			a.den = 1; 
			a.row = A[k] ; 
			a.column = i ; 
			adad.push_back(a) ; 
		}
		if(
	}
}

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std ; 
struct src {
	int second ; 
	int msecond ; 
	//int last_second = 0 ; 
	//int last_msecond = 0 ; 
	string strings[10] ; 
	int ints[10] ;
	int num_update = 0 ;
	//	 int id[3] ;//h ,  main_money , total , num_person 
};
class Restaurant{
	private:
		int n , m , k ; 
		// n is the number of evidence 
		// m is the number of foods 
		// k is the table 
		string s ; 
		struct src t ;
		int A[10] ; 
		foods = map<string , int> ;
		vector<int> table ; 
		string buf1 ;
		string buf2 ; 
		int bufn ; 
	public :
		Restaurant(){
			scanf("%d %d %d",&n,&m,&k);

			// I make the menu here ...
			for(int i = 0 ; i < m ; ++i){
				cin >> buf1 >> buf2 ; 
				bufn = stoi(buf2);	
				foods[buf1] = bufn ;
			}
		}
		

		void start(){
			for(int i = 0 ; i < n ; ++i ){
				getline(cin, s) ;

				int j = 0 ; 
				for(int i = 0 ; i <= s.length() ; i++ ) {
					if((int) s[i] == 32 ){
						A[j] = i ; 
						j++ ; 
					}
				}
				A[j] = s.length() ;

				// So it's better to do the preprocessing on the input text before pass it to any function
				// We khow that the input which start with number are always int and in other case they are strings
				// for this problem I can use "int num = stoi(str)" to cast between the string and integer 

				string buf = "" ; 

				int k = 0 , l = 0 ; 
				for(int i = 0 ; i < j ; i++ ){
					buf = ""; 
					buf = s.substr(A[i]+1 ,(A[i+1])-(A[i]+1)) ;
					// Pay attention that the second argument here is the length of the substr not the endpoint ...
					// and also the length get the initialize point as well ...
					t.strings[l] = buf ; 
					l++; 

					// ---I Love HASHING---
					//I can use the first character and the length which I have No collision at all .
					//cout << l ; 
				}
				//parsing the timestamps  
				string buffer = "" ; 
				int num ; 
				int B[] = {-1,2,5,9} ;
				for(int i = 0 ; i < 3 ; i++){

					//cout << l ;
					//cout << t.strings[l-1] ; 
					buffer = t.strings[l-1].substr(B[i]+1, (B[i+1] - B[i]-1));
					//cout << buffer << "\n";
					num = stoi(buffer);
					//cout << num << "\n" ;

					if(i == 0 ){
						// We initialize the last_second for each ten second update in money
						t.second = num*60 ;
					}

					if(i == 1){
						t.second  += num ; 
					}

					if(i == 2){
						t.msecond = num  ;
					}

				}
				// another parser for strings to ints 
				//

				int hash_score = (int) s[0];
				if(hash_score == 111 ){
					if(s.length() == 5) {
						hash_score = 1 ;  
					}else{
						hash_score = 2 ; 
					}
				}

				switch(hash_score){
					case 1:
						order(struct src t );  
						break;		
					case 2:
						order-status(struct src t);
						break;
					case 112:
						payment(struct src t );
						break;
					case 116:  
						table-status(struct src t);
						break;
					case 103:
						general-status(struct src t)
							break;

						for(int i = 0 ; i <= j ; i++){
							A[j] = 0 ;
						}
				}
			}



		}
};

int main(){

	// there is also another way to parsing the input string and that is to use the find method ...
	Restaurant restaurant ;
	//restaurant.

}

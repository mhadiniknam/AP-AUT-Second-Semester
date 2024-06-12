#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <array>

using namespace std ; 

struct src {
	int second ; 
	int msecond ; 
	string strings[100] ; 
	int ints[10] ;
	int l ; 
}t;
//int table[200][4] ;
array<array <int , 4> , 200 > table ;// I don't know why but I reduce two RUNTIME ERROR AS WELL  
int last = 101 ;
int n , m , k ; 
// n is the number of evidence 
// m is the number of foods 
// k is the table 
int wait ; 
int eating ; 
int ended ;
int EatingTable ;
int ServiceTable ; 
int FreeTable;
int A[100] ; 
map<string , int> foods;
string buf1 ;
string buf2 ; 
char bufc ; 
int bufn ; 
//map<int, vector<int>> table ;// 2D array/ [0] : capacity , [1] : money , [2] : payment_num , [3] : second , [4] : msecond
// from 1-100 is the table and the 100-200 is waiting list 
int money  = 0; 
int finalmoney = 0 ; 
int payment_num = 1 ;

class Restaurant{
	private:
	public :
		string s ; 
		Restaurant(){
			scanf("%d %d %d\n",&n,&m,&k);
			// I make the menu here ...
			for(int i = 0 ; i < m ; ++i){
				cin >> buf1 >> buf2 ; 
				bufn = stoi(buf2);	
				foods[buf1] = bufn ;
				FreeTable = k ; 
			}
			for(int i = 0 ; i < k-1 ; ++i){
				cin >> table[i][0] ; 
			}
			scanf("%d ",&table[k-1][0]);
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
				t.l = l ; 
				//parsing the timestamps  
				string buffer = "" ; 
				int num ; 
				int B[] = {-1,2,5,9} ;
				try {
					// in try catch ro az net bardashtam 
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
						//cout << t.second << endl ; 

					}
					// another parser for strings to ints 
					//
				} catch (const std::invalid_argument& e) {
					// Handle the case when the string cannot be converted to an integer
					cout << "Error: Invalid input string for conversion to integer." << endl;
					cout << "You are trying to convert " << buffer << "into integer" << endl ;
					cout << "This Error located in time parser " << endl;
					// You can also log the error or take appropriate action here
				} catch (const std::out_of_range& e) {
					// Handle the case when the converted value would fall out of the range of the result type
					cout << "Error: Integer value out of range." << endl;
					cout << "This Error located in time parser " << endl;
					// You can also log the error or take appropriate action here
				}

				int hash_score = (int) s[0];
				if(hash_score == 111 ){
					if(A[0] == 5) {
						hash_score = 1 ;  
					}else{
						hash_score = 2 ; 
					}
				}

				/*  
				 *
				 * MONITOR THE TABLES 
				 *
				 for(int i = 0 ; i < 5 ; i++ ){		
				 cout << table[i][0] <<  " "  ; 
				 cout << table[i][1] << " "  ;
				 cout << table[i][2]  << " "  ;
				 cout << table[i][3] << endl ; 
				 }
			 	*/	 


				switch(hash_score){
					case 1:
						order(&t);  
						break;		
					case 2:
						order_status(&t);
						break;
					case 112:
						payment(&t);
						break;
					case 116:  
						table_status(&t);
						break;
					case 103:
						general_status(&t);
						break;
					default : 
						cout << "Error code 1 : the wrong argument ... !" ;
						exit(1) ; 
						break ; 
				}
				for(int i = 0 ; i <= j ; i++){
					A[i] = 0 ;
				}

			}
		}
		void order(struct src *t ){
			int l = t->l ; 
			int flag = 1;
			try{					
				string s1 = t->strings[l-2] ;
				if(s1[1] == 32){
					s1 = s1[0] ;
					// check if we have two digit input
				}
				bufn = stoi(t->strings[l-2]);
			}catch (const std::invalid_argument& e) {
				// Handle the case when the string cannot be converted to an integer
				cout << "Error: Invalid input string for conversion to integer." << endl;
				cout << "This Error located in order function ." << endl;
				cout << "You are trying to convert " << t->strings[l-2]<< "into integer " << endl ;
				// You can also log the error or take appropriate action here
			}
			int table_index = 101 ;
			int moneybuf = 0 ;
			int seen = 0 ; 
			//
			for(int i = 0 ; i <= 100 ; i++){


				if(table[i][0] > 0 ) {
					// it check if the table is valid ;
					//		cout << table[i][0] <<" " << bufn <<" "<<table_num << " "<< table[i][2] << "//" ;
					if((table[i][0] >= bufn)) {
						if(table[i][2] == 0 ){
							if(( table[i][3] && (( t->second- table[i][3] )>= 0 ) && (table[i][4]-(t->msecond) >= 0 ))|| !(table[i][3])){

								// this mean that the table is free 
								table_index = i ; 
								flag = 0 ; 	
								break ; 
							}
						}else{
							seen = 1 ;
						}
					}
				}else{
					break ;
				}
			}

			/*
			   if(flag){
			   for(int i = 0 ; i <= 100 ; i++){
			   if(table[i][0] > 0 ){
			   if((table[i][0] >= bufn) && (table[i][0] < table_num)){
			// this mean that the table is free 
			table_index = i ; 
			table_num = table[i][0] ;
			}
			}else{
			break;
			}	
			}
			}
			*/	
			//cout << t->strings[1] << '\n'  ; 
			//cout << t->strings[2] << '\n' ;
			// i == k
			if(flag && !(seen))
			{
				cout << "not enough seat." << "\n" ; 
				// it mean there is no table with that amount 
			}
			

				if(seen && (flag)){
	for(int i = 0 ; i < (t->l-2) ; i++){
					try{
						int p = t->strings[i].find("X") ;
						buf1 = t->strings[i].substr(p+1,t->strings[i].length()-p);
						bufn = stoi(buf1) ; 
						buf2 = t->strings[i].substr(0,p) ;
						moneybuf += foods[buf2]*bufn ;
					}catch (const std::invalid_argument& e) {
						// Handle the case when the string cannot be converted to an integer
						cout << "Error: Invalid input string for conversion to integer." << endl;
						cout << "You are trying to convert " << buf1 << "into integer " << endl ;
						cout << "this error is in calculating the money in order function "<< endl ; 
						// You can also log the error or take appropriate action here
					}

				}
					// this mean there is a table but it has been occupied 
					money += moneybuf ; 
					//cout << moneybuf ;
					table[last][1] = moneybuf ; 
					table[last][2] = payment_num ; 
					payment_num++ ;
					last++ ; 
					cout << "please wait for free table." << "\n" ; 
					wait++ ; 	
					// there is a table but it has been occupied
				}
				if(!flag){
	for(int i = 0 ; i < (t->l-2) ; i++){
					try{
						int p = t->strings[i].find("X") ;
						buf1 = t->strings[i].substr(p+1,t->strings[i].length()-p);
						bufn = stoi(buf1) ; 
						buf2 = t->strings[i].substr(0,p) ;
						moneybuf += foods[buf2]*bufn ;
					}catch (const std::invalid_argument& e) {
						// Handle the case when the string cannot be converted to an integer
						cout << "Error: Invalid input string for conversion to integer." << endl;
						cout << "You are trying to convert " << buf1 << "into integer " << endl ;
						cout << "this error is in calculating the money in order function "<< endl ; 
						// You can also log the error or take appropriate action here
					}

				}

					money += moneybuf ; 
					table[table_index][1] = moneybuf ; 
					table[table_index][2] = payment_num ; 
					//table[table_index][3] = t->second ; 
					//table[table_index][4] = t->msecond ; 
					/*
					for(int i = 0 ; i < 5 ; i++ ){		
						cout << table[i][0] <<  " "  ; 
						cout << table[i][1] << " "  ;
						cout << table[i][2]  << " "  ;
						cout << table[i][3] << endl ; 
					}
					*/
					payment_num++ ; 
					cout << "please sit at table number " << (table_index+1) << "." << "\n"; 
					FreeTable-- ; 
					EatingTable++ ;

					eating++; 
					
					// there is a free table
				}
			}

		void payment(struct src *t){
			//cout << table[i][0] <<" " << bufn <<" "<<table_num << " "<< table[i][2] << "//" ;
			string s1 = t->strings[0] ;
			if(s1[1] == 32){
				s1 = s1[0] ;
				// check if we have two digit input
			}
			bufn = stoi(t->strings[0]);
			//cout << bufn << " "<< table[0][2] << " "<< table[0][2] << endl ;
			int n = 101; 
			for(int i = 0 ; i <= 100 ; i++){
				if(table[i][2] == bufn){
					n = i ; 
					break;
				}
			}

			//cout << n << endl ; 
			if(n > 100 ){
				cout << "pays after eating." << "\n" ; 	
			}else{
				bufn = table[n][1] ; 
				cout << "you should pay " << bufn << " Toman." << endl ; 
				finalmoney += bufn ;

				table[n][3] = t->second + 2 ; 
				table[n][4] = t->msecond ;
				table[n][2] = 0 ;
				table[n][1] = 0 ;
				eating--; 
				ended++ ;
				EatingTable-- ; 
				ServiceTable++ ;
				int flag2 = 1 ; 
				for(int i = 101 ; i <= 200 ; i++){
					if((table[i][2] != 0) &&  (table[i][0] <= table[n][0])){
						// money_total must be updated
						table[n][1] = table[i][1] ; 
						table[n][2] = table[i][2]; 
						table[i][1] = 0 ; 
						table[i][2] = 0 ;
						wait-- ;
						flag2 = 0 ; 
						break ; 
					}
				}
			}
		}
		void order_status(struct src *t){
			string s1 = t->strings[0] ;
			if(s1[1] == 32){
				s1 = s1[0] ;
				// check if we have two digit input
			}
			bufn = stoi(t->strings[0]);
			int flag = 1; 
			for(int i = 0 ; i <= 100 ; i++ ) {
				if(table[i][2] == bufn ){
					cout << "EATING" << endl ; 
					flag =0 ;	
					break;
				}
			}
			if(flag){
				for(int i = 101 ; i <= 200 ; i++){
					if(table[i][2] == bufn ){
						cout << "WAITING" << endl ; 
						flag =0 ;	
						break ; 
					}
				}
			}
			if(flag){
				cout << "DONE" << endl ; 
			}
		}
		void table_status(struct src *t){
			//int n = 101; 
			bufn = stoi(t->strings[0]) ; 
			/*
			   for(int i = 0 ; i <= 100  ; i++ ) {
			   if(table[i][2] == bufn ){
			   n = i ;
			   break ; 
			   }

			   }
			   */
			if(table[bufn][2] == 0 ){
				if(((table[bufn][3] >= t->second ) && (table[bufn][4]-(t->msecond) >= 0 ))|| (table[bufn][3] == 0)){
					cout << "FREE" << '\n' ;
				}else{
					cout << "PENDING" << endl ; 
				}
			}else{
				if(((table[bufn][3] >= t->second ) && (table[bufn][4]-(t->msecond) >= 0 )|| (table[bufn][3] == 0 ))){	
					cout << "BUSY" << endl ; 
				}else{
					cout << "PENDING" << endl ;
				}
			}
		}
		void general_status(struct  src *t)
		{

			for(int i = 0 ; i <= 100 ; i++ ){
				if(table[i][0] > 0 ){
					if((table[i][3] && (( t->second- table[i][3] )>= 0 ) && (table[i][4]-(t->msecond) >= 0 ))){
						ServiceTable--; 
						FreeTable++ ; 
						table[i][3] = 0 ; 
						table[i][4] = 0 ; 
					}
				}else{
					break ;
				}	
			}

			cout << finalmoney << " " << money-finalmoney << " " << wait << " " <<  eating << " " << ended 
				<< " " << FreeTable << " " <<ServiceTable << " " << EatingTable << endl ; 
		}
};

int main(){

	// there is also another way to parsing the input string and that is to use the find method ...
	Restaurant restaurant ;
	restaurant.start();
	//restaurant.

}

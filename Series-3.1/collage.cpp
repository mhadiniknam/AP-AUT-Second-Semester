#include <iostream> 
#include <string> 
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std; 
int A[10] ;

class user{
	public :
 string name ; 
 string low ; 
 string role ;
 int status = 0 ; 
}a;

//these vectors have the roll of data-base 

vector<user> db;
/*
bool comparei(const string& a ,const string& b) {
	string aLower(a);
	string bLower(b);

	transform(a.begin(),a.end(),aLower.begin(), ::tolower);
	transform(b.begin(),b.end(),bLower.begin(), ::tolower);

	return aLower < bLower ; 
}
*/

struct src {
//	int ints[10] ; 
	string strings[10] ; 
}t ;
void reg(struct src t){
	int flag = 1,flag2 = 0 ,flag3 = 0;
			for(class user suser : db){
			//cout << suser.name << '\n'; 
			if(!(suser.name.compare(t.strings[0]))){
					flag2 = 1 ; 
				// Here we search for the preaccurance of any specific user name
				class user v = suser ; 
		}
			}
			if(flag2){
				cout << "INVALID USERNAME"  << "\n"; 
				flag = 0 ; 
			}
//cout << t.strings[1] ; 
		if(flag){
			if(!t.strings[1].compare("ADMIN")){
				flag3 = 1 ; 
			}
			if(!t.strings[1].compare("MENTOR")){
				flag3 = 1 ; 
			}
			if(!t.strings[1].compare("MEMBER")){
				flag3 = 1 ; 
			}
			if(!flag3){	
				cout << "INVALID ROLE"  << "\n";
			       flag = 0 ;	
			}
		}
		if(flag){
			class user v ; 
			v.name = t.strings[0] ;
			v.role = t.strings[1] ;
		//	v.status = 0 ;
		cout << "WAITING FOR ACCEPT"  << "\n";
		db.push_back(v);
		}
}	
void approve(struct src t){
	int flag = 1,flag2 = 0 ;
	class user v ; 
			for(class user suser : db){
//				cout << suser.name << ":" << suser.status <<  suser.role << '\n' ; 
			if(!(suser.name.compare(t.strings[0]))){
					flag2 = 1 ; 
				// Here we search for the preaccurance of any specific user name
				v = suser ; 
		}
			}
			if(!flag2){
				cout << "INVALID USERNAME"  << "\n"; 
				 
				flag = 0 ;
			}
	if(flag){
		if(!v.status){
			cout<<"WAITING FOR ADMIN" << "\n" ;
			flag = 0 ; 
		}
	}
	if(flag){
		if(v.role.compare("ADMIN")){
			cout << t.strings[0] << " IS NOT ADMIN"  << "\n";
			flag = 0 ; 
		}
	}
	int j = 0 ;
       	int k ;	
//	if(flag){
	flag2 = 0 ; 
					for(class user suser : db){
						j++ ; 
			if(!(suser.name.compare(t.strings[1]))){
				k = j ; 

					flag2 = 1 ; 
				// Here we search for the preaccurance of any specific user name
				v = suser ; 
		}
			}
					if(flag){
			if(!flag2){
				cout << "INVALID USERNAME"  << "\n";  
				flag = 0 ; 
			}
//	}
		if(flag){
		if(v.status){
			cout<<t.strings[1] << " IS ACTIVE"  << "\n";
			flag = 0 ; 
		}
	}
if(flag){
db.erase(db.begin() + k-1); 
v.status = 1; 
db.push_back(v);
	cout << t.strings[1] << " ACTIVATED" << '\n';
}
}
}

void reject(struct src t){
	int flag = 1,flag2 = 0 ;
	class user v ; 
			for(class user suser : db){
			if(!(suser.name.compare(t.strings[0]))){
					flag2 = 1 ; 
				// Here we search for the preaccurance of any specific user name
				v = suser ; 
		}
			}
			if(!flag2){
				cout << "INVALID USERNAME"  << "\n";  
				flag = 0 ;
			}
	if(flag){
		if(!v.status){
			cout<<"WAITING FOR ADMIN"  << "\n";
			flag = 0 ; 
		}
	}
	if(flag){
		if(v.role.compare("ADMIN")){
			cout << t.strings[0] << " IS NOT ADMIN"  << "\n";
			flag = 0 ; 
		}
	}
	int j = 0 ;
       	int k ;	
//	if(flag){
	flag2 = 0 ; 
					for(class user suser : db){		
				j++ ; 
			if(!(suser.name.compare(t.strings[1]))){
				k = j ; 
					flag2 = 1 ; 
				// Here we search for the preaccurance of any specific user name
				v = suser ; 
		}
			}
					if(flag){
			if(!flag2){
				cout << "INVALID USERNAME"  << "\n";  
				flag = 0 ; 
			}
//	}
		if(flag){
		if(v.status){
			cout<<t.strings[1] << " IS ACTIVE" << "\n" ;
			flag = 0 ; 
		}
	}
if(flag){
db.erase(db.begin() + k-1); 
cout << t.strings[1] << " REJECTED" << "\n" ; 
}
}
}
void status(struct src t){

 int flag = 0 , j = 0 , k ;
class user v ; 
				for(class user suser : db){
				//cout << suser.name << ":" << suser.status <<  suser.role << '\n' ; 
						j++ ; 
			if(!(suser.name.compare(t.strings[0]))){
				k = j ; 
				j++ ; 
					flag = 1 ; 
				// Here we search for the preaccurance of any specific user name
				v = suser ; 
		}
			}

			if(!flag){
				cout << "INVALID USERNAME"  << "\n";  
				flag = 0 ;
			}
		
		
			if(flag){
		if(v.status){
			cout << "username: " << t.strings[0] << " role: " << v.role << " active"  << "\n";
		}else{	
			cout  << "username: "<< t.strings[0] << " role: " << v.role << " not active"  << "\n";
		}
	}
}	
void queue(struct src t){
 int flag = 1  , flag2 = 0 ;
class user v ;
int j = 0 , k ; 
					for(class user suser : db){		
				j++ ; 
			if(!(suser.name.compare(t.strings[0]))){
				k = j ; 
					flag2 = 1 ; 
				// Here we search for the preaccurance of any specific user name
				v = suser ; 
		}
			}

			if(!flag2){
				cout << "INVALID USERNAME" << "\n" ;
			      flag = 0 ; 	
			}
			
			
			if(flag){
				if(!v.status){
					cout << "WAITING FOR ADMIN" << "\n";
					flag = 0 ;
				} 
			}
			if(flag){
				if(!(v.role.compare("MEMBER"))){
					cout << "NOT ENOUGH ACCESS"  << "\n";
					flag = 0 ; 
				}
			}
			if(flag){
			vector<string> ds ;
				for(class user suser : db ){
					if(!(suser.status)){
						ds.push_back(suser.name);
					}
				//	for(
				//	suser.low = 
				}
				sort(ds.begin(),ds.end());
				// It's possible that we get to trouble here for sorting : it said to ignore lower or upper case
				 /*
				if(!ds.empty()){
					for(string s1 : ds){
						cout << s1 << " " ; 
					}
					cout << '\n' ;
				}else{
					cout << "NO USER"   << "\n"; 
			}*/
			}
}
void changerole(struct src t){
	int flag = 1,flag2 = 0 ,flag3 = 0 ;
	class user v , u ;
			for(class user suser : db){
		//		cout << suser.name << ":" << suser.status <<  suser.role << '\n' ; 
			if(!(suser.name.compare(t.strings[0]))){
					flag2 = 1 ; 
				// Here we search for the preaccurance of any specific user name
				v = suser ; 
		}
			}
			int j  = 0; 
			int k ; 
			for(class user suser : db){
								j++;
			if(!(suser.name.compare(t.strings[1]))){
				k = j ; 

					flag3 = 1 ; 
				// Here we search for the preaccurance of any specific user name
				u = suser ; 
		}
			}
//cout << flag2 << flag1 ;
			 
			if(!(flag2) || !(flag3) ){
				cout << "INVALID USERNAME"  << "\n";  
				flag = 0 ; 
			}
flag3 = 0 ; 
int vu , vv , vr ;
//cout << u.name << v.name << '\n' ;
//cout << u.status << v.status
		if(flag){
		if(!(u.status) || !(v.status)){
		cout << "WAITING FOR ADMIN"  << "\n";	
			flag = 0 ; 	
		}	
		}
		if(flag){
			if(!t.strings[2].compare("ADMIN")){
				flag3 = 1 ; 
				vr = 2 ;
			}
			if(!t.strings[2].compare("MENTOR")){
				flag3 = 1 ; 
				vr = 1 ;
			}
			if(!t.strings[2].compare("MEMBER")){
				flag3 = 1 ; 
				vr = 0 ; 
			}
			if(!flag3){	
				cout << "INVALID ROLE" ;
			       flag = 0 ;	
			}
		}
		if(!v.role.compare("ADMIN")){
				vv = 2 ;
			}
			if(!v.role.compare("MENTOR")){
				vv = 1 ;
			}
			if(!v.role.compare("MEMBER")){
				vv = 0 ; 
			}
		if(!u.role.compare("ADMIN")){
				vu = 2 ;
			}
			if(!u.role.compare("MENTOR")){
				vu = 1 ;
			}
			if(!u.role.compare("MEMBER")){
				vu = 0 ; 
			}
		//	cout << vu << vv << vr ;  
if(flag){
	if(vv <= vu){
		cout << "NOT ENOUGH ACCESS"  << "\n";
		flag = 0 ; 
	}
}
			if(flag){
				if(vv < vr){
					cout << "INVALID CHANGEROLE"  << "\n";
					flag = 0 ;
				}	
}
if(flag){
	if(vu == vr){
		cout << "ALREADY HAS THIS ROLE"  << "\n"; 
		flag = 0 ; 
	}
}
if(flag){
db.erase(db.begin() + k-1); 
u.role = t.strings[2];
db.push_back(u);
cout << "ROLE CHANGED SUCCESSFULLY"  << "\n";

}}
int main(){
	a.name = "ADMIN" ;
	a.role = "ADMIN" ;
	a.status = 1; 
	db.push_back(a);
	int m ; 
cin >> m ; 
string s = "";

for(int i = 0 ; i <= m ; ++i ){
	getline(cin, s) ;
//	cout << s ;
//	cout << "I am in the loop" ; 

	// khob aval az hame bayad hame string haro joda konim lazem nadarim ke mostaghim hama ro berizim 
	// toye ye string jadid mostaghim hame ro negah mikonim va moshakhas mikonim bayad az kodom dastor
	// estefade konim mitonim dastorat soal ro barasat majmoe dastor aval hash konim ke 
	// kheili rahat tar dastresi peyde konim be hamon tabei ke mikhayim .
	int j = 0 ; 
	for(int i = 0 ; i <= s.length() ; i++ ) {
		if((int) s[i] == 32 ){
		A[j] = i ; 
		j++ ; 
	//	cout << i ; 
	}
	}
	A[j] = s.length() ;
	// So it's better to do the preprocessing on the input text before pass it to any function
	// Or you must do the preprocesesing in each function you have 
	
	// We khow that the input which start with number are always int and in other case they are strings
	// for this matter I can use "int num = stou(str)" to cast between the string and integer 
string buf = "" ; 

int k = 0 , l = 0 ; 
for(int i = 0 ; i < j ; i++ ){
	buf = ""; 
//	if(s[A[j]+1] <= 122 && s[A[j]+1] >= 97 ){
	//	cout << A[i] << A[i+1] << '\n' ; 
		buf = s.substr(A[i]+1 ,(A[i+1])-(A[i]+1)) ;
		/*
		 * I get to a bug here for substr and the reason was that I must get the length insted of the end point
		 */
		t.strings[l] = buf ; 
//		cout << buf << '\n' ; 
		l++; 
/*
}else{
		buf = s.substr(A[j]+1,A[j+1]-1) ;
		t.ints[k] = stoi(buf) ; 
		k++ ; 
	}
*/
}
		/*
		 ---I Love HASHING---
		I can use the first character and the length which I have No 
		collision at all .
		*/
int hash_score = (int) s[0] ;
if(hash_score == 82 ){
	hash_score = A[0] ; 
}
//cout << A[0] ; 
	switch(hash_score){
		case 8:
		//	cout << "I am here" ;
	reg(t);
	break;		
		case 81:
	queue(t);
	break;
		case 65:
	approve(t);
	break;
		case 6:
	reject(t);
	break;
		case  67:
	changerole(t) ; 
	break;
		case  83:
	status(t) ; 
	break;
		for(int i = 0 ; i <= j ; i++){
				A[j] = 0 ;
				}
}
}
}

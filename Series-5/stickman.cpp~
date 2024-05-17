#include <iostream> 
#include <string>
#include <vector>
#include <cstdio>

using namespace std ;
string s ;
 struct src {
	 int min ; 
	 int second ; 
	 int msecond ; 
	string strings[10] ; 
	int ints[10] ;
//	int id[3] ;//h ,  main_money , total , num_person 
}t ;
class master{
	public : 
int unit ; 
int j ; 
int money ; 
int zarbe ; 
int t ; 
int type ; 
int idx ; 
int active ;
};
class miner : public master {
	public :
	miner(){	
		type = 1 ;
	unit = 1; 
	j = 100 ; 
	money = 120 ; 
	zarbe = 100 ; // inja zarbe seke ke mine mishe hast
	t = 10 ; 	
	}
};
class swordwarth : public master {
	public : 
		swordwarth(){
		type = 2; 
	unit = 1; 
	j =120 ; 
	money = 125 ; 
	zarbe = 20 ; 
	t = 1 ;
		}
};
class archidon : public master{
	public : 
	archidon(){
	type = 3 ;
	unit = 1 ; 
	j = 80 ; 
	money = 300 ; 
	zarbe = 10 ; 
	t = 1; 
	}
};

class spearton : public master {
	public : 
	spearton(){
	type = 4 ;
	unit = 2; 
        j =250 ; 
	money = 500 ; 
 	zarbe = 35; 
	t = 3 ;	
	}
};
class magikill : public master {
	public : 
	magikill(){
	type = 5 ;
	unit = 4 ; 
	j = 80 ; 
	money = 1200 ; 
	zarbe = 200 ; 
	t = 5 ; 
	}
};
class giant : public master {
	public : 
	giant(){
	type = 6 ;
	unit = 4 ; 
	j = 1000 ; 
	money = 1500 ; 
	t = 4 ; 
	zarbe = 150 ; 
	}
};
vector<master*>db ; 

void addd(struct src t,int &h , int &num_money , int &total , int &idx , int &num_miner ){	
	char c = t.strings[1][2]  ; 
	update(t,num_money);
	master* y = nullptr ; 
	switch(c){
		// to make it even faster I make another hash with the third charater
		case 'n':{
			miner* x = new miner()  ; 
			y = x ; 
			break ; 
			 }
		case 'o':{
			swordwarth* x = new swordwarth() ; 
			y = x ; 
			break ; 
			 }
		case 'c':{
			archidon* x = new archidon() ; 
			y = x ; 
			break ; 
			 }
		case 'e':{
			spearton* x = new spearton() ; 
			y = x ; 
			break ; 
			 }
		case 'g':{
			magikill* x = new magikill() ; 
			y = x ; 
			break ; 
			 }
		case 'a':{
			giant* x = new giant(); 
			y = x ; 
			break ;
			 } 
int flag = 1 ; 
	if( h <= 0 ) {
		flag = 0 ; 
		cout << "game over" ; 
	}
	if(flag){
		if(num_money < y->money ){
			cout << "not enough money" ;
		}
		flag = 0 ;
	}
	if(flag){
		if( total >= 50 ){
			cout << "too many army" ; 
		}
		flag = 0 ; 
	}
	
	if(flag){
		y->idx = idx ; 
		if(y->type == 1 )
		{
			if(num_miner <= 7){
				y->active = 1; 
			}else{
				y->active = 0 ;
			}

			num_miner++; 
		}
		db.push_back(y) ; 
		num_money -= y->money ; 
		cout << idx ; 
		idx++ ; 
		}
}
}
void damage(struct src t,int &h , int &num_money , int &total , int &idx ) {

// Maybe it does not have some optimize search because doing itteration on db is expensive
// Maybe it was better to have a specialized db for each role ... 

	int flag = 1 ;
	if(h <= 0 ) {
		flag = 0 ; 
		cout << "game over" ; 
	}
	master* y = nullptr ; 
	if(flag){
		for(auto& x : db ){
			if(x->idx == idx){
			 	y = x ;
			}
		if(y == nullptr ){
			flag = 0 ;
		}	
		if(y->j <= 0 ){
			flag = 0;
		}
		if(!flag){
			cout << "no matter" ;
		}
	}
	if(flag){
		y->j -= t.ints[1] ; 
		if(y->j <= 0 {
			cout << "dead" ; 
				if(y->type == 1 ) {
					if(y->active == 1){
					if(num_miner >= 9 ){
					master* e; 
						for(auto& x : db ){
						int flag1 = 1 ;
						if(flag1){
						if(x->type == 1 ) {
							if(x->active == 0){
								e->active = 1 ;	
								flag1 = 0 ; 
								}
							}
						}	
						}else{
						num_miner--;
					}					
				}
		}else{
		cout << y->j ; 
		}
			}
}
void enemy-status(struct src t,int &h){
	if(h <= 0 ) {
		cout << "game over";
	}else{
		cout << h ; 
	}
}	
	int c[5] ; 
void army-status(struct src t , int &h){
	int flag = 1; 
	if(h <= 0 ) {
		flag = 0  ;
		cout << "game over";
	}
	if(flag){
	for(auto& x : db ){
		if(x->j > 0 ){
		switch(x->type){
			case 1:
				c[0]++; 
				break;
			case 2:
				c[1]++; 
				break;
			case 3:
				c[2]++; 
				break;
			case 4:
				c[3]++; 
				break;
			case 5:
				c[4]++; 
				break;
			case 6:
				c[5]++; 
				break;
			}
		}
	}
		printf("%d %d %d %d %d %d",c[0],c[1],c[2],c[3],c[4],c[5]);
	}
}
void update(struct src t,int& num_money){
	//---Money---
// miner ++ 
// add -- (done) 
// time ++
// I write this function and put it in each of these 5 functions to update the money in each round ...
	//---j---
//
	//---h---
}

void money_status(struct src t){

}
int total ;// total number of people it must not exsceed 50 //
int A[10] ;  
int main(){
int main_money = 500 ; 
int mt = 0 ;  
int q , h ; 
int idx = 1; 
int num_miner  = 0 ;
cin >> q >> h ; 
for(int i = 0 ; i <= q ; ++i ){
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
	// Or you must do the preprocesesing in each function you have 
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
		
// try to parse the time 
//sscanf(t.strings[j-1] , "%s:%s:%s" , t.min.data() , t.second.data() , t.second.data());
// there is a feature that is the same over all inputs and that is we have 2 character for min ,2 for second and 3 for msecond
string buffer ; 
int num ; 
int B[] = {0,2,5,9} ;
int w = 0; 
for(int i = 0 ; i < 3 ; i++){
	buffer = t.strings[l-1].substr(B[i]+1 , (B[i+1] - B[i]-1));
	num = stoi(buffer);
	if(!w){
		t.min = num ;
		w++; 
	}else if(w = 1){
		t.second = num ; 
		w++;
	}else{
		t.msecond = num  ;
		w++ ; 
	}
}
}
// another parser for strings to ints 
int z = 0; 
for(int i = 0 ; i < l-1 ; ++i ) {
	if(t.strings[i][0] <= 122 && t.strings[i][0] >= 97 ){
		// yeah it's a number ...
	t.ints[z] = stoi(t.strings[i]);
	z++; 
	}
}
int hash_score = (int) s[0];
if(hash_score == 12 ){
	if((int)s[0] == 101 ) {
	hash_score = 101 ;  
	}else{
		hash_score = 109 ; 
	}
}
/*
t.id[0] = &h ; 
t.id[1] = &main_money ; 
t.id[2] = &total ; 
t.id[3] = &num_person ; 
*/
	switch(hash_score){
		case 3:
			addd(t,h,main_money,total,idx,num_miner);
			break;		
		case 6:
			damage(t,h,main_money,total,idx,num_miner);
			break;
		case 101:
			enemy_status(t,h);
			break;
		case 11:  
			army_status(t,h);
			break;
		case 109:
			money_status(t) ; 
			break;

			for(int i = 0 ; i <= j ; i++){
				A[j] = 0 ;
				}
	}
}
}


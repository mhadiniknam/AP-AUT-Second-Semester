#include <iostream> 
#include <string>
#include <vector>
#include <cstdio>
// pol khob kar nemikone 
// damage khob kar nemide 
// ------Leader-Board-----
// shayad braye khroji tavabe niyaz bashe ke \n bezarim ... ?
// delete to manage the memory :: benazar miyad in kar momken nist chon bayad chack kone morde ya na  
using namespace std ;
string s ;
 struct src {
	 int second ; 
	 int msecond ; 
	 //int last_second = 0 ; 
	 //int last_msecond = 0 ; 
	 string strings[10] ; 
	 int ints[10] ;
	 int num_update = 0 ;
//	 int id[3] ;//h ,  main_money , total , num_person 
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
		// zaman ezafe shodan 
		int second ; 
		int msecond ;
		int num_update ;
};
class miner : public master {
	public :
	miner(){	
		type = 1 ;
	unit = 1; 
	j = 100 ; 
	money = 150 ; 
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
void update(struct src * t,int * num_money, int * h){
//bayad roye hame itterate konim 
// bayad tedad tanavob hayei ke az aval gozashte hesab beshe ... va dar nahayat in adadro dar dar pol zarb konim va jam bezanim hamaro
// t = time-alan - time estekhdam 
// carry = t%tanavob
// t - carry 
// t/tanavob

	for(auto& x : db ){
			if(x->j > 0 ){
		if(x->type == 1) {
			if(x->active == 1){
				int sub = t->second - x->second ;
				int carry = sub % x->t ; 
		 		sub /= x->t ; 
				if(carry == 0){
					if((t->msecond - x->msecond ) < 0){
						sub -= 1 ;
					}
				}
					sub -= x->num_update ;
				if(sub > 0 ){
					//it mean it's time for update ... 
					(x->num_update) += sub ; 
					sub = sub * (x->zarbe) ;
					*(num_money) += sub ; 
				}
				/*
				if((t->second - x->second) >=(x->t)){
					if((t->msecond - x->msecond) >=0){
					       //it means it's time for update ... 
						num_money += x->zarbe ; 
						x->second = t->second ; 
						x->msecond = t->msecond ; 
					}	
				}
				*/
			}
		}else{
				int sub = t->second - x->second ;
				int carry = sub % x->t ; 
		 		sub /= x->t ; 
				if(carry == 0){
					if((t->msecond - x->msecond ) < 0){
						sub -= 1 ;
					}
				}
					sub -= x->num_update ;
				if(sub > 0 ){
					//it mean it's time for update ... 
					(x->num_update) += sub ; 
					sub = sub * (x->zarbe) ;
					*(h) -= sub ; 
				}
			}
			/*
				if((t->second - x->second) >=(x->t)){
					if((t->msecond - x->msecond) >= 0){
					       //it means it's time for update ... 
						*h -= x->zarbe ; 
						x->second = t->second ; 
						x->msecond = t->msecond ; 
					}	
				}
				*/
			}	
		}
	//---Money---
// miner ++ (done) 
// add -- (done) 
// time ++ 
// We need somewhere to store the last update ... 
//cout << t->second << " " << t->last_second << "\n" ; 
//cout << t->msecond << " " << t->last_msecond << "\n" ; 
				int sub = t->second  ;
		 		sub /= 20 ;
				sub -= t->num_update;
				if(t->msecond >= 1){
				if(sub > 0 ){
					//it mean it's time for update ... 
					(t->num_update) += sub ; 
					sub = sub * (180) ;
					*(num_money) += sub ; 
				}
				}
/*
if((t->second - t->last_second) >= 20 ){
	if((t->msecond - t->last_msecond) >= 0 ){
		t->last_msecond = t->msecond ; 
		t->last_second = t->second ; 
		*num_money += 180 ; 
	}
}
*/
}
// I write this function and put it in each of these 5 functions to update the money in each round ...
	//---h--- we do that above code ... 
void addd(struct src *t,int *h , int *num_money , int *total , int *idx , int *num_miner ){	
	string s  = t->strings[0] ;
	char c = s[2] ;
	update(t,num_money,h);
	master* y = nullptr ; 
	switch(c){
		// to make it even faster I make another hash with the third charater
		case 'n':{
			y = new miner()  ; 
			break ; 
			 }
		case 'o':{
			y = new swordwarth() ; 
			break ; 
			 }
		case 'c':{
			y = new archidon() ; 
			break ; 
			 }
		case 'e':{
			y = new spearton() ; 
			break ; 
			 }
		case 'g':{
			y = new magikill() ; 
			break ; 
			 }
		case 'a':{
			y = new giant(); 
			break ;
			 } 
	}

int flag = 1 ; 
	if( *h <= 0 ) {
		flag = 0 ; 
		cout << "game over" ; 
	}
	if(flag){
		if(*num_money < y->money ){
			cout << "not enough money" ;
		flag = 0 ;
		}
	}
	if(flag){
		if( *total >  50 ){
			cout << "too many army" ; 
		flag = 0 ; 
		}
	}
	if(flag){
		y->idx = *idx ; 
		if(y->type == 1 )
		{
			if(*num_miner <= 7){
				y->active = 1; 
			}else{
				y->active = 0 ;
			}

			*(num_miner) += 1; 
		}
			y->num_update = 0 ;
			y->second = t->second; 
			y->msecond = t->msecond ;
			*total += y->unit ; 
			db.push_back(y) ; 
			*num_money -= y->money ; 
			cout << *idx ; 
			*(idx) += 1 ; 
		}
			delete y ; 
}
void damage(struct src * t,int *h , int *num_money , int *total , int *idx , int * num_miner) {
	update(t,num_money,h);
	t->ints[0] = stoi(t->strings[0]);
	t->ints[1] = stoi(t->strings[1]);

// Maybe it does not have some optimize search because doing itteration on db is expensive
// Maybe it was better to have a specialized db for each role ... 
int flag = 1 ;
	if(*h <= 0 ) {
		flag = 0 ; 
		cout << "game over" ; 
	}
	master* y = nullptr ; 
	if(flag){
		for(auto& x : db ){
			if(x->idx == t->ints[0]){
			 	y = x ;
				break ;
			}
		}
		if(y == nullptr ){
			flag = 0 ;
			// if you did not find it ... 
		}	
		if(flag){
		if(y->j <= 0 ){
			flag = 0;
		}
		}
		
		if(!flag){
			cout << "no matter" ;
			return;
		}
		
	}
	if(flag){
		y->j -= t->ints[1] ; 
		if(y->j <= 0 ){
			cout << "dead" ; 
			*total -= y->unit ; 
				if(y->type == 1 ) {
					if(y->active == 1){
						y->active = 0 ;
					if(*(num_miner) >= 9 ){
						master *  x = nullptr ;
						for(auto& x : db ){
						int flag1 = 1 ;
						if(flag1){
						if(x->type == 1 ) {
							if(x->active == 0){
								x->active = 1 ;	
								flag1 = 0 ; 
								}
							}
						}	
						}
						delete x ; 
					}else{
						*(num_miner) -= 1 ;
					}					
				}
			}
		}else{
		cout << y->j ; 
		}
			}
			delete y ; 
}
void enemy_status(struct src *t,int *h,int * num_money){
	update(t,num_money,h);
	if(*h <= 0 ) {
		cout << "game over";
	}else{
		cout << *h ; 
	}
}	
	int c[5] ; 
void army_status(struct src * t , int *h,int * num_money ){
	update(t,num_money,h);
	for(int i  = 0 ; i <= 5 ; ++i){
		c[i] = 0 ;
	}
	int flag = 1; 
	if(*h <= 0 ) {
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
void money_status(struct src * t,int* num_money,int * h ){
	update(t,num_money,h);
	if(*h <= 0 ){
		cout << "game over" ;
	}else{
		cout << *num_money ; 
	}
}
int total ;// total number of people it must not exsceed 50 //
int A[10] ;  
int main(){
int main_money = 500 ; 
int q , h ; 
int idx = 1; 
int num_miner  = 0 ;
scanf("%d %d\n",&q,&h);
for(int i = 0 ; i <  q ; ++i ){
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
		//cout << l ; 
// try to parse the time 
//sscanf(t.strings[j-1] , "%s:%s:%s" , t.min.data() , t.second.data() , t.second.data());
// there is a feature that is the same over all inputs and that is we have 2 character for min ,2 for second and 3 for msecond
}
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
if(hash_score == 97 ){
	if((int)s[1] == 100) {
	hash_score = 102 ;  
	}else{
		hash_score = 114; 
	}
}

/*
t.id[0] = &h ; 
t.id[1] = &main_money ; 
t.id[2] = &total ; 
t.id[3] = &num_person ; 
*/
	switch(hash_score){
		case 102:
			addd(&t,&h,&main_money,&total,&idx,&num_miner);
			break;		
		case 100:
			damage(&t,&h,&main_money,&total,&idx,&num_miner);
			break;
		case 101:
			enemy_status(&t,&h,&main_money);
			break;
		case 114:  
			army_status(&t,&h,&main_money);
			break;
		case 109:
			money_status(&t,&main_money,&h); 
			break;

			for(int i = 0 ; i <= j ; i++){
				A[j] = 0 ;
				}
	}
}
}

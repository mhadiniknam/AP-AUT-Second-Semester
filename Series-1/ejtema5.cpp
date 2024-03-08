#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
double inf = std::numeric_limits<double>::infinity();
double minf = -std::numeric_limits<double>::infinity();
vector<double> v1;
int flag , a , b, n ;
double t , min ;
char p , q ;
int main(){
cin >> n ;
int mflaginf , flaginf;
for(int i = 0 ; i < n+1 ; i++ ){
	scanf("%c%d, %d%c",&p,&a,&b,&q);
	if(a != mnif || a != (-1)*inf){
	if(p == '['){
		v1.push_back(((double)a)-0.1);
		}else{
		v1.push_back(((double)a)+0.1);
		}
	}else{
		mflaginf = 1 ; 
	}

	if(a != mnif || a != (-1)*inf){
		       if(q == ']'){
		v1.push_back(((double)b)+0.1);
		}else{
		v1.push_back(((double)b)-0.1);
		} 
	}else{
		flaginf = 1 ; 
	}	
if(flaginf != 1 || mflaginf != 1 ){
		      for(int j = a+1 ; j <= b-1 ; j++){
			     v1.push_back(j);
		      } 
}

}
sort(v1.begin(),v1.end(),[](double x ,double y){return x > y;});
reverse(v1.begin() , v1.end());
v1.erase(remove(v1.begin(), v1.end(), -0.1), v1.end());
v1.erase(remove(v1.begin(), v1.end(), -0.1), v1.end());
v1.erase(remove(v1.begin(), v1.end(), 0.1), v1.end());
flag = 1; 
for (auto i = v1.begin() ; i != v1.end() ; ++i){
if(flag){
min = *i ; 
flag = 0 ; 
}
if((*i - t ) <= 1.2 ){
		t = *i ;
}else{
flag =1 ; 
if(fmod(min == 0.1)){
		cout << (min-0.1) ;
		}

if(fmod(min == 0)){
	cout << min
	}


if(fmod(min == 0.9){
	cout << (min + 0.1)
}
cout <<", " ;
if(fmod(i* == 0.1)){
		cout << (*i-0.1) ;
		}

if(fmod(min == 0)){
	cout << (*i)
	}


if(fmod(min == 0.9)){
	cout << (*i + 0.1)
}
	//cout << *i << " " ; 
}


return 0 ;
}


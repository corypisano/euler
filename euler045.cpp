#include <iostream>
#include <iomanip>
using namespace std;

inline double hex(int n){
	return n*(2*n-1);}
inline double pent(int n){
	return (n*(3*n-1))/2;}


int main(){
	int g;
	for (int a=40000;a<=50000;a++){
		for (int b=40000;b<=50000;b++){
			if (hex(a)==pent(b)){
				cout << hex(a) << endl;
			}
		}
		
	}
	cin >> g;
	return 0;
}
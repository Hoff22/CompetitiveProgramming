#include <bits/stdc++.h>
 
#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first
 
using namespace std;
 
void solve(){
	string a_;
	string b_;
 
	cin >> a_ >> b_;
 
	int a = 0;
	int b = 0;
 
	for(char c : a_){
		if(c == 'X') a += 10;
		if(c == 'L' or c == 'S') a += 1;
		if(c == 'S') a *= -1;
	}
	for(char c : b_){
		if(c == 'X') b += 10;
		if(c == 'L' or c == 'S') b += 1;
		if(c == 'S') b *= -1;
	}
 
	if(a < b){
		cout << "<"<< endl;
	}
	else if(a > b){
		cout << ">"<< endl;
	}
	else{
		cout << "="<< endl;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;
 
}
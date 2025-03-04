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

int try1(string a, string b){

	int goodA = 1;
	for(int i = 0; i < a.size()-1; i++){
		if(a[i] == a[i+1]) goodA = 0;
	}
	int goodB = 1;
	for(int i = 0; i < b.size()-1; i++){
		if(b[i] == b[i+1]) goodB = 0;
	}

	return (goodA == 1 and goodB == 1);
}

void solve(){
	int a, b;
	cin >> a >> b;
	string sa, sb;
	cin >> sa >> sb;

	string ta = sa;
	string tb = sb;

	while(ta.size() >= 1){
		if(try1(ta,tb)){
			cout << "YES\n";
			return;
		}
		tb = tb + ta[ta.size()-1];
		ta = ta.substr(0, ta.size()-1);
	}
	ta = sa;
	tb = sb;
	while(tb.size() >= 1){
		if(try1(ta,tb)){
			cout << "YES\n";
			return;
		}
		ta = ta + tb[tb.size()-1];
		tb = tb.substr(0, tb.size()-1);
	}
	cout << "NO\n";
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
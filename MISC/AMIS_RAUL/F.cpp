#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

#define endl '\n'

using namespace std;

int bt(int cur, int ods, int evs, int play){
	if(ods + evs == 0) return cur;

	if(ods and evs){
		if(
			bt(!cur, ods-1, evs, !play) == play or
			bt(cur, ods, evs-1, !play) == play
			){
			return play;
		}
		return !play;
	}
	if(ods){
		return bt(!cur, ods-1, evs, !play);
	}
	if(evs){
		return bt(cur, ods, evs-1, !play);
	}
}

void solve(){
	int n;
	cin >> n;

	int odds = (n-1) / 2;	
	int evens = n / 2;

	if(bt(1, odds, evens, 0)){
		cout << "grimy" << endl;
	}	
	else{
		cout << "black" << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}
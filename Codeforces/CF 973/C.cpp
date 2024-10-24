#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

string cur;
set<string> bad;

bool canPutEnd(string suf){
	if(bad.count(suf)) return 0;
	for(int i = 0; i < cur.size(); i++){
		if(bad.count(cur.substr(i, cur.size()-i) + suf)){
			return 0;
		}
	}
	return 1;
}

bool canPutBeg(string pref){
	if(bad.count(pref)) return 0;
	for(int i = 0; i < cur.size(); i++){
		if(bad.count(pref + cur.substr(0, i+1))){
			return 0;
		}
	}
	return 1;
}

void solve(){
	int n;
	cin >> n;

	cur = "";
	bad.clear();

	while(cur.size() != n){
		int res;
		if(canPutEnd("0")){
			cout << "? " << cur + "0" << endl;
			cin >> res;
			if(res == -1) exit(0);
			if(res){
				cur += "0";
			}
			else{
				bad.insert(cur + "0");
			}
		}
		else if(canPutEnd("1")){
			cout << "? " << cur + "1" << endl;
			cin >> res;
			if(res == -1) exit(0);
			if(res){
				cur += "1";
			}
			else{
				bad.insert(cur + "1");
			}
		}
		else if(canPutBeg("0") and canPutBeg("1")){
			cout << "? " << "0" + cur << endl;
			cin >> res;
			if(res == -1) exit(0);
			if(res){
				cur = "0" + cur;
			}
			else{
				bad.insert("0" + cur);
				cur = "1" + cur;
			}
		}
		else if(canPutBeg("0")){
			cur = "0" + cur;
		}
		else{
			cur = "1" + cur;
		}
		// cout << cur << endl;
	}

	cout << "! " << cur << endl;
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
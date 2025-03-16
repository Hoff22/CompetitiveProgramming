#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int isNum(const string &s, int i, int j){
	int ans = 0;
	for(int k = i; k < j; k++){
		if(s[k] < '0' or s[k] > '9') return -1;
		ans = (ans * 10) + (s[k] - '0');
	}
	return ans;
}

void solve(){
	long long ans = 0;
	vector<string> tk;

	string l;
	while(cin >> l){
		for(int i = 0; i < l.size(); i++){

			char c = l[i];

			if(c == 'd' and i + 6 < l.size()){
				if(l[i+1] == 'o' and l[i+2] == 'n' and l[i+3] == '\'' and l[i+4] == 't' and l[i+5] == '(' and l[i+6] == ')'){
					tk.push_back("don't()");
					tk.push_back("");
					i = i+6;
					continue;
				}
			}

			if(c == 'd' and i + 3 < l.size()){
				if(l[i+1] == 'o' and l[i+2] == '(' and l[i+3] == ')'){
					tk.push_back("do()");
					tk.push_back("");
					i = i+3;
					continue;
				}
			}

			if(c == 'm'){
				if(!tk.empty() and tk.back() == ""){
					tk.back().push_back(c);
				}
				else{
					tk.push_back("m");
				}
			}
			else if(!tk.empty()){
				tk.back().push_back(c);
				if(c == ')') tk.push_back("");
			}
		}
	}

	bool enabled = 1;

	for(auto s : tk){
		cout << endl;
		cout << s;

		if(s == "do()"){
			// cout << "do !!!!!" << endl;
			enabled = 1;
		}
		if(s == "don't()"){
			// cout << "dont !!!!!!" << endl;
			enabled = 0;
		}

		// min mul(1,1) = 8
		// max mul(111,111) = 12
		if(s.size() > 12 or s.size() < 8) continue;
		if(s[1] != 'u' or s[2] != 'l' or s[3] != '(') continue;

		int a = -1, b = -1;

		// cout << endl;

		// cout << " > pass 1" << endl; 

		int comma = 0;
		for(int i = 4; i < s.size()-1; i++){
			if(s[i] == ','){
				comma++;
				if(comma == 1){
					// cout << " > comma " << i << endl; 
					a = isNum(s, 4, i);
					b = isNum(s, i+1, s.size()-1);
					// cout << " > a " << a << endl; 
					// cout << " > b " << b << endl; 
				}
			}
		}

		if(comma != 1) continue;
		if(a < 0 or b < 0) continue;

		if(enabled){
			ans = ans + (a*b);
			cout << " o " << (a*b);
		}
		else{
			cout << " x " << (a*b);
		}
	}

	cout << tk.size() << endl;
	cout << "ans: " << ans << endl;
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
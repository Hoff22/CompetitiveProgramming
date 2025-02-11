#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define fi first
#define se second

using namespace std;

map<string,long long> freq;
map<string,string> pre;
map<string,string> suf;

int cntHaha(string s){
	int r = 0;
	for(int i = 0; i < s.length(); i++){
		r += (s.substr(i,4) == "haha");
	}
	return r;
}

void solve(){

	freq.clear();
	pre.clear();
	suf.clear();

	int n;
	cin >> n;


	string s;
	for(int i = 0; i < n; i++){
		string var;
		cin >> var;

		string op;
		cin >> op;

		if(op == ":="){
			string x;
			cin >> x;

			string prefix = x.substr(0,3);
			string suffix = x.substr(max(0,(int)x.length()-3));

			freq[var] = cntHaha(x);
			pre[var] = prefix; 
			suf[var] = suffix; 
		}
		else{
			string a, b;
			string plus;
			cin >> a >> plus >> b;

			string x = suf[a] + pre[b];

			freq[var] = freq[a] + freq[b] + cntHaha(x);

			string prefix = pre[a] + pre[b];
			string suffix = suf[a] + suf[b];

			prefix = prefix.substr(0, 3);
			suffix = suffix.substr(max(0,(int)suffix.length()-3));

			pre[var] = prefix;
			suf[var] = suffix;

			// cout << "\t" << x << endl;
			// cout << pre[var] << " " << suf[var] << endl;
		}

		s = var;
	}

	//cout << ends[s].fi << " " << ends[s].se << endl;
	cout << freq[s] << endl;

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
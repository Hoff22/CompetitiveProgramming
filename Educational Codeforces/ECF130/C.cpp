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
	int n;
	cin >> n;

	string s ,t;
	cin >> s >> t;

	s = "-"+s;
	t = "-"+t;

	string as, at;
	for(int i = 0; i <= n; i++){
		if(s[i] != 'b') as+=s[i];
		if(t[i] != 'b') at+=t[i];
	}

	if(as != at){
		cout << "NO\n";
		return;
	}

	vector<int> bt;
	vector<int> bs;
	vector<int> sumA(n+1);
	vector<int> sumC(n+1);
	sumA[0] = 0;
	sumC[0] = 0;

	for(int i = 1; i <= n; i++){
		if(t[i] == 'b') bt.push_back(i);
		if(s[i] == 'b') bs.push_back(i);
		

		sumA[i] = sumA[i-1] + (s[i] == 'a');
		sumC[i] = sumC[i-1] + (s[i] == 'c');
	}

	// for(int i : sum){
	// 	cout << i << " ";
	// }
	// cout <<"\n";

	int good = 1;
	for(int i = 0; i < bs.size(); i++){
		int beg = bs[i];
		int tar = bt[i];

		if(beg < tar){
			if(sumA[tar] - sumA[beg-1] > 0) good = 0;
		}
		else if(beg > tar){
			if(sumC[beg] - sumC[tar-1] > 0) good = 0;
		}
	}

	
	if(good) cout << "YES\n";
	else cout << "NO\n";

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
// ababab
// bababa
// bbabaa
// bbbaaa

    // abbbaa
    // babbaa
    // bbabaa
    // bbbaaa

    // bcaabaab
    // cbabaaba
    // 
}

// 0  1  2  3  4  5  6

// -  a  b  b  a  b  c
// 0 -1 -1 -1 -2 -2 -1

//    b  b  a  a  c  b

// aaabab
// bbaaaa
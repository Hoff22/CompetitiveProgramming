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
	string s;
	int n;
	cin >> n >> s;

	if(n % 2){
		cout << -1 << endl;
		return;
	}

	map<char, long long> cnt;
	map<pair<char,char>, long long> cntb;
	for(int i = 0; i < n/2; i++){
		if(s[i] == s[n-i-1]) cnt[s[i]]++;
		else{
			cntb[{s[i], s[n-i-1]}]++;
		}
	}

	long long sum = 0;
	long long mx = 0;
	for(auto g : cnt){
		sum += g.se;
		if(cnt[mx] < g.se){
			mx = g.fi;
		}
	}

	if(cnt[mx] > sum-cnt[mx]){

		long long of = cnt[mx] - (sum-cnt[mx]);

		long long sum_b = 0;
		for(auto g : cntb){
			if(g.fi.fi != mx and g.fi.se != mx){
				sum_b += g.se;
			}
		}

		if(sum_b < of){
			cout << -1 << endl;
		}
		else{
			cout << sum / 2 + of << endl;
		}

	}
	else{

		if(sum % 2){
			vector<int> cnt_c(26,0);
			for(auto g1 : cntb){
				for(int c = 0; c < 26; c++){
					if(g1.fi.fi-'a' != c and g1.fi.se-'a' != c){
						cnt_c[c]++;
					}
				}
			}

			int good = 0;
			for(auto g : cnt){
				if(cnt_c[g.fi]){
					good = 1;
				}
			}
			if(!good){
				cout << -1 << endl;
				return;
			}
		}

		cout << (sum+1) / 2 << endl;
	}
}

/*

0 1 2 3 4

abccba
^^^

a 1 
b 1 
c 1

aacdaaaacadcdc
  ^^^ ^^ ^^^
  c 1
  d 1
  a 2  

  taarrrataa

dcbdb dcccc
 ^  

aadaa aaddc
aadaa aaddc
  ^^^

d 1
a 2

*/

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
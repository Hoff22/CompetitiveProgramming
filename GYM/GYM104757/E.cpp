#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

#define N 100

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<unsigned long long> p2;
	for(unsigned long long i = 1; i <= (1ll<<53); i*=2){
		p2.insert(i);
	}

	string s;
	cin >> s;

	for(int i = 0; i < s.size()-1; i++){
		if(s[i] == s[i+1] and s[i] == 'O'){
			cout << "INVALID" << endl;
			return 0;	
		}
		if(s[i] != 'O' and s[i] != 'E'){
			cout << "INVALID" << endl;
			return 0;
		}
	}

	if(s.back() != 'O'){
		cout << "INVALID" << endl;
		return 0;
	}

	reverse(s.begin(), s.end());

	unsigned long long ans = (1ll<<47)+1ll;

	for(long long p = 2; p <= (1ll<<53); p *= 2){
		unsigned long long cur = p;
		int i;
		for(i = 0; i < s.size(); i++){
			// cout << cur << " ";
			if(s[i] == 'O'){
				if((cur-1) % 3 != 0) break;
				cur = (cur - 1ll) / 3ll;
			}
			else{
				if(p2.count(cur)) break;
				cur = cur*2ll;
			}
		}
		if(cur > (1ll<<47)){
			continue;
		}
		if(i == s.size()) ans = min(ans, cur);
	}

	if(ans == (1ll<<47)+1ll){
		cout << "INVALID" << endl;
		return 0;
	}

	cout << ans << endl;

	return 0;

}
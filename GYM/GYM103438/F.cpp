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

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ll n, x, r ,p ,k;
	cin >> n >> x >> r >> p >> k;

	string s;
	cin >> s;

	ll ans = 0;

	vector<ll> pos;
	vector<ll> st;
	for(ll i = 0; i < n; i++){
		if(i < k){
			st.push_back(i);
		}
		else if(s[i] == '1'){
			pos.push_back(i);
		}
	}

	// cout << "st:\n";
	// for(int i : st) cout << i << " ";
	// cout << endl;
	// cout << "pos:\n";
	// for(int i : pos) cout << i << " ";
	// cout << endl;

	ans = x * n;
	int j = st.size()-1;
	int i = 0;
	for(; i < pos.size(); i++){
		if(j < 0) break;
		if(s[st[j]] == '1'){
			j--;
			i--;
			continue;
		}

		// cout << p * (n-st[j]) - r * (n - pos[i]) << " " << p * (n - pos[i]) << endl;

		if(p * (n-st[j]) - r * (n - pos[i]) >= p * (n - pos[i])){
			break;
		}
		else{
			st[j] = pos[i];
			pos[i] = n;
			j--;
		}
	}

	for(int id = 0; id < pos.size(); id++){
		ans -= r * (n-pos[id]);
	}
	for(int id = 0; id < st.size(); id++){
		ans += p * (n-st[id]);
	}

	cout << ans << endl;

    return 0;

}
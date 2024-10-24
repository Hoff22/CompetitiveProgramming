#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

int dp(int i, int z, int o){
	if(i == n){
		if(z and !o) return 0;
		return 1;
	}

	if(z and !o){
		return dp(i+1, z | (a[i] == 0), o | (a[i] == 1));
	}

	return max(
		dp(i+1, z | (a[i] == 0), o | (a[i] == 1)),
		dp(i+1, (a[i] == 0), (a[i] == 1)) + 1
		);
}


#define K 12

bool valid(int x, int n){
	stack<int> st;
	// 0 = abre
	for(int i = 0; i < n; i++){
		if(((x>>i) & 1) and st.empty()) return false;
		if(((x>>i) & 1)) st.pop();
		else{
			st.push(i);
		}
	}
	return st.empty();
}

void print(int x, int sz = K){
	for(int i = 0; i < sz; i++){
		cout << (((x>>i) & 1) ? ')' : '(');
	}
	cout << endl;
}

void solve(){
	int cnt =0;
	for(int i = 0; i < (1<<K); i++){
		if(!valid(i,K)) continue;
		// print(i);
		// cout << endl;
		// 0 = abre
		for(int j = 0; j < (1<<K); j++){
			int s1 = 0;
			int s2 = 0;

			int sz1 = __builtin_popcount(j);
			int sz2 = K - sz1;

			for(int k = 0, of = 0; k < K; k++){
				if(((i>>k) & 1) && ((j>>k) & 1)){
					s1 += (1<<of);
				}
				if(((j>>k) & 1)) of++;
			}

			for(int k = 0, of = 0; k < K; k++){
				if(((i>>k) & 1) && !((j>>k) & 1)){
					s2 += (1<<of);
				}
				if(!((j>>k) & 1)) of++;
			}

			// cout << "  ";
			// print(s1);
			// cout << "  ";
			// print(s2);

			if(__builtin_popcount(s1) != sz1/2 or __builtin_popcount(s2) != sz2/2) continue;

			if(!valid(s1,sz1) and !valid(s2,sz2)){
				cnt++;
				cout << "!!!  ";
				print(i);
				cout << "1 >  ";
				print(s1,sz1);
				cout << "2 >  ";
				print(s2,sz2);
				break;
			}
		}
	}
	cout << cnt << endl;
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
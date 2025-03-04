#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

long long sum[N+1][5];
int last[N+1][5];

void solve(){
	string s;
	cin >> s;

	int n = s.size();

	long long v[5] = {1ll,10ll,100ll,1000ll,10000ll};

	sum[0][0] = sum[0][1] = sum[0][2] = sum[0][3] = sum[0][4] = 0ll;
	last[0][0] = last[0][1] = last[0][2] = last[0][3] = last[0][4] = 0;


	long long total = 0;
	for(int i = 1; i <= n; i++){
		for(int k = 0; k < 5; k++) sum[i][k] = sum[i-1][k];
		for(int k = 0; k < 5; k++) last[i][k] = last[i-1][k];

		if(s[i-1] == 'A'){
			sum[i][1] += 1ll;
			sum[i][2] += 1ll;
			sum[i][3] += 1ll;
			sum[i][4] += 1ll;
		}
		else if(s[i-1] == 'B'){
			sum[i][2] += 10ll;
			sum[i][3] += 10ll;
			sum[i][4] += 10ll;
		}
		else if(s[i-1] == 'C'){
			sum[i][3] += 100ll;
			sum[i][4] += 100ll;
		}
		else if(s[i-1] == 'D'){
			sum[i][4] += 1000ll;
		}

		last[i][s[i-1]-'A'] = i;
	}
	// for(int i = 0; i <= n; i++ ){
	// 	cout << i << ":\t";
	// }
	// cout << endl;
	// for(int k = 0; k < 5; k++){
	// 	for(int i = 0; i <= n; i++ ){
	// 		cout << sum[i][k] << "\t";
	// 	}
	// 	cout << endl;
	// }

	char mx = 'A';
	for(int i = n; i >= 1; i--){
		if(mx > s[i-1]){
			total -= v[s[i-1]-'A'];
		}
		else{
			total += v[s[i-1]-'A'];
		}
		mx = max(mx, s[i-1]);
	}

	// cout << total << endl << endl;


	mx = 'A';
	long long ans = -INFLL;
	for(int i = n; i >= 1; i--){

		if(s[i-1] < mx){
			for(int k = mx-'A'; k < 5; k++){
				long long mx_cont = sum[i-1][mx-'A'] - sum[last[i-1][k]][mx-'A'];
				long long cur_cont = sum[i-1][k] - sum[last[i-1][k]][k];
				// cout << total << " " << sum[i-1][mx-'A'] <<" "<< sum[i-1][k] <<" "<< v[s[i-1]-'A'] << " " << v[k] << endl;
				// cout << " " << total + sum[i-1][mx-'A'] - sum[i-1][k] + v[s[i-1]-'A'] << endl;
				ans = max(ans, total + 2*mx_cont - 2*cur_cont + v[s[i-1]-'A'] + v[k]);
				// sb = s;
				// sb[i-1] = 'A'+k;
				// cout << sb << " " << ans << endl;
			}
		}
		else{
			for(int k = mx-'A'; k < 5; k++){
				long long mx_cont = sum[i-1][mx-'A'] - sum[last[i-1][k]][mx-'A'];
				long long cur_cont = sum[i-1][k] - sum[last[i-1][k]][k];
				// cout << total << " " << sum[i-1][mx-'A'] <<" "<< sum[i-1][k] <<" "<< v[s[i-1]-'A'] << " " << v[k] << endl;
				// cout << " " << total + sum[i-1][mx-'A'] - sum[i-1][k] + v[s[i-1]-'A'] << endl;
				ans = max(ans, total + 2*mx_cont - 2*cur_cont - v[s[i-1]-'A'] + v[k]);
				// string sb = s;
				// sb[i-1] = 'A'+k;
				// cout << sb << " " << ans << endl;
			}
		}

		//cout << best << endl;
		mx = max(mx, s[i-1]);
	}

	cout << ans << endl;
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
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
	long long cntS[26];
	long long cntT[26];

	memset(cntS, 0, sizeof(cntS));
	memset(cntT, 0, sizeof(cntT));

	cntS[0] = 1;
	cntT[0] = 1;

	int q;
	cin >> q;

	long long sizeS = 1;
	long long sizeT = 1;
	
	while(q--){
		int op, k;
		string x;

		cin >> op >> k >> x;


		for(char c : x){
			if(op == 1){
				cntS[c - 'a']+=k;
				sizeS += k;
			}
			if(op == 2){
				cntT[c - 'a']+=k;
				sizeT += k;
			}
		}	

		long long q_sizeS = sizeS;
		long long q_sizeT = sizeT;

		int i = 0;
		do{
			q_sizeS -= cntS[i];
			q_sizeT -= cntT[i];
			i++;
		}while(i < 26 and cntS[i] == cntT[i]);

		//cout << i << endl;

		if(i == 26){
			cout << "NO\n";
			continue;
		}
		
		q_sizeS -= min(cntS[i], cntT[i]);
		q_sizeT -= min(cntS[i], cntT[i]);

		if(!q_sizeS and q_sizeT) cout << "YES\n";
		else if(cntS[i] > cntT[i]) cout << "YES\n";
		else cout << "NO\n";
	}

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
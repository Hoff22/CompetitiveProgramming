#include <bits/stdc++.h>

#define N 2000
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

vector<string> a;
string digis[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int DP[N+1][N+1];

int solve(int i, int k){
	if(i == a.size()) return (k==0);

	if(DP[i][k] != -1) return DP[i][k];

	int r = 0;

	for(int d = 9; d >= 0; d--){
		bool good = 1;
		int cnt = 0;
		for(int p = 0; p < 7; p++){
			if(digis[d][p] == '0' and a[i][p] == '1') good = 0; 
			if(digis[d][p] == '1' and a[i][p] == '0') cnt++; 
		}
		if(!good or cnt > k) continue;

		r |= solve(i+1, k-cnt);

		if(r) break;
	}

	return DP[i][k] = r;
}

void rec(int i, int k){

	if(i == a.size()) return;

	int r = 0;

	for(int d = 9; d >= 0; d--){
		bool good = 1;
		int cnt = 0;
		for(int p = 0; p < 7; p++){
			if(digis[d][p] == '0' and a[i][p] == '1') good = 0; 
			if(digis[d][p] == '1' and a[i][p] == '0') cnt++; 
		}
		if(!good or cnt > k) continue;

		r |= solve(i+1, k-cnt);

		if(r){
			cout << d;
			rec(i+1, k-cnt);
			break;
		}
	}

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		a.push_back(s);
	}

	memset(DP, -1, sizeof(DP));

	if(solve(0,k)){
		rec(0,k);
		cout << endl;
	}
	else{
		cout << -1 << endl;
	}
   
    return 0;
}
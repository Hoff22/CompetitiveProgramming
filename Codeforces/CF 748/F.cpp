#include <bits/stdc++.h>
 
#define N 40
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

vector<int> a;
int dp[N+1][N][N][N+1];
int p10A[N+1];
int p10B[N+1];
int n,A,B;

int solve(int idx, int rA, int rB, int cntA){
	if(idx == n){
		//printf("%d %d %d\n", rA, rB, cntA);
		if(!rA and !rB)	return cntA;
		else return INF;
	}

	if(dp[idx][rA][rB][cntA] != -1) return dp[idx][rA][rB][cntA];

	int nA, nB;

	nA = (p10A[cntA] * a[idx]) % A;
	nB = (p10B[idx - cntA] * a[idx]) % B;

	nA = (nA + rA) % A;
	nB = (nB + rB) % B;

	int s1 = solve(idx+1, nA, rB, cntA+1);
	int s2 = solve(idx+1, rA, nB, cntA);

	if(abs(s1 - n/2) > abs(s2 - n/2)) return dp[idx][rA][rB][cntA] = s2;
	return dp[idx][rA][rB][cntA] = s1;
}

string reconstruct(int idx, int rA, int rB, int cntA){
	if(idx == n){
		return "";
	}

	int nA, nB;

	nA = (p10A[cntA] * a[idx]) % A;
	nB = (p10B[idx - cntA] * a[idx]) % B;

	nA = (nA + rA) % A;
	nB = (nB + rB) % B;

	int s1 = solve(idx+1, nA, rB, cntA+1);
	int s2 = solve(idx+1, rA, nB, cntA);

	if(abs(s1 - n/2) > abs(s2 - n/2)){
		return "B" + reconstruct(idx+1, rA, nB, cntA);	
	} 
	return "R" + reconstruct(idx+1, nA, rB, cntA+1);
}

void go(){
	cin >> n >> A >> B;

	p10A[0] = 1;
	p10B[0] = 1;
	for(int i = 1; i <= N; i++){
		p10A[i] = (p10A[i-1] * 10) % A;
		p10B[i] = (p10B[i-1] * 10) % B;
	}

	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		a.push_back((c - '0'));
	}

	memset(dp, -1, sizeof(dp));

	reverse(a.begin(), a.end());

	string ans = reconstruct(0,0,0,0);

	int i;
	for(i = 1; i < ans.size(); i++){
		if(ans[i] != ans[i-1]) break;
	}

	if(i < ans.size()){
		reverse(ans.begin(), ans.end());

		cout << ans << endl;
	}
	else{
		cout << -1 << endl;
	}
}
 
int main(){
	
	int t;
	scanf(" %d", &t);

	
	while(t--){
		go();
		//break;
	}
    return 0;
 
}
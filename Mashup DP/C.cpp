#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int n;

int dp[8];



void run(){
	cin >> n;

	for(int i = 0; i <= 7; i++){
		dp[i] = INF;
	}

	for(int i = 0; i < n; i++){
		int v;
		cin >> v;

		string s;
		cin >> s;
		int a = (s.find("A") != string::npos) * 4;
		int b = (s.find("B") != string::npos) * 2;
		int c = (s.find("C") != string::npos) * 1;

		dp[a+b+c] = min(dp[a+b+c], v);

	}
	dp[0] = 0;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			dp[i | j] = min(dp[i] + dp[j], dp[i | j]);
		}
	}
	if(dp[7] == INF) printf("-1\n");
	else{
		printf("%d\n", dp[7]);
	}
}

int main(){
	
	run();
    return 0;

}
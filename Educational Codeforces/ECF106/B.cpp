#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

// 17 min to solve

void solve(){
	string s;
	cin >> s;

	int db1 = INF;
	int db0 = 0;
	for(int i = 1; i < (int)s.length(); i++){
		if(s[i-1] == '0' and s[i] == '0'){
			db0 = i;
		}	
	}
	for(int i = 1; i < (int)s.length(); i++){
		if(s[i-1] == '1' and s[i] == '1'){
			db1 = i;
			break;
		}	
	}
	if(db0 > db1){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}
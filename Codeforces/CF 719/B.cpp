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

string n;
int first(int k){
	for(int i = k; i < n.length(); i++){
		if(n[k] > n[i]){
			return 0;
		}
		if(n[k] < n[i]){
			return 1;
		}
	}
	return 1;
}

void solve(){
	cin >> n;

	int cnt = 0;
	cnt += first(0) + (n[0] - '0' - 1);

	cnt += 9 * (n.length()-1);

	printf("%d\n", cnt);
}



int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}
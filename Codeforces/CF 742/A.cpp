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
	int n;
	scanf("%d", &n);

	vector<char> ans;

	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);
		if(c == 'U') ans.push_back('D');
		else if(c == 'D') ans.push_back('U');
		else ans.push_back(c);
	}

	for(char b : ans){
		printf("%c", b);
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}
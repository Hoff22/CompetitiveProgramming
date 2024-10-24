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

void solve(){
	int n;
	cin >> n;

	string s;

	cin >> s;

	unordered_set<int> seen;
	string test = "!@#$%^&*()-+.,""'´;:></\\";
	for(int i = 0; i < (int)s.length(); i++){
		if(s[i] >= 'a' and s[i] <= 'z'){
			seen.insert(1);
		}
		if(s[i] >= 'A' and s[i] <= 'Z'){
			seen.insert(2);
		}

		if(s[i] >= '0' and s[i] <= '9'){
			seen.insert(3);
		}

		if(test.find(s[i]) != string::npos){
			seen.insert(4);
		}
	}
	//printf("%d\n", (int)seen.size());
	int ans = 4-(int)seen.size();

	if(max(n,6) > (int)s.length()+ans){
		ans += max(n,6) - ((int)s.length()+ans);
	}

	printf("%d\n", ans);
}

int main(){

	solve();

    return 0;

}
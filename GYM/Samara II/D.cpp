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
	vector<int> a;
	vector<int> b;
	vector<int> c;

	for(int i = 0; i < 10; i++){
		char ch;
		scanf(" %c", &ch);
		if(ch == '1') a.push_back(1);
		else a.push_back(0);
	}
	for(int i = 0; i < 10; i++){
		char ch;
		scanf(" %c", &ch);
		if(ch == '1') b.push_back(1);
		else b.push_back(0);
	}
	for(int i = 0; i < 10; i++){
		char ch;
		scanf(" %c", &ch);
		if(ch == '1') c.push_back(1);
		else c.push_back(0);
	}

	

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}
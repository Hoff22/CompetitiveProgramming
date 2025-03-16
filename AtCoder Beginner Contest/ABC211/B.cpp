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



int main(){
	
	set<string> cnt;
	for(int i = 0; i < 4; i++){
		string s;
		cin >> s;
		cnt.insert(s);
	}

	if(cnt.size() == 4){
		printf("Yes\n");
	}
	else printf("No\n");
    return 0;

}
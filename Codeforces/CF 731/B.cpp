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

	string s;
	cin >> s;

	int i = 0;
	int j = s.length()-1;

	int c = s.length();
	while(i <= j){
		//printf("%c\n", 'a'+c-1);
		if(s[i] == 'a'+c-1){
			i++;
		}
		else if(s[j] == 'a'+c-1){
			j--;
		}
		else{
			break;
		}
		c--;
	}

	if(c) printf("NO\n");
	else printf("YES\n");
}

int main(){
	
	int t;
	cin >> t;

	while(t--){
		solve();
	}
    return 0;

}
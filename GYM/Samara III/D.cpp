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
	
	int n;
	cin >> n;

	while(n--){
		int cnt[3] = {0,0,0};

		string s;
		cin >> s;

		for(int i = 0; i < s.length(); i++){
			if((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z')){
				cnt[0]++;
			}
			else if(s[i] >= '0' and s[i] <= '9'){
				cnt[1]++;
			}
			else if(s[i] == '@' or s[i] == '?' or s[i] == '!'){
				cnt[2]++;
			}
		}

		if(cnt[0] < 4) cout << "The last character must be a letter.\n";
		else if(cnt[1] < 4) cout << "The last character must be a digit.\n";
		else if(cnt[2] < 2) cout << "The last character must be a symbol.\n";
		else cout << "The last character can be any type.\n";
	}

    return 0;

}
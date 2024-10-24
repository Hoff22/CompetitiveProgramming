#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

#define N 1000

void invd(){
	cout << "invalid" << endl;
}

void solve(){
	string s;
	cin >> s;
	int n = (int)s.size();

	if(s.back() == '-' or s[0] == '-'){
		invd();
		return;
	}


	vector<int> v;

	int h = 0;
	int sum = 0;
	int c = 10;
	for(int i = 0; i < n-1; i++){
		if(s[i] == '-'){
			if(v.size() and v.back() == -1){
				invd();
				return;
			}
			v.push_back(-1);
			h++;
			continue;
		}
		else if(s[i] == 'X'){
			invd();
			return;
		}
		v.push_back((s[i]-'0'));
		sum += (s[i]-'0') * (c--);
	}

	int cs = (s.back() - '0');
	if(s.back() == 'X') cs = 10;

	if((sum + cs) % 11 != 0){
		invd();
		return;
	}

	if(h > 3 or (h == 3 and s[n-2] != '-')){
		invd();
		return;
	}

	if(n-h != 10){
		invd();
		return;
	}

	string ans = "978-";
	sum = 9 + 21 + 8;

	int p = 1;
	for(int i : v){
		if(i == -1){
			ans += '-';
		}
		else{
			ans += (char)('0' + i);
			if(p > 0){
				sum += 3 * i;
			}
			else{
				sum += i;
			}
			p *= -1;
		}
	}

	ans += (char)(((10 - sum % 10) % 10) + '0');

	cout << ans << endl;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;

	while(tt--){
		solve();
	}

	return 0;

}
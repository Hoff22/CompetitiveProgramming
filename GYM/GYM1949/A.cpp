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

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string cur = "abcdefghijk";
	map<string,string> m;

	for(int i = 0; i < n; i++){
		int a;
		string b;
		
		cin >> a >> b;

		while(b.back() == 'L' or b.back() == '0' or b.back() == '.') b.pop_back();

		string s = to_string(a) + b;

		if(m.count(s)) cout << m[s] << endl;
		else{
			m[s] = cur;
			next_permutation(cur.begin(), cur.end());
			cout << m[s] << endl;
		}
	}

}
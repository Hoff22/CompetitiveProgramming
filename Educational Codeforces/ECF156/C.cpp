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
	string s;
	long long p;
	cin >> s >> p;

	long long n = (long long)s.size();

	vector<int> l(n, -1);
	vector<int> r(n, -1);
	for(int i = 1; i < n-1; i++){
		l[i] = i-1;
		r[i] = i+1;
	}
	if(n>1){
		r[0] = 1;
		l[n-1] = n-2;
	}

	multiset<int> ps;
	for(int i = 0; i < n-1; i++){
		if(s[i] > s[i+1]) ps.insert(i);
	}

	long long cur = 0;
	long long sz = n;
	while(cur + sz < p and sz >= 1){
		cur += sz;
		sz--;

		if(ps.empty()){
			s.pop_back();
		}
		else{
			int rem = *ps.begin();
			ps.erase(rem);
			s[rem] = ' ';
			if(l[rem] != -1){
				r[l[rem]] = r[rem];
			}
			if(r[rem] != -1){
				l[r[rem]] = l[rem];
			}

			if(l[rem] != -1 and r[rem] != -1){
				ps.erase(l[rem]);
				if(s[l[rem]] > s[r[rem]]) ps.insert({l[rem]});
			}
		}
		while(s.back() == ' ') s.pop_back();
		// cout << cur << " " <<  s << endl;
	}

	p -= cur;

	// cout << p << " " << s << endl;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' ') continue;
		p--;
		if(p == 0){
			cout << s[i];
			cout.flush();
			break;
		}
	}
}

/*

b a d e r

a b d e r
1 0 2 3 4

a ad ade ader bader 
bade ade ad a 

*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}

	cout << endl;

    return 0;

}
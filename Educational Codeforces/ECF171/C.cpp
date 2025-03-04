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

typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;

	ll sum = 0;
	for(int i = 1; i <= n; i++) sum += i;

	queue<int> q;
	for(int i = n; i >= 1; i--){
		if(s[i-1] == '1'){
			q.push(i);
		}
		else{
			if(q.empty()) continue;
			sum -= q.front();
			// cout << "> "<< q.front() << endl;
			q.pop();
		}
	}	

	vector<int> l;
	while(q.size()){
		l.push_back(q.front());
		q.pop();
	}

	sort(l.begin(), l.end());
	reverse(l.begin(), l.end());

	for(int i = 0; i + (l.size() / 2) < l.size() - l.size()%2; i++){
		sum -= l[i];
		// cout << "> "<< l[i] << endl;
	}

	cout << sum << endl;
}

/*

1 2 3 4 5 6 7 

x 2 3 . . . 7
  1         6
            5
            4
*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}
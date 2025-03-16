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

void fill(string& s, stack<int>& st, char c){
	while(st.size()){
		s[st.top()] = c;
		st.pop();
	}
}

void solve(){
	string s;
	cin >> s;

	int n = s.size();

	stack<int> st;
	int op = -1;
	for(int i = 0; i < n; i++){
		if(s[i] == '?'){
			st.push(i);
		}
		else if(s[i] == '0'){
			fill(s, st, '0');
			op = 0;
		}
		else{
			if(op == 1) fill(s, st, '1');
			else fill(s,st,'0');
			op = 1;
		}
	}

	fill(s, st, '1');

	cout << s << endl;
}


/*
1 0 0 1 0

0 1 0 0 1 

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
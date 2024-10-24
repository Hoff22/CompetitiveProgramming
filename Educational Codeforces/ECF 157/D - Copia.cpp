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

struct bit_trie{
	int sz, child[2];

	bit_trie(){
		this->sz = 0;
		this->child[0] = this->child[1] = -1;
	}
};

vector<bit_trie> bt = {bit_trie()};

void insert(int n, vector<bit_trie>& t){

	int cur = 0;

	for(int i = 30; i >= 0; i--){
		
		t[cur].sz++;

		if(t[cur].child[0] == -1){
			t[cur].child[0] = t.size();
			t.push_back(bit_trie());
			t[cur].child[1] = t.size();
			t.push_back(bit_trie());
		}

		cur = t[cur].child[(n>>i) & 1];
	}

	t[cur].sz++;
}

int xor_count(int n, int x, vector<bit_trie>& t){
	int cur = 0;
	for(int i = 30; i >= 0; i--){
		if(t[cur].sz == 0) break;
		cur = t[cur].child[((n>>i) ^ (x>>i)) & 1];
	}

	return t[cur].sz;
}

int xor_max(int n, vector<bit_trie>& t){
	int cur = 0;
	long long ans = 0;
	
	if(t[cur].sz == 0) return -1;

	for(int i = 30; i >= 0; i--){
		if(t[t[cur].child[!((n>>i) & 1)]].sz > 0){
			ans += (1<<i);
			cur = t[cur].child[!((n>>i) & 1)];
		}
		else{
			cur = t[cur].child[((n>>i) & 1)];
		}
	}

	return ans;
}

void solve(){
	int n; cin >> n;
	vector<int> a(n-1);

	int cur = 0;
	for(int i = 0; i < n-1; i++){
		cin >> a[i];
		cur ^= a[i];
	}

	for(int i = 0; i < n-1; i++){
		insert(cur, bt);
		cur ^= a[i];
	}

	int x;
	for(x = 0; x <= n-1; x++){
		if(xor_max(x, bt) <= n-1) break;
	}

	cur = 0;
	for(int i = 0; i < n-1; i++) cur ^= a[i];

	for(int i = 0; i < n-1; i++){
		cout << (cur^x) << " ";
		cur ^= a[i];
	}
	cout << x << endl;
}

// 13
// 9 2 1 9 5 1 15 9 5 6 14 9 
// 

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}
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

// child[0] = nao tem
// child[1] = tem par
// child[2] = tem impar

struct Trie {
    int child[2];
    int terminal;
    int odd;
    int even;

    Trie() {
        memset(this->child, -1, sizeof(this->child));
        this->odd = this->even = this->terminal = 0;
    }
};

// Root of the Trie.
vector<Trie> vt = {Trie()};

/* O(|S|). */
void trie_insert(const vector<int> &cnt) {
    int cur, i;
    int sum = 0;

    for (i = 0, cur = 0; i < 26; i++) {
        int put;

        sum += cnt[i];

        if(cnt[i] % 2 == 0){ // nao tem
        	put = 0;
        }
        else if(cnt[i] % 2){ // tem impar
        	put = 1;
        }

        // If this child has not been created yet.
        if (vt[cur].child[ put ] == -1) {
            vt[cur].child[ put ] = vt.size(); // Adding pointer.
            vt.push_back(Trie());             // Creating child.
        }

        // Moving to its child.
        cur = vt[cur].child[ put ];
    }

    // At terminal node. String was completely inserted.
    vt[cur].terminal++;
    if(sum % 2) vt[cur].odd++;
    else vt[cur].even++;
}

/* O(|S|). */
int trie_count(int cur, int c, int sum, const vector<int> &cnt, int exclude) {
    if(cur == -1) return 0;
    if(vt[cur].terminal){
    	if(sum % 2) return vt[cur].even;
    	else return vt[cur].odd;
    }

    if(cnt[c] % 2 == 0 and c != exclude){
    	return trie_count(vt[cur].child[1], c+1, sum+cnt[c], cnt, exclude);
    }

	return trie_count(vt[cur].child[0], c+1, sum+cnt[c], cnt, exclude);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;	

	cin >> n;

	vector<string> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	long long ans = 0;

	vector<int> cnt(26, 0);

	for(int ex = 0; ex < 26; ex++){
		vt.clear();
		vt = {Trie()};
		for(int i = 0; i < n; i++){

			fill(cnt.begin(),cnt.end(), 0);
			for(char c : a[i]){
				cnt[c-'a']++;
			}

			if(cnt[ex] != 0) continue;
			ans += trie_count(0,0,0,cnt, ex);

			if(cnt[ex] == 0){
				trie_insert(cnt);
			}
			//trie_print(0, vector<int>(26,-1), 0);
		}
	}


	cout << ans << endl;

    return 0;

}
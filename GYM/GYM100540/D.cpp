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

constexpr int OFFSET = 'a';
constexpr int ALPHABET_SIZE = 26;

struct Trie {
    int child[ALPHABET_SIZE];
    int size, terminal;

    Trie() {
        memset(this->child, -1, sizeof(this->child));
        this->size = this->terminal = 0;
    }
};

// Root of the Trie.
vector<Trie> vt;

/* O(|S|). */
void trie_insert(const string &s) {
    int cur, i;

    for (i = 0, cur = 0; i < s.size(); i++) {
        vt[cur].size++;

        // If this child has not been created yet.
        if (vt[cur].child[s[i] - OFFSET] == -1) {
            vt[cur].child[s[i] - OFFSET] = vt.size(); // Adding pointer.
            vt.push_back(Trie());                     // Creating child.
        }

        // Moving to its child.
        cur = vt[cur].child[s[i] - OFFSET];
    }

    // At terminal node. String was completely inserted.
    vt[cur].size++;
    vt[cur].terminal++;
}

/* O(|S|). */
int trie_count(const string &s) {
    int cur, i;

    for (i = 0, cur = 0; i < s.size(); i++) {
        // If there's no child with this character.
        if (vt[cur].child[s[i] - OFFSET] == -1) {
            return 0;
        }

        // Moving to its child.
        cur = vt[cur].child[s[i] - OFFSET];
    }

    // At terminal node.
    return vt[cur].terminal;
}

vector<long long> cnt(26, 0ll);
long long n_nodes = 0;

void precal(int u, int depth){
	if(depth > 0) n_nodes++;
	
	for(int i = 0; i < ALPHABET_SIZE; i++){
		if(vt[u].child[i] == -1) continue;

		if(depth > 0){
			cnt[i]++;
		}

		precal(vt[u].child[i], depth+1);
	}
}

vector<long long> cur(26, 0ll);

long long solve(int u, int c, int depth){
	long long r = 0;

	if(depth > 0){
		if(depth > 1){
			r = n_nodes - cnt[c];
		}
		else{
			r = n_nodes;
		}

		// cout << c << ": " << r << endl;
	}

	for(int i = 0; i < ALPHABET_SIZE; i++){
		if(vt[u].child[i] == -1) continue;

		r += solve(vt[u].child[i], i,depth+1);
	}

	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    while(true){
	    int n, m;
	    cin >> n >> m;
    	if(n + m == 0) break;

    	for(int i = 0; i < 26; i++) cnt[i] = 0ll;
    	for(int i = 0; i < 26; i++) cur[i] = 0ll;
    	n_nodes = 0;
    	vt.clear();
    	vt = {Trie()};

    	vector<string> p;
    	vector<string> s;

    	for(int i = 0; i < n; i++){
    		string x; cin >> x;
    		p.push_back(x);
    	}
    	for(int i = 0; i < m; i++){
    		string x; cin >> x;
    		reverse(x.begin(), x.end());
    		s.push_back(x);
    	}

    	for(string str : s){
    		trie_insert(str);
    	}

    	precal(0, 0);

    	vt = {Trie()};
    	for(string str : p){
    		trie_insert(str);
    	}

    	cout << solve(0,-1,0) << endl;
    }


    return 0;

}
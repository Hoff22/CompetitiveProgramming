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
constexpr int OFFSET = 0;
constexpr int ALPHABET_SIZE = 2;

struct Trie {
    int child[ALPHABET_SIZE];
    int size, terminal;

    Trie() {
        memset(this->child, -1, sizeof(this->child));
        this->size = this->terminal = 0;
    }
};

// Root of the Trie.
vector<Trie> vt = {Trie()};

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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    cin >> s;

    for(int i = 0; i < s.size(); i++){
    	a[i+1] = (int)s[i];
    }
    int m = s.size();
    
    build(1,1,m);

    int n;
    cin >> n;


    for(int i = 0; i < n; i++){
    	int op;

    	cin >> op;

    	if(op == 1){
    		int x;
    		char y;
    		cin >> x >> y;
    		update(1,1,m,x,y);
    	}
    	else{
    		int x,y;
    		cin >> x >> y;
    		vector<int> r = query(1,1,m,x,y);
    		int ans = 0;
    		for(int j = 0; j < 26; j++){
    			if(r[j])ans++;
    		}
    		cout << ans << endl;
    	}
    }

    return 0;

}
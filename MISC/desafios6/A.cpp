#include <bits/stdc++.h>

#define N 10000
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

constexpr int OFFSET = 'A';
constexpr int ALPHABET_SIZE = 26;

struct Trie {
    int child[ALPHABET_SIZE];
    int size, terminal, height;

    Trie() {
        memset(this->child, -1, sizeof(this->child));
        this->height = this->size = this->terminal = 0;
    }
};

// Root of the Trie.

/* O(|S|). */
void trie_insert(const string &s, vector<Trie>& vt) {
    int cur, i;

    for (i = 0, cur = 0; i < s.size(); i++) {
        vt[cur].size++;

        // cout << s[i] << " " << vt[cur].size << endl;
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


int build(int cura, int curb, vector<Trie>& ta, vector<Trie>& tb){

	if(cura == -1 or curb == -1) return 0;

	ta[cura].size = tb[curb].size = min(ta[cura].size, tb[curb].size);

	int h = 0;
	for(int i = 0; i < 26; i++){
		h = max(
			h,
			build(ta[cura].child[i], tb[curb].child[i], ta, tb)
		);
	}

	ta[cura].height = h+1;

	return ta[cura].height;
}

void findWord(int cur, vector<Trie>& vt){

	int best = 0;
	if(vt[cur].height > 1){
		for(int i = 0; i < 26; i++){
			if(vt[cur].child[i] == -1 or vt[vt[cur].child[i]].size == 0) continue;
			if(vt[cur].child[best] == -1 or vt[vt[cur].child[i]].height > vt[vt[cur].child[best]].height){
				best = i; 
			}
		}

		findWord(vt[cur].child[best], vt);
	}

	vt[cur].size--;
	if(vt[cur].size == 0){
		vt[cur].height = 0;
	}
	else{
		vt[cur].height = 0;
		for(int i = 0; i < 26; i++){
			if(vt[cur].child[i] == -1) continue; // PORRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
			vt[cur].height = max(vt[cur].height, vt[vt[cur].child[i]].height);
		}
		vt[cur].height += 1;
	}
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    while(true){
        cin >> n;
        if(n == -1) break;

        vector<Trie> ta = {Trie()};
        vector<Trie> tb = {Trie()};

        string s;
        for(int i = 0 ; i < n; i++){
            cin >> s;
            while(s.size() and (s[s.size()-1] < 'A' or s[s.size()-1] > 'Z')) s.pop_back();
            trie_insert(s, ta);
        }
        for(int i = 0 ; i < n; i++){
            cin >> s;
            while(s.size() and (s[s.size()-1] < 'A' or s[s.size()-1] > 'Z')) s.pop_back();
            trie_insert(s, tb);
        }

        int ans = 0;

        build(0,0,ta,tb);

        for(int i = 0; i < n; i++){
            ans += (ta[0].height-1);
            findWord(0,ta);
        }

        cout << ans << endl;

    }


    return 0;

}
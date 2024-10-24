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

int n, k, q;
string rule, s;
int neigh(int p){
	int r = 0;
	int begin = p - k;
	if(begin < 0){
		begin += n;
	}
	for(int i = 2*k; i >= 0; i--){
		int index = (begin + i) % n;
		r += (1<<(2*k - i)) * (s[index] == '1');
	}	
	return r;
}

int main(){
	
	cin >> n >> k >> q;

	cin >> rule;
	cin >> s;

	string ns;
	while(q--){
		ns = "";
		for(int i = 0; i < s.size(); i++){
			ns += rule[rule.size() - neigh(i) - 1];
		}
		s = ns;
	}

	cout << ns << endl;

    return 0;

}
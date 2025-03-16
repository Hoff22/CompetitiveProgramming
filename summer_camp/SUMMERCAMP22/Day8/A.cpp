#include <bits/stdc++.h>
#include <fstream>

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

ifstream in;

void solve(){
	int n = 12;
	vector<int> a;

	for(int i = 0; i < n; i++){
		int x;
		in >> x;
		a.push_back(x);
	}

	vector<int> b = a;

	sort(a.begin(), a.end());

	for(int i = 0; i < 4; i++){
		if(a[i] != b[i]){
			cout << "no\n";
			return;
		}
	}
	cout << "yes\n";
	return;
}

int main(){
	in.open("hello.in", ifstream::in);	

	int t;
	in >> t;
	
	while(t--){
		solve();
	}

	in.close();
    return 0;

}
#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){
	
	int n;
	vector<pair<int,string>> a;
	cin >> n;

	for(int i = 0; i < n; i++){
		string k;
		int x;
		cin >> k >> x;

		a.push_back({x, k});
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	cout << a[1].second << endl;

    return 0;

}
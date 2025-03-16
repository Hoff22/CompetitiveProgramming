#include <bits/stdc++.h>

#define N 100000
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


int main(){
	
	int n; 
	cin >> n;

	vector<int> a;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == "LIE"){
			a.push_back(-1);
		}
		else{
			a.push_back(1);
		}
	}

	reverse(a.begin(), a.end());

	int t = a[0];
	for(int i = 1; i < n-1; i++){
		t *= a[i];
	}

	a[n-1] *= t;
	if(a[n-1] == -1) cout << "LIE\n"; 
	else cout << "TRUTH\n";

    return 0;

}
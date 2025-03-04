#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	vector<ll> ks(q);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < q; i++){
		cin >> ks[i];
	}

	sort(a.begin(), a.end());

	vector<ll> k_difs(n+1);
	for(int k = 1; k <= n; k++){
		ll sumdiff = 0;
		for(int i = 1; i < n; i++){
			sumdiff += (a[i]+(k-i)) - (a[0]+k);
		}
		k_difs[k] = sumdiff;
	}

	// for(int i = 0; i < n; i++) cout << a[i] << " ";
	// cout << endl;
	// cout << endl;

	for(int k : ks){
		
		ll p = k-n;

		ll g = (p+1)/2;

		if(g > n){
			g -= k_difs[n];

			cout << (a[0] + k) - (g/n) - (g%n > 0) << endl; 
		}
		else{
			
		}

	}
	cout << endl;

    return 0;

}


/*

^V^V ^V ^

5 2 8 4 4
5 3 8 4 4
5 1 8 4 4






k-n = 6

2 3 3 3
2 3 3 4
2 3 5 4
2 6 5 4
6 6 5 4

9-3 = 6

5 2 8 4
6 2 8 4
4 2 8 4
7 2 8 4
3 2 8 4
 8 2 8 4
 8 2 8 10
 8 9 8 10





*/
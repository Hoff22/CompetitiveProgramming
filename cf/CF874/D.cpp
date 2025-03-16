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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int l;
	int r = 0;

	for(int i = 0; i < n; i++){
		if(i == n-1){
			if(a[i] > a[r+1]){
				r = i;
			}
			if(a[i] == a[r+1]){
				if(max(a[i], a[i-1]) > a[r]) r = i;
			}
		}
		else{
			if(a[i+1] > a[r+1]) r = i;
		}
	}

	l = r;

	while(l > 0 and a[l-1] > a[0]){
		l--;
	}

	reverse(a.begin()+l, a.begin()+r+1);

	for(int i = r+1; i < n; i++){
		cout << a[i] << " ";
	}
	for(int i = l; i <= r; i++){
		cout << a[i] << " ";
	}
	for(int i = 0; i < l; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

/*

4 1 6 7 2 8 5 3

4 1 2 3

1 2 3 4

2 3 1 5 4

5 4 


5 4 1 2 3

3 2 5 4 1

1 2 3 4 5


4 2 1 3


*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}
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

vector<pair<long long,long long>> a;

void solve(){
	int n;
	scanf("%d", &n);
	//cin >> n;



	for(long long i = 1; i <= n; i++){
		//string s;
		long long x;

		scanf(" %*c%*[^']%*c");
		scanf(" %lld", &x);

		a.push_back(make_pair(x,i));
	}

	for(int i = 0; i < a.size(); i++){
		a[i].first = (4*a[i].first*a[i].first) - (100*a[i].first);
		a[i].first *= -1;
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < 3; i++){
		printf("%lld\n", a[i].second);
	}


}

int main(){

	solve();

    return 0;

}
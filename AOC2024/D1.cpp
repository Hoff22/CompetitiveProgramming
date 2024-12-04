// #include <bits/stdc++.h>

//mac-os
#include<vector>
#include<algorithm>
#include<iostream>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	vector<int> a, b;
	int x,y;
	while(cin >> x >> y){
		a.push_back(x), b.push_back(y);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long ans  = 0;
	for(int i = 0; i < a.size(); i++){
		ans += abs(a[i] - b[i]);
	}
	cout << ans << endl;
}

void solve2(){
	vector<int> a;
	int x,y;
	while(cin >> x >> y){
		a.push_back(x);
		cnt[y]++;
	}
	unsigned long long ans = 0;
	for(int i : a){
		ans += (i * cnt[i]);
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
    return 0;
}
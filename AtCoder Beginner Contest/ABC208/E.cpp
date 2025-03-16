#include <bits/stdc++.h>
#include <unordered_map>

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

struct state{
	int i, k;
	bool first, mx;

	bool operator < (const state &b) const {
		if(i == b.i and k == b.k and first == b.first and mx == b.mx) return false;
		else return true;
	}
};

long long n, k;
vector<int> s;
unordered_map<long long, long long> dp[19][2][2];

long long solve(int i, long long cur, bool mx, bool fs){
	
	if(i == s.size()) return (!fs and cur <= k);

	if(dp[i][mx][fs].count(cur)){
		return dp[i][mx][fs][cur];	
	} 

	long long r = 0;

	if(fs) r += solve(i+1, 1, false, true); // caso 0...0d
	else r += solve(i+1, 0, (!s[i] and mx), false);

	if(mx){
		for(int d = 1; d <= s[i]; d++){
			r += solve(i+1, cur*d, (s[i] == d), false);
		}
	}
	else{
		for(int d = 1; d <= 9; d++){
			r += solve(i+1, cur*d, false, false);
		}
	}

	return dp[i][mx][fs][cur] = r;
}



int main(){
	
	scanf("%lld %lld", &n, &k);

	while(n){
		s.push_back(n%10);
		n /= 10;
	}

	reverse(s.begin(), s.end());

	printf("%lld\n", solve(0, 1, true, true));

    return 0;

}
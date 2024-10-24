#include<bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

// int dp[];
string s;
int x, y;

long long solve(int i, int ones, int zeros, int hates){
	if(s[i] == '\0'){
		return hates;
	}
	// x = 01
	// y = 10
	if(s[i] == '1'){
		return solve(i + 1, ones + 1, zeros, hates + (zeros * x));
	}
	if(s[i] == '0'){
		return solve(i + 1, ones, zeros + 1, hates + (ones * y));
	}

	return min(solve(i + 1, ones + 1, zeros, hates + (zeros * x)), solve(i + 1, ones, zeros + 1, hates + (ones * y)));
}

int main(){

	cin >> s;
	cin >> x >> y;

	printf("%lld\n", solve(0, 0, 0, 0));


	return 0;
}
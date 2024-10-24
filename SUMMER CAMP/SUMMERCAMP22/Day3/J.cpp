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

int main(){
	
	
	string s;

	cin >> s;

	int l, r;
	l = r = 0;
	for(int i = 0; i < s.size(); i++){
		int mx = s.size();
		for(int j = i+1; j < s.size(); j++){
			if(s[i] > s[j]){
				if(s[mx] < s[j]){
					mx = j;
					l = i;
					r = mx;
				}
			}
			if(l == 0 and s[r] == '0'){
				l = r = 0;
			}
			//printf("%d %d %d %d\n", i, j, l, r);
		}
	}

	if(l == r){
		cout << -1 << endl;
		return 0;
	}

	swap(s[l], s[r]);

	cout << s << endl;


    return 0;

}
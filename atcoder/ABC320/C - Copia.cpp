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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
   	int n;
   	cin >> n;

   	string s[3];
   	cin >> s[0] >> s[1] >> s[2];

   	int ans = -1;

   	for(int i = 0; i <= 3*n; i++){
   		for(int j = 0; j <= 3*n; j++){
   			for(int k = 0; k <= 3*n; k++){
   				if(i == j or j == k or i == k) continue;
   				if(s[0][i%n] == s[1][j%n] and s[1][j%n] == s[2][k%n]){
   					if(ans == -1) ans = max({i,j,k});
   					ans = min(ans, max({i,j,k}));
   				}
   			}
   		}
   	}

   	cout << ans << endl;

    return 0;

}
#include <bits/stdc++.h>

#define N 20
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

vector<int> op[N+1];

bool impostor(int mask, int member){
	return (mask>>(member-1)) & 1;
}

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		int s;
		scanf("%d", &s);

		for(int j = 0; j < s; j++){
			int x;
			scanf("%d",&x);
			op[i].push_back(x);
		}
	}

	long long ans = 0;
	for(int i = 0; i < (1<<n); i++){
		int member;
		for(member = 1; member <= n; member++){
			int good = 1;
			if(impostor(i, member)){ // member eh impostor
				good = 1;
				for(int guess : op[member]){
					if(impostor(i, guess)){
						good = 0;
						break;
					}
				}
			}
			else{
				good = 0;
				for(int guess : op[member]){
					if(impostor(i, guess)){
						good = 1;
						break;
					}
				}
			}
			if(!good) break;
		}
		if(member > n) ans++;
	}

	printf("%lld\n", ans);

    return 0;

}
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

unsigned long long subnet(unsigned long long ip, int s){
	unsigned long long m = ((1ll<<33))-1;
	m = m - ((1ll<<(33-s-1)) - 1);

	return (ip & m);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	map<pair<unsigned long long, int>, int> cnt;
    vector<int> mx(33);

    for(int i = 0; i < 33; i++){
    	scanf("%d", &mx[i]);
    }

    int q;
    scanf("%d", &q);

    while(q--){
    	unsigned long long ip;

    	int a, b, c, d;
    	scanf("%d%*c%d%*c%d%*c%d ", &a, &b, &c, &d);

    	ip = a*(1ll<<24) + b*(1ll<<16) + c*(1ll<<8) + d;

		// unsigned long long t = ip;
		// while(t){
		// 	if(t&1) printf("1");
		// 	else printf("0");

		// 	t >>= 1;
		// }   
		// printf("\n"); 	

    	int good = 1;
    	for(int i = 0; i <= 32; i++){
    		if(!cnt.count({subnet(ip, i), i})){
    			cnt[{subnet(ip, i), i}] = 0;
    		}

    		if(cnt[{subnet(ip, i), i}] == mx[i]){
    			//printf(" GOOD = 0 \n");
    			good = 0;
    		}

    		// printf("sub %d:\n", i);
    		// t = subnet(ip, i);
			// while(t){
			// 	if(t&1ll) printf("1");
			// 	else printf("0");

			// 	t >>= 1ll;
			// }   
			// printf("\n"); 
    	}

    	if(good){
    		printf("a\n");
    		for(int i = 0; i <= 32; i++){
	    		cnt[{subnet(ip, i), i}]++;
	    	}
    	}
    	else{
    		printf("b\n");
    	}
    }

    return 0;

}
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
	
    int q;
    scanf("%d", &q);

    set<long long> s;
    map<long long,vector<long long>> s2;
    map<long long, long long> m;

    int mapping[N+1];

    while(q--){
    	char c;
    	long long x;
    	scanf(" %c %lld", &c, &x);

    	if(c == '+') s.insert(x);
    	else if(c == '-'){
			for(long long i : s2[x]){
				m[i] = min(x, m[i]);
			}
			s2[x].clear();
			s.erase(x);
    	}
    	else{
    		long long a = x;

    		if(m.count(x)) a = m[x];

    		while(s.count(a)){
    			s2[a].push_back(x);
    			a += x;
    		}
    		printf("%lld\n", a);
    		m[x] = a;
    	}

    }


    return 0;

}
#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<long long> s;
long long cnt[N+1];

int main(){
	
	int q, n;

	scanf("%d %d", &q, &n);

	while(q--){
		int op;
		scanf("%d", &op);

		if(op == 1){
			int id;
			long long x;

			scanf("%d %lld", &id, &x);
			s.erase(s.upper_bound(-cnt[id]));
			cnt[id] += x;
			s.insert(-cnt[id]);
		}
		else{
			long long k;
			scanf("%lld", &k);

			printf("%d\n", (int)s.order_of_key(-k));
		}
	} 


    return 0;

}
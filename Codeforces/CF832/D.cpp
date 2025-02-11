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

vector<long long> v;
vector<long long> x;
vector<long long> s;
vector<long long> d;
vector<long long> z;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, q;
	scanf("%d %d", &n, &q);

	v.assign(n+1, -1);
	x.assign(n+1,  0);
	s.assign(n+1,  0);
	d.assign(n+1,  0);
	z.assign(n+1,  0);

	map<int, vector<int>> psOdd;
	map<int, vector<int>> psEven;

	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
		x[i] = x[i-1] ^ v[i];
		s[i] = s[i-1] + v[i];
		d[i] = d[i-1] + (v[i-1] != v[i]);
		z[i] = z[i-1] + (v[i] == 0);

		if(i % 2){
			psOdd[x[i]].push_back(i);
		}
		else{
			psEven[x[i]].push_back(i);
		}
	}


	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);

		if(s[r] - s[l-1] == 0){
			printf("0\n");
			continue;
		}

		if((r - l + 1) % 2){
			// range impar
			if((x[r] ^ x[l-1]) != 0){
				printf("-1\n");
			}
			else{
				printf("1\n");
			}
		}
		else{
			if((x[r] ^ x[l-1]) != 0){
				printf("-1\n");
				continue;
			}

			if(r - l + 1 <= 2){
				printf("-1\n");
				continue;
			}

			// range par
			if(v[l] == 0 or v[r] == 0){
				printf("1\n");
				continue;
			}

			vector<int>::iterator p;
			
			if(l % 2){
				if(psOdd[x[l-1]].size() == 0){
					printf("-1\n");
					continue;
				}

				p = lower_bound(psOdd[x[l-1]].begin(), psOdd[x[l-1]].end(), l);
			
				if(p == psOdd[x[l-1]].end() or *p > r){
					printf("-1\n");
					continue;
				}
			}
			else{
				if(psEven[x[l-1]].size() == 0){
					printf("-1\n");
					continue;
				}

				p = lower_bound(psEven[x[l-1]].begin(), psEven[x[l-1]].end(), l);
			
				if(p == psEven[x[l-1]].end() or *p > r){
					printf("-1\n");
					continue;
				}
			}

			printf("2\n");

		}
	}

    return 0;

}

/*



3 3    0    3 1 2
 


*/
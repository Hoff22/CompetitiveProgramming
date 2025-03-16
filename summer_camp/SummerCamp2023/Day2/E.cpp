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

	int x, y, aq, bq, cq;
	scanf("%d %d %d %d %d", &x, &y, &aq, &bq, &cq);

	vector<int> a(aq+1);
	vector<int> b(bq+1);
	vector<int> c(cq+1);

	for(int i = 1; i < a.size(); i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < b.size(); i++){
		scanf("%d", &b[i]);
	}
	for(int i = 1; i < c.size(); i++){
		scanf("%d", &c[i]);
	}

	sort(a.begin()+1, a.end());
	reverse(a.begin()+1, a.end());
	sort(b.begin()+1, b.end());
	reverse(b.begin()+1, b.end());
	sort(c.begin()+1, c.end());

	int p = c.size()-1;

	int tx = x;
	int ty = y;

	while((x > 0 or y > 0) and p > 0){
		int ofA = c[p] - a[x];
		int ofB = c[p] - b[y];

		if(ofA <= 0 and ofB <= 0) break;
		if(ofA <= 0 and y <= 0) break;
		if(ofB <= 0 and x <= 0) break;

		if(x <= 0){
			b[y] = c[p];
			y--;
			p--;
			continue;
		}
		if(y <= 0){
			a[x] = c[p];
			x--;
			p--;
			continue;
		}
		if(ofA >= ofB){
			a[x] = c[p];
			x--;
			p--;
			continue;
		}
		if(ofB > ofA){
			b[y] = c[p];
			y--;
			p--;
			continue;
		}
	}

	long long sum = 0;

	for(int i = 1; i <= tx; i++){
		sum = (sum + a[i]);
	}
	for(int i = 1; i <= ty; i++){
		sum = (sum + b[i]);
	}

	printf("%lld\n", sum);

    return 0;

}
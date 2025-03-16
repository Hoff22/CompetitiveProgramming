#include <bits/stdc++.h>

#define N 1000000
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

int seg[4*N+1];
int freq[N+1];
int n, q;

int build(int i, int l, int r){
	int m = l + (r - l) / 2;

	if(l == r){
		seg[i] = freq[l];
	}
	else{
		seg[i] = build(LEFT(i), l, m) + build(RIGHT(i), m + 1, r);
	}
	return seg[i];
}

int query_(int cur, int k, int l, int r){
	int m = l + (r - l) / 2;

	if(l == r){
		return l;
	}

	int esq = seg[LEFT(cur)];

	if(esq >= k) return query_(LEFT(cur), k, l, m);
	return query_(RIGHT(cur), k + esq, m+1, r);
}

int query(int k){
	return query_(1, k, 1, n);
}

void remove_(int i, int t, int l, int r){
	int m = l + (r - l) / 2;

	if(r < t or l > t){
		return;
	}

	if(l == r){
		freq[l]--;
		seg[i] = freq[l];
		return;
	}
	
	remove_(LEFT(i), t, l, m);
	remove_(RIGHT(i), t, m + 1, r);
	
	seg[i] = seg[LEFT(i)] + seg[RIGHT(i)];
}

void remove(int p){

	int t = query(p);

	remove_(1, t, 1, n);
}

void insert_(int i, int t, int l, int r){
	int m = l + (r - l) / 2;

	if(r < t or l > t){
		return;
	}

	if(l == r){
		freq[l]++;
		seg[i] = freq[l];
		return;
	}
	
	insert_(LEFT(i), t, l, m);
	insert_(RIGHT(i), t, m + 1, r);
	
	seg[i] = seg[LEFT(i)] + seg[RIGHT(i)];
}

void insert(int p){
	insert_(1, p, 1, n);
}

int main(){
	
	scanf("%d %d", &n, &q);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		freq[x]++;
	}

	build(1, 1, n);


	for(int i = 0; i < q; i++){
		int x;
		scanf("%d", &x);

		if(x < 0){
			remove(abs(x));
		}
		else{
			insert(x);
		}

		//printf("%d %d\n", abs(x), freq[abs(x)]);
	}
	for(int i = 1; i <= 50; i++){
		printf("%d ", seg[i]);
	}
	printf("\n");

	for(int i = 1; i <= n; i++){
		if(freq[i]){
			printf("%d\n", i);
			return 0;
		}
	}

	printf("0\n");

    return 0;

}
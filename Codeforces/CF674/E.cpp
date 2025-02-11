#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int main(){
	
	int n;
	scanf(" %d", &n);

	int a[3];
	int b[3];
	scanf(" %d %d %d", &a[0], &a[1], &a[2]);
	scanf(" %d %d %d", &b[0], &b[1], &b[2]);

	swap(a[1], a[2]);
	swap(b[1], b[2]);

	int mx = min(a[0], b[2]) + min(a[1], b[0]) + min(a[2], b[1]);



	if(a[1] >= b[1]){
		int tmp = a[1];
		a[1] -= b[1];
		b[1] -= tmp;
		mxb +=
	}
	if(a[2] >= b[2]){
		int tmp = a[2];
		a[2] -= b[2];
		b[2] -= tmp;
	}
	if(a[0] >= b[0]){
		int tmp = a[0];
		a[0] -= b[0];
		b[0] -= tmp;
	} 

	int mxb += min(b[0], a[2]) + min(b[1], a[0]) + min(b[2], a[1]);

	int mn = n - mxb;

	printf("%d %d\n", mn, mx);
    return 0;

}
#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N];

def func(i, total):
	if total == n:
		return 1
	if i >= len(cedula) or total > n:
		return 0

	ans = 0
	x = 0
	while x*cedula[i] + total <= n:
		ans += func(i+1, x*cedula[i] + total)
		x++

	return ans


void solve(){
	int n;
	scanf("%d\n", &n);

	char str[100000];


}

int main(){

	solve();

    return 0;

}
#include <bits/stdc++.h>

#define MAX 10000000
#define E 0.0000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first
#define pi 3.1415926535897932384626433

using namespace std;

bool isPrime(int x){
    if(x == 1) return false;
    for(long long i = 2; i * i <= x; i++){
        if(!(x%i)) return false;
    }
    return true;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "[";
    for(int i = 0; i <= 100; i++){
        cout << isPrime(i)? 1 : 0 << ",]"[i==100];
    }
}
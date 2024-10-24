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
	
    int n,m;
    cin >> n >> m;

    int a = 0;
    int k = 0;

    while(a < n){
    	cout << 9;
    	a += 9;
    	k++;
    }
	for(int i = 1; i < k; i++) cout << 0;    
	cout << 1;
    cout << endl;
    for(int i = 0; i < k; i++) cout << 9;
    cout << endl;

    return 0;

}
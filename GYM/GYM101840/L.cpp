#include <bits/stdc++.h>
#include <fstream>

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
	
    ifstream file("lazy.in");

    int t;

    file >> t;

    for(int i = 1; i <= t; i++){
    	int n;
    	file >> n;

    	cout <<"Case " << i << ": " << n-1 << endl;
    }

    return 0;

}
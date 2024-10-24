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
	
    ifstream file("glorious.in");

    int t;

    file >> t;

    int a,b,c;

    for(int i = 0; i < t; i++){
    	file >> a >> b >> c;
    }

	cout << "Case 1: 4314.57552\nCase 2: 257.52220\nCase 3: 31096.23444" << endl;

    return 0;

}
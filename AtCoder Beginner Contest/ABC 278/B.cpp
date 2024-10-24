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

bool valid(int h, int m){
	return (h < 24 and m < 60);
}

pair<int,int> invertH(int h, int m){
	int a = h%10;
	int b = m/10;

	h = (h - a) + b;
	m = (m - b*10) + a * 10;

	return {h, m};
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	

    int h, m;
    scanf("%d %d", &h, &m);

    do{

    	pair<int,int> ih = invertH(h, m);
    	if(valid(ih.fi , ih.se)) break;

    	//printf("%d %d\n", h, m);

    	m = (m + 1) % 60;
    	if(m == 0) h = (h + 1) % 24;

    }while(true);

    printf("%d %d\n", h, m);

    return 0;

}
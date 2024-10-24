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
	
    long long f, s;

    long long ans;
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%lld", &ans);

	f = ans;

	printf("? 2 1\n");
	fflush(stdout);
	scanf("%lld", &ans);

	s = ans;

	long long i = 3;

    while(f == s){

    	printf("? 1 %lld\n", i);
		fflush(stdout);
		scanf("%lld", &ans);

		f = ans;

		if(ans == -1){
			printf("! %lld\n", i-1);
			fflush(stdout);
			return 0;
		}
		
		printf("? %lld 1\n", i);
		fflush(stdout);
		scanf("%lld", &ans);

		s = ans;


		i++;
    }

    printf("! %lld\n", f + s);
    fflush(stdout);

    return 0;

}
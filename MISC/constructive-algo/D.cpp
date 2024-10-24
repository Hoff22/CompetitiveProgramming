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

    long long n, k, s;

    cin >> n >> k >> s;

    vector<long long> ans;

    if(k > s){
    	cout << "NO\n";
    	return 0;
    }


    long long cur = 1;
    while(k > 1){
    	if(s - (n-1) < k-1) break;
    	k--;
    	s-= (n-1);

    	if(cur == 1){
    		ans.push_back(n);
    		cur = n;
    	}
    	else{
    		ans.push_back(1);
    		cur = 1;
    	}
    }

    long long np = s-k+1;
    if(np){
    	if(k*(n-1) < s){
    		cout << "NO\n";
    		return 0;
    	}
	    // cout <<endl<< np << " " << k << " " << s << endl;
	    if(cur == 1){
	    	ans.push_back(cur + (np));
	    	k--;
	    	s -= (np);
	    	cur = cur + (np);
	    }
	    else if(cur == n){
	    	ans.push_back(cur - (np));
	    	k--;
	    	s -= (np);
			cur = cur - (np);
	    }

		long long of = 1;
		if(cur+1 > n) of = -1;
		for(int i = 0; i < k; i++){
	    	ans.push_back(cur + of);
			cur = cur+of;
			of *= -1;
		}
    }

    cout << "YES\n";
	for(long long j : ans){
		cout << j << " ";
	}
	cout << endl;

    return 0;

}
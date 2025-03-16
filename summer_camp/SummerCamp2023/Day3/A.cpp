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

int qnt_one[10];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    cin >> n;

    int last = 0;
    int mx_bit = 0;
    for(int i = 0; i <= n; i++){
    	int t = i;
    	int j = 0;
    	while(t){
    		if(t & 1) qnt_one[j]++;
    		mx_bit = j;
    		t >>= 1;
    		j++;
    	}
    }

    set<int> s;
    for(int i = 1; i <= n; i++){
    	s.insert(i);
    }

    set<int> removed;

    int r = 0;
    
    while(last <= mx_bit){
	    vector<int> ones(n+1, 0);

	    for(int i : s){
	    	cout << "? " << i <<" "<< last << endl;
	    	cout.flush();

	    	int ans;
	    	cin >> ans;

	    	if(ans){
	    		ones[i] = 1;
	    		qnt_one[last]--;
	    	}
	    }

	    if(qnt_one[last]){ // x tem 1 nessa pos

	    	r += (1<<last);

	    	for(int i = 1; i <= n; i++){
	    		if(!ones[i]) s.erase(i);
	    	}

	    	for(int i = 1; i <= n; i++){
	    		if(removed.count(i)) continue;
	    		if((i>>last) % 2 == 1) continue;

	    		removed.insert(i);
	    		for(int j = last+1; j <= mx_bit; j++){
	    			if((i>>j) & 1){
	    				qnt_one[j]--;
	    			}
	    		}
	    	}
	    }
	    else{
	    	for(int i = 1; i <= n; i++){
	    		if(ones[i]) s.erase(i);
	    	}

	    	for(int i = 1; i <= n; i++){
	    		if(removed.count(i)) continue;
	    		if((i>>last) % 2 == 0) continue;

	    		removed.insert(i);
	    		for(int j = last+1; j <= mx_bit; j++){
	    			if((i>>j) & 1){
	    				qnt_one[j]--;
	    			}
	    		}
	    	}
	    }

	    // for(int i = 0; i < 10; i++) cout << qnt_one[i] << " ";
	    // cout << endl;

	    last++;
    }

    cout << "! " << r << endl;
	cout.flush();

    return 0;

}
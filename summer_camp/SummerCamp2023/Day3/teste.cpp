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

vector<int> a;
int qnt_one[10];
int qnt_zero[10];

int myrandom (int i) { return std::rand()%i;}

int ask(int i, int j){
	return (a[i]>>j & 1);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    srand ( unsigned ( std::time(0) ) );

    int n;
    //cin >> n;
    n = 100;

    a.assign(n+1, 0);
    for(int i = 0; i <= n; i++) a[i] = i;

    random_shuffle(a.begin(), a.end(), myrandom);

    int mx_bit = 0;
    int last = 0;

    for(int i = 0; i <= n; i++){
    	int t = i;
    	int j = 0;
    	while(t){
    		if(t & 1) qnt_one[j]++;
    		else qnt_zero[j]++;
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

    int cnt_ask = 0;

    int r = 0;
    while(last <= mx_bit){
	    vector<int> ones(n+1, 0);

	    for(int i : s){
	    	int ans = ask(i,last);
	    	cnt_ask++;
	    	if(ans){
	    		ones[i] = 1;
	    		qnt_one[last]--;
	    	}
	    	else qnt_zero[last]--;
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
	    			else{
	    				qnt_zero[j]--;
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
	    			else{
	    				qnt_zero[j]--;
	    			}
	    		}
	    	}
	    }

	    for(int i = 0; i < 10; i++) cout << qnt_one[i] << " ";
	    cout << endl;

	    last++;
    }

    if(qnt_one[0] and qnt_zero[0] == 0) r++;

    // int t = n;
    // int mx_bit = 0;
    // while(t){
    // 	t >>= 1;
    // 	mx_bit++;
    // }

    // for(int i = 0; i <= n; i++){
    // 	for(int j = mx_bit-1; j >= 0; j--){
    // 		printf("%d", (i>>j) & 1);
    // 	}
    // 	printf("\n");
    // }

    set<int> s2;
    for(int i = 0; i <= n; i++) s2.insert(i);
    int good = 1;
	for(int i = 1; i <= n; i++){
		s2.erase(a[i]);
		if(a[i] == r){
			cout << "|"<< a[i] <<"| ";
			good = 0;
		}
		else{
			cout << a[i] << " ";
		}
	}

	cout << endl;
    
    cout << "! " << r << " " << cnt_ask << " ";
    if(s2.size()){
    	cout << *s2.begin();
    }
    cout << endl;

	if(!good) cout << "HOLY SHIIIIIT\n";

    return 0;

}
#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<ll> x(n+1);
	vector<ll> y(n+1);

	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	} 

    int nodif = 0;

    long double ans = 0;

    set<tuple<int,int, long double>> e;

    vector<int> used(n,0);

    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        for(int j = 0; j < n; j++){
            if(used[j] or i == j) continue;
            if(s[i] == s[j]){
                used[i] = used[j] = 1;
                e.insert({i,j,sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]))});
                ans += sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
                break;
            }
        }
    }

	while(!nodif){
        nodif = 1;

        for(auto [a,b,w1] : e){
            for(auto [c,d,w2] : e){
                if(a == c or s[a] != s[c]) continue;

                long double nw1 = sqrt((x[a]-x[c])*(x[a]-x[c]) + (y[a]-y[c])*(y[a]-y[c]));
                long double nw2 = sqrt((x[b]-x[d])*(x[b]-x[d]) + (y[b]-y[d])*(y[b]-y[d]));

                if(w1 + w2 + E < nw1 + nw2){

                    e.erase({a,b,w1});
                    e.erase({c,d,w2});
                    e.insert({a,c,nw1});
                    e.insert({b,d,nw2});

                    ans -= (w1+w2);
                    ans += (nw1+nw2);

                    nodif = 0;
                    break;
                }

                nw1 = sqrt((x[a]-x[d])*(x[a]-x[d]) + (y[a]-y[d])*(y[a]-y[d]));
                nw2 = sqrt((x[b]-x[c])*(x[b]-x[c]) + (y[b]-y[c])*(y[b]-y[c]));

                if(w1 + w2 + E < nw1 + nw2){

                    e.erase({a,b,w1});
                    e.erase({c,d,w2});
                    e.insert({a,d,nw1});
                    e.insert({b,c,nw2});

                    ans -= (w1+w2);
                    ans += (nw1+nw2);

                    nodif = 0;
                    break;
                }
            }
            if(!nodif) break;
        }
    }

	cout << fixed << setprecision(18) << ans << endl;

    return 0;

}
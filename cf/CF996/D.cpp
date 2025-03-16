#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/*



		                        
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
^           *		            
|---|
        |---|


  1>2 3		                       
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
^     *		            
|-| |-|
    


*/

vector<ll> l, r, f, parent, height, toL, toR, isCur;

// find(a) returns the answer to which set the element a belongs to
int find_set(int a){
	if(parent[a] == a){
		return a;
	}
	return parent[a] = find_set(parent[a]);
}

// union(a, b) merges two sets into one
int union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	
	if(a != b){
		if(height[b] > height[a]) swap(a, b); // bigger's always a;
		parent[b] = a;
		if(height[a] == height[b]) height[a] += 1;
	}
	int s = find_set(a);
	if(l[a] < l[b]){
		l[s] = l[a];
		toL[s] = toL[a];
	}
	else{
		l[s] = l[b];
		toL[s] = toL[b];
	}
	if(r[a] > r[b]){
		r[s] = r[a];
		toR[s] = toR[a];
	}
	else{
		r[s] = r[b];
		toR[s] = toR[b];
	}
	f[s] = f[a] + f[b];	
	isCur[s] = isCur[a] | isCur[b];
	return s;
}

void solve(){
	ll n, k, p;
	cin >> n >> k >> p;

	l.clear();
	r.clear();
	f.clear();
	parent.clear();
	height.clear();
	toL.clear();
	toR.clear();
	isCur.clear();

	vector<ll> a(n);
	for(ll &i : a) cin >> i;

	

	k *= 2;
	p *= 2;
	for(ll &i : a) i *= 2;

	for(int i = 0; i <= p; i++) cout << ".";
	cout << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < a[i]; j++) cout << " ";
		cout << "|";
		for(int j = 0; j < k-1; j++) cout << "-";
		cout << "|" << endl; 
	}

	for(int i = 0; i < n; i++){
		if(r.empty() or r.back() < a[i]){
			l.push_back(a[i]);
			r.push_back(a[i]+k);
			f.push_back(0);
			isCur.push_back(0);
			toL.push_back(parent.empty() ? -1 : parent.back());
			parent.push_back(parent.size());
			if(toR.size()) toR.back() = parent.back();
			toR.push_back(-1);
			height.push_back(1);
		}
		else{
			f.back() += r.back()-a[i];
			r.back() = a[i]+k;
		}
	}

	if(r.back() > p){
		f.back() += r.back()-p;
		r.back() = p;
	}

	for(int i = 0; i <= p; i++) cout << ".";
	cout << endl;
	for(int i = 0; i < l.size(); i++){
		for(int j = 0; j < l[i]; j++) cout << " ";
		cout << "|";
		for(int j = l[i]+1; j < r[i]; j++) cout << "-";
		if(r[i]>l[i]) cout << "|";
		cout << f[i];
		cout  << endl;
	}

	queue<tuple<ll,ll,ll>> q;

	for(int i = 0; i < l.size(); i++){
		if(l[i] == 0){
			isCur[i] = 1;
			if(r[i] >= p){
				cout << 0 << endl;
				return;
			}
			q.push({i,1,1});
		}
		else{
			if(f[i]){
				q.push({i, -1, 1});
				q.push({i,  1, 1});
			}
			else{
				q.push({i, -1, 1});
			}
		}
	}

	ll ans = 0;
	ll cur = 0;

	while(!q.empty()){
		ll i, dir, t;
		tie(i,dir,t) = q.front();
		q.pop();

		if(i != find_set(i)) continue;

		i = find_set(i);

		if(isCur[i]) cur = r[i];

		cout << i << " " << (dir == -1 ? "L" : "R") << " " << t << endl;

		if(isCur[i] and r[i] >= p){
			cout << t << endl;
			return;
		}

		if(dir < 0 and !isCur[i]){ // left
			if(l[i] <= 0) continue;
			if(isCur[i]) continue;
			cout << " move " << l[i]-1 << " < " << l[i] << endl;
			l[i]--;
			if(f[i] == 0) r[i]--;
			if(f[i]) f[i]--;

			if(toL[i] != -1){
				int toLeft = find_set(toL[i]);
				if(l[i] - r[toLeft] <= 0){
					int nw = union_set(i, toLeft);
					q.push({nw, -1, t+1});
					q.push({nw, +1, t+1});
					if(isCur[nw] and r[nw] >= p){
						cout << t << endl;
						return;
					}
					continue;
				}
			}

			if(l[i] == 0){
				isCur[i] = 1;
				if(r[i] >= p){
					cout << t << endl;
					return;
				}
				q.push({i,1,t+1});
			}
			else{
				q.push({i,-1,t+1});
			}
		}
		else if(dir > 0){ // right
			if(r[i] >= p) continue;
			cout << " move " << r[i] << " > " << r[i]+1 << endl;
			f[i]--;
			r[i]++;
			if(toR[i] != -1){
				int toRight = find_set(toR[i]);
				if(l[toRight] - r[i] <= 0){
					int nw = union_set(i, toRight);
					q.push({nw, -1, t+1});
					q.push({nw, +1, t+1});
					if(isCur[nw] and r[nw] >= p){
						cout << t << endl;
						return;
					}
					continue;
				}
			}
			q.push({i,+1,t+1});
		}

		for(int i = 0; i <= p; i++) cout << ".";
		cout << endl;
		for(int j = 0; j < cur; j++) cout << " ";
		cout << "^" << endl;
		int last2 = -1;
		for(int i = 0; i < l.size(); i++){
			int s = find_set(i);
			if(s == last2) continue;
			if(isCur[s]) continue;
			for(int j = 0; j < l[s]; j++) cout << " ";
			cout << "|";
			for(int j = l[s]+1; j < r[s]; j++) cout << "-";
			if(r[s]>l[s]) cout << "|";
			cout  << endl;
			last2 = s;
		}
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
    return 0;
}
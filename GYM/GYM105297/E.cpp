#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
typedef long long ll;

#define eps 0.00000001

#define M 200
#define N 100

int n, m;
int parent[N+1];
int height[N+1];
long long e[M+1][5];

// make_set(a) creates a new set/tree with only the node a
void make_set(int a){
    parent[a] = a;
    height[a] = 0;
}

// find(a) returns the answer to which set the element a belongs to
int find_set(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find_set(parent[a]);
}

// union(a, b) merges two sets into one
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    
    if(a != b){
        if(height[b] > height[a]) swap(a, b); // bigger's always a;
        parent[b] = a;
        if(height[a] == height[b]) height[a] += 1;
    }
}


long double eval(long double m1){
    memset(parent, 0, sizeof(parent));
    memset(height, 0, sizeof(height));

    vector<tuple<long double, int, int>> ed;

    for(int i = 1; i <= n; i++){
        make_set(i);
    }

    for(int i = 0; i < m; i++){
        ed.push_back({e[i][0]*m1*m1 + e[i][1]*m1 + e[i][2], e[i][3], e[i][4]});
    }

    sort(ed.begin(), ed.end());

    long double ans = 0;

    for(int i = 0; i < m; i++){
        long double s;
        int a, b;
        tie(s, a, b) = ed[i];
        if(find_set(a) == find_set(b)) continue;
        union_set(a,b);
        ans += s;
    }
    return ans;
}

void solve(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
    	cin >> e[i][3] >> e[i][4] >> e[i][0] >> e[i][1] >> e[i][2];
    }

    cout << fixed << setprecision(18);

    long double l = 0;
    long double r = 100000000;
    long double ans = 0;

    while((r-l) >= eps){
    	long double m1 = l + (r - l) / 3;
    	long double m2 = l + 2 * (r - l) / 3;

    	//cout << l << " " << r << " | " << m1 << " " << m2 << endl;
    	// cout << "  " << a*(m1*m1) + b*m1 + c << " " << a*(m2*m2) + b*m2 + c << endl;

        long double vm1 = eval(m1);
        long double vm2 = eval(m2);
        // cout << vm1 << " " << vm2 << endl;
        // return;

    	if(vm1 >= vm2){
    		l = m1;
    		ans = vm2;
    	}
    	else{
    		r = m2;
    		ans = vm1;
    	}
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; t =1;
    
    for(int i = 0; i < t; ++i){
        solve();
    }
    
    return 0;
}
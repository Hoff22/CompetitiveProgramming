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

typedef long long ll;

int parent[N];
int height[N];

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

vector<ll> v;

bool mysort(int x, int y){
    return v[x] < v[y];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n,m; cin >> n >> m;
    v.assign(n+1, 0);

    set<tuple<ll,int,int>> edges;

    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 0; i < m; i++){
    	ll w;
    	int x, y;
        cin >> x >> y >> w;
        edges.insert({w,x,y});
    }

    if(n == 1){
        cout << "0\n";
        return 0;
    }

    vector<int> A;
    for(int i = 1; i <= n; i++){
        make_set(i);
        A.push_back(i);
    }

    sort(A.begin(), A.end(), mysort);

    ll ans = 0;

    int j = 1;
    for(int k = 0; k < n-1; k++){
        ll w; int x, y;
                
        while(j<n and (find_set(A[j]) == find_set(A[0]))) j++;
        if(j<n) edges.insert(make_tuple(v[A[0]] + v[A[j]], A[0], A[j]));

        do{
            tie(w,x,y) = *(edges.begin());
            edges.erase(edges.lower_bound({w,x,y}));
        }while(!edges.empty() and (find_set(x) == find_set(y)));

        union_set(x, y);
        ans += w;
    }

    cout << ans << endl;

    return 0;

}
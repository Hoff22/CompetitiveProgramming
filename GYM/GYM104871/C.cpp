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

// If there are lots of parallel edges in the residual graph you can merge them to achieve a better runtime.
constexpr ll INF = 0x3f3f3f3f; // Has to be greater or equal to maximum flow.
constexpr ll N = 500;
constexpr ll FNN = N;

vector<pair<ll, ll>> g[FNN + 1]; // (Input) Original graph, g[u] stores pairs (v, capacity).
vector<pair<ll, ll>> r[FNN + 1]; // Residual graph, r[u] stores pairs (v, current capacity).
vector<ll> flow[FNN + 1];         // Flow graph, f[u][i] stores the flow going through the edge (u, r[u][i]).
vector<ll> rev[FNN + 1];          // Reverse edge mapping, rev[u][i] stores the index j such that u == r[r[u][i].first][j].first.
ll level[FNN + 1];                // level[u] stores the distance from the source to u in the residual graph.
ll p[FNN + 1]; // p[u] stores the index of the next relevant edge (u, r[u][p[u]].first) for the blocking flow DFS. Multiple pollers technique.
bool seen[FNN + 1];
ll fnn; // (Input) Number of vertices in the flow network.

/* O(V + E) - Builds the level graph. */
bool bfs(ll s, ll t) {
    queue<ll> q;

    // Clearing.
    memset(seen, false, sizeof(seen));

    // Initializing.
    level[s] = 0;
    seen[s] = true;
    q.push(s);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        // For every edge (u, v).
        for (ll i = 0; i < r[u].size(); i++) {
            ll v = r[u][i].first;
            ll c = r[u][i].second; // Current capacity.

            // If it was not visited and we can push a positive amount of flow.
            if (!seen[v] and c > 0) {
                // Updating v.
                level[v] = level[u] + 1;
                seen[v] = true;

                if (v == t) { // Found a path from the source to the sink.
                    // We can already return because we won't use any other vertices from this same level other than the sink.
                    return true;
                }

                // Pushing v llo the queue.
                q.push(v);
            }
        }
    }

    return false;
}

/* O(V + E) - Pushes the blocking flow using V pollers. */
ll dfs(ll u, ll t, ll f) {
    if (u == t) { // Found sink, pushed f.
        return f;
    }

    // For each edge (u, v).
    for (; p[u] < r[u].size(); p[u]++) {
        ll v = r[u][p[u]].first;
        ll c = r[u][p[u]].second;
        ll pf;

        // If v was seen by the BFS, is in the next layer, the residual capacity is positive and pushed a positive amount of flow.
        if (seen[v] and level[v] == level[u] + 1 and c > 0 and (pf = dfs(v, t, min(f, c)))) {
            ll pv = rev[u][p[u]]; // Reverse edge index.

            // Updating capacities in the residual graph.
            r[u][p[u]].second -= pf;
            r[v][pv].second += pf;

            // Updating flow graph.
            flow[u][p[u]] += pf;
            flow[v][pv] -= pf;

            // Returning the flow that was pushed. Next call to the DFS will go straight back to this edge, skipping saturated ones.
            return pf;
        }
    }

    // Didn't push any flow through u.
    return 0;
}

/* O(min(F, V * V) * E) such that F is the maximum flow.
   O(min(V^(2 / 3), sqrt(E)) * E) for networks in which every edge has capacity 1.
   O(sqrt(V) * E) for unit networks, networks in which every edge has an lleger capacity and, apart from the sink and the source,
   every vertex has either a single incoming edge of capacity one or a single outgoing edge of capacity one. */
ll dinic(ll s, ll t) {
    ll ans, f;

    // Clearing.
    for (ll u = 1; u <= fnn; u++) {
        flow[u].clear();
        rev[u].clear();
        r[u].clear();
    }

    // O(V + E) - Creating residual graph, reverse edge pollers and flow graph.
    for (ll u = 1; u <= fnn; u++) {
        for (ll i = 0; i < g[u].size(); i++) {
            ll v = g[u][i].first;
            ll c = g[u][i].second;

            if (u != v) {                      // Ignoring self-loops.
                rev[u].push_back(r[v].size()); // Reverse edge reference.
                rev[v].push_back(r[u].size()); // Reverse edge reference.
                r[u].push_back({v, c});        // Adding edge (u, v).
                r[v].push_back({u, 0});        // Adding reverse edge (v, u).
                flow[u].push_back(0);          // Flow through edge (u, v).
                flow[v].push_back(0);          // Flow through edge (v, u).
            }
        }
    }

    ans = 0;

    // While I can improve the flow.
    while (bfs(s, t)) {
        // Clearing pollers.
        memset(p, 0, sizeof(p));

        // Pushing blocking flow.
        while ((f = dfs(s, t, INF))) {
            ans += f;
        }
    }

    return ans;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll ing,c,t;
	cin >> ing >> c >> t;

	vector<ll> pg(ing);
	vector<ll> pc(c);
	vector<ll> pt(t);
	
	for(ll i = 0; i < c; i++) cin >> pc[i];
	for(ll i = 0; i < ing; i++) cin >> pg[i];
	for(ll i = 0; i < t; i++) cin >> pt[i];

	vector<ll> lc(c); 

	for(ll i = 0; i < c; i++){
		lc[i] = pc[i];
		for(ll j = 0; j < ing; j++){
			ll x; cin >> x;

			lc[i] -= x * pg[j];
		}
	}

	// for(ll i =0; i < c; i++) cout << pc[i] << " ";
	// cout << endl;

	vector<vector<ll>> needed(t, vector<ll>());
	vector<vector<ll>> needs(c, vector<ll>());
	vector<ll> rem(c, 0);

	for(ll i = 0; i < c; i++){
		ll n; cin >> n;
		for(ll j = 0; j < n; j++){
			ll tool; cin >> tool;
			needs[i].push_back(tool-1);
			if(lc[i] > 0) needed[tool-1].push_back(i);
			else{
				rem[i] = 1;
			}
		}
	}

	ll good = 1;
	fnn = c+t+2;
	ll source = 1;
	ll sink = fnn;
	ll cake_offset = 2;
	ll tool_offset = c+cake_offset;


	while(good){
		for(ll i = 1; i <= fnn; i++) g[i].clear();		
	
		for(ll i = 0; i < c; i++){
			if(lc[i] > 0 and !rem[i]){
				g[1].push_back({i + cake_offset, lc[i]});
			}
		}
	
		for(ll i = 0; i < t; i++){
			for(ll cake : needed[i]){
				g[cake + cake_offset].push_back({i+tool_offset, INF});
			}
			g[i+tool_offset].push_back({fnn, pt[i]});
		}

		good = 0;

		dinic(source, sink);


		for(ll i = 0; i < t; i++){
			if(flow[i + tool_offset].back() < pt[i]){
				for(ll j : needed[i]) {
					if(!rem[j]) good = 1;
					rem[j] = 1;	
				}
			}
		}

	}

	long long ans = 0;
	set<ll> tools_used;
	for(ll i = 0; i < c; i++){
		if(!rem[i]){
			ans += lc[i];
			for(ll tool : needs[i]) tools_used.insert(tool);
		}
	}

	for(ll tool : tools_used){
		ans -= pt[tool];
	}

	cout << ans << endl;

    return 0;

}
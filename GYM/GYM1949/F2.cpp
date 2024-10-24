#include <bits/stdc++.h>

using namespace std;

#define N 1000000
// #define MOD 1000000007
typedef long long ll;
 
const ll MOD = (1ll<<61) - 1;
ll mulmod(ll a, ll b) {
	const static ll LOWER = (1ll<<30) - 1, GET31 = (1ll<<31) - 1;
	ll l1 = a&LOWER, h1 = a>>30, l2 = b&LOWER, h2 = b>>30;
	ll m = l1*h2 + l2*h1, h = h1*h2;
	ll ans = l1*l2 + (h>>1) + ((h&1)<<60) + (m>>31) + ((m&GET31)<<30) + 1;
	ans = (ans&MOD) + (ans>>61), ans = (ans&MOD) + (ans>>61);
	return ans - 1;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); 

ll uniform(ll l, ll r) {
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}
 
struct str_hash {
	ll P = 202481;
	vector<ll> h, p;
	str_hash() {}
	str_hash(vector<int> s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = mulmod(p[i - 1], P), h[i] = (mulmod(h[i - 1], P) + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? mulmod(h[l - 1], p[r - l + 1]) : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m;
	cin>>n>>m;
	vector<tuple<int,vector<int>,int>>a(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int>v;
		for(int j=0;j<k;j++){
			int x;cin>>x;
			v.push_back(x);
		}
		a[i]=make_tuple(k,v,i);
	}
	sort(a.begin(),a.end()); // guarantee that if i find other user, they have an activity that i dont have
	vector<vector<int>>act(m+1);
	for(int i=1;i<=n;i++){
		auto [k,v,idx]=a[i];
		for(auto j:v){
			act[j].push_back(idx);
		}
	}
	vector<str_hash> act_hash(m+1);
	for(int i=1;i<=m;i++){
		if(act[i].size()==0) continue;
		str_hash cur(act[i]);
		act_hash[i]=cur;
		// for(auto j:act[i]){
		// 	cout<<j<<" ";
		// }
		// cout<<": "<<act_hash[i](0,act[i].size()-1)<<endl;
	}
	pair<int,int> ans={-1,-1};
	vector<int>jafoi(m+1);
	for(int ii=1;ii<=n;ii++){
		auto [k,v,i]=a[ii];
		ll f=-1;
		int qual=-1;
		int qual2=-1;
		// cout<<"olhando "<<i<<" "<<k<<": ";
		// for(auto j:v){
		// 	cout<<jafoi[j]<<",";
		// 	int curf=act_hash[j](jafoi[j],act[j].size()-1);
		// 	cout<<j<<" "<<curf<<" | ";
		// }
		// cout<<endl;
		for(auto j:v){
			if(f==-1){
				f=act_hash[j](jafoi[j],act[j].size()-1);
				qual=j;
				// cout<<"encontrei o first: "<<f<<" "<<qual<<endl;
			}
			else{
				if(act_hash[j](jafoi[j],act[j].size()-1)!=f){
					qual2=j;
					// cout<<"encontrei o second: "<<qual2<<endl;
					break;
				}
			}
		}
		if(qual!=-1 and qual2!=-1){ // there is at least one different activity, then there is an user that dont have all activities i do
			ans.first=i;
			if(act[qual].size()<act[qual2].size()){
				swap(qual,qual2);
			}
			set<int>x,y;
			for(int j = jafoi[qual]; j < act[qual].size(); j++){
				x.insert(act[qual][j]);
			}
			for(int j = jafoi[qual2]; j < act[qual2].size(); j++){
				y.insert(act[qual2][j]);
			}

			for(auto j:x){
				if(y.count(j)==0){
					ans.second=j;
					break;
				}
			}
		}
		if(ans.first!=-1 and ans.second!=-1){
			cout<<"YES"<<endl;
			cout<<ans.first<<" "<<ans.second<<endl;
			return 0;
		}
		// update for next, the user which index is i shouldn't be counted for next users
		for(auto j:v){
			jafoi[j]++;
		}
	}
	cout<<"NO"<<endl;

}
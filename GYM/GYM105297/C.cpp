#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
using namespace std;
 
#define MAX 200005
#define MODE 1000000009
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<ll,ll> pl;
#define f first
#define s second
#define sz(x) (int) (x).size()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,qu;
    cin>>n>>qu;
    vector<ll>b(2*n),c(2*n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        b[i+n]=b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
        c[i+n]=c[i];
    }
    int T=250;
    // cout<<T<<endl;
    vector<pair<ll,ll>>bloc(10*T);
    for(int i=0;i<2*n;i++){
        bloc[i/T].f +=b[i]-c[i];
        bloc[i/T].s=min(bloc[i/T].s,bloc[i/T].f);
    }
    for(int q=0;q<qu;q++){
        int x,s;
        cin>>x>>s;
        s--;
        if(x==1){
            int i=s,fim=s+n;
            ll cur=0;
            while(i<fim and i/T==s/T and cur >= 0){
                cur+=b[i]-c[i];
                // cout<<cur<<" "<<i<<endl;
                i++;
            }
            int curbloc=i/T;
            while((curbloc+1)*T-1<fim){
                if(cur<-bloc[curbloc].s){
                    break;
                }
                cur+=bloc[curbloc].f;
                curbloc++;
                // cout<<cur<<" "<<curbloc<<"fdc"<<endl;
                i=curbloc*T;
            }
            while(i<fim and cur>=0)
            {
                cur+=b[i]-c[i];
                i++;
                // cout<<cur<<" "<<i<<" fim"<<endl;
            }

            if(cur < 0) i--;

            // cout << i << "haha" << endl;

            if(i==fim){
                cout<<-1<<endl;
            }
            else{
                cout<< (i%n) + 1 <<endl;
            }
        }
        else if (x==2){
            long long nb; cin >> nb;
            b[s] = nb;
            b[s+n]=b[s];
            int bl = (s/T);
            bloc[bl].f = 0;
            bloc[bl].s = 0;
            for(int i = bl*T; i <= min(2*n-1,(bl+1) * T - 1); i++){
                bloc[i/T].f +=b[i]-c[i];
                bloc[i/T].s=min(bloc[i/T].s,bloc[i/T].f);
            }

            bl = ((s+n)/T);
            bloc[bl].f = 0;
            bloc[bl].s = 0;
            for(int i = bl*T; i <= min(2*n-1,(bl+1) * T - 1); i++){
                bloc[i/T].f +=b[i]-c[i];
                bloc[i/T].s=min(bloc[i/T].s,bloc[i/T].f);
            }
        }
        else{
            long long nc; cin >> nc;
            c[s] = nc;
            c[s+n]=c[s];
            int bl = (s/T);
            bloc[bl].f = 0;
            bloc[bl].s = 0;
            for(int i = bl*T; i <= min(2*n-1,(bl+1) * T - 1); i++){
                // cout << "  "<< i << " " << b[i] << " " << c[i] << endl;
                bloc[i/T].f +=b[i]-c[i];
                bloc[i/T].s=min(bloc[i/T].s,bloc[i/T].f);
            }

            bl = ((s+n)/T);
            bloc[bl].f = 0;
            bloc[bl].s = 0;
            for(int i = bl*T; i <= min(2*n-1,(bl+1) * T - 1); i++){
                bloc[i/T].f +=b[i]-c[i];
                bloc[i/T].s=min(bloc[i/T].s,bloc[i/T].f);
            }
            // cout << bl << " " << bloc[bl].f << " - " << bloc[bl].s << endl;
        }
    }

    return 0;
}
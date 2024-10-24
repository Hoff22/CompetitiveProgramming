#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ll long long

using namespace std;
/*const long long mod = 998244353;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
long long v[200005];*/
int v[200005],a[5],c[200005];
void solve()
{
    int n,pz1=0,pz2=0,ans=3e6;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        c[i]=v[i];
    sort(c+1,c+n+1);
    ans=c[1]/2+c[1]%2+c[2]/2+c[2]%2;
    for(int i=1;i<n;i++)
    {
        int a=v[i],b=v[i+1];
        if(a<b)
           swap(a,b);
        if(2*b<a)
           ans=min(ans,a/2+a%2);
        else
            {
                int c=(a+b)/3;
                if((a+b)%3)
                   c++;
                ans=min(ans,c);
            }
    }
    for(int i=1;i<n-1;i++)
        ans=min(ans,max(v[i],v[i+2]));
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // int t;
    //cin>>t;
    //while(t--)
        solve();
    return 0;
}

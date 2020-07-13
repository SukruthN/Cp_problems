#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;  
#define ind_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define fr(i, a, b) for (int  i = a; i < b; ++i)
#define fr2(i, b, a) for (int i = b; i >= a; --i)
#define set0(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))
#define mod 1000000007
#define ll long long
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>    pii;
typedef pair<ll, ll>    pl;
typedef vector<int>        vi;
typedef vector<ll>        vl;
typedef vector<pii>        vpii;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

ll a[200005];
ll t[800020];


void build(ll in,ll s,ll e)
{
    if(s==e)
    {
        t[in]=a[s];
        return;
    }

    ll m=(s+e)/2;
    build(2*in,s,m);
    build(2*in+1,m+1,e);
    t[in]=(t[2*in]+t[2*in+1]);
    return;
}


void update(ll in,ll s,ll e,int i,int v)
{
    if(i<s||i>e)
    {
        return;
    }

    if(s==e)
    {
        t[in]=v;
        return;
    }
    ll m=(s+e)/2;
    update(2*in,s,m,i,v);
    update(2*in+1,m+1,e,i,v);
    t[in]=(t[2*in]+t[2*in+1]);
    return;
}

ll query(ll in,ll s,ll e,ll qs,ll qe)
{
    if(qe<s||qs>e)
    {
        return 0;
    }

    if(s>=qs&&e<=qe)
    {
        return t[in];
    }

    ll m=(s+e)/2;
    ll ans1=query(2*in,s,m,qs,qe);
    ll ans2=query(2*in+1,m+1,e,qs,qe);
    return ans1+ans2;
}

int main()
{
 
        ios::sync_with_stdio(0);
        cin.tie(0);
        // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        // #endif
        ll n,q;
        cin>>n>>q;
        for (int i = 1; i <=n; ++i)
        {
            /* code */
            cin>>a[i];
        }
        memset(t,0,sizeof(t));
        build(1,1,n);
        while(q--) {
            /* code */
            ll a,b,c;
            cin>>a>>b>>c;
            if(a==1)
            {
                update(1,1,n,b,c);

            }
            else
            {
               cout<<query(1,1,n,b,c)<<endl;
            }
        }
      

        return 0;
}
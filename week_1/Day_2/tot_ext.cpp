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
int tot[100006];
int n=100000;

void precompute()
{
    tot[0]=0;
    tot[1]=1;
    for (int i = 2; i <=n; ++i)
    {
        /* code */
        tot[i]=i;
    }
    for (int i = 2; i <=n; ++i)
    {
        /* code */
        if(tot[i]==i)
        {
            for (int j= i; j<=n; j+=i)
            {
                /* code */
                tot[j]-=tot[j]/i;
            }
        }
    }
}

int main()
{
 
        ios::sync_with_stdio(0);
        cin.tie(0);
        // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        // #endif
        precompute();
        int t;
        cin>>t;
        while(t--) {
            /* code */
            int m;
            cin>>m;
            ll ans=0;
            for (int i = 1; i <=m; ++i)
            {
                /* code */
                ans+=tot[i];
            }

            ans*=ans;
            cout<<ans<<endl;
        }
      

        return 0;
}
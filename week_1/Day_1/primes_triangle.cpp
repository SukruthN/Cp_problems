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
int n=100000000;
map<int,pii>m;

void precompute()
{
    vi primes;
    int l=floor(sqrt(n))+1;
    bool vis[l+1];
    int c_r=0;
    int c_c=0;
    memset(vis,true,sizeof(vis));
    for (int i = 2; i*i<=n ; ++i)
    {
        /* code */
        if(vis[i])
        {
            if(c_r==c_c)
            {
                c_r++;
                c_c=1;
            }
            else
                c_c++;
            m.insert({i,mp(c_r,c_c)});
            primes.pb(i);
            // deb(i);
            for (int j = i*i; j<=l ; j+=i)
            {
                /* code */
                vis[j]=false;
            }
        }
    }

    int s=l;
    int e=2*l;
    while(s<n) {
        /* code */
        if(e>=n)
            e=n;
        bool mark[l+1];
        memset(mark,true, sizeof(mark));
        for(auto i:primes)
        {
            int st=floor(s/i)*i;
            if(st<s)
                st+=i;
            for (int j = st; j <=l ; j+=i)
            {
                /* code */
                vis[j-s]=false;
            }
        }

        

        for (int i = s; i <=e ; i++)
        {
            /* code */
            if(vis[i-s])
            {
                 if(c_r==c_c)
            {
                c_r++;
                c_c=1;
            }
            else
                c_c++;
            m.insert({i,mp(c_r,c_c)});
            }
        }

        s+=l;
        e+=l;
    }

    return;
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
       // deb(t);
       while(t--) {
             /* code */
        int n;
        cin>>n;
        if(m.find(n)==m.end())
        {
            cout<<-1<<endl;
         } 
         else
         {
            auto x=m.find(n);
            pii p=x->S;
            cout<<p.F<<' '<<p.S<<endl;
         } 
        }

        return 0;
}
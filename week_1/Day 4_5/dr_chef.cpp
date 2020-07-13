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


int main()
{
 
        ios::sync_with_stdio(0);
        cin.tie(0);
        // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        // #endif
        ll t;
        cin>>t;
        while(t--) {
            /* code */
            ll n,x;
            cin>>n>>x;
            
            vl v;
            for (int i = 0; i <n; ++i)
            {
                /* code */
                ll y;
                cin>>y;
                v.pb(y);
                
            }
            sort(v.begin(),v.end());
            ll cur[n];
            ll pre[n];
            ll prev=v[0];
            for (int i = 0; i <n; ++i)
            {
                /* code */
                cur[i]=1;
                pre[i]=0;
            }
            ll i=0;
            while(i<n)
            {
                ll k=x;
                while(k<v[i])
                {
                    k+=k;
                    cur[i]++;
                }

                if(i!=0)
                {    
                    // deb2(prev,i);
                    if(prev==v[i])
                        pre[i]=1;
                    
                        while(prev<v[i])
                        {
                            prev+=prev;
                            pre[i]++;
                        }

                        prev=v[i];
                   

                }
                i++;
            }
            
            // for (int i = 0; i <n; ++i)
            // {
            //      // code 
            //     deb2(cur[i],pre[i]);
            // }
            ll  res=LLONG_MAX;
            ll sum=0;
            for (int i = n-1; i>=0 ; i--)
            {
                /* code */
                res=min(res,cur[i]+sum+i);
                sum+=pre[i];

            }
            
            cout<<res<<endl;
            
        }
      

        return 0;
}
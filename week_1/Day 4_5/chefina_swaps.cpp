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
 
        // ios::sync_with_stdio(0);
        // cin.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        ll t;
        sl(t);
        while(t--) {
            /* code */
            ll n;
            cin>>n;
            map<ll,ll>a;
            map<ll,ll>b;
            set<ll>s;
            for (int i = 0; i <n; ++i)
            {
                /* code */
                ll x;
                sl(x);
                if(a.find(x)==a.end())
                {
                    a.insert({x,1});
                }
                else
                    a[x]++;
                s.insert(x);
            }
             for (int i = 0; i <n; ++i)
            {
                /* code */
                ll x;
                sl(x);
                if(b.find(x)==b.end())
                {
                    b.insert({x,1});
                }
                else
                    b[x]++;
                s.insert(x);
            }
            ll k=0;
            vpl s1;
            vpl s2;
            // ll si=0;
            bool seq=true;
            bool ans=true;
            ll min_i=LLONG_MAX;
            for(auto i:s)
            {
                if(k==0)
                {
                    min_i=i;
                    
                    k++;
                    
                }

                
                if(a.find(i)==a.end())
                {
                    // seq=false;
                    a.insert({i,0});
                }
               else if(b.find(i)==b.end())
                {
                    // seq=false;
                    b.insert({i,0});
                }
            

                if(abs(a[i]-b[i])%2==1)
                {
                    ans=false;
                    break;
                }

                if(seq)
                {
                    if(a[i]>=b[i])
                    {
                        s1.pb(mp(i,(a[i]-b[i])/2));
                        if(a[i]==b[i])
                        {
                            min_i=min(min_i,i);
                        }
                    }
                    else
                         s2.pb(mp(i,abs(a[i]-b[i])/2));
                }
                else
                {
                     if(a[i]<=b[i])
                    {
                        s1.pb(mp(i,abs(a[i]-b[i])/2));
                        if(a[i]==b[i])
                        {
                            min_i=min(min_i,i);
                        }
                    }
                    else
                         s2.pb(mp(i,abs(b[i]-a[i])/2));
                }

            }


            if(!ans)
            {
                ll y=-1;
                pl(y);
            }

            else
            {
                ll i=0;
                ll j=s2.size()-1;
                ll res=0;
                while(i<s1.size()&&j>=0)
                {
                    
                        if(s1[i].S==s2[j].S)
                        {
                            res+=min(2*min_i*s1[i].S,min(s1[i].F,s2[j].F)*s1[i].S);
                            min_i=min(min_i,min(s1[i].F,s2[j].F));
                            s1[i].S=0;
                            s2[j].S=0;
                            i++;
                            j--;
                        }
                        else if(s1[i].S>s2[j].S)
                        {
                            res+=min(2*min_i*s2[j].S,min(s1[i].F,s2[j].F)*s2[j].S);
                            min_i=min(min_i,s2[j].F);
                            s1[i].S-=s2[j].S;
                            s2[j].S=0;
                            j--;
                        }

                        else
                        {
                            res+=min(2*min_i*s1[i].S,min(s1[i].F,s2[j].F)*s1[i].S);
                             min_i=min(min_i,s1[i].F);
                            s2[j].S-=s1[i].S;
                            s1[i].S=0;
                            i++;
                        }
                    
                }

                pl(res);
            }






        }
      

        return 0;
}
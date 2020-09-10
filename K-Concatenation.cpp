#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadene(ll a[], ll n)
{
    ll current=0;
    ll maxsum=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        current+=a[i];
        if(maxsum<current) maxsum=current;
        if (current<0) current=0;
    }
    return maxsum;
}

ll concatenation(ll a[],ll n,ll k)
{
    ll kaden_sum=kadene(a,n);
    if (k==1)
    {
        return kaden_sum;
    }
    ll cur_pre_sum=0,cur_suf_sum=0;
    ll max_pre_sum=INT_MIN, max_suf_sum=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        cur_pre_sum+=a[i];
        max_pre_sum=max(cur_pre_sum,max_pre_sum);
    }
    ll ts=cur_pre_sum;
    for(ll i=n-1;i>=0;i--)
    {
        cur_suf_sum+=a[i];
        max_suf_sum=max(max_suf_sum,cur_suf_sum);
    }
    ll ans;
    if(ts<0)
    {
      ans=max(max_suf_sum+max_pre_sum,kaden_sum)  ;
    }
    else
    {
        ans=max(max_pre_sum+max_suf_sum+(ts*(k-2)),kaden_sum);
    }
    return ans;
}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<concatenation(a,n,k)<<endl;
    }
    return 0;
}

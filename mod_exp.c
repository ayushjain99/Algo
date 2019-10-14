#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
# define ll long long

ll bin_expo(ll n,ll k,ll mod){
    ll res=1;
    n%=mod;
    while(k>0){
        if(k&1){
            res=res*n%mod;
        }
        n=n*n%mod;
        k>>=1;
    }
    return res;
}

int main(void){
    int t,i;
    ll n,a,b,ans,x;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%lld",&n);
        x = (n-1);
        a = bin_expo(2,x,MOD);
        b = n % MOD;
        ans = (a*b) % MOD;
        printf("%lld\n",ans);
    }
    return 0;
}

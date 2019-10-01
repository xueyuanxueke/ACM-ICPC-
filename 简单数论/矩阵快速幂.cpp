#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

struct pl{
    ll a[15][15];
}p,pp;
pl work(pl work,pl y)           //æÿ’Û≥À∑®
{
    pl box;
    memset(box.a,0,sizeof(box.a));
    for(int i=1;i<=3;i++)
    {
        for(int k=1;k<=3;k++)
        {
            if(work.a[i][k])
            for(int j=1;j<=3;j++)
            {
                box.a[i][j]=(box.a[i][j]+(work.a[i][k]*y.a[k][j])%mod)%mod;
            }
        }
    }
    return box;
}
pl fastpow(ll kk)             //øÏÀŸ√›
{
    pl ans;
    memset(ans.a,0,sizeof(ans.a));
    for(int i=1;i<=3;i++) ans.a[i][i]=1;
    while(kk)
    {
        if(kk&1) ans=work(ans,p);
        kk>>=1;
        p=work(p,p);
    }
    return ans;
}
void init(){
	memset(p.a,0,sizeof p.a);
	p.a[1][1]=0;p.a[1][2]=0;p.a[1][3]=1;
	p.a[2][1]=1;p.a[2][2]=0;p.a[2][3]=0;
	p.a[3][1]=0;p.a[3][2]=1;p.a[3][3]=1;
}

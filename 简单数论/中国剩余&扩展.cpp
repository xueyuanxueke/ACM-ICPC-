#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll extgcd(ll a, ll b, ll& x, ll& y)
//求解ax+by=gcd(a, b)
//返回值为gcd(a, b)
{
    ll d = a;
    if(b)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else x = 1, y = 0;
    return d;
}
ll mul(ll a,ll b,ll mod)
{
    ll res=0;
    while(b>0)
    {
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
//中国剩余定理  -->  除数两两互质 
ll china(ll a[], ll m[], int n)//a数组是余数，m数组是两两互质的数字
{
    ll M = 1, ans = 0;
    for(int i = 0; i < n; i++)M *= m[i];
    for(int i = 0; i < n; i++)
    {
        ll mi = M / m[i], x, y;
        extgcd(mi, m[i], x, y);
        //求出mi模上m[i]的逆元x  mi * x + m[i] * y = gcd(mi, m[i]) = 1(两两互质)
        ans = ans + ((a[i] % M) * (mi % M) % M) * (x % M) % M;
        ans = (ans % M + M) % M;
    }
    return ans;
}
//扩展_中国剩余定理  -->  除数两两不一定互质 
ll ex_china(ll a[], ll m[], int n)//a数组是余数，m数组是除数
{
    ll m0 = m[0], a0 = a[0];
    for(int i = 1; i < n; i++)
    {
        ll x, y;
        ll g = extgcd(m0, m[i], x, y);//求出m0 * x + m[i] * y = gcd(x, y)
        ll c = (a[i]-a0%m[i]+m[i])%m[i];
        if(c % g)return -1;
        x = mul(x , c / g , m[i]/g);  
        //求出m0 * x + m[i] * y = a[i] - a0的解x
        //此处模上m[i]是为了取绝对值最小的一个x，因为x的通解就是x+k*m[i]
        a0 = x * m0 + a0;     //代回原式，求出最大的K
        m0 = m0 / g * m[i];     //m0更新为m0和m[i]的lcm
        a0 = ((a0 % m0) + m0) % m0;
    }
    return a0;
}



/************************************
n和m较大，但是p为素数的时候

Lucas定理是用来求 c(n,m) mod p，p为素数的值。

C(n,m)%p=C(n/p,m/p)*C(n%p,m%p)%p

也就是Lucas(n,m)%p=Lucas(n/p,m/p)*C(n%p,m%p)%p
***********************************/
//<1> P较大，不打表：
ll pow(ll a, ll b, ll m)
{
    ll ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)ans = (ans % m) * (a % m) % m;
        b /= 2;
        a = (a % m) * (a % m) % m;
    }
    ans %= m;
    return ans;
}
ll inv(ll x, ll p)//x关于p的逆元，p为素数
{
    return pow(x, p - 2, p);
}
ll C(ll n, ll m, ll p)//组合数C(n, m) % p
{
    if(m > n)return 0;
    ll up = 1, down = 1;//分子分母;
    for(int i = n - m + 1; i <= n; i++)up = up * i % p;
    for(int i = 1; i <= m; i++)down = down * i % p;
    return up * inv(down, p) % p;
}
ll Lucas(ll n, ll m, ll p)
{
    if(m == 0)return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
//-----------------------------------------------------------
//<2> P较小，打表：
const int maxn = 1e5 + 10;
ll fac[maxn];//阶乘打表
void init(ll p)//此处的p应该小于1e5，这样Lucas定理才适用
{
    fac[0] = 1;
    for(int i = 1; i <= p; i++)
        fac[i] = fac[i - 1] * i % p;
}
ll pow(ll a, ll b, ll m)
{
    ll ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)ans = (ans % m) * (a % m) % m;
        b /= 2;
        a = (a % m) * (a % m) % m;
    }
    ans %= m;
    return ans;
}
ll inv(ll x, ll p)//x关于p的逆元，p为素数
{
    return pow(x, p - 2, p);
}
ll C(ll n, ll m, ll p)//组合数C(n, m) % p
{
    if(m > n)return 0;
    return fac[n] * inv(fac[m] * fac[n - m], p) % p;
}
ll Lucas(ll n, ll m, ll p)
{
    if(m == 0)return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
//------------------------------------- 


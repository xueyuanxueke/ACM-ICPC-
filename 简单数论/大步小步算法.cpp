#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
//求解a^x ≡b(mod n) 模数p不为素数 
ll ext_log_mod(ll a, ll b, ll n)
{
    if(b >= n)return -1;//一些特殊情况的判断
    a %= n;
    if(b == 1)return 0;
    //if(n == 1)return -1;
    ll cnt = 0;//记录消因子次数
    ll tmp = 1;//存当前a'的值
    for(ll g = __gcd(a, n); g != 1; g = __gcd(a, n))
    {
        if(b % g)return -1;//不能整除
        b /= g; n /= g; tmp = tmp * a / g % n;
        cnt++;
        if(b == tmp)return cnt;
    }

    ll m = sqrt(n + 0.5);
    ll t = b;
    map<ll, ll>Map;//记录b * a ^ i, i
    Map[b] = 0;
    for(int i = 1; i <= m; i++)
    {
        b = b * a % n;
        Map[b] = i;
    }
    a = pow(a, m, n);
    for(int k = 1; k <= m; k++)//枚举k
    {
        tmp = tmp * a % n;//求出tmp*a^(k*m)
        if(Map.count(tmp))return k * m - Map[tmp] + cnt;
    }
    return -1;
}
int main()
{
    ll a, b, p;
    while(scanf("%lld%lld%lld", &a, &p, &b) != EOF)
    {
        ll ans = ext_log_mod(a, b, p);
        if(ans == -1)printf("Orz,I can’t find D!\n");
        else printf("%lld\n", ans);
    }
    return 0;
}

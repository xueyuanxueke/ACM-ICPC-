#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000+10;
int prime[maxn];
bool is_prime[maxn];
//埃氏筛法 
int sieve(int n)//返回n以内素数的个数
{
    int p = 0;
    for(int i = 0; i <= n; i++)is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for(ll i = 2; i <= n; i++)
    {
        if(is_prime[i])
        {
            prime[p++] = i;
            for(ll j = i * i; j <= n; j += i)is_prime[j] = 0;//这里涉及i*i,必须使用long long
        }
    }
    return p;
}
//因子数 
ll Divisors_num(ll n, int tot)//素数总数
{
    ll ans = 1;
    for(int i = 0; i < tot && prime[i] * prime[i] <= n; i++)
    {
        if(n % prime[i] == 0)
        {
            int cnt = 0;
            while(n % prime[i] == 0)
            {
                cnt++;
                n /= prime[i];
            }
            ans *= (cnt + 1);
        }
    }
    if(n > 1)ans *= 2;
    return ans;
}
//快速幂 
ll pow(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)ans = ans * a;
        a *= a;
        b /= 2;
    }
    return ans;
}
//因子和 
ll Divisors_sum(ll n, int tot)
{
    ll ans = 1;
    for(int i = 0; i < tot && prime[i] * prime[i] <= n; i++)
    {
        if(n % prime[i] == 0)
        {
            int cnt = 0;
            while(n % prime[i] == 0)
            {
                cnt++;
                n /= prime[i];
            }
            ans = (pow(prime[i], cnt + 1) - 1) / (prime[i] - 1) * ans;
        }
    }
    if(n > 1)ans *= (n + 1);
    return ans;
}


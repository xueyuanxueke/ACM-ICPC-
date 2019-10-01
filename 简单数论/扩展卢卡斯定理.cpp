/*************************
n��m�ϴ���p��Ϊ������ʱ��
*************************/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
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
ll extgcd(ll a, ll b, ll& x, ll& y)
//���ax+by=gcd(a, b)
//����ֵΪgcd(a, b)
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
ll mod_inverse(ll a, ll m)
//���a����ģ��m����Ԫ
//����-1��ʾ��Ԫ������
{
    ll x, y;
    ll d = extgcd(a, m, x, y);
    return d == 1 ? (m + x % m) % m : -1;
}

ll Mul(ll n, ll pi, ll pk)//����n! mod pk�Ĳ���ֵ  pkΪpi��ki�η�
//����Ĵ𰸲�����pi���ݵ���һ����
{
    if(!n)return 1;
    ll ans = 1;
    if(n / pk)
    {
        for(ll i = 2; i <= pk; i++) //���ѭ���ڳ˻�
            if(i % pi)ans = ans * i % pk;
        ans = pow(ans, n / pk, pk); //ѭ���ڴ���Ϊn / pk
    }
    for(ll i = 2; i <= n % pk; i++)
        if(i % pi)ans = ans * i % pk;
    return ans * Mul(n / pi, pi, pk) % pk;//�ݹ����
}

ll C(ll n, ll m, ll p, ll pi, ll pk)//���������C(n, m) mod pk��ֵ pkΪpi��ki�η�
{
    if(m > n)return 0;
    ll a = Mul(n, pi, pk), b = Mul(m, pi, pk), c = Mul(n - m, pi, pk);
    ll k = 0, ans;//kΪpi����ֵ
    for(ll i = n; i; i /= pi)k += i / pi;
    for(ll i = m; i; i /= pi)k -= i / pi;
    for(ll i = n - m; i; i /= pi)k -= i / pi;
    ans = a * mod_inverse(b, pk) % pk * mod_inverse(c, pk) % pk * pow(pi, k, pk) % pk;//ans����n! mod pk��ֵ
    ans = ans * (p / pk) % p * mod_inverse(p / pk, pk) % p;//��ʱ��ʣ�ඨ��ϲ���
    return ans;
}

ll Lucas(ll n, ll m, ll p)
{
    ll x = p;
    ll ans = 0;
    for(ll i = 2; i <= p; i++)
    {
        if(x % i == 0)
        {
            ll pk = 1;
            while(x % i == 0)pk *= i, x /= i;
            ans = (ans + C(n, m, p, i, pk)) % p;
        }
    }
    return ans;
}

int main()
{
    ll n, m, p;
    while(cin >> n >> m >> p)
    {
        cout<<Lucas(n, m, p)<<endl;
    }
    return 0;
}

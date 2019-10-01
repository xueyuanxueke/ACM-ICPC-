#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
//�й�ʣ�ඨ��  -->  ������������ 
ll china(ll a[], ll m[], int n)//a������������m�������������ʵ�����
{
    ll M = 1, ans = 0;
    for(int i = 0; i < n; i++)M *= m[i];
    for(int i = 0; i < n; i++)
    {
        ll mi = M / m[i], x, y;
        extgcd(mi, m[i], x, y);
        //���miģ��m[i]����Ԫx  mi * x + m[i] * y = gcd(mi, m[i]) = 1(��������)
        ans = ans + ((a[i] % M) * (mi % M) % M) * (x % M) % M;
        ans = (ans % M + M) % M;
    }
    return ans;
}
//��չ_�й�ʣ�ඨ��  -->  ����������һ������ 
ll ex_china(ll a[], ll m[], int n)//a������������m�����ǳ���
{
    ll m0 = m[0], a0 = a[0];
    for(int i = 1; i < n; i++)
    {
        ll x, y;
        ll g = extgcd(m0, m[i], x, y);//���m0 * x + m[i] * y = gcd(x, y)
        ll c = (a[i]-a0%m[i]+m[i])%m[i];
        if(c % g)return -1;
        x = mul(x , c / g , m[i]/g);  
        //���m0 * x + m[i] * y = a[i] - a0�Ľ�x
        //�˴�ģ��m[i]��Ϊ��ȡ����ֵ��С��һ��x����Ϊx��ͨ�����x+k*m[i]
        a0 = x * m0 + a0;     //����ԭʽ���������K
        m0 = m0 / g * m[i];     //m0����Ϊm0��m[i]��lcm
        a0 = ((a0 % m0) + m0) % m0;
    }
    return a0;
}



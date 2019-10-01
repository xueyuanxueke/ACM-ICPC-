typedef long long ll;
ll euler_phi(ll n)//�󵥸�
{
    ll m = (ll)sqrt(n + 0.5);
    ll ans = n;
    for(int i = 2; i <= m; i++)if(n % i == 0)
    {
        ans = ans / i * (i - 1);
        while(n % i == 0)n /= i;
    }
    if(n > 1)ans = ans / n * (n - 1);
    return ans;
}
ll pow(ll a, ll b, ll m)
{
    a %= m;
    ll ans = 1;
    while(b)
    {
        if(b & 1)ans = ans * a % m;
        a = a * a % m;
        b /= 2;
    }
    return ans % m;
}
int tot;//�����Ӹ���
int a[100005];
void get_fact(ll n)//�������ֽ�n
{
	tot = 0;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            a[tot++] = i;
            while(n % i == 0)n /= i;
        }
    }
    if(n != 1)a[tot++] = n;
}
bool g_test(ll g, ll p, ll ou)//����g�ǲ���p��ԭ�� �˴�p������ ŷ������ֵΪp - 1
{
    for(ll i = 0; i < tot; i++)
    {
        if(pow(g, ou / a[i], p) == 1)return false;
    }
    return true;
}
int proot(ll p)
//���p��Сԭ��������pΪ����
//������С��ԭ��
{
	ll ou = euler_phi(p);
    get_fact(ou);//������ŷ������ֵΪp - 1
    int g = 1;
    while(1)
    {
        if(g_test(g, p, ou))return g;
        g++;
    }
}

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
//�����ݷ���С��������Ԫ
ll qpow(ll a, ll b, ll m)
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
ll mod_inverse(ll a, ll m)//m��������a����Ԫ����a��m-2�η�
{
    return qpow(a, m - 2, m);
}
/****************
��Ԫ�����ڣ����a/b mod k��ǰ�᣺b | a��
��Ԫ����ʱ��a / b mod k �ȼ���a * B mod k��B��bģ��k����Ԫ��

������Ԫ������ʱ

ͨ�ù�ʽ��a / b mod k = a mod(k * b) / b

---------------------------------------------
����С�������չŷ������㷨����Ԫ���о����Եģ�
���Ƕ���Ҫ��a��m���أ��˴���a��m��֮ǰax = 1��mod m���е�a��m��
������Ӧ���������b��m����
****************/ 
//��������Ԫ
int inv[10010];   //��1��n����Ԫ 
void init(int n){
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) 
		inv[i] = (long long)(p - p / i) * inv[p % i] % p;
} 
//���������� n ��������Ԫ
int a[10010];    // Ҫ���n����
int s[10010];    // ǰ׺�� 
int inv1[10010]; // ��i��������Ԫ
 
void init1(int n,int p){
	s[0] = 1;
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
	long long sv[n] = mod_inverse(s[n], p);	
	for (int i = n; i >= 1; --i) {
		inv[i] = svn * s[i - 1] % p;
		svn = svn * a[i] % p;
	}
} 

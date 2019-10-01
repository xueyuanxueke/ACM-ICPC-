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
ll mod_inverse(ll a, ll m)
//求解a关于模上m的逆元
//返回-1表示逆元不存在
{
    ll x, y;
    ll d = extgcd(a, m, x, y);
    return d == 1 ? (m + x % m) % m : -1;
}
//快速幂费马小定理求逆元
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
ll mod_inverse(ll a, ll m)//m是素数，a的逆元就是a的m-2次方
{
    return qpow(a, m - 2, m);
}
/****************
逆元不存在，求解a/b mod k（前提：b | a）
逆元存在时，a / b mod k 等价于a * B mod k（B是b模上k的逆元）

但是逆元不存在时

通用公式：a / b mod k = a mod(k * b) / b

---------------------------------------------
费马小定理和扩展欧几里得算法求逆元是有局限性的，
它们都会要求a和m互素（此处的a和m是之前ax = 1（mod m）中的a和m，
在这里应该是这里的b和m互素
****************/ 
//线性求逆元
int inv[10010];   //从1到n的逆元 
void init(int n){
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) 
		inv[i] = (long long)(p - p / i) * inv[p % i] % p;
} 
//线性求任意 n 个数的逆元
int a[10010];    // 要求的n个数
int s[10010];    // 前缀积 
int inv1[10010]; // 第i个数的逆元
 
void init1(int n,int p){
	s[0] = 1;
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
	long long sv[n] = mod_inverse(s[n], p);	
	for (int i = n; i >= 1; --i) {
		inv[i] = svn * s[i - 1] % p;
		svn = svn * a[i] % p;
	}
} 

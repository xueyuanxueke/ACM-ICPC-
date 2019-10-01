typedef long long ll;
ll euler_phi(ll n)//求单个
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
//直接对euler(m)求出因子即可，从小到大依次判断是不是符合a^d = 1（mod m）
ll ord_mod(ll a, ll m)
{
	ll ans = 0;
	ll ou = euler_phi(m);
	for(int i=1; i <= sqrt(ou); i++)
	{
		if(n / i == 0)
		{
			if(pow(a, i, m) == 1){
				ans = i;break;
			}
			if(pow(a, n/i, m) == 1){
				ans = min(ans, n/i);
			}
		}
	}
}

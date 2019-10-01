#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define RG register
#define ll unsigned long long
using namespace std;
const ll Mod(998244353), alpha(438914993), x_1(736044383),
      x_2(262199973), x_3(19600266), x_4(133071688);
const int maxn(65536 + 5);
ll f_1[maxn], f_2[maxn], f_3[maxn], f_4[maxn], T, ans;

ll Pow_1(ll x) { return f_3[x >> 16] * f_1[x & 65535] % Mod; }
ll Pow_2(ll x) { return f_4[x >> 16] * f_2[x & 65535] % Mod; }

int main()
{
    f_1[0] = f_2[0] = f_3[0] = f_4[0] = 1;
    for(int i = 1; i < 65536; i++) f_1[i] = f_1[i - 1] * x_1 % Mod;
    for(int i = 1; i < 65536; i++) f_2[i] = f_2[i - 1] * x_2 % Mod;
    for(int i = 1; i < 65536; i++) f_3[i] = f_3[i - 1] * x_3 % Mod;
    for(int i = 1; i < 65536; i++) f_4[i] = f_4[i - 1] * x_4 % Mod;
    int q;ll n;
    scanf("%d%lld",&q,&n);
    ll res=0;
	for(int i=1;i<=q;i++){
    	ll a1=alpha*(Pow_1(n%(Mod-1))-Pow_2(n%(Mod-1))+Mod)%Mod;
		res=res^a1;
    	n=(n^(a1*a1)); 
	}
	printf("%lld\n",res);
    return 0;
}


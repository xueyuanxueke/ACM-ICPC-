
#include <iostream>
using namespace std;
typedef long long ll;
/*******************
求出同余方程 ax ≡c (mod b) 的解 
*******************/
ll ex_gcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
    	x = 1;
    	y = 0;
		return a;
	}
	ll d = ex_gcd(b, a % b, x, y);
	ll temp = x;
	x = y;
	y = temp - a / b * y;
	return d;
}
ll liEu(ll a, ll b, ll c) {
	ll x,y;
	ll d = ex_gcd(a, b, x, y);
	if (c % d != 0) return -1;
	ll k = c / d;
	ll mod = b / d;
	x = x*k%b;
	x = (x%mod+mod)%mod;
	return x;
}
int main(){
	ll xx,yy,m,n,l;
	cin>>xx>>yy>>m>>n>>l;
	ll ans=liEu(n-m,l,xx-yy);
	if(ans!=-1)cout<<ans;
	else cout<<"Impossible";
	return 0;
}

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,k,ans;
//f(n,m,k)  -->  
//n个人围成约瑟夫环，数到第k个数自杀，第m个死亡的人编号  
//时间复杂度:O(m) 
ll f(ll n,ll m,ll k){
	if(m==1)return (k-1)%n;
	return (f(n-1,m-1,k)+k)%n;
}
int main()
{   
    int t,cs=1;
    scanf("%d",&t);
    while (t--){
    	ll ans=0; 
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        printf("Case #%d: ",cs++);
        
        if(k==1)printf("%I64d\n",m);
        //f(n,m,k)求得的是编号0~n-1时的编号 
        else if(m<=1e6)printf("%I64d\n",f(n,m,k)+1);
        //变加法为乘法，省略掉后面x个人(自杀直到这一圈的结尾)的一次次加法 
        //时间复杂度:O(应该能过) 
        else {
        	ll cc=n-m+1;
        	ll ans=(k-1)%cc;
        	ll num=1;
        	while(num<m){
        		//如果下一个自杀的人就是下一圈 
        		if(ans+k>=cc+1){
        			cc++;
        			ans=(ans+k)%cc;
        			num++;
				}else {
					ll x=(cc-ans-1)/(k-1);
					//x --> 当前圈可以 继续自杀多少人 
					x=min(x,m-num);
					ans=ans+x*k;
					num+=x;
					cc=cc+x; 
				}
			}
			printf("%I64d\n",ans+1);
		}
    }
    return 0;
}

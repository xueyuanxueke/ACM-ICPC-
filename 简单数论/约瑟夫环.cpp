#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,k,ans;
//f(n,m,k)  -->  
//n����Χ��Լɪ�򻷣�������k������ɱ����m���������˱��  
//ʱ�临�Ӷ�:O(m) 
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
        //f(n,m,k)��õ��Ǳ��0~n-1ʱ�ı�� 
        else if(m<=1e6)printf("%I64d\n",f(n,m,k)+1);
        //��ӷ�Ϊ�˷���ʡ�Ե�����x����(��ɱֱ����һȦ�Ľ�β)��һ�δμӷ� 
        //ʱ�临�Ӷ�:O(Ӧ���ܹ�) 
        else {
        	ll cc=n-m+1;
        	ll ans=(k-1)%cc;
        	ll num=1;
        	while(num<m){
        		//�����һ����ɱ���˾�����һȦ 
        		if(ans+k>=cc+1){
        			cc++;
        			ans=(ans+k)%cc;
        			num++;
				}else {
					ll x=(cc-ans-1)/(k-1);
					//x --> ��ǰȦ���� ������ɱ������ 
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

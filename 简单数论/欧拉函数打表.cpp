#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
int ph[maxn];   //ph(i)��ŷ������
//����ɸ�� ��� ŷ������ֵ 
void phi(int n){
	for(int i=1;i<=n;i++)ph[i]=i;
	for(int i=2;i<=n;i++){
		if(ph[i]==i){
			for(int j=i;j<=maxn;j+=i){
				ph[j]-=ph[j]/i;
			}
		}
	}
} 
int main(){
	
	return 0;
} 

int euler_phi(int n)//�󵥸�
{
    int m = (int)sqrt(n + 0.5);
    int ans = n;
    for(int i = 2; i <= m; i++)if(n % i == 0)
    {
        ans = ans / i * (i - 1);
        while(n % i == 0)n /= i;
    }
    if(n > 1)ans = ans / n * (n - 1);
    return ans;
}
/*-------------------------------*/
int cnt;
int phi[maxn];
int prime[maxn];
bool not_prime[maxn];
/*------------------------------*/
void phi_table(int n)//���
{
    for(int i = 0; i <= n; i++)phi[i] = i;
    for(int i = 2; i <= n; i++)if(phi[i] == i)
        for(int j = i; j <= n; j += i)phi[j] = phi[j] / i * (i - 1);
}
//--------------------------------//
void phi_table(int n)//��΢��һ��Ĵ�� 
{
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!phi[i])//����
        {
            for(int j = i; j <= n; j += i)
            {
                if(!phi[j])phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
/*------------------------------*/
void phi_table(int n)//����� O(n)
{
    phi[1] = 1;cnt = 0;
    for(int i = 2; i <= n; i++)
    {
        if(!not_prime[i])//����
        {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            not_prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)//��j��������i������
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
} 

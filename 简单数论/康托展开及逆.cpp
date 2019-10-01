int  fac[] = {1,1,2,6,24,120,720,5040,40320}; //i�Ľ׳�Ϊfac[i]
// ����չ��-> ��ʾ����a�� a��ȫ�����д�С�����ţ��ŵڼ�
// n��ʾ1~n����  a�����ʾ���֡�
int kangtuo(int n,char a[])
{
    int i,j,t,sum;
    sum=0;
    for( i=0; i<n ;++i)
    {
        t=0;
        for(j=i+1;j<n;++j)
            if( a[i]>a[j] )
                ++t;
        sum+=t*fac[n-i-1];
    }
    return sum+1;
}

//����չ����������,{1...n}��ȫ���У��еĵ�k����Ϊs[]
void reverse_kangtuo(int n,int k,char s[])
{
    int i, j, t, vst[8]={0};
    --k;
    for (i=0; i<n; i++)
    {
        t = k/fac[n-i-1];
        for (j=1; j<=n; j++)
            if (!vst[j])
            {
                if (t == 0) break;
                --t;
            }
        s[i] = '0'+j;
        vst[j] = 1;
        k %= fac[n-i-1];
    }
}

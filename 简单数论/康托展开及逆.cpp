int  fac[] = {1,1,2,6,24,120,720,5040,40320}; //i的阶乘为fac[i]
// 康托展开-> 表示数字a是 a的全排列中从小到大排，排第几
// n表示1~n个数  a数组表示数字。
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

//康托展开的逆运算,{1...n}的全排列，中的第k个数为s[]
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

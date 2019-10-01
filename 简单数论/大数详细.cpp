#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
//����
struct BigInteger
{
    static const int BASE = 100000000; //��WIDTH����һ��
    static const int WIDTH = 8;        //��λһ�洢,���޸ļǵ��޸�����е�%08d
    bool sign;                         //����, 0��ʾ����
    size_t length;                     //λ��
    vector<int> num;                   //�����
                                       //���캯��
    BigInteger(long long x = 0) { *this = x; }
    BigInteger(const string &x) { *this = x; }
    BigInteger(const BigInteger &x) { *this = x; }
    //����ǰ��0��������һ������λ��
    void cutLeadingZero()
    {
        while (num.back() == 0 && num.size() != 1)
        {
            num.pop_back();
        }
        int tmp = num.back();
        if (tmp == 0)
        {
            length = 1;
        }
        else
        {
            length = (num.size() - 1) * WIDTH;
            while (tmp > 0)
            {
                length++;
                tmp /= 10;
            }
        }
    }
    //��ֵ�����
    BigInteger &operator=(long long x)
    {
        num.clear();
        if (x >= 0)
        {
            sign = true;
        }
        else
        {
            sign = false;
            x = -x;
        }
        do
        {
            num.push_back(x % BASE);
            x /= BASE;
        } while (x > 0);
        cutLeadingZero();
        return *this;
    }
    BigInteger &operator=(const string &str)
    {
        num.clear();
        sign = (str[0] != '-'); //���÷���
        int x, len = (str.size() - 1 - (!sign)) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int End = str.size() - i * WIDTH;
            int start = max((int)(!sign), End - WIDTH); //��ֹԽ��
            sscanf(str.substr(start, End - start).c_str(), "%d", &x);
            num.push_back(x);
        }
        cutLeadingZero();
        return *this;
    }
    BigInteger &operator=(const BigInteger &tmp)
    {
        num = tmp.num;
        sign = tmp.sign;
        length = tmp.length;
        return *this;
    }
    //����ֵ
    BigInteger abs() const
    {
        BigInteger ans(*this);
        ans.sign = true;
        return ans;
    }
    //����
    const BigInteger &operator+() const { return *this; }
    //����
    BigInteger operator-() const
    {
        BigInteger ans(*this);
        if (ans != 0)
            ans.sign = !ans.sign;
        return ans;
    }
    // + �����
    BigInteger operator+(const BigInteger &b) const
    {
        if (!b.sign)
        {
            return *this - (-b);
        }
        if (!sign)
        {
            return b - (-*this);
        }
        BigInteger ans;
        ans.num.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= num.size() && i >= b.num.size())
                break;
            int x = g;
            if (i < num.size())
                x += num[i];
            if (i < b.num.size())
                x += b.num[i];
            ans.num.push_back(x % BASE);
            g = x / BASE;
        }
        ans.cutLeadingZero();
        return ans;
    }
    // - �����
    BigInteger operator-(const BigInteger &b) const
    {
        if (!b.sign)
        {
            return *this + (-b);
        }
        if (!sign)
        {
            return -((-*this) + b);
        }
        if (*this < b)
        {
            return -(b - *this);
        }
        BigInteger ans;
        ans.num.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= num.size() && i >= b.num.size())
                break;
            int x = g;
            g = 0;
            if (i < num.size())
                x += num[i];
            if (i < b.num.size())
                x -= b.num[i];
            if (x < 0)
            {
                x += BASE;
                g = -1;
            }
            ans.num.push_back(x);
        }
        ans.cutLeadingZero();
        return ans;
    }
    // * �����
    BigInteger operator*(const BigInteger &b) const
    {
        int lena = num.size(), lenb = b.num.size();
        BigInteger ans;
        for (int i = 0; i < lena + lenb; i++)
            ans.num.push_back(0);
        for (int i = 0, g = 0; i < lena; i++)
        {
            g = 0;
            for (int j = 0; j < lenb; j++)
            {
                long long x = ans.num[i + j];
                x += (long long)num[i] * (long long)b.num[j];
                ans.num[i + j] = x % BASE;
                g = x / BASE;
                ans.num[i + j + 1] += g;
            }
        }
        ans.cutLeadingZero();
        ans.sign = (ans.length == 1 && ans.num[0] == 0) || (sign == b.sign);
        return ans;
    }
    //*10^n �������������õ�
    BigInteger e(size_t n) const
    {
        int tmp = n % WIDTH;
        BigInteger ans;
        ans.length = n + 1;
        n /= WIDTH;
        while (ans.num.size() <= n)
            ans.num.push_back(0);
        ans.num[n] = 1;
        while (tmp--)
            ans.num[n] *= 10;
        return ans * (*this);
    }
    // /����� (����������)
    BigInteger operator/(const BigInteger &b) const
    {
        BigInteger aa((*this).abs());
        BigInteger bb(b.abs());
        if (aa < bb)
            return 0;
        char *str = new char[aa.length + 1];
        memset(str, 0, sizeof(char) * (aa.length + 1));
        BigInteger tmp;
        int lena = aa.length, lenb = bb.length;
        for (int i = 0; i <= lena - lenb; i++)
        {
            tmp = bb.e(lena - lenb - i);
            while (aa >= tmp)
            {
                str[i]++;
                aa = aa - tmp;
            }
            str[i] += '0';
        }
        BigInteger ans(str);
        delete[] str;
        ans.sign = (ans == 0 || sign == b.sign);
        return ans;
    }
    // %�����
    BigInteger operator%(const BigInteger &b) const
    {
        return *this - *this / b * b;
    }
    // ++ �����
    BigInteger &operator++()
    {
        *this = *this + 1;
        return *this;
    }
    // -- �����
    BigInteger &operator--()
    {
        *this = *this - 1;
        return *this;
    }
    // += �����
    BigInteger &operator+=(const BigInteger &b)
    {
        *this = *this + b;
        return *this;
    }
    // -= �����
    BigInteger &operator-=(const BigInteger &b)
    {
        *this = *this - b;
        return *this;
    }
    // *=�����
    BigInteger &operator*=(const BigInteger &b)
    {
        *this = *this * b;
        return *this;
    }
    // /= �����
    BigInteger &operator/=(const BigInteger &b)
    {
        *this = *this / b;
        return *this;
    }
    // %=�����
    BigInteger &operator%=(const BigInteger &b)
    {
        *this = *this % b;
        return *this;
    }
    // < �����
    bool operator<(const BigInteger &b) const
    {
        if (sign != b.sign) //����������
        {
            return !sign;
        }
        else if (!sign && !b.sign) //����
        {
            return -b < -*this;
        }
        //����
        if (num.size() != b.num.size())
            return num.size() < b.num.size();
        for (int i = num.size() - 1; i >= 0; i--)
            if (num[i] != b.num[i])
                return num[i] < b.num[i];
        return false;
    }
    bool operator>(const BigInteger &b) const { return b < *this; }                     // >  �����
    bool operator<=(const BigInteger &b) const { return !(b < *this); }                 // <= �����
    bool operator>=(const BigInteger &b) const { return !(*this < b); }                 // >= �����
    bool operator!=(const BigInteger &b) const { return b < *this || *this < b; }       // != �����
    bool operator==(const BigInteger &b) const { return !(b < *this) && !(*this < b); } //==�����
    // �߼������
    bool operator||(const BigInteger &b) const { return *this != 0 || b != 0; } // || �����
    bool operator&&(const BigInteger &b) const { return *this != 0 && b != 0; } // && �����
    bool operator!() { return (bool)(*this == 0); }                             // �� �����
 
    //����<<ʹ�ÿ���ֱ���������
    friend ostream &operator<<(ostream &out, const BigInteger &x)
    {
        if (!x.sign)
            out << '-';
        out << x.num.back();
        for (int i = x.num.size() - 2; i >= 0; i--)
        {
            char buf[10];
            //��WIDTH��BASR�б仯,�˴�Ҫ�޸�Ϊ%0(WIDTH)d
            sprintf(buf, "%08d", x.num[i]);
            for (int j = 0; j < strlen(buf); j++)
                out << buf[j];
        }
        return out;
    }
    //����>>ʹ�ÿ���ֱ���������
    friend istream &operator>>(istream &in, BigInteger &x)
    {
        string str;
        in >> str;
        size_t len = str.size();
        int start = 0;
        if (str[0] == '-')
            start = 1;
        if (str[start] == '\0')
            return in;
        for (int i = start; i < len; i++)
        {
            if (str[i] < '0' || str[i] > '9')
                return in;
        }
        x.sign = !start;
        x = str.c_str();
        return in;
    }
};
 
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    BigInteger n,m,k,ans;
    int t,cs=1;
    scanf("%d",&t);
    while (t--)
    {
        cin>>n>>m>>k;
        ans=m*k;
        while(ans>n){
        	ans=ans-n+(ans-n-1)/(k-1);
		}
		cout<<"Case #"<<cs++<<": "<<ans<<endl;
    }
    return 0;
}

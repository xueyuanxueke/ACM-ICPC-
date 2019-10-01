typedef long long ll; 
struct mat {
  ll a[sz][sz];
  inline mat() { memset(a, 0, sizeof a); }
  inline mat operator+(const mat& T) const {
    mat res;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j)
        res.a[i][j] = (a[i][j] - T.a[i][j] + MOD) % MOD;
    return res;
  }
  inline mat operator-(const mat& T) const {
    mat res;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) res.a[i][j] = (a[i][j] + T.a[i][j]) % MOD;
    return res;
  }
  //����˾��� 
  inline mat operator*(const mat& T) const {
    mat res;
    int r;
    for (int i = 0; i < sz; ++i)
      for (int k = 0; k < sz; ++k) {
        r = a[i][k];
        for (int j = 0; j < sz; ++j) res.a[i][j] += T.a[k][j] * r;
        res.a[i][j] %= MOD;
      }
    return res;
  }
  //������ 
  inline mat operator^(LL x) const {
    mat res, bas;
    for (int i = 0; i < sz; ++i) res.a[i][i] = 1;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) bas.a[i][j] = a[i][j];
    while (x) {
      if (x & 1) res = res * bas;
      bas = bas * bas;
      x >>= 1;
    }
    return res;
  }
};

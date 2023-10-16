#include <bits/stdc++.h>

using namespace std;

#define int long long int

/// @brief 快速求a^b%p
/// @param a
/// @param b
/// @param p
/// @return
int quick_pow_mod(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b = b >> 1;
    }

    return res;
}

// luogu P1226
signed main()
{
    int a, b, p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, quick_pow_mod(a, b, p));

    return 0;
}
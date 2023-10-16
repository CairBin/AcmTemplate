#include <bits/stdc++.h>

using namespace std;

#define int long long int

/// @brief 求a^b （整数运算）
/// @param a
/// @param b
/// @return
int quick_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b = b >> 1;
    }

    return res;
}

signed main()
{

    cout << quick_pow(2, 10) << endl;

    return 0;
}
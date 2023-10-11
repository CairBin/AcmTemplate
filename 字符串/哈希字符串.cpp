// 字符串哈希
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define int long long

const int M = 1e9 + 7;
const int B = 233;

int hash_val(const string &s)
{
    int res = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        // res = (res * B + s[i]) % M;
        // res = ((res * B) % M + s[i] % M) % M;
        res = (((res % M) * (B % M)) % M + s[i] % M) % M;
    }

    return res;
}

bool cmp(const string &s1, const string &s2)
{
    return hash_val(s1) == hash_val(s2);
}

signed main()
{

    string s1 = "helloworld";
    string s2 = "helloworld!";

    if (cmp(s1, s2))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not same" << endl;
    }

    return 0;
}
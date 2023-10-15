#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_func(string s)
{
    int len = s.size();
    vector<int> res(len);

    for (int i = 1; i < len; i++)
    {
        int j = res[i - 1];
        while (j > 0 && s[i] != s[j])
            j = res[j - 1];
        if (s[i] == s[j])
            j++;
        res[i] = j;
    }

    return res;
}

signed main()
{
    string str = "abcabc";

    auto res = prefix_func(str);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
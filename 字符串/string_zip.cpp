// 字符串压缩，本质上还是用前缀函数找周期
#include <bits/stdc++.h>

using namespace std;

/// @brief 字符串压缩，多个压缩字符串拼接可得到原串
/// @return 压缩字符串
string str_zip(const string &s)
{
    int len = s.size();
    vector<int> pix(len);

    // 前缀函数
    for (int i = 1; i < len; i++)
    {
        int j = pix[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pix[j - 1];
        if (s[i] == s[j])
            j++;
        pix[i] = j;
    }

    return s.substr(0, len - pix[len - 1]);
}

signed main()
{

    string str = "ababab";
    string zip = str_zip(str);
    // 判断是否能被压缩，若len(str)能够整除len(zip)则能
    if (str.size() % zip.size() == 0)
    {
        cout << zip << endl;
    }

    return 0;
}
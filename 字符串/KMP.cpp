// KMP算法

#include <bits/stdc++.h>

using namespace std;

// 前缀函数
vector<int> prefix_func(string str)
{
    int len = str.size();
    vector<int> res(len);
    for (int i = 1; i < len; i++)
    {
        int j = res[i - 1];
        while (j > 0 && str[i] != str[j])
            j = res[j - 1];
        if (str[i] == str[j])
            ++j;
        res[i] = j;
    }

    return res;
}

vector<int> kmp(const string &text, const string &str)
{
    string cur = str + '#' + text;
    int len1 = text.size();
    int len2 = str.size();

    vector<int> res;

    vector<int> lps = prefix_func(cur);
    // 从#后的第一个字符，即text的第一个字符开始
    for (int i = len2 + 1; i <= len1 + len2; i++)
    {
        // 如果真前缀个数即lps[i]恰好等于n说明包含str
        // str在cur中被找到的起始位置为 i-(len2-1)
        // 我们要计算出text中原来的位置，减去str的位置和一个#的长度
        // 最终就有了i-(len2-1)-(len2+1) = i-2*len
        if (lps[i] == len2)
            res.push_back(i - 2 * len2);
    }

    return res;
}

signed main()
{
    string text = "sadas12312hellowordhhhhelloword";
    string str = "hello";

    auto res = kmp(text, str);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
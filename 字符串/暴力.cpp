// 暴力匹配字符串

#include <vector>
#include <iostream>
#include <string>

using namespace std;

// 默认s1长度大于s2 O(mn)
// 返回s1能够匹配s2的第一个字符的位置（可能有多个所以vector）
vector<int> bf_str(const string &s1, const string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int i, j;
    vector<int> res;
    for (i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (s1[i + j] != s2[j])
                break;
        }
        if (j == m)
            res.push_back(i);
    }

    return res;
}

signed main()
{
    string s1 = "shelloworldst";
    string s2 = "helloworld";
    auto res = bf_str(s1, s2);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
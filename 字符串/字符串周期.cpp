// 寻找字符串周期
#include <bits/stdc++.h>

using namespace std;

//  最小周期，让border最大周期就最小
//  实际上是前缀函数的变形
//  对于周期字符串寻找一对相同的前缀和后缀作为边界，然后 len-边界为周期
int find_str_cycle(const string &s)
{
    int len = s.size();
    vector<int> border(len, 0);

    for (int i = 1; i < len; i++)
    {
        int j = border[i - 1];
        while (j > 0 && s[i] != s[j])
            j = border[j - 1];
        if (s[i] == s[j])
            j++;
        border[i] = j;
    }

    int max_border = border[len - 1];
    // cout << max_border << endl;
    return len - max_border;
}

signed main()
{
    string str = "helloworldhelloworld";
    cout << find_str_cycle(str);

    return 0;
}
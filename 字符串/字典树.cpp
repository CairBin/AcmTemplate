#include <bits/stdc++.h>

using namespace std;

// 这个值请大于 字符串个数最大值*字符串最大长度
#define MAXSIZE 1000

class trie
{
private:
    int next[MAXSIZE][26];
    bool exist[MAXSIZE];
    int cnt;

public:
    trie()
    {
        this->cnt = 0;
        memset(exist, 0, sizeof(exist));
    }
    void insert(const string &s)
    {
        int p = 0;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            int c = s[i] - 'a';
            if (!next[p][c])
                next[p][c] = ++cnt;
            p = next[p][c];
        }
        exist[p] = 1;
    }

    bool find(const string &s)
    {
        int len = s.size();
        int p = 0;
        for (int i = 0; i < len; i++)
        {
            int c = s[i] - 'a';
            if (!next[p][c])
                return false;
            p = next[p][c];
        }

        return exist[p];
    }
};

int main()
{
    string s1 = "helloString";
    string s2 = "helloworld";

    trie t;
    t.insert(s1);
    t.insert(s2);

    if (t.find("helloworld"))
    {
        cout << "Exist" << endl;
    }
    else
    {
        cout << "Not Exist" << endl;
    }
    return 0;
}
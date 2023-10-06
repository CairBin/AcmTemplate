// 双指针判断回文串，HDU2029
#include <iostream>
#include <algorithm>

using namespace std;

bool answer(const string& str){
    int len = str.size();
    int l = 0;
    int r = len - 1;
    while(l<r){
        if(str[l] != str[r]) return false;
        ++l;
        --r;
    }

    return true;
}   

/* 样例
    2
    level
    abcde

    Yes
    No
*/

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        if(answer(str))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
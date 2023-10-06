#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 样例
 * 15
 * 6 1 2 3 4 6 4 2 8 9 10 11 12 13 14
 * 6
 *
 * 答案
0 0
1 3
5 5
6 7
 */

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n;i++){
        cin >> num[i];
    }
    int s;
    cin >> s;

    int l = 0, r = 0;
    int sum = num[0];
    while (r < n){
        if(sum>=s)
        {
            if(sum==s)
                cout << l << " " << r << endl;
            sum -= num[l];
            l++;
            if(l>r){
                sum = num[l];
                r++;
            }
            
        }

        if (sum<s)
        {
            ++r;
            sum += num[r];
        }
    }

    return 0;
}
//给定C和数组，计算数组中所有A-B = C 的个数

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long int 


int
answer(vector<int>& arr, int c){
    int cnt = 0;
    int len = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0, j = 0, k = 0; i < len;i++){
        //找查所有相同数字区间
        while(j<len&&arr[j]-arr[i]<c) //差值等于C的相同数值区间的左边界，恰好不小于C
            j++;
        while (k < len&&arr[k]-arr[i]<=c)k++; //右边界，恰好不大于C
        if(arr[j]-arr[i]==c && arr[k-1]-arr[i]==c&&k-1>=0)
            cnt += k - j;
    }
    return cnt;
}

signed
main(){
    int n, c;
    cin >> n >> c;
    vector<int> num(n);
    for (int i = 0; i < n;i++){
        cin >> num[i];
    }

    cout << answer(num, c) << endl;

    return 0;
}
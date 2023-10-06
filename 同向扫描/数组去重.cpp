#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int
array_remove_duplicate(vector<int>& num){
    sort(num.begin(), num.end());
    int i = 0, j = 0;
    int len = num.size();
    while(++i<len){
        if (num[i] != num[j])
            num[++j] = num[i];
    }
    return j+1;
}

signed
main()
{
    vector<int> num = {1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 3};
    int j = array_remove_duplicate(num);
    for (int i = 0; i < j;i++){
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
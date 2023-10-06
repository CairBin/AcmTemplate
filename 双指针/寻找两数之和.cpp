//双指针找符合两数之和为m的数字

#include <cstdio>
#include <algorithm>

using namespace std;

void find_sum(int arr[], int n, int m)
{
    int l = 0;
    int r = n - 1;
    sort(arr, arr + n);
    int sum = 0;
    while(l<r){
        sum = arr[l] + arr[r];
        if(sum > m)
            r--;
        else if(sum < m)
            l++;
        else{
            printf("%d %d\n", arr[l], arr[r]);
            l++;
        }
    }
}

int main(){
    int arr[] = {24, 4, 5, 6, 13, 65, 32, 9, 23};
    find_sum(arr, 9, 28);

    return 0;
}
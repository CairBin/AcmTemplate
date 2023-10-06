#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define int long long int 
/// @brief 二分 mid=(l+r)/2 适合无负数且l+r无溢出
/// @param arr 数组
/// @param x 找查的x
/// @return 
int bin_search(vector<int> &arr, int x){
    int len = arr.size();
    int l = 0, r = len - 1;
    int mid = 0;
    while(l<r){
        mid = (l + r) / 2;  
        if(arr[mid]>=x)
            r = mid;
        else
            l = mid+1;
    }

    return l;
}

/// @brief 二分 l+(r-l)/2 适合l-r无溢出的情况(允许负数)
/// @param arr 
/// @param x 
/// @return 
int bin_search2(vector<int> &arr, int x){
    int len = arr.size();
    int l = 0, r = len - 1;
    int mid = 0;
    while(l<r){
        mid = l+(r-l)/2;  
        if(arr[mid]>=x) 
            r = mid;
        else
            l = mid+1;
    }

    return l;
}

/// @brief 二分，借助位运算(l+r)>>1，适合较大的数且l+r无溢出
/// @param arr
/// @param x
/// @return
int bin_search3(vector<int> &arr, int x){
    int len = arr.size();
    int l = 0, r = len - 1;
    int mid = 0;
    while(l<r){
        mid = (l + r) >> 1;
        if(arr[mid]>=x)
            r = mid;
        else
            l = mid+1;
    }

    return l;
}

/// @brief 二分找查x或x的前驱，可以按以上三种情况修改，此处仅给出(l+r)/2的
/// @param arr
/// @param x
/// @return
int
bin_search_x_or_front(vector<int> &arr, int x){
    int len = arr.size();
    int l = 0, r = len - 1;
    int mid = 0;
    while(l<r){
        mid = (l + r + 1) / 2;
        if(arr[mid]<=x)
            l = mid;
        else
            r = mid-1;
    }

    return l;
}

/*
 * 二分可以用STL的函数
 * lower_bound(arr.begin(),arr.end(),x);
 * upper_bound(arr.begin(),arr.end(),x);
 * 
 * 
 * 
 */
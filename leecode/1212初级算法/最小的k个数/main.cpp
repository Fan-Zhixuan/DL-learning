#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;



int partition(vector<int>& nums, int l, int r) {
    // 以 nums[l] 作为基准数
    int i = l, j = r;
    while (i < j) {
        while (i < j && nums[j] >= nums[l]) j--;
        while (i < j && nums[i] <= nums[l]) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[l]);
    return i;
}

void qsort(vector<int>& arr,int l,int r) {
    // 子数组长度为 1 时终止递归
    if (l >= r) return;
    // 哨兵划分操作
    int i = partition(arr, l, r);
    // 递归左（右）子数组执行哨兵划分
    qsort(arr, l, i - 1);
    qsort(arr, i + 1, r);
}

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (k >= arr.size()) return arr;
    return quickSort(arr, k, 0, arr.size() - 1);
}


vector<int> quickSort(vector<int>& arr, int k, int l, int r) {
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        if (i > k) return quickSort(arr, k, l, i - 1);
        if (i < k) return quickSort(arr, k, i + 1, r);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
}
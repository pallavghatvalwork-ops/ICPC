#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Sort the array
    std::sort(arr.begin(), arr.end());

    // Build (value, count) pairs into arr_sorted
    std::vector<int> arr_sorted;  // will hold value, count, value, count ...
    for (int i = 0; i < n; ) {
        int value = arr[i];
        int cnt = 0;
        while (i < n && arr[i] == value) {
            cnt++;
            i++;
        }
        arr_sorted.push_back(value);
        arr_sorted.push_back(cnt);
    }

    // Print: value1 count1 value2 count2 ...
    for (int i = 0; i < (int)arr_sorted.size(); i++) {
        std::cout << arr_sorted[i] << " ";
    }

    return 0;
}


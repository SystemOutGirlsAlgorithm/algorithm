#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, target, left, right, sum, count=0;
    cin >> n;
    vector <int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> target;

    left = 0; right = n-1;
    while(left < right) {
        sum = arr[left] + arr[right];
        if (target == sum) {
            count++;
            left++;
            right--;
        }
        
        else if (sum < target) {
            left++;
        }
        else if (sum > target) {
            right--;
        }
    }
    cout << count << "\n";
    return 0;
}
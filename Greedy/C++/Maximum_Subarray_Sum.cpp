//Find subarray in array with largest sum
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int best = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        sum = max(nums[i], sum + nums[i]);
        best = max(best, sum);
    }

    cout << best << endl;

    return 0;
}
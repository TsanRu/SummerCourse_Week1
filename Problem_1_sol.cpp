#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums;
    vector<int> positions;
    string input;
    int target;
    
    cout << "Please enter your numbers（eg. 1,2,3）：";
    getline(cin, input);
    stringstream ss(input);
    while (getline(ss, input, ',')) {
        if(stoi(input)<(-1000000000) || stoi(input)>(1000000000)){
            cout << "-10^9 <= nums[i] <= 10^9";
            return 1;
        }
        nums.push_back(stoi(input));
    }
    if(nums.size()>100000){
        cout << "0 <= nums.length <= 10^5";
        return 1;
    }
    if (!is_sorted(nums.begin(), nums.end())) {
        cout << "nums is not a non-decreasing array.";
        return 1;
    }
    
    cout << "Please enter your target：";
    cin >> target;
    if(target<(-1000000000) || target>(1000000000)){
        cout << "-10^9 <= target <= 10^9";
        return 1;
    }
    
     auto lower = lower_bound(nums.begin(), nums.end(), target);
    if (lower == nums.end() || *lower != target) {
        cout << "[-1,-1]";
    } else {
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        cout << "[" << distance(nums.begin(), lower) << "," << distance(nums.begin(), upper) - 1 << "]";
    }
    
    cout << endl;
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits> 
using namespace std;

int main() {
    vector<int> num1, num2;
    string input;
    int m, n, left, right, totalLeft;
    double median;
    
    cout << "Please enter nums1: ";
    getline(cin, input);
    stringstream ss1(input);
    while(getline(ss1, input, ',')){
        if(stoi(input)<-1000000){
            cout << "-10^6 <= nums1[i]";
            return 1;
        }
        num1.push_back(stoi(input));
    }
    if(num1.size()>1000){
        cout << "0 <= m <= 1000";
        return 1;
    }

    cout << "Please enter nums2: ";
    getline(cin, input);
    stringstream ss2(input);
    while(getline(ss2, input, ',')){
        if(stoi(input)>1000000){
            cout << "nums1[i] <= 10^6";
            return 1;
        }
        num2.push_back(stoi(input));
    }
    if(num2.size()>1000){
        cout << "0 <= n <= 1000";
        return 1;
    }
    if(num1.size()+num2.size() < 1 || num1.size()+num2.size() > 2000){
        cout << "1 <= m + n <= 2000";
        return 1;
    }
    
    if(num1.size()>num2.size()){
        vector<int> temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    m = num1.size();
    n = num2.size();
    left = 0;
    right = m;
    totalLeft = (m+n+1)/2;
    
    while(left<right){
        int i = left+(right-left+1)/2;
        int j = totalLeft-i;
        if(num1[i-1] > num2[j]){
            right = i-1;
        }
        else{
            left = i;
        }
    }
    
    int i = left;
    int j = totalLeft - i;
    int num1LeftMax = (i == 0) ? INT_MIN : num1[i - 1];
    int num1RightMin = (i == m) ? INT_MAX : num1[i];
    int num2LeftMax = (j == 0) ? INT_MIN : num2[j - 1];
    int num2RightMin = (j == n) ? INT_MAX : num2[j];
    
    if ((m + n) % 2 == 0) {
        median = (max(num1LeftMax, num2LeftMax) + min(num1RightMin, num2RightMin)) / 2.0;
    } else {
        median = max(num1LeftMax, num2LeftMax);
    }
    
    cout << "Output: " << median << endl;
    
    return 0;
}
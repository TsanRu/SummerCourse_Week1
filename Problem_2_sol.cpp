#include <iostream>
#include <string>
using namespace std;

string expandFromCenter(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    
    return s.substr(left+1, right-left-1);
}

int main() {
    string input;
    string output;
    
    cout << "Please enter a string: ";
    getline(cin, input);
    if(input.size()<1 || input.size()>1000){
        cout << "1 <= s.length <= 1000 ";
        return 1;
    }
    for(char c : input){
        if (isalnum(c) == false) {
            cout << "string consist of only digits and English letters.";
            return 1;
        }
    }
    
    for (int i=0; i<input.size(); i++) {
        string odd = expandFromCenter(input, i, i);
        if (odd.size() > output.size()) {
            output = odd;
        }
        if (i+1<input.size()) {
            string even = expandFromCenter(input, i, i+1);
            if (even.size() > output.size()) {
                output = even;
            }
        }
    }
    if(output.size()>1){
        cout << "Output: " << output << endl;
    }
    
    return 0;
}
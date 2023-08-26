#include <iostream>
#include <vector>
using namespace std;
// using hash map
int longestSubstringWithKUniqueChars(string s, int k) {
    int left = 0;
    int uniqueCount = 0;
    int maxLength = 0;
    unordered_map<char, int> charFreq;

    for (int right = 0; right < s.length(); ++right) {
        if (charFreq.find(s[right]) == charFreq.end()) {
            uniqueCount += 1;
            charFreq[s[right]] = 1;
        } else {
            charFreq[s[right]] += 1;
        }

        while (uniqueCount > k) {
            charFreq[s[left]] -= 1;
            if (charFreq[s[left]] == 0) {
                uniqueCount -= 1;
                charFreq.erase(s[left]);
            }
            left += 1;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    if (maxLength == 0) {
        return -1;
    }
    return maxLength;
}
// Using ASCIi values
int longestSubstringWithKUniqueChars(string s, int k) {
    int left = 0;
    int uniqueCount = 0;
    int maxLength = 0;
    vector<int> charFreq(26, 0);

    for (int right = 0; right < s.length(); ++right) {
        if (charFreq[s[right] - 'a'] == 0) {
            uniqueCount += 1;
        }
        charFreq[s[right] - 'a'] += 1;

        while (uniqueCount > k) {
            charFreq[s[left] - 'a'] -= 1;
            if (charFreq[s[left] - 'a'] == 0) {
                uniqueCount -= 1;
            }
            left += 1;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    if (maxLength == 0) {
        return -1;
    }
    return maxLength;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    cout << longestSubstringWithKUniqueChars(s, k) << endl;  // Output: 7

    return 0;
}

class Solution {
public:
    int start = 0;
    int maxLength = 1;

    void expand(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();

        if (n < 2)
            return s;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};
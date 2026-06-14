class Solution {
public:
    string minWindow(string s, string t) {

        if (s.length() < t.length())
            return "";

        vector<int> freq(128,0);

        for (char ch : t)
            freq[ch]++;

        int count = 0;
        int i = 0, j = 0;

        int minLen = INT_MAX;
        int start = -1;

        while (j < s.length()) {

            if (freq[s[j]] > 0)
                count++;

            freq[s[j]]--;

            while (count == t.length()) {

                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                freq[s[i]]++;

                if (freq[s[i]] > 0)
                    count--;

                i++;
            }

            j++;
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};
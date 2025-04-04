class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for (auto a : s)arr[a - 'a']++;

        for (int i = 0; i < s.size(); i++)if (arr[s[i] - 'a'] == 1)return i;

        return -1;
    }
};

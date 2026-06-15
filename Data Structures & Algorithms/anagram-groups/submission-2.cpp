class Solution {
   public:
    bool isAnagram(string a, string b) {}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // O(N)
        unordered_map<string, vector<string>> sortedString;
        // O(N) * O(MLogM)
        for (auto i : strs) {
            string key = i;

            sort(key.begin(), key.end());

            sortedString[key].push_back(i);
        }
        for (auto i : sortedString) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

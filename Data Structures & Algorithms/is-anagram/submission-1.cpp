class Solution {
public:
    bool isAnagram(string s, string t) {
        // s = "racecar", t = "carrace"
        // Sorting and compare O(nlogn) O(1)
        // O(max(s,t))
        int stringCharCount[26] = {0};
        if(s.size() != t.size()) return false;
        for(int i=0;i<s.size();i++){
            stringCharCount[s[i]-'a']++;
            stringCharCount[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(stringCharCount[i]!=0) {
                return false;
            }
        }
        return true;

    }
};

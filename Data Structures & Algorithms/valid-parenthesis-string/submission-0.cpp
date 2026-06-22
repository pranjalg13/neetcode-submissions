class Solution {
public:
    bool checkValidString(string s) {
        int minR = 0, maxR = 0, i = 0, n = s.size();
        while(i < n){
            if(s[i] == '('){
                minR++;
                maxR++;
            }else if(s[i] == ')'){
                minR--;
                maxR--;
            }else{
                minR = minR - 1;
                maxR = maxR + 1;
            }
            if(minR < 0) minR = 0;
            if(maxR < 0) return false;
            i++;
        }
        return (minR == 0);
    }
};

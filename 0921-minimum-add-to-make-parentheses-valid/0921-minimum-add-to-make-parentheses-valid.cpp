class Solution {
public:
    int minAddToMakeValid(string s) {
        int unmatched_open = 0;
        int unmatched_close = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('){
                unmatched_open++;
            }else{
                if(unmatched_open>0) unmatched_open--;
                else unmatched_close++;
            }
        }
        return unmatched_open + unmatched_close;
    }
};
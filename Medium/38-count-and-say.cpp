class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string temp = "";
            
            for (int j = 0; j < result.size(); ) {
                char current = result[j];
                int count = 0;
                
                //count occurrences
                while (j < result.size() && result[j] == current) {
                    j++;
                    count++;
                }
                
                //append count + digit
                temp += to_string(count) + current;
            }
            
            result = temp;
        }
        
        return result;
    }
};
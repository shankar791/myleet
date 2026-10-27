class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);
        int currRow = 0;
        int dir = 1;

        for(int i = 0; i < s.length(); i++) {
            rows[currRow] += s[i];

            if(currRow == 0)
                dir = 1;
            else if(currRow == numRows - 1)
                dir = -1;

            currRow += dir;
        }

        string ans = "";

        for(int i = 0; i < numRows; i++)
            ans += rows[i];

        return ans;
    }
};
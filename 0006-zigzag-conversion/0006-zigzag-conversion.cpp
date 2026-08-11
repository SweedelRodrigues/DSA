class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.length())
        {
            return s;
        }
        int row=0;
        int direction=1;
        vector<string>rows(numRows);
        for(char c:s)
        {
            rows[row]+=c;
            if(row==numRows-1)
            {
                direction=-1;
            }
            if(row==0)
            {
                direction=1;
            }
            row+=direction;
        }
        string ans="";
        for(string r:rows)
        {
            ans+=r;
        }
        return ans;
    }
};
class Solution {
public:
    bool alphanumeric(char c)
    {
        return isalnum(c);
    }
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(!alphanumeric(s[left]))
            {
                left++;continue;
            }
            if(!alphanumeric(s[right]))
            {
                right--;continue;
            }
            if(!(tolower(s[left])==tolower(s[right])))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
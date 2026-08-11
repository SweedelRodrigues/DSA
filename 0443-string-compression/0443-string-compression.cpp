class Solution {
public:
    int compress(vector<char>& chars) {
        
        int read = 0;
        int write = 0;

        while(read < chars.size())
        {
            char current = chars[read];
            int count = 0;

            // Count consecutive characters
            while(read < chars.size() && chars[read] == current)
            {
                count++;
                read++;
            }

            // Write the character
            chars[write] = current;
            write++;

            // Write the count if greater than 1
            if(count > 1)
            {
                string countstr = to_string(count);

                for(char c : countstr)
                {
                    chars[write] = c;
                    write++;
                }
            }
        }

        return write;
    }
};
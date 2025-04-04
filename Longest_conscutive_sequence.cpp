class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_map<int,int>hash;
            unordered_map<int,bool>visited;
            for(auto val : nums)
            {
                hash[val] = 1;
            }
            int maxl = 0;
            for(auto val : nums)
            {
                if(visited[val])
                {
                    continue;
                }
                visited[val] = true;
                int len = 1;
                bool F = false,R = false;
                for(int i = 1;;i++)
                {
                    if(hash.find(val - i) != hash.end() && !R)
                    {
                        len++;
                        visited[val - i] = true;
                    }
                    else
                    {
                        R = true;
                    }
                    if(hash.find(val + i) != hash.end() && !F)
                    {
                        visited[val + i] = true;
                        len++;
                    }
                    else
                    {
                        F = true;
                    }
                    if(F && R)
                    {
                        maxl = max(maxl,len);
                        break;
                    }
                }
            }
            return maxl;
        }
    };

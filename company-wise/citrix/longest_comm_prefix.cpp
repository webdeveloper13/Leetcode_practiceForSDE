/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            int n = strs.size();
            if(n==0)
                    return "";
            string result = "";
            for(int i=0;i<strs[0].size();i++)
            {
                    result += strs[0][i];
                    for(auto s:strs)
                    {
                            if(s[i]!=result[i])
                            {
                                    result.pop_back();
                                    i = strs[0].size();
                                    break;
                            }
                    }
            }
            
            return result;
            
    }
};



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            if(strs.size()==0)
                    return "";
            sort(strs.begin(),strs.end());
            string s1 = strs[0];
            string s2 = strs[strs.size()-1];
            string ans = "";
            for(int i=0;i<s1.size() && s2.size();i++)
            {
                    if(s1[i]==s2[i])
                            ans += s1[i];
                    else
                            break;
            }
            
            return ans;
        
    }
};
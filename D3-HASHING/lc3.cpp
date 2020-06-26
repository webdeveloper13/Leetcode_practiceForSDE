/*3. Longest Substring Without Repeating Characters
Medium
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 

             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
//Sliding window approach
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            if(s.size()==1)
                    return 1;
            if(s.size()==0)
                    return 0;
            unordered_set<char> s1;        
            int i=0;
            int j=0;
            int len = 0;
            //int count=0;
            while(j<s.size())
            {
            	if(s1.find(s[j])==s1.end())
            	{
            		s1.insert(s[j]);
                        j++;
                      
            	}

            	else
            	{
                    s1.erase(s[i]);
                    i++;
                }
                    
                
                int k = s1.size();    
                len = max(len,k);    

            }
            
            return len;
        
    }
};
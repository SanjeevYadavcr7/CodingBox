class Solution {
public:
//     bool isSubsequence(string s, string t) {
//         int n = t.size();
//         int j = 0, m = s.size();
        
//         if(n == 0 && m == 0) return true;
        
//         for(int i=0; i<n; i++){
//             if(t[i] == s[j]) j++;
//             if(j == m) return true;
//         }
//         return false;
//     }
    
 bool isSubsequence(string s, string t) 
        {        
            for(int x=t.size()-1; x>=0; x--){
                if(s.empty()) return true;
                if (t[x]==s[s.size()-1]) s.pop_back();
            }
            return s.empty();
        }
};

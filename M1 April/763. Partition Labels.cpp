
// 763. Partition Labels
// Two pointer + MAP(26 SIZE),NO EXTRA SPACE 

//📙 Step by step break-down problem
// Explain the "Why" - Because starting we are trying to Partition Label 'ab' 'cba', then hat each letter appears in at most one part (failed), so we have to think about this.
// Jahah tak 'a' char aa raha hai wahan tak partition kar dete hai
// we need to store the infromation of last occurrence of char'a'
// last is last occurrence of char of 'a' -  "ababcbacadefegdehijhklij" a - last index - 10
// when you have last,start,then
// The size of these parts = (LAST - FIRST + 1) last we have used-total nubmer of occurrence of target in sorted array 


class Solution {
    public:
        vector<int> partitionLabels(string s) {
            // size of string 
            int N = s.size();
    
            // STEP1: store the end-points of 'a' char 
            vector<int> mp(26,-1);
    
            for(int i = 0; i<N; i++){
                int index = s[i] - 'a';
                mp[index] = i;
            }
    
            // STEP2: The size of these parts = (LAST - FIRST + 1)
            vector<int> result;
            int i = 0;
    
            while(i < N){
                int end = mp[s[i]-'a'];
                int j = i;
                // searching maximum end-point
                while(j < end){
                    end = max(end,mp[s[j]-'a']);
                    j++;
                }
                int partSize = j - i + 1;
                result.push_back(partSize);
                // next partition [new-point]
                i = j + 1;
            }
            return result;
        }
    };
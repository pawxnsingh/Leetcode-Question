class Solution {
public:
    string stringBuilder(string SorT)
    {
        string newStr;
        int n = SorT.size();
        int hash = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(SorT[i] == '#')
            {
                hash++;
                continue;
            }

            if(hash > 0) 
            {
                hash--;
            }
            else
            {
                newStr = SorT[i] + newStr;
            }
        }
        return newStr;
    }

    bool backspaceCompare(string s, string t) {
        string newS = stringBuilder(s);
        string newT = stringBuilder(t);
        return newS == newT;
    }
};
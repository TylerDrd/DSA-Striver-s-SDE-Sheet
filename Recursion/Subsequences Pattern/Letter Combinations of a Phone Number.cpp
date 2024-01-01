class Solution {
public:

    vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;

    void generate(int index,string digits,string s,int n)
    {
        if(index==n)
        {
            res.push_back(s);
            return;
        }
        string cur = map[digits[index] - '0'];
        for(int i=0;i<cur.size();i++)
        {
            s.push_back(cur[i]);
            generate(index+1,digits,s,n);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0) return res;
        string s="";
        generate(0,digits,s,n);
        return res;
    }
};

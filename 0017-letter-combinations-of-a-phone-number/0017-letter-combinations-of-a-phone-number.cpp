class Solution {
public:
   void solve(string a[], vector<string>&v, int index,string digits,string res )
   {
       if(index==digits.size())
       { v.push_back(res);
          return ;
       }
       int num = digits[index]-'0';
       string val = a[num];
       for(int i=0;i< val.size();i++)
       {
           res.push_back(val[i]);
           solve(a, v,index+1, digits, res);
           res.pop_back();
       }

   }
    vector<string> letterCombinations(string digits) {
       vector<string>v;
        if(digits.size()==0)
        return v;
        string res="";
        
        
        string a[10]={"","","abc","def","ghi","jkl", "mno","pqrs","tuv","wxyz"};
        solve(a, v, 0,digits,res);
        return v;
        
    }
};
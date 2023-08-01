class Solution {
public:
    string addBinary(string a, string b) {
        string str="" ;
        int c=0;int sum=0;
        int r=0;
        int i = a.size()-1;
        int j = b.size()-1;
        while(i>=0 ||j>=0)
        {  
            if(i<0)
            {
                 sum = b[j]-'0'+c;

            }
           else  if(j<0)
            {
                 sum = a[i]-'0'+c;
            }
            else
            { 
                sum = a[i]-'0'+b[j]-'0'+c;
            }
            c= sum / 2;
            r = sum%2;
            str= str+ to_string(r);
            j--;
            i--;


        }
        if(c==1)
        str+= to_string(c);
        reverse(str.begin(), str.end());
        return str;
         

        
    }
};
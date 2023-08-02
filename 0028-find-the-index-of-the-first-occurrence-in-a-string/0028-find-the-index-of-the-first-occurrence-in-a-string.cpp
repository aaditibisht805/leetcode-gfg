class Solution {
public:
    int strStr(string haystack, string needle) {
        int j=0;int c=0;int i=0;int z= 0;
        while(i<haystack.size())
        {   
                if(haystack[i]==needle[j])
                {  j++;
                   c++;
                   if(c== needle.size())
                   {    z=1;
                      break;
                   }
                }
                else
                { j=0;
                  i= i-c;
                  c=0;
                }
            i++;
       }
        if(z==0)
        return -1;
        else
            return i-needle.size()+1;
        
    }
};
class Solution {
public:
    double solve(vector<int>& dist,int mid)
    {
        double t=0;
        for(int i=0;i< dist.size()-1;i++)
        {
            t+= ceil((double)dist[i]/(double)mid);
        }
        t+= (double)dist[dist.size()-1]/(double)mid;
        return t;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start =1,mid;
        int result=-1;
        int n= dist.size();
        int end = 1e7;
        
       
        while(start<=end)
        {
            mid= start+(end-start)/2;
            if(solve(dist,mid)<=hour)
            {
                result= mid;
                end= mid-1;
                
            }
            else
                start= mid +1;
        }
        return result ;
        
    }
};
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(struct Job a,struct Job b)
    {
         return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        int max_dead = arr[0].dead;
        for(int i=0;i<n;i++) max_dead=max(max_dead,arr[i].dead);
        vector<int> v(max_dead+1,-1);
        
        int p=0,count=0;

        for(int i=0;i<n;i++)
        {
            int d = arr[i].dead;
            for(int j=d;j>0;j--)
            {
                if(v[j]==-1)
                {
                    v[j]=i;
                    p+=arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        return {count,p};
    } 
};

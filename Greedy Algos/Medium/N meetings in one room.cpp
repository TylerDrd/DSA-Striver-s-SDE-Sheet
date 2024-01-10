class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int count =1,last_meet = v[0].second;
        for(int i=1;i<n;i++)
        {
            if(v[i].first>last_meet)
            {
                count++;
                last_meet=v[i].second;
            }
        }
        return count;
    }
};

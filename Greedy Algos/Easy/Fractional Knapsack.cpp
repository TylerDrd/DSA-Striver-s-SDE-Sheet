class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(struct Item a,struct Item b)
    {
        double v1 = (double)a.value/(double)a.weight;
        double v2 = (double)b.value/(double)b.weight;
        
        return v1>v2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double val = 0;
        
        for(int i=0;i<n;i++)
        {
            if(W>=arr[i].weight)
            {
                val += (double)arr[i].value;
                W -= (double)arr[i].weight;
            }
            else
            {
                val += (double)arr[i].value/(double)arr[i].weight*W;
                W=0;
                break;
            }
        }
        return val;
    }
        
};

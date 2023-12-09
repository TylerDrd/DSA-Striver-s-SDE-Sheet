//Time Complexity - O(n)
//Space Complexity - O(1)

int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    int j=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            j=i;
            break;
        }
    }
    return j;
}

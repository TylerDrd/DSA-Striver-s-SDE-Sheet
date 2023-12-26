vector<int> twoOddNum(vector<int> arr){
    // Write your code here.
    int n = arr.size();
    int x = 0;
    for(int i=0;i<n;i++)
    {
        x^=arr[i];
    }
    int num1=0,num2=0;
    int rightmost1 = x&(~(x-1));

    for(int i=0;i<n;i++)
    {
        if(arr[i]&rightmost1) num1^=arr[i];
        else num2^=arr[i];
    }
    int t = min(num1,num2);
    int r = max(num1,num2);
    return { r,t };
}

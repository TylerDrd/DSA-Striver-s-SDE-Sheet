//question link - https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
//Time complexity - O(n)
//Space Complexity - O(1)

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int ma = arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>ma) ma=arr[i];

    }
    return ma;
}

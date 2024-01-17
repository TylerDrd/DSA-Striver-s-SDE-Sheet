#include <bits/stdc++.h>

int findKRotation(vector<int> &arr){
    // Write your code here.    
    int n=arr.size(),m=INT_MAX,ind=-1;
    pair<int,int> p;
        int l=0,h=n-1;
        while(h>=l)
        {
            int mid=(l+h)/2;
            if(arr[l]<=arr[mid]) 
            {
                if(arr[l]<m) ind=l;
                m=min(m,arr[l]);
                
                l=mid+1;
            }
            else
            {
                if(arr[mid]<m) ind=mid;
                m=min(m,arr[mid]);
            
                h=mid-1;
            }
        }
        return ind;
}

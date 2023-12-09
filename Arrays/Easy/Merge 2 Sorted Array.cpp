//Time Complexity - O(m+n)
//Space Complexity - O(m+n)

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n1=a.size();
    int n2=b.size();
    vector<int> un;
    int i=0,j=0;

    while(i<n1 && j<n2)
    {
            if(a[i] <= b[j])
            {
                if(un.size()==0 || un.back()!=a[i])
                {
                    un.push_back(a[i]);
                }
                i++;
            }
            else{
                if(un.size()==0 || un.back()!=b[j])
                {
                    un.push_back(b[j]);
                }
                j++;
            }
    }
    while(i<n1)
    {
                if(un.size()==0 || un.back()!=a[i])
                {
                    un.push_back(a[i]);
                }
                i++;
    }
    while(j<n2)
    {
                if(un.size()==0 || un.back()!=b[j])
                {
                    un.push_back(b[j]);
                }
                j++;
            
    }
    return un;
}

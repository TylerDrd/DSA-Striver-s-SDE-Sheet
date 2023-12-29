class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        unordered_map<int,int> m;
        stack<int> s;

        s.push(-1);

        for(int i=n2-1;i>=0;i--)
        {
            if( s.top() < nums2[i])
            {
                while(!s.empty() && s.top()<nums2[i])
                {
                    s.pop();
                }
                if(s.empty()) s.push(-1);   
                m[nums2[i]] = s.top();
                
            }
            else
            {
                m[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> t;
        for(int i=0;i<nums1.size();i++)
        {
            t.push_back(m[nums1[i]]);
        }
        return t;
    }
    
};


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n2=nums2.size();
//         unordered_map<int,int> m;
//         stack<int> s;
//         for(int i=0;i<n2;i++)
//         {
//             if(s.empty() || s.top() > nums2[i]) s.push(nums2[i]);
//             else
//             {
//                 while( !s.empty() && s.top()<nums2[i])
//                 {
//                     m[s.top()] = nums2[i];
//                     s.pop();
//                 }
//                 s.push(nums2[i]);
//             }
//         }
//         int n1=nums1.size();
//         vector<int> op(n1,-1);
//         for(int i=0;i<n1;i++)
//         {
//             if(m.find(nums1[i]) != m.end()) op[i]=m[nums1[i]];
//             else op[i]=-1;
//         }
//         return op;
//     }
// };

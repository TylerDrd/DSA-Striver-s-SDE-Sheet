class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        stack<long long> s;
        vector<long long> left(n), right(n);
        for (long long i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (long long i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        long long minans = 0;
        for (long long i = 0; i < n; i++) {
            minans += arr[i] * (i - left[i]) * (right[i] - i) ;
        }

        while (!s.empty()) {
            s.pop();
        }
        left.clear();right.clear();
        for (long long i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (long long i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        long long maxans = 0;
        for (long long i = 0; i < n; i++) {
            maxans += arr[i] * (i - left[i]) * (right[i] - i) ;
        }
        return maxans-minans;
    }
};

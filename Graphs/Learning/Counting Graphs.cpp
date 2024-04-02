#include <bits/stdc++.h>
int countingGraphs(int N)
{
    // Write your code here.
    int t = N*(N-1)/2;
    return pow(2,t);
}

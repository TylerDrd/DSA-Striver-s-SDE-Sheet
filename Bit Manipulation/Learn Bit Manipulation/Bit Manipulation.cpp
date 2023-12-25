vector<int> bitManipulation(int num, int i){
    // Write your code here.
    int mask = (1<<(i-1));
    vector<int> v;
    if(num&mask) v.push_back(1);
    else v.push_back(0);

    v.push_back(num|mask);
    v.push_back(num&(~mask));
    return v;
}

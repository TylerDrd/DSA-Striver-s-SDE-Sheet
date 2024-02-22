class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if( n % groupSize != 0 ) return false;
        map<int,int> m;
        for(auto i : hand) m[i]++;
        while(!m.empty())
        {
            int mini = m.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                cout << mini + i << " ";
                if(m.find(mini+i)==m.end()) return false;
                if(m.find(mini+i)->second==1) m.erase(m.find(mini+i));
                else m[mini+i]--;
            }
        }
        return true;
    }
};

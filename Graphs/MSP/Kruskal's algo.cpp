vector<int> parent(n);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                pq.push({it[1],{i,it[0]}});
                pq.push({it[1],{it[0],i}});
            }
        }
        
        int ans = 0;
        
        while(pq.size()){
            
            int from = pq.top().second.first;
            int to = pq.top().second.second;
            int wt = pq.top().first;
            pq.pop();
            
            if(find(parent,from) != find(parent,to)){
                ans += wt;
                join(parent,from,to);
            }
            
        }
        
        return ans;

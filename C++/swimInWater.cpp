class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0],{0,0}});

        vector<vector<int>> dist(n, vector<int> (n,1e9));
        dist[0][0]=grid[0][0];
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            int d = node.first, x=node.second.first, y = node.second.second;
            if(d>dist[x][y])continue;

            for(auto &el:dir){
                int nx=x+el[0], ny= y+el[1];

                if(nx<n && nx>=0 && ny<n && ny>=0 && dist[nx][ny]> max(grid[nx][ny], d)){
                    dist[nx][ny]= max(grid[nx][ny], d);
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }

        }

        return dist[n-1][n-1];
    }
};

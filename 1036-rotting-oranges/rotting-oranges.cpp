class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // we will be using the bfs algorithm
        // in bfs we will be requiring the queue

        // store the coordinates of the rotten oranges
        queue<pair<int,int>>q;

        int timer = 0;
        int total = 0;
        int rotten = 0;


        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1 || grid[i][j] == 2){
                    total++;
                }
            }
        }

        if(total == 0) return 0;
        
        // now apply bfs
        while(!q.empty()){
            int size = q.size();
            rotten += size;
            
            if(rotten == total){
                return timer;
            }
            

            timer++;
            // reason of doing this cuz we are moniter in every minute
            for(int i=0;i<size;i++){
                auto pair = q.front();
                q.pop();
                int row = pair.first;
                int col = pair.second;

                // now for the 4-directionally adjacent

                // top
                if(row > 0 && grid[row-1][col] == 1){
                    grid[row-1][col] = 2;
                    q.push({row-1,col});
                }
                // right
                if(col < grid[0].size()-1 && grid[row][col+1] == 1){
                    grid[row][col+1] = 2;
                    q.push({row,col+1});
                }
                // bottom
                if(row < grid.size()-1 && grid[row+1][col] == 1){
                    grid[row+1][col] = 2;
                    q.push({row+1,col});
                }
                // left
                if(col > 0 && grid[row][col-1] == 1){
                    grid[row][col-1] = 2;
                    q.push({row,col-1});
                }
            }
        }
        return -1;

    }
};
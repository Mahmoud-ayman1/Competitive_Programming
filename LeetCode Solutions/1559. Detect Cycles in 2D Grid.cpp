const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
class Solution {
public:
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<short>>vis(n,vector<short>(m));
        for(int i=0;i<n;i++)
        {
            for(int o=0;o<m;o++)
            {
                if(!vis[i][o])
                {
                    queue<array<int,4>>q;
                    q.push({i,o,-1,-1});
                    while(q.size())
                    {
                        auto[a,b,x,y]=q.front();
                        q.pop();
                        if(vis[a][b]) return 1;
                        vis[a][b]=1;
                        for(int p=0;p<4;p++)
                        {
                            int xx=a+dx[p],yy=b+dy[p];
                            if(xx>=0&&xx<n&&yy>=0&&yy<m&&(xx!=x||yy!=y)&&grid[xx][yy]==grid[a][b])
                            {
                                q.push({xx,yy,a,b});
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};

from collections import deque 

class Solution:
        
    
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not len(grid) or not len(grid[0]):
            return 0
        
        m = len(grid)
        n = len(grid[0])
        
        nodes = deque(self.get_rotten_oranges(grid))
        time = 0
        
        while len(nodes):
            curr_level_len = len(nodes)
            
            
            for i in range(curr_level_len):
                curr = nodes.popleft()
                
                fresh_neighbours = filter(lambda c : 0 <= c[1] < n and 0 <= c[0] < m and grid[c[0]][c[1]] == 1,
                                          map(lambda d : (curr[0] + d[0], curr[1] + d[1]), [(-1, 0), (1, 0), (0, -1), (0, 1)]))
                
                
                for y, x in fresh_neighbours:
                    grid[y][x] = 2
                    nodes.append((y, x))
            
            if len(nodes):
                time += 1
        
        
        return -1 if self.contains_fresh_orange(grid) else time
    
    def get_rotten_oranges(self, grid):
        m = len(grid)
        n = len(grid[0])
        
        res = []
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    res.append((i, j))
                
        return res
                

    def contains_fresh_orange(self, grid):
        m = len(grid)
        n = len(grid[0])
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return True
        
        return False;
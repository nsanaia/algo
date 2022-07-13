import java.util.*;

class Solution {
    
    private static final int[] MOVE_DELTAS = new int[] {-1, 0, 1};
    
    public boolean canCross(int[] stones) {
        Set<Long> stonesSet = new HashSet<>();        
        for (int s : stones) stonesSet.add((long)s);
        
        Set<String> visitedStones = new HashSet<>();
        
        Queue<StoneData> q = new ArrayDeque<>();
        q.offer(new StoneData(0, 0));
        visitedStones.add(0 + "#" + 0);
        
        while (!q.isEmpty()) {
            StoneData curr =  q.poll();
            
            if (curr.pos == stones[stones.length - 1]) return true;
            
            for (int d : MOVE_DELTAS) {
                if (curr.pos == 0 && d < 0) continue;
                
                long nextK =  curr.k + d;
                long nextPos = curr.pos + nextK;
                
                if (stonesSet.contains(nextPos) && !visitedStones.contains(nextPos + "#" + nextK))  {
                    q.offer(new StoneData(nextPos, nextK));
                    visitedStones.add(nextPos + "#" + nextK);
                }
            }
        }
        
        return false;
    }
    
    
    class StoneData {
        
        long pos;
        
        long k;
        
        public StoneData(long pos, long k) {
            this.pos = pos;
            this.k = k;
        }
    }
}
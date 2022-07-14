import java.util.*;
import java.lang.*;


class Solution {
    public static final Map<Dir, Integer[]> NEIGHBOUR_DELTAS = new HashMap<Dir, Integer[]>() {{
        put(Dir.UP, new Integer[]{1, 0});
        put(Dir.DOWN, new Integer[]{-1, 0});
        put(Dir.LEFT, new Integer[]{0, -1});
        put(Dir.RIGHT, new Integer[]{0, 1});
    }};

    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int N = maze.length;
        int M = maze[0].length;

        int[][] dists = new int[N][M];
        for (int[] d : dists) Arrays.fill(d, Integer.MAX_VALUE);

        PriorityQueue<NodeInfo> nodes = new PriorityQueue<>((a, b) -> a.dist - b.dist);
        nodes.offer(new NodeInfo(start[0], start[1], 0, null));
        dists[start[0]][start[1]] = 0;

        while (!nodes.isEmpty()) {
            NodeInfo curr = nodes.poll();

            if (curr.r == destination[0] && curr.c == destination[1]) return curr.dist;

            for (NodeInfo n : getDirectNeighbours(curr, maze)) {
                if (n.dist < dists[n.r][n.c]) {
                    dists[n.r][n.c] = n.dist;
                    nodes.offer(n);
                }
            }
        }


        return -1;
    }

    private List<NodeInfo> getDirectNeighbours(NodeInfo curr, int[][] maze) {
        List<NodeInfo> res = new ArrayList<>();

        for (Map.Entry<Dir, Integer[]> e : NEIGHBOUR_DELTAS.entrySet()) {
            if (curr.comeFrom == e.getKey()) continue;

            int deltaR = e.getValue()[0];
            int deltaC = e.getValue()[1];

            int r = curr.r;
            int c = curr.c;

            while (isInBounds(r + deltaR, c + deltaC, maze) && maze[r + deltaR][c + deltaC] != 1) {
                r += deltaR;
                c += deltaC;
            }

            int weight = Math.abs(r != curr.r ? r - curr.r : c - curr.c);

            res.add(new NodeInfo(r,
                    c,
                    Integer.MAX_VALUE - weight < curr.dist ? Integer.MAX_VALUE : curr.dist + weight,
                    Dir.getOpposite(e.getKey())));
        }

        return res;
    }

    private boolean isInBounds(int r, int c, int[][] maze) {
        int N = maze.length;
        int M = maze[0].length;

        return c >= 0 && c < M && r >= 0 && r < N;
    }


    class NodeInfo {
        int r;
        int c;

        int dist;

        Dir comeFrom;

        public NodeInfo(int r, int c, int dist, Dir comeFrom) {
            this.r = r;
            this.c = c;
            this.dist = dist;
            this.comeFrom = comeFrom;
        }
    }

    enum Dir {
        LEFT,
        RIGHT,
        UP,
        DOWN;

        public static Dir getOpposite(Dir dir) {
            if (dir == Dir.LEFT) return Dir.RIGHT;
            if (dir == Dir.RIGHT) return Dir.LEFT;
            if (dir == Dir.UP) return Dir.DOWN;
            if (dir == Dir.DOWN) return Dir.UP;
            return null;
        }
    }
}
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    static int[] area;
    static int[][] chk;
    static int[] dy = {0,0,1,-1};
    static int[] dx = {1, -1, 0, 0};
    static int N,M;
    int[][] land;

    int[] col_sum;

    public int solution(int[][] land) {
        this.land = land;
        int answer = 0;
        N = land.length;
        M = land[0].length;
        area = new int[(N*M)/2]; //최대 생길 수 있는 구역의 수
        chk = new int[N][M]; // 땅이 1인 지역의 마을 번호
        Arrays.stream(chk).forEach(e -> Arrays.fill(e, -1));
        col_sum = new int[M];
        int count = 0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(chk[i][j] == -1 && land[i][j] == 1){
                    bfs(i, j, count++);
                }
            }
        }


//        boolean[] c = new boolean[area.length];
//        for(int i=0; i<M; i++){
//            int tmp = 0;
//            Arrays.fill(c, false);
//            for(int j=0; j<N; j++){ //수직으로 꽃아봄
//                if(land[j][i] == 1 && !c[chk[j][i]]){
//                    c[chk[j][i]] = true;
//                    tmp += area[chk[j][i]]; //해당 지역의 석유 덩어리 크기
//                }
//            }
//            answer = Math.max(tmp, answer);
//        }

        for(int i=0; i<col_sum.length; i++){
            answer = Math.max(answer, col_sum[i]);
        }


        return answer;
    }

    private void bfs(int y, int x, int count) {
        chk[y][x] = count; // (y,x)의 시추 영역 번호 새기기
        area[count]++;
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(y, x));
        int min_x = x;
        int max_x = x;
        while (!q.isEmpty()) {
            Node n = q.poll();
            for(int i=0; i<4; i++){
                int ny = n.y + dy[i];
                int nx = n.x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(land[ny][nx] == 1 && chk[ny][nx] == -1){
                    q.add(new Node(ny,nx));
                    chk[ny][nx] = count;
                    area[count]++;
                    min_x = Math.min(min_x, nx);
                    max_x = Math.max(max_x, nx);
                }
            }
        }

        for(int i=min_x; i<=max_x; i++){
            col_sum[i] += area[count];
        }
    }

    static class Node{
        int y;
        int x;

        public Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }


}

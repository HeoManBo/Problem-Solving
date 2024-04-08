public class Solution {

    private int N_int, M_int;
    private static final int[] dy = {0,0,1,-1};
    private static final int[] dx = {1, -1, 0, 0};

    private boolean[][] blueCheck = new boolean[11][11];
    private boolean[][] redCheck = new boolean[11][11];

    private int ans = Integer.MAX_VALUE;
    private int[][] maze = null;

    private static final int RED_TARGET = 3;
    private static final int BLUE_TARGET = 4;

    public int solution(int[][] maze) {
        int answer = 0;
        N_int = maze.length;
        M_int = maze[0].length;
        this.maze = maze;
        Surae red = null,blue = null;
        //수레 위치 찾기
        for(int i = 0; i< N_int; i++){
            for(int j = 0; j< M_int; j++){
                if(maze[i][j] == 1){
                    red = new Surae(i, j, RED_TARGET); //도착 좌표
                }
                if(maze[i][j] == 2){
                    blue = new Surae(i, j,BLUE_TARGET);
                }
            }
        }

        redCheck[red.y][red.x] = true;
        blueCheck[blue.y][blue.x] = true;

        // red먼저 선시작
        int r = move(red, blue, 0, BLUE_TARGET);

        // 블루 돌기
        int b = move(blue, red, 0, RED_TARGET);
        
        int ans = Math.min(r, b);
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }


    private int move(Surae now, Surae next, int count, int color){

        if(now.target == color){ //턴 갱신
            count++; //턴 갱신
        }

        if(checkGoalIn(now) && checkGoalIn(next)) { //두 곳다 골인한 경우
            return count;
        }

        int result = Integer.MAX_VALUE;
        //이번에 움직여야 할 것
        if(checkGoalIn(now)){ //만약 현재것이 도착했으면 다음것만 움직임
            result = move(next, now, count, color);
        }else{ //도착 안했으면 움직이기
            for(int i=0; i<4; i++){
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N_int || nx >= M_int || maze[ny][nx] == 5) continue; //맵 밖, 벽 이동
                if(!(ny == next.y && nx == next.x)){ //같은 곳 이동 불가
                    if(now.target == BLUE_TARGET){ //현재 블루가 움직인다면
                        if(!blueCheck[ny][nx]){ //방문 처리
                            blueCheck[ny][nx] = true;
                            result = Math.min(result, move(next, new Surae(ny, nx, now.target), count, color));
                            blueCheck[ny][nx] = false;
                        }
                    }else if(now.target == RED_TARGET){
                        if(!redCheck[ny][nx]){ //방문 처리
                            redCheck[ny][nx] = true;
                            result = Math.min(result, move(next, new Surae(ny, nx, now.target), count, color));
                            redCheck[ny][nx] = false;
                        }
                    }
                }
            }
        }

        return result;
    }

    private boolean checkGoalIn(Surae now) { //각 색갈의 공이 골인한 경우
        if(maze[now.y][now.x] == now.target){
            return true;
        }
        return false;
    }

    static class Surae {

        int y;
        int x;
        int target; //목표 색깔

        public Surae(int y, int x, int target) {
            this.y = y;
            this.x = x;
            this.target = target;
        }
    }


}

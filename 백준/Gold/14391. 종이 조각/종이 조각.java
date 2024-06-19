import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static final boolean VERTICAL = false; // 세로
    static final boolean HORIZON = true; //가로

    static int N, M;
    static int[][] paper;
    static int ans = Integer.MIN_VALUE;
    static boolean[][] chk; // true : 가로로 조립, false : 세로로 조립

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        paper = new int[N][M];
        chk = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                paper[i][j] = str.charAt(j) - '0';
            }
        }

        go(0, 0);

        System.out.println(ans);
        br.close();
    }

    private static void go(int y, int x) {
        //모든 배정이 끝났으면
        if(y == N) {
            int sum = 0;
            //가로에 대해 조립
            for (int i = 0; i < N; i++) {
                int tmp = 0;
                for (int j = 0; j < M; j++) {
                    if (chk[i][j] == HORIZON) { //해당 좌표가 수평으로 이어진 경ㅇ
                        tmp = tmp * 10 + paper[i][j];
                    } else { //수직으로 이어진 경우 여태까지 값 저장
                        sum += tmp;
                        tmp = 0;
                    }
                }
                sum += tmp;
            }

            //세로에 대해 조립
            for (int i = 0; i < M; i++) {
                int tmp = 0;
                for (int j = 0; j < N; j++) {
                    if(chk[j][i] == VERTICAL) {
                        tmp = tmp * 10 + paper[j][i];
                    }else{
                        sum += tmp;
                        tmp =0;
                    }
                }
                sum += tmp;
            }

            ans = Math.max(sum, ans);
            return;
        }


        chk[y][x] = HORIZON; // 가로
        if(x + 1 == M) {
            go(y + 1, 0);
        }else{
            go(y, x + 1);
        }

        chk[y][x] = VERTICAL; //세로
        if(x + 1 == M){
            go(y + 1, 0);
        }else{
            go(y, x + 1);
        }


    }


}

import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static List<int[]> home, chicken;
    static boolean[] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        home = new ArrayList<>();
        chicken = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int num = Integer.parseInt(st.nextToken());
                if (num == 1) {
                    home.add(new int[]{i, j});
                }
                if (num == 2) {
                    chicken.add(new int[]{i, j});
                }
            }
        }
        chk = new boolean[chicken.size()];
        System.out.println(solve(0, 0));
    }

    private static int solve(int idx, int cnt) {
        if (cnt == M) { // M개의 치킨집을 다 골랐으면
            return calculcate();
        }

        int result = Integer.MAX_VALUE;
        for (int i = idx; i < chicken.size(); i++) {
            if (!chk[i]) {
                chk[i] = true;
                result = Math.min(result, solve(i, cnt + 1));
                chk[i] = false;
            }
        }

        return result;
    }

    private static int calculcate() {
        int result = 0;

        //각 집에서 가장 가까운 치킨집의 거리의 총 합을 구한다
        for (int[] house : home) {
            int nearnest = Integer.MAX_VALUE;
            for (int i = 0; i < chicken.size(); i++) {
                if (chk[i]) { //선택된 치킨집이ㅕㅁㄴ
                    nearnest = Math.min(dist(house, chicken.get(i)), nearnest);
                }
            }
            result += nearnest;
        }

        return result;
    }

    private static int dist(int[] house, int[] chicken) {
        return Math.abs(house[0] - chicken[0]) + Math.abs(house[1] - chicken[1]);
    }


}
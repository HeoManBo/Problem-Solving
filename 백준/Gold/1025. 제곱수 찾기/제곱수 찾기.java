

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 제곱수 찾기 : 구현
public class Main {

    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        String[] arr = new String[N];
        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine();
        }

        int ans = Integer.MIN_VALUE;
        //한글자가 완전 제곱수인것
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int val = arr[i].charAt(j) - '0';
                if (sqrt(val)) {
                    ans = Math.max(ans, val);
                }
            }
        }

        // 범위
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //등차 수열
                for (int dy = -N+1; dy < N; dy++) {
                    for (int dx = -M+1; dx < M; dx++) {
                        if(dy == 0 && dx == 0) continue;
                        int ny = i;
                        int nx = j;
                        StringBuilder sb = new StringBuilder();
                        while (ny >= 0 && nx >= 0 && ny < N && nx < M) {
                            sb.append(arr[ny].charAt(nx));
                            ny += dy;
                            nx += dx;
                            int val = Integer.parseInt(sb.toString());
                            if (sqrt(val)) {
                                ans = Math.max(val, ans);
                            }
                        }
                    }
                }
            }
        }

        ans = ans == Integer.MIN_VALUE ? -1 : ans;
        System.out.println(ans);
    }

    private static boolean sqrt(int val){
        int sqrt = (int) Math.sqrt(val);
        return ((sqrt * sqrt) == val);
    }

}

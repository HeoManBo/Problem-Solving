import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.EnumSet;
import java.util.StringTokenizer;

public class Main {

    static int N, B, W;
    static String s;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        s = br.readLine();
        int l = 0, r = 0;
        int blackCnt = 0, whiteCnt = 0;
        int ans = 0;
        while (l <= r && r < s.length()) {
            // 까만 조약돌을 B개 초과로 주운 경우
            if (blackCnt > B) {
                // l의 범위를 증가시키며 B를 감소시킨다.
                char cc = s.charAt(l);
                if(cc == 'B'){
                    blackCnt--;
                }else{
                    whiteCnt--;
                }
                l++;
            }else{
                char c = s.charAt(r);
                if(c == 'B'){
                    blackCnt++;
                }else {
                    whiteCnt++;
                }
                r++;
            }

            if (whiteCnt >= W && blackCnt <= B) {
                ans = Math.max(ans, r - l);
            }
        }

        if (whiteCnt >= W && blackCnt <= B) {
            ans = Math.max(ans, r - l);
        }

        System.out.println(ans);
        br.close();
    }



}

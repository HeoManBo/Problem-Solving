import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int l = 0, r = 0;
        int odd = 0, even = 0;
        int ans = 0;

        while (l <= r && r < N) {
            if (odd <= K) { // 최대 K번 편집 가능 
                if (arr[r] % 2 == 1) {
                    odd++;
                }else{
                    even++;
                }
                r++;
                ans = Math.max(ans, even);
            }else{ // 최대 K개를 편집한 경우
                if (arr[l] % 2 == 1) {
                    odd--;
                }else{
                    even--;
                }
                l++;
            }
        }

        System.out.println(ans);
    }


}
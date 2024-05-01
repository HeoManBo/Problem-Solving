import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        int[] sum = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int ans = -1;
        for (int i = 0; i < N; i++) {
            sum[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && sum[i] < sum[j] + arr[i]) {
                    sum[i] = sum[j] + arr[i];
                }
            }
            ans = Math.max(sum[i], ans);
        }


        System.out.println(ans);
    }


}
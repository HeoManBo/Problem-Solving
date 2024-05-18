import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            if (A < B && B < C) {
                print(t, 0);
                continue;
            }

            int ans = 0;

            while (C <= B) {
                B--;
                ans++;
            }

            while (B <= A) {
                A--;
                ans++;
            }

            if(A < 1 || B <= 0){
                print(t, -1);
                continue;
            }

            print(t, ans);
        }
    }

    private static void print(int iter, int ans) {
        System.out.printf("#%d %d\n", iter, ans);
    }


}

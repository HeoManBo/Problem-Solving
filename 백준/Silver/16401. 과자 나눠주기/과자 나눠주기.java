import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {

    static int M, N;
    static int[] snack;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        snack = new int[N];
        st = new StringTokenizer(br.readLine());
        int maxLength = -1;
        for (int i = 0; i < N; i++) {
            snack[i] = Integer.parseInt(st.nextToken());
            maxLength = Math.max(maxLength, snack[i]); // 스낵의 최대 길이
        }

        int l = 1, r = maxLength;
        int ans = 0;
        while (l <= r) {
            int cutSize = (l + r) / 2; //나눠줄 사이즈
            if (valid(cutSize)) { // M명이상에게 나눠 줄 수 있으면
                ans = cutSize;
                l = cutSize + 1; //나눠주는 과자의 크기를 늘린다
            }else{
                r = cutSize - 1;
            }
        }

        System.out.println(ans);
        br.close();
    }

    // 과자 하나를 cutSize로 잘라서 나눠줄 때 최대 몇 명에게 잘라줄 수 있는지 확인한다.
    private static boolean valid(int cutSize) {
        int count = 0;
        for (int i = 0; i < snack.length; i++) {
            if(snack[i] < cutSize) continue;
            count += snack[i] / cutSize; //해당 과자로 몇 개의 cutSize개의 과자를 만들 수 있는지
        }

        return count >= M; // M명 이상에게 나눠줄 수 있는가
    }
}

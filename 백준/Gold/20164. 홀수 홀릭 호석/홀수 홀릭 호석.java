

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] ans = go(s,0,0);

        System.out.println(ans[1] + " " + ans[0]);
    }

    private static int[] go(String s, int idx, int odd) {
        // 수가 한자리
        if(s.length() == 1){
            if (((s.charAt(0) - '0') % 2) == 1){
                odd++;
            }
            return new int[]{odd, odd}; //홀수의 수 반횐
        }

        int[] ret = new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE};
        int o = 0;
        for (int i = 0; i < s.length(); i++) {
            if (((s.charAt(i) - '0') % 2) == 1) { //현재 수의 홀수 개수
                o++;
            }
        }

        //수가 두 자리
        if(s.length() == 2){
            int a = s.charAt(0) - '0';
            int b = s.charAt(1) - '0';
            int sum = a + b;
            int[] tmp = go(String.valueOf(sum), idx, odd + o);
            ret[0] = Math.max(ret[0], tmp[0]);
            ret[1] = Math.min(ret[1], tmp[1]);
        }

        //수가 세자리면 임의의 위치에서 3자리를 끊음
        for (int i = 0; i < s.length()-2; i++) {
            for (int j = i + 1; j < s.length()-1; j++) {
                for (int k = j + 1; k < s.length(); k++) {
                    String sub1 = s.substring(i, j);
                    String sub2 = s.substring(j, k);
                    String sub3 = s.substring(k);
                    int sum = Integer.parseInt(sub1) + Integer.parseInt(sub2) + Integer.parseInt(sub3);
                    int[] tmp = go(String.valueOf(sum), idx, odd + o);
                    ret[0] = Math.max(ret[0], tmp[0]);
                    ret[1] = Math.min(ret[1], tmp[1]);
                }
            }
        }

        return ret;
    }
}

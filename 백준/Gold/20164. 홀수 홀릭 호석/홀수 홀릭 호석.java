

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] ans = go(s, 0);

        System.out.println(ans[1] + " " + ans[0]);
    }

    private static int[] go(String s, int odd) {
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
            return go(String.valueOf(sum), odd + o);
        }

        //수가 세자리면 임의의 위치에서 3자리를 끊음
        for (int i = 1; i < s.length()-1; i++) {
            for (int j = i + 1; j < s.length(); j++) {
                    String sub1 = s.substring(0, i);
                    String sub2 = s.substring(i, j);
                    String sub3 = s.substring(j);
                    int sum = Integer.parseInt(sub1) + Integer.parseInt(sub2) + Integer.parseInt(sub3);
                    int[] tmp = go(String.valueOf(sum), odd + o);
                    ret[0] = Math.max(ret[0], tmp[0]);
                    ret[1] = Math.min(ret[1], tmp[1]);
                }
            }

        return ret;
    }
}

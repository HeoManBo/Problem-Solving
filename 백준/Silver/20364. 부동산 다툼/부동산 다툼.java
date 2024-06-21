import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N, Q;
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        boolean[] chk = new boolean[(int) Math.pow(2, 20)];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            int num = Integer.parseInt(br.readLine());

            // num == 1이 될때까지 거슬러가면서 조상이 이미 땅이 선점된적이 있는지 확인한다.
            int chkNumber = isCan(num, chk);
            if (chkNumber == 1) {
                chk[num] = true;
                sb.append(0).append('\n');
            }else{
                sb.append(chkNumber).append('\n');
            }
        }

        System.out.println(sb);
        br.close();
    }

    private static int isCan(int num, boolean[] chk) {
        int ret = 1;
        while (num > 1) {
            if(chk[num]){
                ret = num;
            }
            if (num % 2 == 1) {
                num = (num - 1) / 2;
            }else{
                num = (num / 2);
            }
        }

        return ret;
    }


}
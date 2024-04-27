import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// BOJ 1038 감소하는 수

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        if (N <= 10) {
            System.out.println(N);
            return;
        }

        Queue<Long> q = new LinkedList<>();
        for (int i = 0; i <= 9; i++) {
            q.add((long)i);
        }
        int cnt = 10;

        while (!q.isEmpty()) {
            long now = q.poll();

            //맨 낮은 자리수의 숫자를 추출함
            long num = now % 10;
            for (int init = 0; init < num; init++) {
                long next = now * 10 + init;
                if (cnt == N) {
                    System.out.println(next);
                    return;
                }
                cnt++;
                q.add(next);
            }
        }


        System.out.println(-1);
    }

}
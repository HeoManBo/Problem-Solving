import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        while(T-- > 0){
            int N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            PriorityQueue<Long> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a)); //내림 차순
            for (int i = 0; i < N; i++) {
                pq.add(Long.valueOf(st.nextToken()));
            }

            long ans = 0;
            while (pq.size() != 1) {
                // 두 개 꺼냄
                long t1 = pq.poll();
                long t2 = pq.poll();
                // 두 개 합치는데 필요한 코스트 덧셈
                ans += t1 + t2;
                pq.add(t1 + t2);
            }

            System.out.println(ans);
        }

    }

}
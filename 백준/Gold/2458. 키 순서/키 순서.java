import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<List<Integer>> greater = new ArrayList<>(); //자기보다 키큰 놈들
    static List<List<Integer>> smaller = new ArrayList<>(); //자기보다 작은 놈들

    static int cnt = 0;



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for(int i=0; i<= N; i++){
            smaller.add(new ArrayList<>());
            greater.add(new ArrayList<>());
        }

        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            greater.get(u).add(v);
            smaller.get(v).add(u);
        }

        int ans = 0;
        boolean[] chk = new boolean[N + 1];
        for(int i=1; i<=N; i++){

            // 해당 노드에서 몇 개의 정점이 더 큰지
            Count out = new Count();
            Arrays.fill(chk, false);
            dfs(greater, i, chk, out);

            // 해당 노드에서 몇 개의 정점이 더 작은지
            Count in = new Count();
            Arrays.fill(chk, false);
            dfs(smaller, i, chk, in);

            // 큰 개수와 작은 개수의 합이 N-1이면 순위를 정할 수 있음
            if((out.count + in.count) == N-1) ans++;
        }
        
        System.out.println(ans);
    }

    static class Count {
        int count;

        public int getCount() {
            return count;
        }

        public Count() {
            this.count = 0;
        }

        public void addCount(){
            count++;
        }
    }

    private static void dfs(List<List<Integer>> greater, int now, boolean[] chk, Count count) {
        chk[now] = true;

        for (int next : greater.get(now)) {
            if(!chk[next]){
                count.addCount();
                dfs(greater, next, chk, count);
            }
        }
    }

}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;


public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        List<List<Integer>> bridge = new ArrayList<>();
        Boolean[] chk = new Boolean[N+1];
        Arrays.fill(chk, false);

        for(int i=0; i<=N; i++){
            bridge.add(new ArrayList<>());
        }
        StringTokenizer st;
        for(int i=0; i<N-2; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            bridge.get(u).add(v);
            bridge.get(v).add(u);
        }

        for(int i=1; i<=N; i++){
            if(!chk[i]){
                bfs(bridge, chk, i);
                break;
            }
        }
        int u  = 0, v = 0;
        for(int i=1; i<=N; i++){
            if(chk[i]){
                u = i;
                break;
            }
        }
        for(int i=1; i<=N; i++){
            if(!chk[i]){
                v = i;
                break;
            }
        }
        System.out.println(u + " " + v);
    }

    private static void bfs(List<List<Integer>> bridge, Boolean[] chk, int now) {
        chk[now] = true;
        for(int i=0; i<bridge.get(now).size(); i++){
            int next = bridge.get(now).get(i);
            if(!chk[next]){
                bfs(bridge, chk, next);
            }
        }
    }

}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, W;
    static List<List<int[]>> graph;



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int TC = Integer.parseInt(st.nextToken());
        while (TC-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            graph = new ArrayList<>();
            for (int i = 0; i <= N; i++) {
                graph.add(new ArrayList<>());
            }

            for (int i = 0; i < M; i++) {
                int a,b,c;
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                c = Integer.parseInt(st.nextToken());
                graph.get(a).add(new int[]{b, c});
                graph.get(b).add(new int[]{a, c});
            }

            for (int i = 0; i < W; i++) {
                int a,b,c;
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                c = Integer.parseInt(st.nextToken());
                graph.get(a).add(new int[]{b, -c});
            }

            bellmanfod();
        }
    }

    private static void bellmanfod() {
        int[] dist = new int[N + 1];
        Arrays.fill(dist, 0x3f3f3f3f);
        for (int iter = 0; iter < N - 1; iter++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 0; j < graph.get(i).size(); j++) {
                    int next = graph.get(i).get(j)[0];
                    int nc = graph.get(i).get(j)[1];
                    if (dist[next] > dist[i] + nc) {
                        dist[next] = dist[i] + nc;
                    }
                }
            }
        }

        // 여기서 또 갱신되면 음수
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < graph.get(i).size(); j++) {
                int next = graph.get(i).get(j)[0];
                int nc = graph.get(i).get(j)[1];
                if (dist[next] > dist[i] + nc) {
                    System.out.println("YES");
                    return;
                }
            }
        }

        System.out.println("NO");
    }


}
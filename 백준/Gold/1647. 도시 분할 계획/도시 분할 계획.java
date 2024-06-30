import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.EnumSet;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static Road[] roads;
    static int[] connect;

    static class Road implements Comparable<Road> {
        int A;
        int B;
        int C;

        public Road(int a, int b, int c) {
            A = a;
            B = b;
            C = c;
        }

        @Override
        public int compareTo(Road o) {
            return this.C - o.C;
        }
    }

    static int find(int u) {
        if (connect[u] == u) {
            return u;
        }

        return connect[u] = find(connect[u]);
    }

    static void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            connect[v] = u;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        roads = new Road[M];
        connect = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            connect[i] = i;
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            roads[i] = new Road(A, B, C);
        }
        Arrays.sort(roads);
        long sum = 0;
        int connected = 0;
        for (int i = 0; i < roads.length; i++) {
            int u = roads[i].A;
            int v = roads[i].B;
            int c = roads[i].C;

            if (find(u) != find(v)) {
                merge(u,v);
                sum += c;
                connected++;
                if (connected == N - 1) {
                    sum -= c;
                    break;
                }
            }

        }


        System.out.println(sum);
        br.close();
    }



}

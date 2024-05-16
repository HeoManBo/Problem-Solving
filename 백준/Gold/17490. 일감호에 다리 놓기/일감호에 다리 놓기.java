
import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static long K;
    static int[] stone, parent;
    static Set<Node> chk = new HashSet<>();

    static List<Node> nodes = new ArrayList<>();

    static class Node implements Comparable<Node> {
        int u;
        int v;
        int cost;

        public Node(int u, int v, int cost) {
            this.u = u;
            this.v = v;
            this.cost = cost;
        }


        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Node node = (Node) o;
            return u == node.u && v == node.v;
        }

        @Override
        public int hashCode() {
            return Objects.hash(u, v);
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        if (M <= 1) {
            System.out.println("YES");
            return;
        }

        st = new StringTokenizer(br.readLine());
        stone = new int[N + 1];
        parent = new int[N + 2];
        for (int i = 1; i <= N; i++) {
            stone[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 1; i < N; i++) {
            nodes.add(new Node(i+1, i, 0));
            nodes.add(new Node(N+1, i, stone[i]));
        }
        nodes.add(new Node(N, 1, 0));
        nodes.add(new Node(N+1, 1, stone[1]));
        nodes.add(new Node(N+1, N, stone[N]));
        for (int i = 1; i <= N + 1; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            if (u < v) {
                int tmp = u;
                u = v;
                v = tmp;
            }
            chk.add(new Node(u,v,0));
        }

        boolean  flag = true;
        int cnt = 0;
        Collections.sort(nodes);

        for (Node n : nodes) {
            int u = n.u;
            int v = n.v;
            int cost = n.cost;
            if (chk.contains(new Node(u,v,0))) { //둘이 공사중인경우
                continue;
            }
            if (find(u) != find(v)) {
                merge(u, v);
                K -= cost;
                cnt++;
            }
        }

        if(K < 0){
            System.out.println("NO");
        } else if (cnt == N) {
            System.out.println("YES");
        } else{
            System.out.println("NO");
        }

    }

    static int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    static void merge(int u, int v) {
         u = find(u);
         v = find(v);

         if(u != v){
             parent[v] = u;
         }
    }

}
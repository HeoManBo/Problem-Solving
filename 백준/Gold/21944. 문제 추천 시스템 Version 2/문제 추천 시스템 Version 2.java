import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {


    // 명령어 1, [G, [i,j]] --> [i,j]는난이도순
    static TreeMap<Integer, TreeSet<Problem>> recommend1 = new TreeMap<>();
    // 알고리즘 분류가 G인 문제들의 난이도 순 정렬, 난이도 같다면 문제 번호 ==> 명령어 2,3
    static TreeSet<Problem> classifyAlgorithm = new TreeSet<>();

    static Map<Integer, Problem> problem = new HashMap<>(); // 문제 번호에 대한 난이도 및 알고리즘 분류


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());


        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int P = Integer.parseInt(st.nextToken()); // 문제 번호
            int L = Integer.parseInt(st.nextToken()); // 난이도
            int G = Integer.parseInt(st.nextToken()); // 알고리즘 분류
            TreeSet<Problem> tree = recommend1.getOrDefault(G, new TreeSet<>());
            tree.add(new Problem(P, L, G));
            recommend1.putIfAbsent(G, tree);
            problem.put(P, new Problem(P, L, G));
            classifyAlgorithm.add(new Problem(P, L, G));
        }

        int query = Integer.parseInt(br.readLine());
        StringJoiner sj = new StringJoiner("\n");
        for (int i = 0; i < query; i++) {
            String[] split = br.readLine().split(" ");
            String command = split[0];
            if(command.equals("recommend")){
                int G = Integer.parseInt(split[1]);
                int x = Integer.parseInt(split[2]);
                TreeSet<Problem> problems = recommend1.get(G);
                if (x == 1) {
                    sj.add(String.valueOf(problems.last().P)); //가장 어려운 문제 중 가장 큰 번호
                } else if (x == -1) {
                    sj.add(String.valueOf(problems.first().P)); //가장 쉬운 문제 중 가장 작은 번호
                }
            } else if (command.equals("recommend2")) {
                int x = Integer.parseInt(split[1]);
                if(x == 1){
                    sj.add(String.valueOf(classifyAlgorithm.last().P));
                } else if (x == -1) {
                    sj.add(String.valueOf(classifyAlgorithm.first().P));
                }
            } else if (command.equals("recommend3")) {
                int x = Integer.parseInt(split[1]);
                int L = Integer.parseInt(split[2]);
                if (x == 1) {
                    Problem p = classifyAlgorithm.ceiling(new Problem(0, L, 0));
                    //주어진 키보다 같거나 큰 키중 가장 작은키를 반환함
                    if (p == null) {
                        sj.add("-1");
                    }else{
                        sj.add(String.valueOf(p.P));
                    }
                } else if (x == -1) {
                    //주어진 키보다 같거나 작은 키 중 가장 큰 키 반환
                    Problem p = classifyAlgorithm.floor(new Problem(0, L, 0));
                    if (p == null) {
                        sj.add("-1");
                    }else{
                        sj.add(String.valueOf(p.P));
                    }
                }
            } else if (command.equals("add")) {
                int P = Integer.parseInt(split[1]);
                int L = Integer.parseInt(split[2]);
                int G = Integer.parseInt(split[3]);
                TreeSet<Problem> problemSet = recommend1.getOrDefault(G, new TreeSet<>());
                Problem p = new Problem(P, L, G);
                problemSet.add(p);
                recommend1.putIfAbsent(G, problemSet);
                classifyAlgorithm.add(p);
                problem.put(p.P, p);
            } else if (command.equals("solved")) {
                int P = Integer.parseInt(split[1]);
                int L = problem.get(P).L;
                int G = problem.get(P).G;
                Problem p = new Problem(P, L, G);
                recommend1.get(G).remove(p);
                classifyAlgorithm.remove(p);
                problem.remove(P);
            }


        }


        System.out.println(sj.toString());
    }


    static class Problem implements Comparable<Problem>{
        int P;
        int L;
        int G;

        public Problem(int p, int l, int g) {
            P = p;
            L = l;
            G = g;
        }


        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Problem problem = (Problem) o;
            return P == problem.P && L == problem.L && G == problem.G;
        }

        @Override
        public int hashCode() {
            return Objects.hash(P, L, G);
        }

        @Override
        public int compareTo(Problem o) {
            if (o.L == this.L) {
                return this.P - o.P;
            }

            return this.L - o.L;
        }
    }


}

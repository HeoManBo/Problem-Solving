
import java.io.*;
import java.util.*;

public class Main {


    static int N;
    static List<List<Integer>> arr;



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        arr = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            arr.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int parent = Integer.parseInt(st.nextToken());
            if (parent != -1) {
                arr.get(parent).add(i); //자식으로 전파
            }
        }


        System.out.println(solve(0));
    }

    private static int solve(int now) {
        if(arr.get(now).size() == 0){ // 부하가 더 이상 없으면 연락 XX
            return 0;
        }

        List<Integer> time = new ArrayList<>();
        for (int i = 0; i < arr.get(now).size(); i++) {
            time.add(solve(arr.get(now).get(i))); // 부하들에게 연락을 다 돌림
        }

        time.sort((a, b) -> b - a); //현재 상사가 가장 밑 자식까지 연락이 가장 오래 걸리는 부하부터 연락을 돌림

        //한 부하에서 가장 밑까지 연락을 돌리는데 필요한 시간 + 해당 부하에게 연락하는데 필요한 시간
        int ret = Integer.MIN_VALUE;
        for (int i = 0; i < time.size(); i++) {
            ret = Math.max(ret, time.get(i) + (i + 1));
        }

        return ret;
    }


}
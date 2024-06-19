import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, K;
    static int[] arr;
    static Set<Integer> s = new HashSet<>();
    static Set<Integer> chk = new HashSet<>();
    static int[] dx = {-1, 1};

    static class Info {
        int start; //시작 우물 위치
        int nowPos; //현재 위치

        public Info(int start, int nowPos) {
            this.start = start;
            this.nowPos = nowPos;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            s.add(arr[i]);
        }

        Queue<Info> q = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            q.add(new Info(arr[i], arr[i]));
        }

        long sum = 0;
        int install = 0;
        while (!q.isEmpty()) {
            Info info = q.poll();

            int start = info.start;
            int nowPos = info.nowPos;
            boolean isEnd = false;
            for (int i = 0; i < 2; i++) {
                int nextPos = nowPos + dx[i]; // 설치하려는 집의 X 좌표
                if(s.contains(nextPos)) { // 집을 설치하려는 곳에 우물이 있는 경우 패스
                    continue;
                }
                if(!chk.contains(nextPos)){
                    chk.add(nextPos);
                    sum += Math.abs(start - nextPos); // 집과 시작 우물까지의 거리
                    q.add(new Info(start, nextPos));
                    install++;
                    if (install == K) { // 집 K개를 다 지었으면 중단
                        isEnd = true;
                        break;
                    }
                }
            }

            if(isEnd){
                break;
            }
        }


        System.out.println(sum);
        br.close();
    }





}
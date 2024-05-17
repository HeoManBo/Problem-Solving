
import java.io.*;
import java.util.*;

public class Main {

    static int N,K;
    static String left, right;

    static class Info {
        int now; // 현재 위치
        int pos; // 0 : 왼쪽, 1 : 오른쪽
        int time; // 현재 시간

        public Info(int now, int pos, int time) {
            this.now = now;
            this.pos = pos;
            this.time = time;
        }

    }

    static boolean[][] chk ;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        left = br.readLine();
        right = br.readLine();
        String[] arr = new String[2];
        arr[0] = left;
        arr[1] = right;
        chk = new boolean[2][left.length()+3];

        int time = 0;
        Queue<Info> q = new LinkedList<>();
        q.add(new Info(0, 0, 0));
        chk[0][0] = true;
        boolean flag = false;
        while(true){
            Queue<Info> next = new LinkedList<>();
            while (!q.isEmpty()) {
                Info now = q.poll();
                if (now.now >= left.length()-1) {
                    flag = true;
                    break;
                }
                if (now.now < time) { // 이동 불가
                    continue;
                }

                // 앞으로 이동
                int front = now.now + 1;
                int dir = now.pos;
                int ntime = now.time + 1;
                if(arr[dir].charAt(front) == '1' && !chk[dir][front]){
                    next.add(new Info(front, dir, ntime));
                    chk[dir][front] = true;
                }

                // 뒤로 이동
                int back = now.now - 1;
                dir = now.pos;
                if (back >= 0 && arr[dir].charAt(back) == '1' && !chk[dir][back]) {
                    next.add(new Info(back, dir, ntime));
                    chk[dir][back] = true;
                }

                // 건너 편으로 이동
                int jump = now.now + K;
                dir = (now.pos + 1) % 2;
                if(jump >= N) {
                    flag = true;
                    break;
                }
                if (arr[dir].charAt(jump) == '1' && !chk[dir][jump]) {
                    next.add(new Info(jump, dir, ntime));
                    chk[dir][jump] = true;
                }
            }

            if(flag) {
                break;
            }
            if (next.isEmpty()) {
                flag = false;
                break;
            }else{
                q = next;
                time++;
            }
        }

        if (flag) {
            System.out.println("1");
        }else{
            System.out.println("0");
        }

    }

}
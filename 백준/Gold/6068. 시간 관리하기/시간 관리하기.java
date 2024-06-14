import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

   static int N;

   static class Job implements Comparable<Job>{
       int requireTime;
       int mustEndTime;

       public Job(int requireTime, int mustEndTime) {
           this.requireTime = requireTime;
           this.mustEndTime = mustEndTime;
       }

       @Override
       public int compareTo(Job o) {
           return this.mustEndTime - o.mustEndTime; //먼저 시작해야하는 작업부터
       }
   }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Job[] jobs = new Job[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int requiredTime = Integer.parseInt(st.nextToken());
            int mustEndTime = Integer.parseInt(st.nextToken());
            jobs[i] = new Job(requiredTime, mustEndTime);
        }
        Arrays.sort(jobs);
        int ans = -1;
        int must_start = jobs[0].mustEndTime - jobs[0].requireTime; //반드시 시작해야하는 시간
        for (int time = must_start; time >= 0; time--) { // 한칸씩 줄여보면서 최대한 늦게 시작하는 시간을 찾는다
            int t = time;
            boolean f = true;
            for (int i = 0; i < jobs.length; i++) {
                t += jobs[i].requireTime; // 해당 작업에 필요한 시간 더함
                if (t > jobs[i].mustEndTime) { // 끝내야 하는 시간보다 늦게 끝내면 time에 시작 불가능
                    f = false;
                    break;
                }
            }
            if(f){
                ans = time;
                break;
            }
        }

        System.out.println(ans);
    }



}
import java.util.*;

class Solution {
    static class Work{
        int start;
        int time;

        public Work(int start, int time) {
            this.start = start;
            this.time = time;
        }
    }

    public int solution(int[][] jobs) {
        List<Work> list = new ArrayList<>();
        for(int[] job : jobs){
            list.add(new Work(job[0], job[1]));
        }
        Collections.sort(list, Comparator.comparingInt(a -> a.start)); //빨리 시작하는 것부터 시작
        Queue<Work> q = new LinkedList<>(list); //time에 도달하지 못한 작업들
        PriorityQueue<Work> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.time)); //작업시간이 짧은 것부터 수행
        int time = 0, exec = 0; //수행 시간
        while(!q.isEmpty() || !pq.isEmpty())
        {
            //time 시간 이전에 요청된 pq에 추가 
            while(!q.isEmpty() && q.peek().start <= time){
                pq.add(q.poll());
            }
            if(pq.isEmpty()){
                time = q.peek().start;
                continue;
            }
            Work work = pq.poll();
            exec += (time + work.time - work.start); //현재 수행하는 작업의 수행 시간 time에 work.start가 중복되어 있으므로 빼줌.
            time += work.time;
        }
        
        return exec/ jobs.length;
    }   
}
import java.util.*;

class Solution {
    private static class Work{
        int progresses;
        int speed;

        public Work(int progresses, int speed) {
            this.progresses = progresses;
            this.speed = speed;
        }
    }

    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Work> q = new LinkedList<>();
        for(int i=0; i< progresses.length; i++){
            q.add(new Work(progresses[i], speeds[i]));
        }
        List<Integer> ans = new ArrayList<>();
        int completeDate = 0;
          while(!q.isEmpty()){
            int add = 1;
            Work cur = q.poll();
            completeDate = (int)Math.ceil((100 - cur.progresses) / (double)cur.speed);
            while(!q.isEmpty()){
                Work next = q.peek();
                if((next.progresses + next.speed * completeDate) >= 100){
                    add++;
                    q.poll();
                }else{
                    break;
                }
            }
            ans.add(add);
        }

        return ans.stream().mapToInt(i -> i).toArray();
    }
}
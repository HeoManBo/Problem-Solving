import java.util.*;


class Solution {
   private static Map<String, Integer> report_chk = new HashMap<>(); // key에 대하여 신고한 사람의 이름들 담아둠
    private static Map<String, List<String>> user_report_list = new HashMap<>(); // key가 신고한 사람들의 이름을 담아둠.

    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        for(String id : id_list){
            user_report_list.put(id, new ArrayList<>());
        }

        for(String re : report){
            String[] sp = re.split(" ");
            String user = sp[0];
            String report_user = sp[1]; //user가 신고한 유저 이름
            List<String> list = user_report_list.get(user);
            if(!list.contains(report_user)) { //반복 신고 1회만 카운트
                list.add(report_user);
                //신고 횟수 카운트 1증가
                report_chk.put(report_user, report_chk.getOrDefault(report_user, 0) + 1);
            }
        }
        
        for(int i=0; i< id_list.length; i++){
            List<String> report_list = user_report_list.get(id_list[i]); //i번 유저가 신고한 아이디 리스트
            //i번 유저가 신고한 유저들을 보면서 K번이상 신고됐는지 확인한다.
            for(String r : report_list){
                if(report_chk.get(r) >= k){
                    answer[i]++;
                }
            }
        }
        
        return answer;
    }
}
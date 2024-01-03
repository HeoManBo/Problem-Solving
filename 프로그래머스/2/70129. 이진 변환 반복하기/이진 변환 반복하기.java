class Solution {
    public static int[] solution(String s) {
        /*int toBinaryCount = 0; //2진수 변환 횟수
        int removeZeroCount = 0; //0제거 개수
        while(s.length() != 1){ //s가 1이 될 까지
            StringBuffer x = new StringBuffer();

            //1. x의 모든 0제거
            for(char c : s.toCharArray()){
                if(c == '0'){ //0인 경우 제거
                    removeZeroCount++;
                }else{ //1인경우 붙이기
                    x.append('1');
                }
            }

            //2. x의 길이를 c라고 하면 x를 c를 2진법으로 변환한 문자열로 바꿈
            int c = x.length();
            s = Integer.toString(c, 2);
            toBinaryCount++;
            }

        return new int[]{toBinaryCount, removeZeroCount};*/

        int[] answer = new int[2];
        while(!s.equals("1")){
            answer[1] += s.length();
            s = s.replace("0", "");
            int tmp = s.length();
            s = Integer.toString(tmp, 2);
            answer[0] += 1;
            answer[1] -= tmp;
        }
        
        return answer;
    }
}
class Solution {
    private static int[][] array;

    public int[] solve(int y,int x, int length){ //시작점,
        if(length == 1){ //종료 조건, 한 변만 체크
            if(array[y][x] == 0){
                return new int[]{1,0};
            }else {
                return new int[]{0,1};
            }
        }
        int[] sub_solve = new int[2];
        boolean zero_flag = true, one_flag = true; //주어진 사각형이 한 가지 숫자로만 구성되어있는지 확인
        for(int i=y; i< y + length; i++){
            for(int j=x; j<x+length; j++){
                if(array[i][j] == 1){
                    zero_flag = false;
                } else if(array[i][j] == 0){
                    one_flag = false;
                }
            }
        }
        if(zero_flag){ //해당 영역이 모두 0으로 채워져 있으면
            return new int[]{1, 0};
        }
        if(one_flag){
            return new int[]{0, 1};
        }
        //그렇지 않은 경우 재귀
        int[] upper_left = solve(y,x, length/2); //반지름 /2;
        int[] upper_right = solve(y,x+length/2, length/2);
        int[] lower_left = solve(y+length/2, x, length/2);
        int[] lower_right = solve(y+length/2, x+length/2, length/2);
        sub_solve[0] = upper_left[0] + upper_right[0] + lower_left[0] + lower_right[0];
        sub_solve[1] = upper_left[1] + upper_right[1] + lower_left[1] + lower_right[1];

        return sub_solve;
    }

    public int[] solution(int[][] arr) {
        array = arr;
        int length = arr.length; //한 변의 길이

        int[] answer = solve(0, 0, length);

        return answer;
    }
}
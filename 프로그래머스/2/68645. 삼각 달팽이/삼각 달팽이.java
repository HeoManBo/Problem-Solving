class Solution {
    public int[] solution(int n) {
        int number = 1;

        int[][] arr = new int[n][n];
        int y = 0,x = 0; //초기 채울 위치

        while(true) {
            //아래 방향
            while (true) {
                arr[y][x] = number++;
                if (y + 1 == n) break; // 맨 밑에
                if (arr[y + 1][x] != 0) break; // 숫자가 채워진 경우
                y += 1;
            }
            if (x + 1 == n || arr[y][x + 1] != 0) break; //오른쪽 끝 or 오른쪽에 이미 채워진 경우 중단
            x += 1;

            //오른쪽 방향
            while (true) {
                arr[y][x] = number++;
                if (x + 1 == n) break; // 맨 밑에
                if (arr[y][x + 1] != 0) break; //숫자가 채워진 경우
                x += 1;
            }
            if (arr[y - 1][x - 1] != 0) break; //왼쪽 대각선이 이미 채워진 경우
            y -= 1;
            x -= 1;

            //위쪽 방향
            while (true) {
                arr[y][x] = number++;
                if (arr[y - 1][x - 1] != 0) break; //왼쪽 대각선이 이미 차있는 경우
                y -= 1;
                x -= 1;
            }
            if (y + 1 == n || arr[y + 1][x] != 0) break;
            y += 1;
        }

        int[] answer = new int[number-1];
        int idx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                answer[idx++] = arr[i][j];
            }
        }

        return answer;
    }
}
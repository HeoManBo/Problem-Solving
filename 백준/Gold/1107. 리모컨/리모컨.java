import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, M;

    static final int INIT = 100;

    static boolean[] brokenButton = new boolean[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(br.readLine());
        Arrays.fill(brokenButton, true);
        if(M != 0){
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) {
                int num = Integer.parseInt(st.nextToken());
                brokenButton[num] = false;
            }
        }
        

        if (N == INIT) {
            System.out.println(0);
            return;
        }

        // +, - 버튼만 눌러서 가기
        int onlyButton = Math.abs(N - INIT);
        int ans = onlyButton;
        // 0~500000번까지 버튼으로 눌러서 가서
        // N번까지 버튼으로 눌러서 가기
        for (int i = 0; i <= 1_000_000; i++) {
            if(canPress(i)){ //해당 번호로 누를 수 있다면 해당 번호를 누르는데 버튼 수 +
                int btnClick = Integer.toString(i).length();
                ans = Math.min(ans, btnClick + Math.abs(N - i));
            }
        }


        System.out.println(ans);
    }

    private static boolean canPress(int number) {
        // 해당 번호까지 눌러서 갈 수 있는지 확인한다.
        String str = Integer.toString(number);
        for (int i = 0; i < str.length(); i++) {
            if(!brokenButton[str.charAt(i) - '0']){
                return false;
            }
        }
        return true;
    }

}

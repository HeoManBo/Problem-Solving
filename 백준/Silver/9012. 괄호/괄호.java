

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer s = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(s.nextToken());
        for (int t = 0; t < T; t++) {
            String str = br.readLine();
            Stack<Character> st = new Stack<>();
            boolean flag = true;
            for (int i = 0; i < str.length(); i++) {
                if(str.charAt(i) == '('){
                    st.push('(');
                }else{
                    if (st.isEmpty()) {
                        flag = false;
                        break;
                    }else{
                        st.pop();
                    }
                }
            }
            if (!flag) {
                System.out.println("NO");
            }else{
                if (st.isEmpty()) {
                    System.out.println("YES");
                }else{
                    System.out.println("NO");
                }
            }

        }
    }

}

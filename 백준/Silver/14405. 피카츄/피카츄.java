import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main{

    static String[] prefixes = {"pi", "ka", "chu"};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int idx = 0;
        while (idx < s.length()) {
            boolean flag  = false;
            for (int i = 0; i < prefixes.length; i++) {
                String prefix = prefixes[i];
                if (idx + prefix.length() <= s.length()) {
                    if (s.startsWith(prefix, idx)) {
                        idx += prefix.length();
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }

}
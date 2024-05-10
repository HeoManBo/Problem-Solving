import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static String S, T;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = br.readLine();
        T = br.readLine();

        solve(new StringBuilder(S), T);
        System.out.println(0);
    }

    private static void solve(StringBuilder sb, String t) {
        if (sb.toString().equals(t)) {
            System.out.println(1);
            System.exit(0);
        }

        if(sb.length() >= t.length()) return;
        StringBuilder temp = new StringBuilder(sb);
        boolean t1 = t.contains(temp.toString());
        boolean t2 = t.contains(temp.reverse().toString());

        if (!t1 && !t2) {
            return;
        }

        // A 추가
        StringBuilder next = new StringBuilder(sb);
        next.append('A');
        solve(next, t);

        // B추가 후 뒤집기
        StringBuilder next2 = new StringBuilder(sb);
        next2.append('B').reverse();
        solve(next2, t);
    }

}
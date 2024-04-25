import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] words = new String[5];
        int max_length = Integer.MIN_VALUE;
        for (int i = 0; i < 5; i++) {
            words[i] = br.readLine();
            max_length = Math.max(words[i].length(), max_length);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < max_length; i++) {
            for (int j = 0; j < 5; j++) {
                if (words[j].length() <= i) {
                    continue;
                }else{
                    sb.append(words[j].charAt(i));
                }
            }
        }


        System.out.println(sb.toString());

    }



}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static String word;
    static int N;

    static int ans = Integer.MAX_VALUE;

    static int[] count = new int[27], select = new int[27];

    static Book[] books;

    static class Book  {
        int price;
        String title;

        public Book(int price, String title) {
            this.price = price;
            this.title = title;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        word = br.readLine();
        for (char c : word.toCharArray()) {
            count[c - 'A']++; //해당 알파벳 갯수
        }
        N = Integer.parseInt(br.readLine());
        books = new Book[N];
        for(int i=0; i<N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int price = Integer.parseInt(st.nextToken());
            String title = st.nextToken();
            books[i] = new Book(price, title);
        }

        go(0, 0);


        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
        br.close();
    }

    static void go(int bookNumber, int price) {
        if (bookNumber == N) {
            if(valid()){
                ans = Math.min(price, ans);
            }
            return;
        }

        //현재 책 선택해서 알파벳 추출
        for (char c : books[bookNumber].title.toCharArray()) {
            select[c - 'A']++;
        }
        go(bookNumber + 1, price + books[bookNumber].price);

        // 현재 책 선택 X
        for (char c : books[bookNumber].title.toCharArray()) {
            select[c - 'A']--;
        }
        go(bookNumber + 1, price);

    }

    //모든 알파벳이 충분한지 확인함
    private static boolean valid() {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                if (count[i] > select[i]) {
                    return false;
                }
            }
        }

        return true;
    }


}
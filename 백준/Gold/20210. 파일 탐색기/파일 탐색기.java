import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {

    static int N;

    static String[] str;
    static int[] idx = new int[60];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        str = new String[N];
        for (int i = 0; i < N; i++) {
            str[i] = br.readLine();
        }

        int q = 0;
        for(char i = 'A'; i<='Z'; i++){
            idx[(i - 'A') * 2] = q;
            q += 2;
        }
        for(char i = 'a'; i<='z'; i++){
            idx[(i - 'a') * 2 + 1] = idx[(i - 'a') * 2] + 1;
        }

        Arrays.sort(str, (a,b) -> {
            int minLength = Math.min(a.length(), b.length());

            for(int i=0; i<minLength; i++) {
                char a1 = a.charAt(i);
                char b1 = b.charAt(i);
                //이전 풀이 
                //  //둘다 숫자인 경우
                // if(Character.isDigit(a1) && Character.isDigit(b1)){
                //     StringBuilder sb1 = new StringBuilder();
                //     StringBuilder sb2 = new StringBuilder();
                //     sb1.append(a1 - '0');
                //     sb2.append(b1 - '0');
                //     //숫자가 아닐때까지 계속 이어 붙임
                //     int aIdx = i+1;
                //     int bIdx = i+1;
                //     while(aIdx < a.length() && Character.isDigit(a.charAt(aIdx))){
                //         sb1.append(a.charAt(aIdx++) - '0');
                //     }
                //     while(bIdx < b.length() && Character.isDigit(b.charAt(bIdx))){
                //         sb2.append(b.charAt(bIdx++) - '0');
                //     }
                //     BigInteger aNum = new BigInteger(sb1.toString());
                //     BigInteger bNum = new BigInteger(sb2.toString());
                //     //두개의 수가 같은지 확인
                //     if(aNum.equals(bNum)){
                //         int aZero = 0;
                //         int bZero = 0;
                //         aIdx = 0;
                //         bIdx = 0;
                //         while(aIdx < sb1.length() && Character.isDigit(sb1.charAt(aIdx))){
                //             int c = sb1.charAt(aIdx++) -'0';
                //             if(c == 0){ //맨 앞의 0의 개수 세기
                //                 aZero++;
                //             }else{
                //                 break;
                //             }
                //         }
                //         while(bIdx < sb2.length() && Character.isDigit(sb2.charAt(bIdx))){
                //             int d = sb2.charAt(bIdx++) -'0';
                //             if(d == 0){ //맨 앞의 0의 개수 세기
                //                 bZero++;
                //             }else{
                //                 break;
                //             }
                //         }
                //         if(aZero == bZero){ // 두 개의 0이 같은 경우 계속 진행
                //             i = (i+aIdx) - 1;
                //             continue;
                //         }
                //         return aZero - bZero;
                //     }else{
                //         return aNum.compareTo(bNum);
                //     }
                // }

                //둘다 숫자인 경우
                if(Character.isDigit(a1) && Character.isDigit(b1)){
                    //0 개수 세기
                    int aIdx = i;
                    int bIdx = i;
                    int zeroA = 0;
                    int zeroB = 0;
                    while(aIdx < a.length() && Character.isDigit(a.charAt(aIdx))){
                        if(a.charAt(aIdx) == '0') {
                            zeroA++;
                            aIdx++;
                        }else{
                            break;
                        }
                    }
                    while(bIdx < b.length() && Character.isDigit(b.charAt(bIdx))){
                        if(b.charAt(bIdx) == '0') {
                            zeroB++;
                            bIdx++;
                        }else{
                            break;
                        }
                    }
                    StringBuilder sb1 = new StringBuilder();
                    StringBuilder sb2 = new StringBuilder();
                    //실제 숫자 붙이기
                    while (aIdx < a.length() && Character.isDigit(a.charAt(aIdx))) {
                        sb1.append(a.charAt(aIdx++));
                    }
                    while (bIdx < b.length() && Character.isDigit(b.charAt(bIdx))) {
                        sb2.append(b.charAt(bIdx++));
                    }

                    //앞의 0을 제외한 실제 숫자
                    String realNumberA = sb1.toString();
                    String realNumberB = sb2.toString();

                    //실제 숫자 비교
                    if(realNumberA.length() > realNumberB.length()) return 1;
                    if(realNumberA.length() < realNumberB.length()) return -1;

                    // 위의 두 조건문이 같다면 숫자의 길이가 같으므로 앞자리 수부터 비교
                    for (int ii = 0; ii < realNumberA.length(); ii++) {
                        if(realNumberA.charAt(ii) > realNumberB.charAt(ii)) return 1;
                        if(realNumberA.charAt(ii) < realNumberB.charAt(ii)) return -1;
                    }

                    // 이제 0의 개수
                    if (zeroA != zeroB) {
                        return zeroA - zeroB;
                    }

                    //0의 개수까지 같다면 다음 idx로
                    i = aIdx - 1;
                }
                //a1만 숫자 인 경우
                else if(Character.isDigit(a1) && Character.isLetter(b1)){
                    return -1;
                }
                else if(Character.isLetter(a1) && Character.isDigit(b1)){ // b1만 숫자인 경우
                    return 1;
                }else{ //둘다 문자인 경우
                    if(a1 == b1){ // 두 문자가 같은 경우
                        continue;
                    }
                    int n1 = 0, n2 = 0;
                    //우선순위 계산
                    if(Character.isUpperCase(a1)){
                        n1 = idx[(a1 - 'A') * 2];
                    }else{
                        n1 = idx[(a1 - 'a') * 2 + 1];
                    }
                    if(Character.isUpperCase(b1)){
                        n2 = idx[(b1 - 'A') * 2];
                    }else{
                        n2 = idx[(b1 - 'a') * 2 + 1];
                    }
                    return n1 - n2;
                }
            }

            // 짧은 문자가 긴 문자의 앞부분과 동일하다면 길이로 비교
            return a.length() - b.length();
        });

        for (String s : str) {
            System.out.println(s);
        }
        br.close();
    }
}

class Solution {
    public String solution(String s, int n) {
        StringBuilder sb = new StringBuilder();

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == ' ') sb.append(' ');
            else{
                char push;
                if(Character.isUpperCase(s.charAt(i))){
                    int off = ((s.charAt(i) - 'A') + n) % 26;
                    push = (char)('A' + off);
                }else{
                    int off = ((s.charAt(i) - 'a') + n) % 26;
                    push = (char)('a' + off);
                }
                sb.append(push);
            }
        }

        return sb.toString();
    }
}
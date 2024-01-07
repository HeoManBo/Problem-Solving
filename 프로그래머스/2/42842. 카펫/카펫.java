class Solution {
    public int[] solution(int brown, int yellow) {
       for(int width = 3; width<=5000; width++){
           for(int height = 3; height <= width; height++){
               int bound = (width + height - 2) * 2;
               int inner = (width * height) - bound;
               if(bound == brown && inner == yellow) {
                   return new int[]{width, height};
               }
           }
       }

       return new int[]{0,0};
    }
}
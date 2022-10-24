package algorithm;

public class programmers_배열_뒤집기 {
	public int[] solution(int[] num_list) {
        int[] answer = new int[num_list.length];
        for(int i = 0; i< num_list.length; i++){
            answer[i] = num_list[num_list.length-i-1];
        }
        return answer;
//         int[] answer = new int[num_list.length];
//         StringBuffer sb = new StringBuffer();
        
//         for (int i=0; i < num_list.length; i++) {
//             String temp = Integer.toString(num_list[i]);
//             sb.append(temp);
//         }
        
//         sb.reverse();
        
//         String sTemp = sb.toString();
//         String[] arrTemp = sTemp.split("");
        
//         for (int j=0; j < arrTemp.length; j++) {            
//              answer[j] = Integer.parseInt(arrTemp[j]);
//          }
        
        //return answer;
    }
}

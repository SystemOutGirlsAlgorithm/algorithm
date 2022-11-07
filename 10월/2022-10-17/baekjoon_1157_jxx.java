import java.io.*;

public class baekjoon_1157_jxx {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] arr = new int[26]; // 영문자의 개수 26개
        String input = br.readLine().toUpperCase(); // 입력받은 영단어 대문자로 변환

        for (int i = 0; i < input.length(); i++) { // 반복문을 돌면서 해당 문자가 어떤 문자냐에 따라 해당 배열 원소를 증가시켜줌
            arr[input.charAt(i) - 65]++; // input의 i번째 글자를 char로 변환하고 65를 빼서, 해당 배열의 알파벳과 대응하는 인덱스를 찾아 원소를 증가시킴
        }

        int max = -1;
        char result = '?';
        for (int i = 0; i < 26; i++) { // 반복문을 돌면서 배열 arr의 원소 중 최댓값 찾기
            if (arr[i] > max) { 
                max = arr[i]; // 가장 많이 사용된 알파벳의 사용 횟수 max에 저장
                result = (char)(i + 65); // 해당 알파벳 result에 저장
            }
            else if (arr[i] == max) {
                result = '?'; // 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력
            }
        }
        System.out.print(result);
    }
}
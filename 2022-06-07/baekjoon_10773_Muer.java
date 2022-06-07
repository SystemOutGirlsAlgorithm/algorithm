import java.util.ArrayList;
import java.util.Scanner;

public class baekjoon_10773_Muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num = scanner.nextInt();
        ArrayList<Integer> arrayList = new ArrayList<>();

        for(int i = 0; i < num; i++){
            int res = scanner.nextInt();

            if(res != 0){
                //System.out.println(arrayList.size());
                arrayList.add(res);
            }else{
                arrayList.remove(arrayList.size()-1);
            }
        }

        int result = 0;
        for (Integer integer : arrayList) {
            result += integer;
        }

        System.out.println(result);

    }
}

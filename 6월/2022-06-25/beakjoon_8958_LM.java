package main;

import java.util.Scanner;

public class Beakjoon_8958_LM {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    String arr[] = new String[in.nextInt()];

    for(int i = 0; i < arr.length; i++){
      arr[i] = in.next();
    }

    in.close();

    for (int i = 0; i < arr.length; i++){

      int count = 0;
      int sum = 0;

      for(int j = 0; j < arr[i].length(); j++){

        if(arr[i].charAt(j) == 'O'){
          count++;
        }
        else {
          count = 0;
        }
        sum += count;
      }

      System.out.println(sum);
    }

  }
}

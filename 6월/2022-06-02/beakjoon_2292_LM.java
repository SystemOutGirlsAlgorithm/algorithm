package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Beakjoon_2292_LM {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int num = Integer.parseInt(br.readLine());
    int count = 1;
    int min = 2;

    if(num == 1){
      System.out.println(1);
    }
    else {
      while(min <= num){
        min = min + (6 * count);
        count++;
      }

      System.out.println(count);
    }

  }
}

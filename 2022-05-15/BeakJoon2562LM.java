package main;

import java.util.Scanner;

public class BeakJoon2562LM {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int[] numbers = { sc.nextInt(), sc.nextInt(), sc.nextInt(),
        sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt() };

    int count = 0;
    int max = 0;
    int index = 0;
    for (int num : numbers) {
      count++;
      if (num > max) {
        max = num;
        index = count;
      }
    }
    System.out.println("max : " + max + ", index :" + index);
  }
}

package main;

import java.util.Arrays;
import java.util.Scanner;

public class Beakjoon_1546_LM {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int input = sc.nextInt();
    double[] numbers = new double[input];

    for (int i = 0; i < input; i++){
      numbers[i] = sc.nextDouble();
    }
    Arrays.sort(numbers);

    double avg = 0;
    for (int i = 0; i < numbers.length; i++){
      double score = (numbers[i]/numbers[numbers.length-1]) * 100;
      avg += score;
    }
    System.out.println(avg/ numbers.length);
  }
}

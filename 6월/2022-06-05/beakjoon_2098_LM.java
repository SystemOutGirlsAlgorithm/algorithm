package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Beakjoon_2908_LM {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer stk = new StringTokenizer(br.readLine(), " ");

    int a = Integer.parseInt(new StringBuilder(stk.nextToken()).reverse().toString());
    int b = Integer.parseInt(new StringBuilder(stk.nextToken()).reverse().toString());

    System.out.println(a > b ? a : b);
  }
}
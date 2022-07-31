package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Beakjoon_1427_¶óÀÓ¹ÎÆ® {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    char[] nums = br.readLine().toCharArray();

    Arrays.sort(nums);

    for (int i = nums.length - 1; i >= 0; i--) {
      System.out.print(nums[i]);
    }
  }
}
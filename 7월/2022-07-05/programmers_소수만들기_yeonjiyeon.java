class Solution {
  boolean isPrime(int num){
    for(int i = 2; i < num; i++){
      if(num % i == 0) return false;

    }
    return true;
  }

  public int solution(int[] nums) {
    int answer = 0;
    for(int i = 0; i < nums.length; i++){
      for(int j = i + 1; j < nums.length; j++){
        for(int k = j + 1; k < nums.length; k++){
          if(isPrime(nums[i] + nums[j] + nums[k])) answer++;
          //System.out.println(i + j + k);
          //System.out.println(isPrime(i + j + k));
        }
      }
    }

    return answer;
  }
}
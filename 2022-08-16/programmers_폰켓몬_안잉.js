function solution(nums) {
  var answer = 0;
  const result = [...new Set(nums)].length;
  answer = result > nums.length / 2 ? nums.length / 2 : result;
  return answer;
}

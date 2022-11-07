function removeElement(nums: number[], val: number): number {
  // nums[i]가 val과 값이 같으면 잘라내고 i--
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === val) {
      nums.splice(i, 1);
      i--;
    }
  }
  // 마지막에 남은 nums의 길이를 반환
  return nums.length;
}

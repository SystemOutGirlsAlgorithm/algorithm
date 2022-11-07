function searchInsert(nums: number[], target: number): number {
  if (nums.includes(target)) return nums.indexOf(target);
  else {
    nums.push(target);
    nums.sort((a, b) => a - b);
    return nums.indexOf(target);
  }
}

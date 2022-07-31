function solution(n, arr1, arr2) {
  var answer = [];

  const toBinary = (v) => {
    let binary = [];
    while (v !== 0) {
      binary.push(v % 2);
      v = Math.floor(v / 2);
    }
    while (binary.length !== n) {
      binary.push(0);
    }
    return binary.reverse();
  };

  const binaryArr1 = arr1.map((v) => toBinary(v), []);
  const binaryArr2 = arr2.map((v) => toBinary(v), []);

  for (let i = 0; i < n; i++) {
    let result = "";
    for (let j = 0; j < n; j++) {
      result += binaryArr1[i][j] === 0 && binaryArr2[i][j] === 0 ? " " : "#";
    }
    answer.push(result);
  }
  return answer;
}

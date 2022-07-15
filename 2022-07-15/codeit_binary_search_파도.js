function binarySearch(element, someList) {
  // 01. 첫번쨰 index와 마지막 index정의
  let firstIndex = 0;
  let lastIndex = someList.length - 1;

  // 03. 중간인덱스와 찾고자는 원소와 비교
  while (firstIndex <= lastIndex) { // 04.while 조건식이 false가 나와야 멈춤!

    // 02. 중간인덱스 지정 = 첫번째index와 마지막 index의 값을 합한뒤 / 2
    let middleIndex = Math.floor((firstIndex + lastIndex) / 2);

    // 03 -1. 중간인덱스가 찾고자 하는 원소랑 같으면, 중간인덱스 리턴
    if (someList[middleIndex] == element) {
      return middleIndex;
      // 03-2. 중간인덱스가 찾고자하는 원소보다 작으면, 왼쪽날리기
    } else if (someList[middleIndex] < element) {
      firstIndex = middleIndex + 1;
      // 03-2. 중간인덱스가 찾고자하는 원소보다 크면, 오른쪽날리기
    } else if (someList[middleIndex] > element) {
      lastIndex = middleIndex - 1;
    }
  }
  return '바보'; // 04-1. false일때 출력!
}

console.log(binarySearch(2, [2, 3, 5, 7, 11]));
console.log(binarySearch(0, [2, 3, 5, 7, 11]));
console.log(binarySearch(5, [2, 3, 5, 7, 11]));
console.log(binarySearch(3, [2, 3, 5, 7, 11]));
console.log(binarySearch(11, [2, 3, 5, 7, 11]));

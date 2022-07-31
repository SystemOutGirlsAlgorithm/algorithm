// 탐색 알고리즘 평가

// 선형 탐색
// 1. 리스트에서 한번에 찾는 경우 -> O(1) + O(1) + O(1) + O(1) = O(4) => O(1)
// 2. 리스트에 없는 경우 -> O(1) * n => O(1) + O(1) + O(n) + O(1) = O(n+3) => O(n)

function linearSearch(element, someList) {
  let i = 0; // 01. 시간복잡도 O(1) <list 크기와 상관X>
  let n = someList.lenght; // 02. 시간복잡도 O(1) <list 크기와 상관X>

  // 03. 시간복잡도 O(1) <list 크기와 상관X>
  while (i < n) {
    if (someList[i] == element) {
      return i;
    }
    i++;
  }
  return -1; // 04. 시간복잡도 O(1) <list 크기와 상관X>
}


// ========================================================================================


// 이진 탐색
// 1. 리스트에서 한번에 찾는 경우 -> O(1) + O(1) + O(1) + O(1) = O(4) => O(1)
// 2. 리스트에 없는 경우 -> O(1) * log2n = O(lg(n)) => O(1) + O(1) + O(lg(n)) + O(1) = O(lg(n)+3) => O(lg(n))

function binarySearch(element, someList) {
  startIndex = 0; // 01. 시간복잡도 O(1) <list 크기와 상관X>
  endIndex = someList.length - 1; // 02. 시간복잡도 O(1) <list 크기와 상관X>

  // 03. 시간복잡도 O(1) <list 크기와 상관X>
  while (startIndex <= endIndex) { 
    let midPoint = (startIndex + endIndex) / 2;

    if (someList[midPoint] == element) {
      return midPoint;
    } else if (element < someList[midPoint]) {
      endIndex = midPoint - 1;
    } else {
      startIndex = midPoint + 1;
    }
    return '바보'; // 04. 시간복잡도 O(1) <list 크기와 상관X>
  }
}

https://github.com/MIINII/algorithm.git

function linearSearch(element, someList) {
  for (let i = 0; i <= someList.length; i++) {
    if (element == someList[i]) {
      return i;
    } 
  }
  return "바보"
}

console.log(linearSearch(2, [2, 3, 5, 7, 11]));
console.log(linearSearch(0, [2, 3, 5, 7, 11]));
console.log(linearSearch(5, [2, 3, 5, 7, 11]));
console.log(linearSearch(3, [2, 3, 5, 7, 11]));
console.log(linearSearch(11, [2, 3, 5, 7, 11]));
const getCombinations = (arr, selectNumber) => {
  const result = [];
  if (selectNumber === 1) return arr.map((el) => [el]);

  arr.map((fixed, index, origin) => {
    const rest = origin.slice(index + 1);
    const combination = getCombinations(rest, selectNumber - 1);
    const attach = combination.map((el) => [fixed, ...el].sort());
    result.push(...attach);
  });
  return result;
};

function solution(orders, course) {
  let com = [];
  orders.map((order) => {
    course.map((num) => {
      if (num <= order.length) {
        const combine = getCombinations(order.split(""), num)
          .sort()
          .map((el) => el.join(""));
        com.push(...combine);
      }
    });
  });
  const menu = {};
  com.map((el) => {
    if (Object.keys(menu).includes(el)) menu[el] += 1;
    else menu[el] = 1;
  });
  let tt = Object.entries(menu)
    .sort((a, b) => b[1] - a[1])
    .sort((a, b) => a[0].length - b[0].length);
  let max = 0;
  let len = 0;
  const answer = tt
    .filter((el) => {
      if (el[1] < 2) return false;
      if (len === el[0].length && max === el[1]) {
        return true;
      } else if (len < el[0].length) {
        len = el[0].length;
        max = el[1];
        return true;
      }
    })
    .map((el) => el[0]);
  return answer.sort();
}

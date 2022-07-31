const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [k, n] = input[0].split(" ").map((v) => Number(v));
input.shift();
const [...list] = input.map((v) => Number(v));

const bSerach = (arr, target) => {
    let min = 1;
    let max = Math.max(...arr);

    while (min <= max) {
        let mid = Math.floor((min + max) / 2);

        let pieces = arr.map((v) => parseInt(v / mid)).reduce((acc, cur) => acc + cur);

        pieces >= target ? (min = mid + 1) : (max = mid - 1);
    }
    return max;
};

console.log(bSerach(list, n));

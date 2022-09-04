const input = require("fs").readFileSync("/dev/stdin").toString().split(" ");
const day = new Date(`2007-${input[0]}-${input[1]}`).getDay();
const days = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];

console.log(days[day]);

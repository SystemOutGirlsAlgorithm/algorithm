function computeTime(time) {
  const [hour, min] = time.split(":");
  return +hour * 60 + +min;
}

function calculateFee(fees, time) {
  if (time < fees[0]) return fees[1];
  return fees[1] + Math.ceil((time - fees[0]) / fees[2]) * fees[3];
}

function solution(fees, records) {
  const cars = {};
  records.map((el) => {
    const [time, number, inout] = el.split(" ");
    const tmpTime = computeTime(time);
    if (cars[number]) {
      cars[number] = [
        (cars[number][0] += inout === "IN" ? -tmpTime : tmpTime),
        inout,
      ];
    } else cars[number] = [-tmpTime, "IN"];
  });
  const answer = Object.keys(cars)
    .sort((a, b) => a - b)
    .map((key) => {
      let [time, inout] = cars[key];
      if (inout === "IN") time += computeTime("23:59");
      return calculateFee(fees, time);
    });
  return answer;
}

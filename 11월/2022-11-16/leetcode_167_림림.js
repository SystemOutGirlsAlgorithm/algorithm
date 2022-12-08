// 첫번째 방법 (time limit 초과 나옴) - 아마 이중 for문 사용 때문?
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(numbers, target) {
    let result = [];
    for(let i = 0; i < numbers.length; i++) {
        for (let j = i+1; j < numbers.length; j++) {
            if(numbers[i] + numbers[j] === target) {
                result.push(i+1, j+1);
            }
        }
    }
    return result;
};

// 두번쨰 방법 - while문을 사용하였음
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(numbers, target) {
    let i = 0;
    let j = numbers.length - 1;
    while(i < j) {
        let sum = numbers[i] + numbers[j];
        if (sum === target) {
            return [i+1, j+1];
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
};
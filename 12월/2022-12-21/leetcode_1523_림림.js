/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
 var countOdds = function(low, high) {
    let count = 0; //갯수 초깃값 0
    for(let i=low; i<high+1; i++){
        //값이 홀수이면 갯수 1 더하기
        if(i % 2 !== 0) {
            count += 1;
        //값이 짝수이면 아무것도 안더함
        } else {
            count += 0;
        }
    }
    //결과값 반환
    return count;
};
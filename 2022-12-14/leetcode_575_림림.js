/**
 * @param {number[]} candyType
 * @return {number}
 */
 var distributeCandies = function(candyType) {
    let divider = candyType.length/2;
    const set = new Set(candyType); //Set은 중복값 제거
    //나눴을 때 값이 더 크거나 같으면 set.size 반환
    if(divider >= set.size) { //Set의 길이는 size
        return set.size;
    // 그외에는 divider 반환
    } else {
        return divider;
    }
};
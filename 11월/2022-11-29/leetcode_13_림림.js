/**
 * @param {string} s
 * @return {number}
 */
 var romanToInt = function(s) {
    symbols = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000
    };
    
    let value = 0;
    for(let i = 0; i < s.length; i++){
            // 삼항연산자 이용하기
            symbols[s[i]] < symbols[s[i+1]] ? value -= symbols[s[i]]: value += symbols[s[i]]; 
    }
    return value;
};
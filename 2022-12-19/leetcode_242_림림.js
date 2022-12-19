/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
 var isAnagram = function(s, t) {
    const arrs = [...s]; //문자열->배열
    const arrt = [...t]; //문자열->배열
    arrs.sort(); //정렬
    arrt.sort(); //정렬
    if(JSON.stringify(arrs) === JSON.stringify(arrt)) { //JSON.stringify는 json, Object 객체, Object Array를 문자열로 변환
        return true;
    } else {
        return false;
    }
};
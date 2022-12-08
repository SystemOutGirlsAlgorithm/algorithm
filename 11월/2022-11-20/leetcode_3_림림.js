// string.indexOf(searchvalue)
// 배열, 문자열에서 둘 다 사용가능
// 문자열에서 특정 문자열을 찾고, 검색된 문자열이 '첫번째'로 나타나는 위치 index 리턴함
// 찾는 문자열이 없으면 -1 리턴함, 문자열을 찾을 때 대소문자 구분함

/**
 * @param {string} s
 * @return {number}
 */
 var lengthOfLongestSubstring = function(s) {
    var sub = [];
    var maxLength = 0;
    
    for(var i = 0; i < s.length; i++){
        // 찾는 문자열이 없으면
        if(sub.indexOf(s[i]) === -1){
            // 배열에 push
            sub.push(s[i]);
            if(sub.length > maxLength)
                maxLength = sub.length;
        }else{
            // 찾는 문자열이 있으면 slice
            sub = sub.slice(sub.indexOf(s[i]) + 1, sub.length);
            sub.push(s[i]);
        }
    }
    return maxLength;
};  
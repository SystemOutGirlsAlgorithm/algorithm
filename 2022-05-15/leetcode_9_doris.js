/**
 * @param {number} x
 * @return {boolean}
 */
 const isPalindrome = function(x) {
  const s = String(x)
  const len = s.length
  const center = Math.floor(len/2)

  //가운데를 찾고 양 옆으로 체크해 나가며 palindrome인지 확인
  
  if(len % 2 === 0) {
      for(let i=0;i<len-1;i++) {
          if(s[center-1-i] !== s[center+i]) {
              return false
          }
          continue
      }
      return true
  } else {
      for(let i=0;i<len-1;i++) {
          if(s[center-i] !== s[center+i]) {
              return false
          }
          continue
      }
      return true
  }
}
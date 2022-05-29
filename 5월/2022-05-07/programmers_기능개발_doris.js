function solution(progresses, speeds) {
  const answer = []
  const len = progresses.length
  
  let leftDaysOfPrev = Number.MAX_SAFE_INTEGER
  let featuresAtRelease = 0
  
  for(let i=0;i<len;i++) {
      const leftProgress = 100 - progresses[i]
      const leftDays = Math.ceil(leftProgress/speeds[i])
      
      if(i===0) leftDaysOfPrev = leftDays
      
      if(leftDays > leftDaysOfPrev) {
          answer.push(featuresAtRelease)
          leftDaysOfPrev = leftDays
          featuresAtRelease = 0
      }
      
      featuresAtRelease++
      
      if(i===len-1) answer.push(featuresAtRelease)
  }
  return answer
}
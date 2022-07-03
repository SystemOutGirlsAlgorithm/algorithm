a = '- **안녕** ✅ [어쩌고 저쩌고]' 

l = a.split('**')
print(l[2][1])
problem_count = {}
import re
k = '한 주에 1문제 이상 풀기'
numbers = re.sub(r'[^0-9]', '', k)
problem_count['test'] = numbers
print(problem_count)



MEMBER_LIST = ["말감 🎱", "진도 🧶", "Yoou 🐧 ", "Marvy 🕶️", "Muer ☁", "미도리 👻", "Beankong 🌊", "안잉 ❄️", "라임민트 S2", "유감 🍒", "Jedi 🖖", "OoO 🐯", "룰루 🎈", "yoon ⛄", "dyno0o 🦕", "한딱 🐋", "Soyou 🌈", "서나 🔥", "hoodu 🐱"]
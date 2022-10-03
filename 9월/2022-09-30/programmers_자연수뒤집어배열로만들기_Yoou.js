function solution(n) {
	var answer = [];

	// 1. 숫자를 문자열로 만들기
	let str = String(n);
	// 2. 문자열을 잘라서 배열로 만들기
	answer = str.split('');
	// 3. 문자들을 숫자로 만들어주기 
	answer = answer.map(x => Number(x));
	// 3. 배열을 역순으로 만들기
	answer.reverse();

	return answer;
}
function solution(n)
{
    var answer = 0;
    let num_string = String(n);
    // let num_string = n.toString();
    for(let i = 0; i < num_string.length; i++)
	{
		answer += Number(num_string[i]);
		// answer += parseInt(num_string[i]);
	}
	return answer;
}
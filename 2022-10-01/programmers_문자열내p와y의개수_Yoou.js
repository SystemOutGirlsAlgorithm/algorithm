function solution(s){
    var answer = true;
    
    s = s.toUpperCase();
    let P_array_size = s.split("P").length;
    let Y_array_size = s.split("Y").length;
    
    answer = (P_array_size === Y_array_size);
    return answer;
}
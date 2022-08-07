function solution(n, m) {
    var answer = [];
    const gcd = (a, b) => {
        if (b === 0)
            return (a);
        return (gcd(b, a % b));
    }
    
    const lcm = (a, b) => {
        return (a * b) / gcd(a, b);
    }
    return [gcd(n, m), lcm(n, m)];
}
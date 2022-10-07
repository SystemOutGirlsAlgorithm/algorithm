class Solution {
    fun romanToInt(s: String): Int {
        val romanNumeral = mapOf(
            'I' to 1,
            'V' to 5,
            'X' to 10,
            'L' to 50,
            'C' to 100,
            'D' to 500,
            'M' to 1000
        )

        var answer = 0

        s.forEachIndexed { idx, char ->
            answer += romanNumeral.getOrDefault(char, 0)
            s.getOrNull(idx-1)
                ?.takeIf{
                    romanNumeral.getOrDefault(s[idx], 0) > romanNumeral.getOrDefault(s[idx-1], 0)
                }
                ?.let {
                    answer -= (romanNumeral.getOrDefault(s[idx-1],0))*2
                }
        }

        return answer
    }
}
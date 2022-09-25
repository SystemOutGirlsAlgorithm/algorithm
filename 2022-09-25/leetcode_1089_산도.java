class Solution {
    public void duplicateZeros(int[] arr) {
        // 배열에 0이 있으면 그 다음 인덱스에 0을 삽입하고 나머지 요소는 뒤로 밀린다.
        // 배열에 0이 없으면 그대로 리턴.
        int len = arr.length;
        int i = 0, sh = 0;
        // I : [1,0,2,3,0,4,5,0]
        // O : [1,0,0,2,3,0,0,4]
        
        // 고정된 배열 길이에서 0을 찾으면서 사라질(밀릴) 요소의 개수를 센다. (shift)
        for(i = 0 ; i + sh < len; i++){
            sh += arr[i] == 0 ? 1 : 0;
        }
        
        for(i = i-1 ; sh > 0 ; i--){
            if( i + sh < len) arr[i+sh] = arr[i];
            if( arr[i] == 0 ) arr[i + --sh] = arr[i];
        }
    }
}
// 커뮤니티 확인 함. 추후 더 쉬운 방법 강구해야 함.
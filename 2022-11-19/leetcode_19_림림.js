/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
 var removeNthFromEnd = function(head, n) {
    // dummyRoot를 하나 생성
    const dummyRoot = new ListNode(0);
    dummyRoot.next = head;
    // front, back을 dummyRoot 노드로 설정
    let front = dummyRoot;
    let back = dummyRoot;
    // n값이 0보다 크거나 같을 동안 front를 움직임
    while(n >= 0){
        front = front.next;
        n--;
    }
    // front가 null일 때까지 움직임
    while(front) {
        front = front.next;
        back = back.next;
    }
    
    back.next = back.next.next; // 현재 front는 null이고 back의 다음 노드가 삭제할 대상이므로
    return dummyRoot.next; // 실질적인 head를 가리키고 있는 dummyRoot.next를 반환
};
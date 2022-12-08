/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
 var reverseList = function(head) {
    // [prev, curr]에 null과 head를 넣어줌
    let [prev, curr] = [null, head];
    // curr이 참일 동안
    while(curr) {
        [curr.next, prev, curr] = [prev, curr, curr.next];
    }
    // prev 반환
    return prev;
};
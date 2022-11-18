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
 var middleNode = function(head) {
    let currentNode = head;
    let length = 0;
    // linked list의 전체 길이 구하기
    while(currentNode !== null) {
        length++;
        currentNode = currentNode.next;
    };
    // second middle
    for(let i = 0; i < parseInt(length/2); i++) {
        head = head.next;
    }
    return head;
};
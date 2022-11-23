/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
 var mergeTwoLists = function(list1, list2) {
    // list1 or list2가 null이면 둘 중 null이 아닌 것 반환
    if (!list1) return list2;
    if (!list2) return list1;

    // list1.val이 list2.val보다 작으면
    if (list1.val <= list2.val) {
        // list1의 next를 list2로 옮김
        list1.next = mergeTwoLists(list1.next, list2);
        return list1;
    // list1.val이 list2.val보다 크면
    } else {
        // list2의 next를 list1으로 옮김
        list2.next = mergeTwoLists(list1, list2.next);
        return list2;
    }
};
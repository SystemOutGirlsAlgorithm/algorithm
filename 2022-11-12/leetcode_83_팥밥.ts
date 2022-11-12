/* Definition for singly-linked list. */
class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function deleteDuplicates(head: ListNode | null): ListNode | null {
  if (!head) return null; // head가 비어있으면 null반환
  if (!head.next) return head; //head.next가 비어있으면 head반환

  let prev = head;
  let cur = head.next;

  while (cur) {
    // cur에 값이 있는 동안 반복
    while (cur && cur.val === prev.val) {
      // cur에 값이 있고 cur.val가 prev.val가 같은 동안 반복
      cur = cur.next as ListNode;
    }
    prev.next = cur;
    prev = cur;
    if (cur) {
      cur = cur.next as ListNode;
    }
  }
  return head;
}

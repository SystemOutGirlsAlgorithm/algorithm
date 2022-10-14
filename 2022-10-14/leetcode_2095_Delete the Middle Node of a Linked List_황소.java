public class leetcode_2095_Delete the Middle Node of a Linked List_황소 {
    //you are given the head of a linked list
    // delete the middle node -> return the head of the modified linked list
    // middle node? n/2 th node in the n size of a linked list(from the start, uses 0-based indexing && x denotes the largest integer less than or equal to x)

    public static void main(String[] args) {
        ListNode head = new ListNode(1, new ListNode (3, new ListNode(4, new ListNode(7, new ListNode(1, new ListNode(2, new ListNode(6)))))));
        System.out.println(deleteMiddle(head));
    }

    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) {
            this.val = val;
        }
        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
        @Override
        public String toString() {
            return val + ((next == null) ? "" : ", " + next);
        }
    }

    public static ListNode deleteMiddle(ListNode head) {
        if (head == null || head.next == null) return null;
        // twice: 2배속, steady: 1배속
        ListNode twice = head.next.next, steady = head;
        while (twice != null && twice.next != null) {
            steady = steady.next;
            twice = twice.next.next;
        }
        // steady.next 쪽 연결고리 무효화
        steady.next = steady.next.next;
        return head;
    }
}
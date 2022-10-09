public class leetcode_876_Middle Node of a Linked List - 황소 {
    /* ListNode에서 ListNode로 출력해야 하기 때문에 문제에 제시된 ListNode class 형태를 잘 이해해야 함
     * ArrayList 등으로 index 값을 따로 구하기보다는 어떤 node에서 시작하는 ListNode를 출력할 건지 고려
     */
    public static void main(String[] args) {
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        System.out.println(middleNode(head));
    }

    public static ListNode middleNode(ListNode head) {
        ListNode answer = head, advanceSquad = head; // 문제에서 요구하는 건 "1/2" 기준이니 advanceSquad는 answer보다 2배 빠른 속도라고 생각

        while (advanceSquad != null && advanceSquad.next != null) {
            answer = answer.next;
            advanceSquad = advanceSquad.next.next;
        }
        return answer;

        /*ArrayList<ListNode> array = new ArrayList<>();
        int length = 0;
        while (head != null) {
            array.add(head);
            head = head.next;
            length++;
        }
        return array.get(length / 2); */ // time complexity O(n), space complexity O(n)
    }

    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {} // [IntelliJ] safe delete 가능

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }

        @Override
        public String toString() { // 참고 사이트: https://jaimemin.tistory.com/1545
            return val + (next == null ? "" : ", " + next);
        }
    }
}
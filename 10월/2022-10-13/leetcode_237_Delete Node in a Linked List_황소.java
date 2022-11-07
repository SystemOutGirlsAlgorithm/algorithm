public class leetcode_237_Delete Node in a Linked List_황소 {
    public static void main(String[] args) {
        ListNode input = new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));
        deleteNode(input.next); // 문제에서 나온 입력값은 5였는데 의미상 통하는 걸로 했음
        System.out.println(input);
    }

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            this.next = null;
        }
        public ListNode(int x, ListNode nextNode) {
            val = x;
            next = nextNode;
        }
        @Override
        public String toString() {
            return val + ", " + next;
        }
    }
    // 연결고리를 없앤다는 느낌으로 다음 연결고리 값으로 바로 넘겨줌
    // 체감 난이도는 easy
    public static void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
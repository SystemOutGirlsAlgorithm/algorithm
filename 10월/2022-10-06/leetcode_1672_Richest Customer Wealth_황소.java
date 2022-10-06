import java.util.Arrays;

public class leetcode_1672_Richest Customer Wealth_황소 {
    /*
     * Q. m x n integer grid "accounts", accounts[i][j] = amount of money ith customer has in the jth bank
     * return: the wealth that the richest customer has
     * a customer's wealth = amount of total money they have in their bank accounts
     * */

    /*
     * same customer(i), different bank(j) -> get total -> get max value
     * */


    public static void main(String[] args) {
        int[][] accounts = {{1,5}, {7, 3}, {3, 5}};
        System.out.println(maximumWealth(accounts));
    }

    public static int maximumWealth(int[][] accounts) {
        // 1번째 시도
        int[] list = new int[accounts.length];
        for (int i = 0; i < accounts.length; i++) {
            for (int j = 0; j < accounts[i].length; j++) {
                list[i] += accounts[i][j];
            }
        }
        Arrays.sort(list); // 최대값 구할 때 sort를 이용하기보다 일일이 비교하며 큰 수를 찾는 방식으로 진행할 수도 있을 듯
        return list[accounts.length - 1];
    }
}

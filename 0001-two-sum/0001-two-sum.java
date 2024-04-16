import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] answer = new int[2];

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                answer[0] = i;
                answer[1] = map.get(target - nums[i]);

                if (answer[0] > answer[1]) {
                    int tmp = answer[0];
                    answer[0] = answer[1];
                    answer[1] = tmp;
                }

                return answer;
            }
            map.put(nums[i], i);
        }

        return answer;
    }
}
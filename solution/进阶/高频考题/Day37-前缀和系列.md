## [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

### 思路1（前缀和）

-   构建前缀和数组，可以快速计算任意区间的和
-   **注意**：计算区间时候，下标有变化，计算`nums[i..j]`之间的和，那么就是`sum = prefixSum[j+1] - prefixSum[i]`，因为prefixSum的0索引位置是0，总的长度比nums大1

### 代码


```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int[] prefixSum = new int[nums.length+1];

        for (int i = 0; i < nums.length; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        int res = 0;
        for (int i = 1; i <= nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (prefixSum[i] - prefixSum[j] == k) {
                    res++;
                }
            }
        }
        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N^2)$，其中 N 为数组长度
- 空间复杂度：$O(N)$，其中 N 为数组长度

### 思路2（前缀和+哈希表优化）

-   `prefixSum[i] - prefixSum[j] = k` 我们可以通过变形成 `prefixSum[j] = prefixSum[i] - k`
-   由于只关心具体的次数，而不是解，所以我们可以用哈希表来记录前缀和出现的次数
-   之前保存了相同前缀和的个数，所以再计算总区间的时候不是再去计算相加，而是符合条件直接从哈希表中找到出现的次数加到res中
-   这样子时间复杂度就降到了$O(N)$了

### 代码


```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> prefixSum = new HashMap<>();
        prefixSum.put(0, 1);
        int sumI = 0;
        int res = 0;

        for (int i = 0; i < nums.length; i++) {
            sumI += nums[i];
            // 当前的前缀和（即从0...i）的值减去k，得到的值就是j..i区间的前缀和的值
            int sumJ = sumI - k;
            // 要查找的前缀和看看是否有存在，如果存在说明符合条件，就添加到res中
            if (prefixSum.containsKey(sumJ)) {
                res += prefixSum.get(sumJ);
            }
            // 每次把前缀和的及其出现的次数添加道哈希表中，如果不存在，就初始化为1，存在的话就加1即可
            prefixSum.put(sumI, prefixSum.getOrDefault(sumI, 0) + 1);
        }

        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$，其中 N 为数组长度
- 空间复杂度：$O(N)$，其中 N 为数组长度

<hr>

## [1371. 每个元音包含偶数次的最长子字符串](https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)

TODO

<hr>

## [网易面试题](../../../problem/网易面试题-前缀和系列.md)

TODO
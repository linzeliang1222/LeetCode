## [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

### 思路（辅助栈）

-   用栈后进先出（LIFO）将符号入栈
-   再利用HashMap存储符号对
-   由于都是这些符号，所以对每一个符号进行判断，如果左括号直接入栈，右括号再进行判断是否符合

### 代码


```java
class Solution {
    public boolean isValid(String s) {
        if (s.length() == 0) {
            return true;
        }

        Deque<Character> stack = new LinkedList<>();
        HashMap<Character, Character> symbolMap = new HashMap<>();
        symbolMap.put(')', '(');
        symbolMap.put('}', '{');
        symbolMap.put(']', '[');

        // 遍历字符串
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            // 字符为右半部分
            if (symbolMap.get(ch) != null) {
                // 如果栈是空，但是当前字符ch又是右半部分，则直接为false
                // 或者如果左右符号不匹配，也返回false
                if(stack.isEmpty() || stack.pop() != symbolMap.get(ch)) {
                    return false;
                }
            } else {
                // 左括号直接入栈
                stack.push(ch);
            }
        }
        
        // 栈stack为空说明括号有效，返回true
        return stack.isEmpty();
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$，其中 N 为字符串长度
- 空间复杂度：$O(N)$，其中 N 为字符串长度

<hr>

## [32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)

TODO
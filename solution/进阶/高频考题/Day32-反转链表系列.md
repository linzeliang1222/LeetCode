## [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

### 思路1（递归）

-   两两交换，迭代遍历
-   用一个pre记录前一个的节点，刚开始要初始化pre为null，因为这个null就是新链表的最后一个节点指向的地方

### 代码


```java
class Solution {
    public ListNode reverseList(ListNode head) {
        // 记录上一个结点
        ListNode pre = null;
        ListNode cur = head;
        // 不为null说明还没到链表尾部
        while (cur != null) {
            // 先记录下一个结点
            ListNode n = cur.next;
            // 改变当前结点的next指针
            cur.next = pre;
            // cur和pre都后移一位
            pre = cur;
            cur = n;
        }
        // 最后不要忘了返回链表的头结点
        return pre;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$，其中 N 为链表长度
- 空间复杂度：$O(1)$

### 思路2（迭代）

-   递归的终止条件是遍历道最后一个节点，到达最后一个节点，就返回最后一个节点，并且把它记录下来，因为他是新链表的头结点；但是如果链表是空的话我们就返回null，所以可以将这两个判断合并在一个判断中：`head == null || head.next == null`
-   先递归道最后一个节点，然后修改指针方向，将下一个节点的next指向当前节点：`head.next.next = head;`
-   修改指针原则是：将下一个节点的next指向当前节点，然后当前节点的next就必须要指向null了，否则会存在环，而且新链表的最后一个节点要指向null，所以必须：`  head.next = null;`

### 代码


```java
class Solution {
    public ListNode reverseList(ListNode head) {
        //如果是最后一个结点就结束递归，将他作为头结点返回
        if (head == null || head.next == null) {
            return head;
        }
        //设置后一个结点的next指向
        ListNode p = reverseList(head.next);
        head.next.next = head;
        //将当前结点next指向null，这样就不用单独为最后一个结点指定null了
        head.next = null;
        return p;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$，其中 N 为链表的长度
- 空间复杂度：$O(N)$，其中 N 为链表的长度

<hr>

## [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

### 思路1（迭代）

-   将反转链表分成3个部分：前一段未反转的部分、待反转链表部分、后一段未反转部分
-   将3个片段分离后，然后再连接起来
-   **细节注意：**如果是从第一个开始反转链表，即**前一段未反转的部分**不存在，那么返回的结果就直接是反转链表片段的新节点，否则就是head

### 代码


```java
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null) {
            return null;
        }

        // cur用于记录当前节点的指向，刚开始就是指向head
        ListNode cur = head;
        // prev用于记录 前一段未反转的部分 的最后一个节点，默认初始指向null
        ListNode prev = null;
        // 反转链表后的头结点
        ListNode tail = null;
        // 用于记录表反转之后的最后一个节点
        ListNode reverseTail = null;

        // 先获取prev，遍历结束后cur指向的是 待反转链表部分 的起使位置
        for (int i = 1; i < m; i++) {
            prev = cur;
            cur = cur.next;
        }
        
        // 待反转链表部分 的起使位置也就是链表反转之后的最后一个节点，我们先记录下来，为了最后和 后一段未反转部分 连接起来
        reverseTail = cur;

        // 开始反转链表，遍历次数要是n-m+1，这样才能反转全，那么此时cur指向的就是 后一段未反转部分 的起始位置
        for (int i = 0; i < n-m+1; i++) {
            ListNode next = cur.next;
            cur.next = tail;
            tail = cur;
            cur = next;
        }

        // 现在将 待反转链表部分 的尾节点与 后一段未反转部分 的起始节点连接起来
        reverseTail.next = cur;

        // 判断 前一段未反转的部分 的最后一个节点是否为空，如果为空的话，说明反转的是该链表前n个节点，直接返回 反转链后的头结点
        if (prev == null) {
            return tail;
        } else { 
            // 否则的话，将 前一段未反转的部分 的最后一个节点与 待反转链表部分 的头节点连接起来，然后返回head
            prev.next = tail;
            return head;
        }
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

### 思路2（递归）

-   我们可以递归实现反转链表
-   然后难度再加深一点，实现反转前 n 个链表
-   但是题目需求是还有前 m-1 个链表节点不需要反转，所以我们通过递归把前 m-1 个个省略跳过即可（递归时候m和n都要同时减1，这样才能保证反转的部分保持不变），当 m 减少为1时，反转前n个即可
-   在 reverseN 中，我们需要一个tail来记录后一部分不反转链表的第一个节点，也是反转链表最后一个节点指向的地方：`head.next = tail;`

### 代码


```java
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        // m为1代表就是直接反转前n个节点
        if (m == 1) {
            return reverseN(head, n);
        }

        head.next = reverseBetween(head.next, m-1, n-1);
        return head;
    }

    /**
    * 用于记录反转链表部分的尾结点指向
    */
    ListNode tail = null;

    /**
    * 反转链表的前n个节点
    */
    public ListNode reverseN(ListNode head, int n) {
        if (n == 1) {
            tail = head.next;
            return head;
        }

        ListNode p = reverseN(head.next, n-1);
        head.next.next = head;
        head.next = tail;
        return p;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

<hr>

## [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

### TODO


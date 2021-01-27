## [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

### 思路

-   刚开始想的是用stack1作为数据存储的地方，stack2用来作为辅助栈，如果添加元素直接push入stack1，如果删除元素，把stack1中的n-1个给pop到stack2中，然后剩下一个直接pop掉，然后再把stack2中的元素给在倒回去，虽然可以实现，但是速度会很慢，因此有了另一个思路
-   stack1用来添加专门元素，stack2用来专门删除元素，逻辑是这样子的：
    -   添加元素直接push到stack1中
    -   如果要删除元素，先判断stack2中**有没有元素**（说过了stack2用来删除元素用的栈）
        -   如果有，只需要将stack2中的末尾的元素pop即可
        -   如果没有，我们就要把stack1中的元素倒入到stack2中（如果此时stack1中也是空的话，说明都没有元素了还要删除，那么我们返回-1就行），然后再执行popstack2中的最后一个元素即可

### 代码


```java
class CQueue {

    Deque<Integer> stack1;
    Deque<Integer> stack2;

    public CQueue() {
        stack1 = new LinkedList<>();
        stack2 = new LinkedList<>();
    }
    
    public void appendTail(int value) {
        stack1.push(value);
    }
    
    public int deleteHead() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        if (stack2.isEmpty()) {
            return -1;
        } else {
            return stack2.pop();
        }
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

<hr>
##  [146. LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)

TODO

<hr>

## [641. 设计循环双端队列](https://leetcode-cn.com/problems/design-circular-deque/)

TODO

<hr>

## [1206. 设计跳表](https://leetcode-cn.com/problems/design-skiplist/)

TODO
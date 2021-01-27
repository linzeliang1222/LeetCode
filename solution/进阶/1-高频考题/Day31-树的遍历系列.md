## [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

### 思路1（递归）

-   前序先遍历根节点，然后左孩子，然后右孩子
-   使用递归解题

### 代码


```java
class Solution {
    List<Integer> res = new LinkedList<>();

    public List<Integer> preorderTraversal(TreeNode root) {
        preOrder(root);
        return res;
    }

    public void preOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        res.add(root.val);
        preOrder(root.left);
        preOrder(root.right);
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$，其中 N 为二叉树的结点数
- 空间复杂度：$O(N)$

### 思路2（迭代）

-   用栈来遍历

### 代码


```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        Deque<TreeNode> stack = new LinkedList<>();

        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                res.add(root.val);
                stack.push(root);
                root = root.left;
            }
            root = stack.pop().right;
        }
        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$，其中 N 为二叉树的结点数
- 空间复杂度：$O(N)$

### 思路3（Morris遍历）

-   如果左孩子不为空
    -   找到左子树的最右端的节点
        -   如果该节点的right是null，那么将其right指向当前节点，并且将当前节点加入res
        -   否则将其right置为null
-   如果左孩子为空
    -   直接将当前节点加入res
-   每次循环结束都将指针指向当前节点的右孩子right

### 代码


```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        TreeNode p1 = root;
        TreeNode p2 = null;

        while (p1 != null) {
            p2 = p1.left;
            if (p2 != null) {
                while (p2.right != null && p2.right != p1) {
                    p2 = p2.right;
                }
                if (p2.right == null) {
                    res.add(p1.val);
                    p2.right = p1;
                    p1 = p1.left;
                    continue;
                } else {
                    p2.right = null;
                }
            } else {
                res.add(p1.val);
            }
            p1 = p1.right;
        }
        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$，其中 N 为二叉树的结点数
- 空间复杂度：$O(1)$

<hr>

## [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

### 思路1（递归）

-   中序先遍历左孩子，然后父节点，然后右孩子
-   递归遍历

### 代码


```java
class Solution {
    List<Integer> res = new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {
        inOrder(root);
        return res;
    }

    public void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        inOrder(root.left);
        res.add(root.val);
        inOrder(root.right);
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

### 思路2（迭代）

-   用栈遍历

### 代码


```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        Deque<TreeNode> stack = new LinkedList<>();
        
        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

            root = stack.pop();
            res.add(root.val);
            root = root.right;
        }

        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

### 思路3（Morris遍历）

-   和前序的Morris基本一样，只是在`p2.right == null`中的`res.add(p1.val);`被移动到了`p2.right != null`中

### 代码


```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode p1 = root;
        TreeNode p2 = null;
        
        while (p1 != null) {
            p2 = p1.left;
            if (p2 != null) {
                while (p2.right != null && p2.right != p1) {
                    p2 = p2.right;
                }

                if (p2.right == null) {
                    p2.right = p1;
                    p1 = p1.left;
                    continue;
                } else {
                    res.add(p1.val);
                    p2.right = null;
                }
            } else {
                res.add(p1.val);
            }
            p1 = p1.right;
        }
        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

<hr>

## [145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)

### 思路1（递归）

-   中序先遍历左孩子，然后右孩子，最后父节点
-   递归遍历

### 代码


```java
class Solution {
    List<Integer> res = new ArrayList<>();

    public List<Integer> postorderTraversal(TreeNode root) {
        postOrder(root);
        return res;
    }

    public void postOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        postOrder(root.left);
        postOrder(root.right);
        res.add(root.val);
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

### 思路2（迭代）

-   用栈遍历

### 代码


```java
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Deque<TreeNode> stack = new LinkedList<>();
        TreeNode pre = null;

        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

            root = stack.pop();
            if (root.right == null || root.right == pre) {
                res.add(root.val);
                pre = root;
                root = null;
            } else {
                stack.push(root);
                root = root.right;
            }
        }
        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

### 思路3（Morris遍历）

-   代码结构就是Morris的前序遍历
-   把原来所有的`right`改成`left`，把原来所有的`left`改成`right`
-   返回结果之前反转一下数组

### 代码


```java
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        TreeNode p1 = root;
        TreeNode p2 = null;

        while (p1 != null) {
            p2 = p1.right;
            if (p2 != null) {
                while (p2.left != null && p2.left != p1) {
                    p2 = p2.left;
                }

                if (p2.left == null) {
                    res.add(p1.val);
                    p2.left = p1;
                    p1 = p1.right;
                    continue;
                } else {
                    p2.left = null;
                }
            } else {
                res.add(p1.val);
            }
            p1 = p1.left;
        }
        Collections.reverse(res);

        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

<hr>

## [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

### 思路1（迭代）

-   BFS广度优先搜索
-   用队列先进先出特性遍历

### 代码


```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        Deque<TreeNode> queue = new LinkedList<>();

        queue.offer(root);
        while (!queue.isEmpty()) {
            List<Integer> level = new LinkedList<>();
            int size = queue.size();
            while (size > 0) {
                TreeNode node = queue.poll();
                level.add(node.val);
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
                size--;
            }
            res.add(level);
        }
        return res;
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

### 思路2（递归）

-   DFS深度优先搜索
-   `res.size() < index`：每一层只能添加一个链表用来存储本层节点的值
-   每次搜索遍历都将本节点添加道对应的层的位置

### 代码


```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        dfs(1, res, root);
        return res;
    }

    public void dfs(int index, List<List<Integer>> res, TreeNode root) {
        if (root == null) {
            return;
        }
        // 每层只能添加一个链表
        if (res.size() < index) {
            res.add(new LinkedList<>());
        }

        // 将节点的值添加道本层的链表中
        res.get(index-1).add(root.val);

        dfs(index+1, res, root.left);
        dfs(index+1, res, root.right);
    }
}
```

### **复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：$O(h)$，其中 h 为树的高度
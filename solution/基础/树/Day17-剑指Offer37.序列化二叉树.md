### 思路

-   序列化其实就是**层序遍历**
-   但是，要能反序列化的话，前、中、后、层序遍历是不够的，必须在序列化时候保存所有信息，这样子反序列化才可以完全恢复一颗树
-   利用层序遍历，在遍历时候同时计算序列化结果，注意**最后一个没有逗号**
-   反序列化其实也是使用了层序遍历
-   由于起始位置是0，可以得出，索引位置为n的结点他的左孩子的索引为`n*2+1`，右孩子索引为`n*2+2`
-   从头开始遍历结点时候，判断孩子**是否为null**：不为null才为其构造结点作为其孩子，且将孩子结点入队，如果是null就跳过，判断下一个结点
-   **注意，每次循环结束要将index加一，因为进入到下一个结点的判断了嘛**

### 代码


```java
public class Codec {
    public String serialize(TreeNode root) {
        // 如果是空树，就直接返回[]
        if (root == null) {
            return "[]";
        }

        // 使用队列进行层序遍历
        Deque<TreeNode> queue = new LinkedList<>();
        // 用来存储结果
        StringBuilder res = new StringBuilder("[");
        queue.offer(root);

        // 在层序遍历时候完成字符串的拼接
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            // 如果为空就添加null进去否则添加结点的值进去
            if (node == null) {
                res.append("null,");
            } else {
                res.append(node.val + ",");
                queue.offer(node.left);
                queue.offer(node.right);
            }
        }
        // 删除最后一个逗号
        res.deleteCharAt(res.length() - 1);
        // 将右括号加上
        res.append("]");
        // 返回序列化的字符串
        return res.toString();
    }

    public TreeNode deserialize(String data) {
        // 如果传入的是空的字符串，那么就直接返回null
        if ("[]".equals(data)) {
            return null;
        }
        // 将字符串进行拆分成数据
        String[] values = data.substring(1, data.length() - 1).split("\\,");
        // 初始化根节点
        TreeNode root = new TreeNode(Integer.parseInt(values[0]));
        Deque<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        int index = 0;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            // 判断左孩子是否为空
            if (!"null".equals(values[index*2 + 1])) {
                node.left = new TreeNode(Integer.parseInt(values[index*2 + 1]));
                queue.offer(node.left);
            }

            // 判断右孩子是否为空
            if (!"null".equals(values[index*2 + 2])) {
                node.right = new TreeNode(Integer.parseInt(values[index*2 + 2]));
                queue.offer(node.right);
            }

            // index++代表进入下一个结点的判断
            index++;
        }
        // 返回反序列化的二叉树
        return root;
    }
}
```

### **复杂度分析**

- 序列化：
    - 时间复杂度：$O(N)$，其中 N 为二叉树的节点数
    - 空间复杂度：$O(N)$，其中 N 为二叉树的节点数
- 反序列化
    - 时间复杂度：$O(N)$，其中 N 为二叉树的节点数
    - 空间复杂度：$O(N)$，其中 N 为二叉树的节点数


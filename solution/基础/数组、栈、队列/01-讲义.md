# 数组

## 介绍

虽然数据结构有很多，比如树，图，哈希表，但真正实现它们的还需要落实到具体的基础数据结构，即**数组和链表**。之所以说他们是基础的数据结构，是因为它们直接控制物理内存的使用。

数组使用连续的内存空间，来存储一系列同一数据类型的值。如图表示的是数组的**每一项都使用一个 byte 存储**的情况。

![](../../../image/01.png)

那么为什么数组要存储相同类型的值呢？为什么有的语言（比如 JS）就可以存储不同类型的值呢？

实际上存储相同的类型有两个原因：

1. 相同的类型**大小是固定且连续的**(这里指的是基本类型，而不是引用类型，当然引用类型也可以存一个大小固定的指针，而将真实的内容放到别的地方，比如内存堆)，这样数组就可以**随机访问**了。试想数组第一项是 4 字节，第二项是 8 字节，第三项是 6 字节，我如何才能随机访问？而如果数组元素的大小都一样，我们就可以用**基址 + 偏移量**来定位任意一个元素，其中基值指的是数组的引用地址，如上图就是 1001。 偏移量指的是数组的索引。
2. 静态语言要求指定数组的类型。

> 虽然在一些语言，比如 JavaScript 中，数组可以保存不同类型的值，这是因为其内部做了处理。对于 V8 引擎来说， 它将数据类型分为基本类型和引用类型，基本类型直接存储值在栈上，而引用类型存储指针在栈上，真正的内容存到堆上。因此不同的数据类型也可以保持同样的长度。

数组的一个特点就是**支持随机访问**，请务必记住这一点。当你需要支持随机访问的数据结构的话， 自然而然应该想到数组。

本质上数组是一段连续的地址空间，这个是和我们之后要讲的链表的本质差别。 虽然二者从逻辑上来看都是线性的数据结构。

- 一个数组表示的是一系列的元素
- 数组（static array）的长度是固定的，一旦创建就不能改变（但是可以有 dynamic array）
- 所有的元素需要是同一类型（个别的语言除外）
- 可以通过下标索引获取到所储存的元素（随机访问）。 比如 array[index]
- 下标可以是是 0 到 array.length - 1 的任意整数

当数组里的元素也是一个数组的时候，就可以形成多维数组。例子：

1. 用一个多维数组表示坐标 `array[y]`
2. 用一个多维数组来记录照片上每一个 pixel 的数值

力扣中有很多二维数组的题目，我一般称其为 board。

## 数组的常见操作

1. 随机访问，时间复杂度 O(1)

```py
arr = [1,2,33]
arr[0] # 1
arr[2] # 33
```

2. 遍历，时间复杂度 O(N)

```py
for num in nums:
  print(num)
```

3. 任意位置插入元素、删除元素

```py
arr = [1,2,33]
# 在索引2前插入一个5
arr.insert(2, 5)
print(arr) # [1,2,5,33]
```

我们不难发现， 插入 2 之后，新插入的元素之后的元素（最后一个元素）的索引发生了变化，从 2 变成了 3，而其前面的元素没有影响。从平均上来看，数组插入元素和删除元素的时间复杂度为`O(N)`。最好的情况删除和插入发生在尾部，时间复杂度为 `O(1)`。

基本上数组都支持这些方法。 虽然命名各有不同，但是都是上面四种操作的实现：

- each()： 遍历数组
- pop(index)：删除数组中索引为 index 的元素
- insert(item, index)：数组索引为 index 处插入元素

**时间复杂度分析小结**

- 随机访问 -> O(1)
- 根据索引修改 -> O(1)
- 遍历数组 -> O(N)
- 插入数值到数组 -> O(N)
- 插入数值到数组最后 -> O(1)
- 从数组删除数值 -> O(N)
- 从数组最后删除数值 -> O(1)

## 基本概念

- 数组交集
- 数组并集
- 数组合并

## 题目推荐

- [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)
- [75. 颜色分类](https://leetcode-cn.com/problems/sort-colors/)
- [380. 常数时间插入、删除和获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/)

另外推荐两个思考难度小，但是边界多的题目， 这种题目如果可以一次写出 bug free 的代码会很加分。

- [59. 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)
- [859. 亲密字符串](https://leetcode-cn.com/problems/buddy-strings/)

# 栈

![](../../../image/02.png)

栈是一种受限的数据结构， 体现在只允许新的内容从一个方向插入或删除，这个方向我们叫栈顶，而从其他位置获取内容是不被允许的

栈最显著的特征就是 LIFO(Last In, First Out - 后进先出)

举个例子：

栈就像是一个放书本的抽屉，进栈的操作就好比是想抽屉里放一本书，新进去的书永远在最上层，而退栈则相当于从里往外拿书本，永远是从最上层开始拿，所以拿出来的永远是最后进去的哪一个

## 栈的常用操作

1. 进栈 - push - 将元素放置到栈顶
2. 退栈 - pop - 将栈顶元素弹出
3. 栈顶 - top - 得到栈顶元素的值
4. 是否空栈 - isEmpty - 判断栈内是否有元素

## 栈的常用操作时间复杂度

由于栈只在尾部操作就行了，我们用数组进行模拟的话，可以很容易达到 O(1)的时间复杂度。当然也可以用链表实现，即链式栈。

1. 进栈 - O(1)
2. 出栈 - O(1)

![](../../../image/03.png)

## 应用

- 函数调用栈
- 浏览器前进后退
- 匹配括号
- 单调栈用来寻找下一个更大（更小）元素

除此之外，有两个在数学和计算机都应用超级广泛的就是是`波兰表示法`和`逆波兰表示法`，之所以叫波兰表示法，是因为其是波兰人发明的。

波兰表示法（Polish notation，或波兰记法），是一种逻辑、算术和代数表示方法，其特点是操作符置于操作数的前面，因此也称做前缀表示法。如果操作符的元数（arity）是固定的，则语法上不需要括号仍然能被无歧义地解析。波兰记法是波兰数学家扬·武卡谢维奇 1920 年代引入的，用于简化命题逻辑。

扬·武卡谢维奇本人提到：[1]

> “ 我在 1924 年突然有了一个无需括号的表达方法，我在文章第一次使用了这种表示法。 ”

以下是不同表示法的直观差异：

- 前缀表示法 （+ 3 4 ）
- 中缀表示法 （3 + 4）
- 后缀表示法 （3 4 + ）

LISP 的 S-表达式中广泛地使用了前缀记法，S-表达式中使用了括号是因为它的算术操作符有可变的元数（arity）。逆波兰表示法在许多基于堆栈的程序语言（如 PostScript）中使用，以及是一些计算器（特别是惠普）的运算原理。

力扣相关题目推荐：

- [150. 逆波兰表达式求值](https://github.com/azl397985856/leetcode/blob/master/problems/150.evaluate-reverse-polish-notation.md)

## 题目推荐

- [1381. 设计一个支持增量操作的栈](https://leetcode-cn.com/problems/design-a-stack-with-increment-operation/)
- [394. 字符串解码](https://leetcode-cn.com/problems/decode-string/)
- [946. 验证栈序列](https://leetcode-cn.com/problems/validate-stack-sequences/)

# 队列

- 正如前面所说，队列是逻辑结构，底层可以用数组实现，也可以用链表实现，不同实现有不同的取舍。
- 队列也是一种受限的数据结构。和栈相反的是队列是只允许在一端进行插入，在另一端进行删除的线性表。
- 队列(Queue)是一种先进先出(FIFO - First In First Out)的数据结构
- 队列中，插入元素会发生在尾部而删除元素会发生在头部 - 先进先出原则

![](../../../image/04.png)

## 队列分类

- 双端队列
- 优先级队列

## 队列的操作

- 插入 - 在队列的尾部添加元素
- 删除 - 在队列的头部删除元素
- 查看首个元素 - 返回队列头部的元素的值

## 队列操作的时间复杂度

时间复杂度取决于你的底层实现是数组还是链表。我们知道直接用数组模拟队列的话， 在队头删除元素是无法达到 O(1) 的复杂度的， 上面提到了由于存在调整数组的原因，时间复杂度为`O(N)`。因此我们需要一种别的方式，这种方式就是下面要讲的 Linked List。 以链表为例，其时间复杂度：

- 插入 - O(1)
- 删除 - O(1)

## 队列的实现（Linked List）

我们知道链表的删除操作，尤其是删除头节点的情况下，是很容易做到 O(1)。那么我们是否可利用这一点来弥补上面说的删除无法达到 O(1)？

> 删除非头节点可以做到 O(1)么？什么情况下可以？

但是在链表末尾插入就不是 O(1)，而是 O(N)了。其实只要维护一个变量 tail， 存放当前链表的尾节点即可在 `O(1)` 的时间完成插入操作。

还有一种队列是循环队列，用的不是很多，大家可以自己查一下。

## 推荐题目

- [min-stack](https://leetcode-cn.com/problems/min-stack/)
- [evaluate-reverse-polish-notation](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)
- [decode-string](https://leetcode-cn.com/problems/decode-string/)
- [binary-tree-inorder-traversal](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)
- [clone-graph](https://leetcode-cn.com/problems/clone-graph/)
- [number-of-islands](https://leetcode-cn.com/problems/number-of-islands/)
- [largest-rectangle-in-histogram](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)
- [implement-queue-using-stacks](https://leetcode-cn.com/problems/implement-queue-using-stacks/)
- [01-matrix](https://leetcode-cn.com/problems/01-matrix/)

# 相关专题

## 前缀和

关于前缀和， 看我的这篇文章就够了 ~ [【西法带你学算法】一次搞定前缀和](https://lucifer.ren/blog/2020/09/27/atMostK/)

## 单调栈

单调栈适合的题目是求解**第一个一个大于 xxx**或者**第一个小于 xxx**这种题目。所有当你有这种需求的时候，就应该想到[单调栈](https://lucifer.ren/blog/2020/11/03/monotone-stack/)。

下面两个题帮助你理解单调栈， 并让你明白什么时候可以用单调栈进行算法优化。

- [84. 柱状图中最大的矩形](https://github.com/azl397985856/leetcode/blob/master/problems/84.largest-rectangle-in-histogram.md)
- [739.每日温度](https://github.com/azl397985856/leetcode/blob/master/daily/2019-06-06.md)

## 栈匹配

当你需要比较类似栈结构的匹配的时候，就应该想到使用栈。

比如判断有效括号。 我们知道有效的括号是形如：`((()))` 这样的括号， 其中第一个左括号和最后一个右括号匹配，因此一种简单的思路是把左括号看出是入栈，右括号看出是出栈即可轻松利用栈的特性求解。·

再比如链表的回文判断。 我们就可以一次遍历压栈，再一次遍历出栈的同时和当前元素比较即可。这也是利用了栈的特性。

- [20. 有效的括号](https://github.com/azl397985856/leetcode/blob/master/problems/20.valid-parentheses.md)

## 分桶 & 计数

[49.字母的异位词分组](https://leetcode-cn.com/problems/group-anagrams/description/)，[825. 适龄的朋友](https://leetcode-cn.com/problems/friends-of-appropriate-ages/solution/) 以及 [【每日一题】 Largest Range](https://github.com/azl397985856/leetcode/issues/420) 等就是分桶思想的应用。力扣关于分桶思想的题目有很多，大家只要多留心就不难发现。

从算法上看，我们通常会建立一个 counts 数组来计数，其本质和 Python 的 collections.Counter 类似，你也可用数组进行模拟，代码也比较简单。 比如：

```py
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        str_dict = collections.defaultdict(list)
        for s in strs:
          s_key = [0] * 26
          for c in s:
            s_key[ord(c)-ord('a')] += 1
          str_dict[tuple(s_key)].append(s)
        return list(str_dict.values())

```

如果代码就是 [49.字母的异位词分组](https://leetcode-cn.com/problems/group-anagrams/description/) 的一个可行解。 代码中的 s_key 就是一个桶，其中桶的大小为 26，表示一个单词中的 26 个字母出现的频率分布，这点有点像计数排序。

适合用分桶思想的题目一定是不在乎顺序的，这一点也不难理解，比较分桶之后原来的顺序信息就丢失了。

## 链表反转

链表反转考察的次数非常多，是一个很经典的题目了。我这里给大家准备了三个题目，你如果能轻松搞定这三道题，那么我相信面试再也不会怕链表反转的题目了。

链表的题目基本都是考察指针操作，只要你做到**心中有链**，切记出现环，就离成功不远了。再利用一些诸如哨兵节点的技巧简化代码，相信你写出 bug free 代码也不是难事。

- [206.反转链表](https://github.com/azl397985856/leetcode/blob/master/problems/206.reverse-linked-list.md)
- [92.反转链表-ii](https://github.com/azl397985856/leetcode/blob/master/problems/92.reverse-linked-list-ii.md)
- [25. K 个一组翻转链表](https://github.com/azl397985856/leetcode/blob/master/problems/25.reverse-nodes-in-k-groups.md)

# 总结

数组和链表是最最基础的数据结构，大家一定要掌握，其他数据结构都是基于两者产生的。

栈和队列是两种受限的数据结构，我们人为地给数组和链表增加一个限制就产生了它们。那我们为什么要自己给自己设限制呢？目的就是为了简化一些常见问题，这就好像是人类模仿鸟制造了飞机，模仿鸽子做了地震仪一样。栈和队列能帮我们简化问题。 比如队列的特性就很适合做 BFS，栈的特性就很适合做括号匹配等等。

你可以这么理解。 我们一开始做 BFS 的时候，没有队列。慢慢大家写地多了，发现是不是可以**抽象一个数据结构单独来处理这种通用的需求**？队列就产生了，其他数据结构也是一样。

# 参考

- [基础数据结构 by lucifer](https://github.com/azl397985856/leetcode/blob/master/thinkings/basic-data-structure.md)
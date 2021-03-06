# 哈希表

## 介绍

- 定义：散列表（Hash table，也叫哈希表），是根据关键码值(Key)而直接进行访问的数据结构。散列表可以使用**数组 + 链表**的方式来实现，也可以用别的方式，比如**数组 + 红黑树**。 JDK1.8 的 HashMap 就同时使用了这两种方式。

![](../image/38.jpg)

- 哈希函数：哈希表查找过程是根据 Key 来算出 hashcode（通常是一个数字），根据这个数字来随机访问数组，而理论上两个不同的 key 是可以算出同样的 hashcode 的。这个就叫做哈希冲突。比如 JDK1.8 的哈希函数就是先拿到通过 key 的 hashcode，是 32 位的 int 值，然后让 hashcode 的高 16 位和低 16 位进行异或操作。之所以这么做是因为这样做的哈希冲突的概率会小，那什么是哈希冲突呢？

- 哈希冲突：hash 函数不是万能的，根据**抽屉原理**不可避免的可能会造成两个不同的 Key 算出来的 hash 值相同，比如 hash 函数是 x % 3，这样 key=2 和 key=5 算出的 hash 值都为 2，这是要怎么办呢？一般我们有两种方法来处理，开放地址法和拉链法，具体大家可以查阅相关资料。这里简单的画了个图给大家直观看一下大概意思：

![](../image/39.jpg)

> 最后偷偷说一下，用 Java 的同学有兴趣可以看看 HashSet 的源码，底层也是用的 HashMap😄

- 哈希表的性能：构造一个冲突小，稳定性高的 hash 函数是很重要的，我们在刷题的时候大部分时间都不会去考虑这个问题，但是实际工程中有时不可避免需要我们自己构造 hash 函数，这时就要根据实际情况进行分析测试啦。

## 常用操作的时间复杂度

- 插入：O(1)
- 删除：O(1)
- 查找：O(1)

是的，常用的操作在非极其特殊情况下，平均的时间复杂度都为**O(1)**

## 常见的题类型

- **统计 xx 出现次数/频率/** （见下方多人运动）

该种题比较直观，若已知数据范围较小且比较连续，可以考虑用数组来实现。

题目推荐：

- [811.子域名访问计数](https://leetcode-cn.com/problems/subdomain-visit-count/description/)

- **需要查找/增加/删除操作为 O(1)时间复杂度** （一些设计题）

见到这种要求的题可以考虑一下是否需要 hash 表来做，比如 LRU，LFU 之类的题，题目中要求了时间复杂度，就是用 hash 表+双向链表解决的。

- **题目类型为图数据结构相关** （比如并查集）

这样可能需要构建有向图/无向图，这时可以用 hash 表来表示图并进行后续操作。

- **需要存储之前的状态以减少计算开销**（比如经典的两数和）

相信大家做过 dp 的一些题目就知道，记忆化搜索，该方法就利用 hash 表来存储历史状态，这样可以大大减少重复计算。

- **等等，大家多做类似的题目，相信可以总结出一套自己的思路。**

## 模板（伪代码）

1. 判断目标值是否出现过（例题如：两数之和、是否存在重复元素、合法数独等等）

```python
for num in nums:
    if num(该处为目标值target) in hashtable:
	return true
return false
```

2. 统计频率

数据比较离散

```python
for num in nums:
    if num in hashtable:
	hashtable[num] += 1
    else
	hashtable[num] = 1
# 后续操作
-------------------
```

数据范围较小且连续则可以用数组代替

```java
// 假设数据范围是0-n且n较小
int[] hashtable = new int[n + 1];

for num in nums:
    hashtable[num] += 1;

// 后续操作
------------------
```

## 题目推荐 - 👥 多人运动

### 题目描述

已知小猪每晚都要约好几个女生到酒店房间。每个女生 i 与小猪约好的时间由 [si , ei］表示，其中 si 表示女生进入房间的时间， ei 表示女生离开房间的时间。由于小猪心胸开阔，思想开明，不同女生可以同时存在于小猪的房间。请计算出小猪最多同时在做几人的「多人运动」。

例子：

Input ： [[ 0 , 30] ,[ 5 , 10 ] ， [15 , 20 ] ]

OutPut ：最多同时有两个女生的「三人运动」

### 思路

这个题 解法不止一种，但是我们这里因为在讲 hash 表，统计频率。下面我只写一下大致思路的伪代码，具体细节大家不妨可以尝试自己实现一下。

```java
// 上面刚刚说了关于频率统计的方法，这里读完题，是不是就立刻想到了：
// 用hash表来统计每个时刻房间内的人数并维护一个最大值就是我们所求的结果啦

res = -1

for everyGirl in girls:
    for curTime in [everyGirl.start, everyGirl.end]:
	// 套上面板子
	if curTime in hashtable:
	    hashtable[curTime] += 1
	else
	    hashtable[curTime] = 1

	// 维护最大值
	res = max(res, hashtable[curTime])

----------------------------
```

线下验证通过可以贴到这里哦，[【每日一题】- 2020-04-27 - 多人运动](https://github.com/azl397985856/leetcode/issues/347)

这里还有各种解题方法，大家都可以学习下思路并试着自己做一做！

类似推荐

- [面试题 01.04. 回文排列](https://leetcode-cn.com/problems/palindrome-permutation-lcci/)
- [500. 键盘行](https://leetcode-cn.com/problems/keyboard-row/description/)
- [36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/description/)
- [37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/description/) 与 36 类似，还需要点回溯的思想
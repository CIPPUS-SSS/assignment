#skiplist
skiplist的讲义.
[Pugh 1989]

##链表的表现
插入删除是常数的,(常数删除比较有意思)
但是搜索是O(n)[如果不是二分搜索的话].
如果是线性查找不能马上移动到某个中间结点.

skiplist能够弥补这些缺陷,适用于字典型的数据结构.

skiplist 相对于 treaps,red-black tree,B-tree 手写更容易实现.

试问谁能在1到2个小时之内,不参考其他代码.写出一个红黑树?
但是skiplist可以做到,因为结构简单.
还有一点redis在数据结构里面用的是skiplist,原因是为了降低并发锁的粒度.

Randmized structure.

O(logn) in expectation.
	with high probability. (very strong claim).

start from scratch.
	sorted linked list.
	linked-list,不可以randmized访问,所以二分查找行不通.
	搜索效率只能是O(logn).
	只有数组可以二分搜索.

跳跃链表的最低端是所有的元素,上层是部分的元素.
如果有两条线,那么搜索复杂度应该是:|L1|+( |L2|/|L1| )
直觉上说就是|L1|的搜索,加上划分出来属于那个搜索范围的区间.
我们的目标是 m+n/m 最小.
m = n^(1/2)
Every line is half the line below(except the bottom line)
It's like a balance tree -> ideal skip list.

Insert & Delete

It's really trivial.

Insert(x);
	Search(x) to find where x fits at bottom;
	Insert x in bottom list.
	What are we going to do? Which other list stores x?
	flip a coin  丢硬币,1/2之一的概率向上伸展.
	if heads x promote to next level
	flip coin again

PS:
	always stores -minus infinity.


##理解跳跃链表

```
1--2--3--4--5--6--7--8
```

这个搜索是线性的.但是如果再加一个链表,每隔一个结点取一次,可以节省一半的时间.

```
1-----3-----5-----7---
1--2--3--4--5--6--7--8
```

这样搜索8只要4次.

以此类推我们需要M个链表来得到log(n)的搜索效果.

```
1-----------5---------
1-----3-----5-----7---
1--2--3--4--5--6--7--8
```

用这样结构保持一个完美的平衡树并不是很划得来.
但是把每个结点看成竖着的链表,整体是一个链表的话就不一样了.

coin flip迭代1/2的高度.

http://dsqiu.iteye.com/blog/1705530
http://stats.stackexchange.com/questions/136806/expected-number-of-tosses-till-first-head-comes-up

## 二分图最大匹配问题(匈牙利算法)
---

## 二分图

&emsp;二分图是这样的一个图：其顶点可以划分为两个集合 $X$ 和 $Y$, 任何一条边所关联的两个顶点中，恰好有一个属于集合 $X$ , 另一个属于 $Y$。 同一个集合内的顶点必没有边相连。如果一个图是二分图，那么它一定没有 **奇环** (边为奇数的环路)， 如果一个图没有 **奇环** ,那么它就一定是 二分图。

![二分图](https://hexoblog-1257022783.cos.ap-chengdu.myqcloud.com/binaryGraph/bm.PNG#pic_center)

## 二分图的匹配

&emsp;给定一个二分图 G , 在 G 的一个子图 M 中， M 的边集 { E } 中的任意两条边都不依附于同一个顶点， 则称 M 是一个匹配。 翻译成人话就是 在图 G 中找到一些边构成一个集合， 这个集合中的任意一条边所连接的两个顶点都只属于这条边的连个端点，即每条边的顶点都不与其他边共用。如下图： 边集合 E = {(1,5),(3,6),(4,7)} 构成了一个匹配。
 ![匹配](https://hexoblog-1257022783.cos.ap-chengdu.myqcloud.com/binaryGraph/match.PNG#pic_center)

 ## 最大匹配

 &emsp;顾名思义，就是最大化满足上述规定的边集 E 。如上图的一个最大匹配结果为：
 ![最大匹配](https://hexoblog-1257022783.cos.ap-chengdu.myqcloud.com/binaryGraph/maxmatch.PNG#pic_center)

 
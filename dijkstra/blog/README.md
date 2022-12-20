狄克斯特拉（Dijkstra）算法的Python语言实现
==========================================

Dijkstra算法主要用于解决单源点最短路径问题。该算法有如下特点：

- 可以处理有向图或无向图（大部分只提到有向图）；
- 要求图中的任何边的权重都是非负的；
- 方法简单，但很强大，是贪心设计模式的例子。

算法导论中Dijkstra的伪码是基于优先级队列来实现的，不过优先级队列本身就可以用一篇文章来介绍，
所以我这里结合了其他教材中的介绍，希望以更容易理解和记忆的方式介绍Dijkstra算法。

首先，我们先给出Dijkstra算法（改进版）的伪码，然后，通过具体的例子（一张带边权重的有向图）
来具体的分析Dijkstra算法，并同时给出对应的Python实现。

Initialize dist(s) to 0, other dist($\cdot$) values to $\infty$
R = { } (the "known region")
while R $\neq$ V:
    Pick the node v $\not\in$ R with smallest dist($\cdot$)
    Add v to R
    for all edges (v, z) $\in$ E:
        if dist(z) > dist(v) + l(v, z):
            dist(z) = dist(v) + l(v, z)
            prev(z) = v

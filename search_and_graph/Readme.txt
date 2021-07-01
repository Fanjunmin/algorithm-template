图的存储方式
1. 邻接矩阵:
g[N][N], 元素g[u][v]=w, 表示顶点u->v, 该边的权重为w

2. 邻接表
对每个顶点u, 若存在顶点v,有边<u, v>权值w, 使用链表来存储v
链表的头节点: h[N]
链表表示: e[M], ne[M], wt[M], idx
节点初始化:
memset(h, -1, sizof(h)); idx = 0;
添加权重为w的节点<u, v>
idx++; wt[idx] = w; e[idx] = v; ne[idx] = h[u]; h[u] = idx;
对于头节点为k的链表遍历
for(int i = h[k]; i != -1; i = ne[i]) {
    int j = e[i];   //下一个节点
}

无向图可以用有向图来表示
无向图的<u, v>等价于有向图的<u, v> + <v, u>

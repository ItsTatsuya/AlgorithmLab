//algorithm for quicksort

'''
quickSort(A, p, r)
    if p < r
        q = partition(A, p, r)
        quickSort(A, p, q-1)
        quickSort(A, q+1, r)

partition(A, p, r)
    x = A[r]
    i = p - 1
    for j = p to r - 1
        if A[j] <= x
            i = i + 1
            exchange A[i] with A[j]
    exchange A[i+1] with A[r]
    return i + 1
'''

//algorithm for insertion sort

'''
insertionSort(A)
    for j = 2 to A.length
        key = A[j]
        //Insert A[j] into the sorted sequence A[1..j-1]
        i = j - 1
        while i > 0 and A[i] > key
            A[i+1] = A[i]
            i = i - 1
        A[i+1] = key
'''

//algorithm for minimum path cost in a matrix

'''
minCost(cost, m, n)
    for i = 0 to m
        for j = 0 to n
            if i == 0 and j == 0
                minCost[i, j] = cost[i, j]
            else if i == 0
                minCost[i, j] = minCost[i, j-1] + cost[i, j]
            else if j == 0
                minCost[i, j] = minCost[i-1, j] + cost[i, j]
            else
                minCost[i, j] = min(minCost[i-1, j-1], minCost[i-1, j], minCost[i, j-1]) + cost[i, j]
    return minCost[m, n]

OR

minCost(cost, m, n)
    if m < 0 or n < 0
        return infinity
    else if m == 0 and n == 0
        return cost[m, n]
    else
        return cost[m, n] + min(minCost(cost, m-1, n-1), minCost(cost, m-1, n), minCost(cost, m, n-1))
'''





//algorithm for coin change problem

'''
coinChange(C, n)
    for i = 1 to n
        min = infinity
        for j = 1 to m
            if i >= C[j] and min > coinChange(C, i - C[j]) + 1
                min = coinChange(C, i - C[j]) + 1
        coinChange(C, i) = min
    return coinChange(C, n)
  OR 
coinChange(C, n)
    if n == 0
        return 0
    min = infinity
    for i = 1 to m
        if n >= C[i] and min > coinChange(C, n - C[i]) + 1
            min = coinChange(C, n - C[i]) + 1
    return min
'''

//algorithm for knapsack problem

'''
knapsack(W, w, v, n)
    if n == 0 or W == 0
        return 0
    if w[n-1] > W
        return knapsack(W, w, v, n-1)
    else
        return max(v[n-1] + knapsack(W-w[n-1], w, v, n-1), knapsack(W, w, v, n-1))

 OR

knapsack(W, w, v, n)
    for i = 0 to n
        for j = 0 to W
            if i == 0 or j == 0
                K[i, j] = 0
            else if w[i-1] <= j
                K[i, j] = max(v[i-1] + K[i-1, j-w[i-1]], K[i-1, j])
            else
                K[i, j] = K[i-1, j]
    return K[n, W]
'''

'''

//algorithm for krushkal's algorithm

'''
krushkal(G)
    A = {}
    for each vertex v in G.V
        MAKE-SET(v)
    sort the edges of G.E into nondecreasing order by weight w
    for each edge (u, v) in G.E, taken in nondecreasing order by weight
        if FIND-SET(u) != FIND-SET(v)
            A = A U {(u, v)}
            UNION(u, v)
    return A

MAKE-SET(x)
    x.p = x
    x.rank = 0

FIND-SET(x)
    if x != x.p
        x.p = FIND-SET(x.p)
    return x.p

UNION(x, y)
    xRoot = FIND-SET(x)
    yRoot = FIND-SET(y)
    xRoot.p = yRoot
'''

//algorithm for dijkstra's algorithm

'''
dijkstra(G, s)
    for each vertex v in G.V
        v.d = infinity
        v.pi = NIL
    s.d = 0
    S = {}
    Q = G.V
    while Q != {}
        u = EXTRACT-MIN(Q)
        S = S U {u}
        for each vertex v in G.Adj[u]
            if v.d > u.d + w(u, v)
                v.d = u.d + w(u, v)
                v.pi = u

OR

dijkstra(G, s)
    for each vertex v in G.V
        v.d = infinity
        v.pi = NIL
    s.d = 0
    S = {}
    Q = G.V
    while Q != {}
        u = EXTRACT-MIN(Q)
        S = S U {u}
        for each vertex v in G.Adj[u]
            RELAX(u, v, w)

RELAX(u, v, w)
    if v.d > u.d + w(u, v)
        v.d = u.d + w(u, v)
        v.pi = u
'''

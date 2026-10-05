Algorithm Dijkstra(S)
Input: Gptr, source, N
Output: d[1-N], path[1-N]
STEPS:
 * for i = 1 to N do
   * 1.1 known[i] = false
   * 1.2 if (Gptr[S][i] ≠ 0) then
     * 1.2.1 d[i] = Gptr[S][i]
     * 1.2.2 path[i] = S
   * 1.3 else
     * 1.3.1 d[i] = \infty
     * 1.3.2 path[i] = NULL
   * 1.4 End if
 * End for
 * known[S] = true
 * d[S] = 0
 * complete = false
 * while (not completed) do
   * 6.1 j = search_min(d, known)
   * 6.2 known[j] = true
   * 6.3 for i = 1 to N do
     * 6.3.1 if (known[i] = false) and (Gptr[j][i] ≠ 0) then
       * 6.3.1.1 if (d[j] + Gptr[j][i] < d[i]) then
         * 6.3.1.1.1 d[i] = d[j] + Gptr[j][i]
         * 6.3.1.1.2 path[i] = j
       * 6.3.1.2 End if
     * 6.3.2 End if
   * 6.4 End for
   * 6.5 complete = true
   * 6.6 for i = 1 to N do
     * 6.6.1 if (known[i] = false) then
       * 6.6.1.1 complete = false
       * 6.6.1.2 Break,
     * 6.6.2 End if
   * 6.7 End for
 * End while
 * Stop
Algorithm Kruskal's
Input: Gptr, N, X \rightarrow Adjacent list
Output: minimum spanning tree.
Algorithm:
 * k = 0
 * for i = 1 to N-1 do
   * 2.1 for j = i+1 to N do
     * 2.1.1 if (Gptr[i][j] > 0) then
       * 2.1.1.1 k = k+1
       * 2.1.1.2 X[k].vi = i
       * 2.1.1.3 X[k].vj = j
       * 2.1.1.4 X[k].weight = Gptr[i][j]
       * 2.1.1.5 X[k].known = false
     * 2.1.2 end for (written as end for in place of end if)
   * 2.2 end for
 * End for
 * ne = k
 * if (ne < N-1) then
   * 5.1 print "spanning tree is not possible"
   * 5.2 Exit
 * End if
 * for i = 1 to N do
   * 7.1 for j = 1 to N do
     * 7.1.1 TREE[i][j] = 0
   * 7.2 End for
 * End for
 * X.SORTEDEDGES()
 * l = 1
 * k = 0
 * while (k < N) do
   * 12.1 temp = TREE
   * 12.2 i = X[l].vi
   * 12.3 j = X[l].vj
   * 12.4 temp[i][j] = 1
   * 12.5 temp[j][i] = 1
   * 12.6 WARSHALLS(temp)
   * 12.7 flag = false
   * 12.8 for p = 1 to N do
     * 12.8.1 if (temp[p][p] = 1) then
       * 12.8.1.1 flag = True
       * 12.8.1.2 break
     * 12.8.2 End if
   * 12.9 End for
   * 12.10 if (not flag) then
     * 12.10.1 k = k + 1
     * 12.10.2 TREE[i][j] = 1
     * 12.10.3 TREE[j][i] = 1
     * 12.10.4 X[l].known = true;
   * 12.11 End if
   * 12.12 l = l + 1
 * End while
 * stop


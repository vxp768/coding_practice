/* 
 * 1. guess number of edges needed for shortest paths.
 * calculate shortest path for every possible length
 * DP:
 *
  for (len : 1 to |V|-1)
    for u in V
        for v in V
            for x in V
                if ( d(u,v) > d(u,x)+w(x,v) )
                    d(u,v) = d(u,x)+w(x,v)
 *
 * 
 * 
 * 2. Intermediate vertices could only from (1 ... K)
 * Differetn way of slicing the problem space.
 */
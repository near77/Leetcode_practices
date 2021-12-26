import heapq
from typing import List
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points_with_dist = []
        heapq.heapify(points_with_dist)
        for point in points:
            if len(points_with_dist) < k:
                heapq.heappush(points_with_dist, (-(point[0]**2+point[1]**2),[point[0], point[1]]))
            else:
                heapq.heappushpop(points_with_dist, (-(point[0]**2+point[1]**2),[point[0], point[1]]))
            
        return [item[1] for item in points_with_dist]
        
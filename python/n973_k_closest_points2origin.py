from typing import List
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        k_points = []
        distance_map = {}
        for point in points:
            if distance_map.get(str(point), None) == None:
                distance_map[str(point)] = [pow(point[0], 2) + pow(point[1], 2), 1]
            else:
                distance_map[str(point)][1] += 1
        sorted_map = dict(sorted(distance_map.items(), key=lambda item:item[1][0]))
        cnt = 0
        for key in sorted_map:
            if cnt < k:
                while sorted_map[key][1] > 0:
                    k_points.append(eval(key))
                    sorted_map[key][1] -= 1
                    cnt += 1
        return k_points
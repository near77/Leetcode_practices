from typing import List
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        r_map = {}
        res = 0
        for t in time:
            key = t % 60
            res += r_map.get((60-key)%60, 0)
            if r_map.get(key, 0) == 0:
                r_map[key] = 1
            else:
                r_map[key] += 1
        return res
# Your interview score of 5.56/10 beats 82% of all users.
# Time Spent: 45 minutes 13 seconds
# Time Allotted: 1 hour

from typing import *
# n551 Student Attendance Record I
# 113 / 113 Testcases Passed
class Solution:
    def checkRecord(self, s: str) -> bool:
        absent_cnt = 0
        l = len(s)
        for i in range(l):
            char = s[i]
            if char == "A":
                absent_cnt += 1
                if absent_cnt > 1:
                    return False
            if char == "L":
                if i < l - 2:
                    if s[i+1] == "L" and s[i+2] == "L":
                        return False
        return True

# n743 Network Delay Time
# 52 / 52 Testcases Passed
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        dst_mat = [[0] * n for i in range(n)]
        neighbor_map = {i: [] for i in range(n)}
        for time in times:
            src = time[0]-1
            dst = time[1]-1
            w = time[2]
            dst_mat[src][dst] = w
            neighbor_map[src].append(dst)
        shortest_paths = [10100]*n
        shortest_paths[k-1] = 0
        update = True
        cur_nodes = [k-1]
        while update:
            update = False
            next_dsts = []
            for src in cur_nodes:
                next_dsts += neighbor_map[src]
                for dst in neighbor_map[src]:
                    if shortest_paths[src]+dst_mat[src][dst] < shortest_paths[dst]:
                        shortest_paths[dst] = shortest_paths[src]+dst_mat[src][dst]
                        update = True
            cur_nodes = list(set(next_dsts))
        if max(shortest_paths) == 10100:
            return -1
        else:
            return max(shortest_paths)
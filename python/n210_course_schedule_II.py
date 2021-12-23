from typing import List
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        prereq = {}
        for prerequisite in prerequisites:
            course = prerequisite[0]
            req = prerequisite[1]
            if prereq.get(course, None) == None:
                prereq[course] = [req]
            else:
                prereq[course].append(req)
        used = [False]*numCourses
        res = []
        while not all(used):
            change = False
            for i in range(numCourses):
                if used[i]:
                    continue
                else:
                    can_take = True
                    if prereq.get(i, False):
                        for preq in prereq[i]:
                            if not used[preq]:
                                can_take = False
                                break
                    if can_take:
                        res.append(i)
                        used[i] = True
                        change = True
                        for key in prereq:
                            if i in prereq[key]:
                                prereq[key].remove(i)
            if not change:
                return []
        return res
        
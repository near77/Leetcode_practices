from typing import List
class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        first_list_len = len(firstList)
        second_list_len = len(secondList)
        first_idx = 0
        second_idx = 0
        intersections = []
        while first_idx < first_list_len and second_idx < second_list_len:
            if firstList[first_idx][0] > secondList[second_idx][1]:
                second_idx += 1
            elif secondList[second_idx][0] > firstList[first_idx][1]:
                first_idx += 1
            else:
                intersection = [max(firstList[first_idx][0], secondList[second_idx][0]), min(firstList[first_idx][1], secondList[second_idx][1])]
                intersections.append(intersection)
                if firstList[first_idx][1] <= secondList[second_idx][1]:
                    first_idx += 1
                else:
                    second_idx += 1
        return intersections
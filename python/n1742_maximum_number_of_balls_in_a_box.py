class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        cnt_map = {}
        max_cnt = 0
        for i in range(lowLimit, highLimit+1):
            sum_of_dig = 0
            while i != 0:
                sum_of_dig += i % 10
                i = int(i/10)
            if cnt_map.get(sum_of_dig, 0) == 0:
                cnt_map[sum_of_dig] = 1
            else:
                cnt_map[sum_of_dig] += 1
            max_cnt = max(cnt_map[sum_of_dig], max_cnt)
        return max_cnt
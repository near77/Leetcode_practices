# Your interview score of 3.95/10 beats 47% of all users.
# Time Spent: 58 minutes 32 seconds
# Time Allotted: 1 hour
from typing import *
# n929. Unique Email Addresses
# 184 / 184 Testcases Passed
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        return_mails = []
        for email in emails:
            domain = email.split("@")[1]
            local_name = email.split("@")[0]
            local_name = local_name.split("+")[0]
            local_name = local_name.replace(".", "")
            combined_mail = local_name + "@" + domain
            return_mails.append(combined_mail)
        return len(set(return_mails))
# n904. Fruit Into Baskets
# 90 / 90 Testcases Passed
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        fruit_last_position_map = {}
        first_idx = 0
        cur_two_fruit = []
        max_num = 0
        for i in range(len(fruits)):
            fruit_last_position_map[fruits[i]] = max(fruit_last_position_map.get(fruits[i], 0), i)
            if fruits[i] not in cur_two_fruit:
                if len(cur_two_fruit) == 2:
                    first_idx = i - 1
                    while fruits[first_idx] == fruits[first_idx-1]:
                        first_idx -= 1
                    if cur_two_fruit[0] == fruits[i-1]:
                        cur_two_fruit.pop(1)
                    else:
                        cur_two_fruit.pop(0)
                    cur_two_fruit.append(fruits[i])
                else:
                    cur_two_fruit.append(fruits[i])
            max_num = max(max_num, i - first_idx + 1)
        return max_num
# Your interview score of 6.98/10 beats 75% of all users.
# Time Spent: 20 minutes 26 seconds
# Time Allotted: 1 hour

# n1185. Day of the Week
# 43 / 43 Testcases Passed
import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        weekday = datetime.date(year, month, day)
        return weekday.strftime("%A")

# n232. Implement Queue using Stacks
# 21 / 21 Testcases Passed
class MyQueue:

    def __init__(self):
        self.stack_in = []
        self.stack_out = []

    def push(self, x: int) -> None:
        self.stack_in.append(x)

    def pop(self) -> int:
        if len(self.stack_out) == 0:
            while not len(self.stack_in) == 0:
                top_element = self.stack_in[-1]
                self.stack_out.append(top_element)
                self.stack_in.pop()
        top_element = self.stack_out[-1]
        self.stack_out.pop()
        return top_element

    def peek(self) -> int:
        if len(self.stack_out) == 0:
            while not len(self.stack_in) == 0:
                top_element = self.stack_in[-1]
                self.stack_out.append(top_element)
                self.stack_in.pop()
        top_element = self.stack_out[-1]
        return top_element
        

    def empty(self) -> bool:
        if len(self.stack_out) == 0 and len(self.stack_in) == 0:
            return True
        else:
            return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
from typing import List
class StreamChecker:
    def __init__(self, words: List[str]):
        self.words_map = {}
        self.current_str = ""
        for word in words:
            if self.words_map.get(word[-1], -1) == -1:
                self.words_map[word[-1]] = [word]
            else:
                self.words_map[word[-1]].append(word)

    def query(self, letter: str) -> bool:
        self.current_str += letter
        if self.words_map.get(letter, -1) == -1:
            return False
        else:
            for word in self.words_map[letter]:
                n = len(word)
                if len(self.current_str) < n:
                    continue
                else:
                    if self.current_str[-n:] == word:
                        return True
            return False


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
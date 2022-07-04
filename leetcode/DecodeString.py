class Solution:
    def decode_string_helper(self, s: str, idx: int = 0) -> tuple:
        res = ''

        while idx < len(s):
            curr = s[idx]

            if curr == ']':
                return res, idx
            elif curr == '[':
                curr_res = self.decode_string_helper(s, idx + 1)
                res += self.get_left_number(s, idx - 1) * curr_res[0]
                idx = curr_res[1]
            elif not self.is_number(curr):
                res += curr

            idx += 1

        return res, idx

    def decodeString(self, s: str) -> str:
        return self.decode_string_helper(s)[0]

    def is_number(self, ch: str) -> bool:
        return ord('0') <= ord(ch) <= ord('9')

    def get_left_number(self, s: str, right_idx: int) -> int:
        res = 0
        tens = 1

        while right_idx >= 0 and self.is_number(s[right_idx]):
            curr = int(s[right_idx])
            res = curr * tens + res
            tens *= 10
            right_idx -= 1

        return res
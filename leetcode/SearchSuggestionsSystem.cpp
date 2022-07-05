class TrieNode:

    def __init__(self):
        self.children = 26 * [None]
        self.word = None

    def contains_char(self, ch):
        return self.children[self.get_char_idx(ch)] is not None

    def get_child(self, ch):
        return self.children[self.get_char_idx(ch)]

    def insert_child(self, ch, childNode):
        self.children[self.get_char_idx(ch)] = childNode

    def get_char_idx(self, ch):
        return ord(ch) - ord('a')


class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert_word(self, word):
        curr = self.root

        for ch in word:
            if not curr.contains_char(ch):
                curr.insert_child(ch, TrieNode())

            curr = curr.get_child(ch)

        curr.word = word

    def find_first_k_words(self, prefix, k):
        curr = self.root

        for ch in prefix:
            if not curr.contains_char(ch):
                curr.insert_child(ch, TrieNode())

            curr = curr.get_child(ch)

        res = []

        def fill_first_k_words(node):
            nonlocal k

            if len(res) == k:
                return

            if node.word is not None:
                res.append(node.word)

            for child in filter(lambda c: c is not None, node.children):
                fill_first_k_words(child)

        fill_first_k_words(curr)
        return res


class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        trie = Trie()

        for prod in products:
            trie.insert_word(prod)

        prefix = ''
        res = []

        for ch in searchWord:
            prefix += ch
            res.append(trie.find_first_k_words(prefix, 3))

        return res
import heapq


class MinItem:

    def __init__(self, score, name):
        self.name = name
        self.score = score
    
    def __lt__(self, other):
        if self.score == other.score:
            return self.name > other.name

        return self.score < other.score


    def to_MaxItem(self):
        return MaxItem(self.score, self.name)

class MaxItem:

    def __init__(self, score, name):
        self.name = name
        self.score = score

    def __lt__(self, other):
        if self.score == other.score:
            return self.name < other.name

        return self.score > other.score
    
    def to_MinItem(self):
        return MinItem(self.score, self.name)

class SORTracker:

    def __init__(self):
        self.min_heap = []
        self.max_heap = []

    def add(self, name: str, score: int) -> None:
        new_max_item = MaxItem(score, name)

        if not len(self.min_heap) or (new_max_item > self.min_heap[0].to_MaxItem()):
            heapq.heappush(self.max_heap, new_max_item)
            return

        
        heapq.heappush(self.min_heap, new_max_item.to_MinItem())
        heapq.heappush(self.max_heap, heapq.heappop(self.min_heap).to_MaxItem())

    def get(self) -> str:
        curr = heapq.heappop(self.max_heap)
        heapq.heappush(self.min_heap, curr.to_MinItem())

        return curr.name


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()


# ******************************************************************************************** 2nd solution *****************************

from sortedcontainers import SortedList


class Item:
    
    def __init__(self, score, name):
        self.score = score
        self.name = name
    
    def __lt__(self, other):
        if self.score == other.score:
            return self.name < other.name
        
        return self.score > other.score

class SORTracker:

    def __init__(self):
        self.data = SortedList()
        self.get_idx = 0
        

    def add(self, name: str, score: int) -> None:
        self.data.add(Item(score, name))

    def get(self) -> str:
        res = self.data[self.get_idx].name
        self.get_idx += 1
        return res


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()
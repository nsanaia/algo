class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        user_data = self.construct_user_data(username, timestamp, website)

        triplets = {}
        best = [float('-inf'), '']

        for user, websites in user_data.items():
            websites.sort()
            self.iterate_triplets(websites, triplets, best)
        
        return best[1].split('#')

    def iterate_triplets(self, websites: list, triplets: dict, best: list):
        N = len(websites)
        if N < 3:
            return
        
        uniques_per_user = set()
    
        for i in range(0, N - 2):
            for j in range(i + 1, N - 1):
                for k in range(j + 1, N):
                    triplet_key = '#'.join((websites[i][1], websites[j][1], websites[k][1]))
                    
                    if triplet_key in uniques_per_user:
                        continue
                    
                    uniques_per_user.add(triplet_key)
    
                    if triplet_key not in triplets:
                        triplets[triplet_key] = 0
    
                    triplets[triplet_key] += 1
    
                    if triplets[triplet_key] == best[0]:
                        if triplet_key < best[1]:
                         best[1] = triplet_key
                    elif triplets[triplet_key] > best[0]:
                        best[0] = triplets[triplet_key]
                        best[1] = triplet_key


    def construct_user_data(self, username: List[str], timestamp: List[int], website: List[str]) -> dict:
        N = len(username)
        res = {}  # userId : [(timestamp, website)]
    
        for i in range(N):
            if username[i] not in res:
                res[username[i]] = []
    
            res[username[i]].append((timestamp[i], website[i]))
    
        return res
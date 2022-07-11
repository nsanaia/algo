import java.util.*;


class CacheItem {
    int key;
    int value;
    CacheItem pre;
    CacheItem next;
    int useCount;
    
    public CacheItem(int key, int value) {
        this.key = key;
        this.value = value;
        this.useCount = 1;
    }
}

class UsageCountData {
    CacheItem start;
    CacheItem end;
    int size;
    
    public UsageCountData() {
        start = new CacheItem(0, 0);
        end = new CacheItem(0, 0);
        start.next = end;
        end.pre = start;
    }
    
    public void addItem(CacheItem item) {
        CacheItem pre = end.pre;
        pre.next = item;
        item.pre = pre;
        item.next = end;
        end.pre = item;
        size++;
    }
    
    public void removeItem(CacheItem item) {
        CacheItem pre = item.pre;
        pre.next = item.next;
        item.next.pre = pre;
        size--;
    }
    
    public CacheItem pollFirst() {
        CacheItem res = start.next;
        removeItem(res);
        return res;
    }
}


class LFUCache {
    
    int len;
    int capacity;
    Map<Integer, CacheItem> items;
    Map<Integer, UsageCountData> counts;
    int minUseCount;
    
    
    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.items = new HashMap<>();
        this.counts = new HashMap<>();
        this.minUseCount = 1;
    }
    
    public int get(int key) {
        if (!items.containsKey(key)) return -1;
        return getInternal(key).value;
    }
    
    public void put(int key, int value) {
        if (items.containsKey(key)) {
            CacheItem item = getInternal(key);
            item.value = value;
            return;
        }
        
        CacheItem newItem = new CacheItem(key, value);
        items.put(key, newItem);
        
        counts.putIfAbsent(1, new UsageCountData());
        counts.get(1).addItem(newItem);
        
        
        
        if (len >= capacity) {
            int k = counts.get(minUseCount).pollFirst().key;
            len--;
            items.remove(k);
        }   
        len++;
        
        
        minUseCount = 1;
    }
    
    
    private CacheItem getInternal(int key) {
        
        CacheItem item = items.get(key);
        UsageCountData oldUsageData = counts.get(item.useCount);
        oldUsageData.removeItem(item);
        
        
        item.useCount++;
        counts.putIfAbsent(item.useCount, new UsageCountData());   
        counts.get(item.useCount).addItem(item);
        
        if (item.useCount - 1 == minUseCount) {
            minUseCount = oldUsageData.size == 0 ? item.useCount : minUseCount;
        }
        
        return item;
    }
    
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
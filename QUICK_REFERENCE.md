# 🚀 Quick Reference Guide - Days 41-100

## 📌 Quick Access to All Topics

### 🔹 Queue & Stack
```c
// Day 41: Queue Using Linked List
gcc Day41/queue_using_linked_list.c -o queue && ./queue

// Day 42: Reverse Queue
gcc Day42/reverse_queue_using_stack.c -o revqueue && ./revqueue
```

### 🌳 Binary Trees
```c
// Day 43: Level Order Traversal
gcc Day43/binary_tree_level_order.c -o levelorder && ./levelorder

// Day 44: All Traversals
gcc Day44/binary_tree_traversals.c -o traversals && ./traversals

// Day 45: Tree Height
gcc Day45/height_of_binary_tree.c -o height && ./height

// Day 48: Count Leaf Nodes
gcc Day48/count_leaf_nodes.c -o leafcount && ./leafcount
```

### 🔍 Binary Search Tree
```c
// Day 49: BST Insert
gcc Day49/bst_insert.c -o bstinsert && ./bstinsert

// Day 50: BST Search
gcc Day50/bst_search.c -o bstsearch && ./bstsearch

// Day 51: Lowest Common Ancestor
gcc Day51/lowest_common_ancestor_bst.c -o lca && ./lca
```

### 📊 Graph Algorithms
```c
// Day 63: DFS Traversal
gcc Day63/dfs_graph_traversal.c -o dfs && ./dfs

// Day 64: BFS Traversal
gcc Day64/bfs_graph_traversal.c -o bfs && ./bfs

// Day 65: Cycle Detection
gcc Day65/cycle_detection_undirected.c -o cycle && ./cycle

// Day 69: Dijkstra's Algorithm
gcc Day69/dijkstra_algorithm.c -o dijkstra && ./dijkstra

// Day 70: Bellman-Ford
gcc Day70/bellman_ford.c -o bellman && ./bellman

// Day 80: Floyd-Warshall
gcc Day80/floyd_warshall.c -o floyd && ./floyd
```

### 🔎 Searching Algorithms
```c
// Day 81: Binary Search
gcc Day81/binary_search.c -o bsearch && ./bsearch

// Day 87: Koko Eating Bananas
gcc Day87/koko_eating_bananas.c -o koko && ./koko
```

### 📈 Sorting Algorithms
```c
// Day 91: Merge Sort
gcc Day91/merge_sort.c -o mergesort && ./mergesort

// Day 92: Quick Sort
gcc Day92/quick_sort.c -o quicksort && ./quicksort

// Day 93: Insertion Sort
gcc Day93/insertion_sort.c -o insertionsort && ./insertionsort

// Day 94: Counting Sort
gcc Day94/counting_sort.c -o countingsort && ./countingsort
```

### 🎯 Advanced Problems
```c
// Day 100: Count Inversions
gcc Day100/count_inversions.c -o inversions && ./inversions
```

## ⚡ Time Complexity Cheat Sheet

### Sorting Algorithms
| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) |

### Searching Algorithms
| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Linear Search | O(1) | O(n) | O(n) | O(1) |

### Graph Algorithms
| Algorithm | Time | Space |
|-----------|------|-------|
| DFS | O(V+E) | O(V) |
| BFS | O(V+E) | O(V) |
| Dijkstra | O(E log V) | O(V) |
| Bellman-Ford | O(VE) | O(V) |
| Floyd-Warshall | O(V³) | O(V²) |

### Tree Operations
| Operation | BST Average | BST Worst |
|-----------|-------------|-----------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Traversal | O(n) | O(n) |

## 🎓 Common Patterns

### 1. Binary Search Pattern
```c
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### 2. DFS Pattern
```c
void dfs(int node, int vis[], int adj[][MAX], int V) {
    vis[node] = 1;
    printf("%d ", node);
    for(int i = 0; i < V; i++) {
        if(adj[node][i] && !vis[i]) {
            dfs(i, vis, adj, V);
        }
    }
}
```

### 3. BFS Pattern
```c
void bfs(int start, int adj[][MAX], int vis[], int V) {
    int queue[MAX];
    int front = 0, rear = 0;
    vis[start] = 1;
    queue[rear++] = start;
    
    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for(int i = 0; i < V; i++) {
            if(adj[node][i] && !vis[i]) {
                vis[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
```

### 4. Tree Traversal Pattern
```c
void inorder(struct Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
```

## 🐛 Common Debugging Tips

### Memory Issues
```bash
# Check for memory leaks
gcc -g Day41/queue_using_linked_list.c -o queue
valgrind --leak-check=full ./queue
```

### Compilation Warnings
```bash
# Enable all warnings
gcc -Wall -Wextra -Werror Day41/queue_using_linked_list.c -o queue
```

### Optimization
```bash
# Optimize for speed
gcc -O2 Day91/merge_sort.c -o mergesort

# Optimize for size
gcc -Os Day91/merge_sort.c -o mergesort
```

## 📝 Testing Tips

### 1. Test Edge Cases
- Empty input
- Single element
- Duplicate elements
- Maximum/Minimum values
- Negative numbers

### 2. Test Different Sizes
- Small (n < 10)
- Medium (n = 100-1000)
- Large (n > 10000)

### 3. Test Special Cases
- Already sorted
- Reverse sorted
- All same elements
- Random order

## 🔗 Quick Links

- **LeetCode**: https://leetcode.com/problemset/all/
- **GeeksforGeeks**: https://www.geeksforgeeks.org/data-structures/
- **Visualgo**: https://visualgo.net/en (Algorithm Visualization)
- **C Reference**: https://en.cppreference.com/w/c

## 💡 Pro Tips

1. **Always initialize variables**
   ```c
   int vis[100] = {0};  // Good
   int vis[100];        // Bad - undefined values
   ```

2. **Check for NULL pointers**
   ```c
   if(root == NULL) return;  // Always check
   ```

3. **Free allocated memory**
   ```c
   int* arr = malloc(n * sizeof(int));
   // ... use arr ...
   free(arr);  // Don't forget!
   ```

4. **Use meaningful variable names**
   ```c
   int numberOfNodes;  // Good
   int n;              // Okay for small scope
   int x;              // Bad
   ```

5. **Comment complex logic**
   ```c
   // Calculate mid to avoid overflow
   int mid = low + (high - low) / 2;
   ```

## 🎯 Practice Strategy

### Week 1: Basics
- Days 41-50: Queue, Stack, Basic Trees

### Week 2: Trees
- Days 51-60: BST, Tree Problems

### Week 3: Graphs
- Days 61-70: Graph Traversal, Shortest Path

### Week 4: Advanced Graphs
- Days 71-80: MST, All-Pairs Shortest Path

### Week 5: Searching
- Days 81-90: Binary Search Variations

### Week 6: Sorting
- Days 91-100: Sorting Algorithms, Advanced Problems

## 📊 Progress Tracker

```
Day 41: ✅ Queue Using Linked List
Day 42: ✅ Reverse Queue
Day 43: ✅ Level Order Traversal
Day 44: ✅ Tree Traversals
Day 45: ✅ Tree Height
...
Day 100: ✅ Count Inversions
```

---

**Happy Coding! 🚀**

*Keep this guide handy for quick reference!*

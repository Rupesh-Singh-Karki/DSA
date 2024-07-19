#include <vector>
#include <unordered_map>
using namespace std;

long nearlySimilarRectangles(vector<vector<long>>& sides) {
    unordered_map<pair<long, long>, long, hash_pair> ratioCount;
    long ans = 0;
    
    for (auto& side : sides) {
        long gcd = __gcd(side[0], side[1]);
        long x = side[0] / gcd;
        long y = side[1] / gcd;
        ratioCount[{x, y}]++;
    }
    
    for (auto& entry : ratioCount) {
        long count = entry.second;
        if (count > 1) {
            ans += (count * (count - 1)) / 2;  // combination of 2 from count
        }
    }
    
    return ans;
}

// Helper function to compute the greatest common divisor
long __gcd(long a, long b) {
    if (b == 0) return a;
    return __gcd(b, a % b);
}

// Custom hash function for pairs
class hash_pair {
public:
    // Template definition for different types of pair elements
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        // Compute hash values for the first and second elements of the pair
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        /*
        1.std::hash<T1>{}:

        Creates a temporary instance of std::hash<T1>. This instance is an object capable of hashing values of type T1.
        2.(p.first):

        Calls the operator() function of the std::hash<T1> object, passing p.first as an argument. This function computes the hash value for p.first.
        */
        
        // Combine the two hash values using XOR
        return hash1 ^ hash2;  
    }
};

    /*
    Certainly! The `struct hash_pair` is a custom hash function used for hashing pairs in the `unordered_map`. In C++, `unordered_map` requires a hash function to compute the hash value for its keys, which allows for efficient storage and retrieval.

### Purpose of `hash_pair`

In the code, the key of the `unordered_map` is a `pair<long, long>`, representing a rectangle's aspect ratio in its simplest form. The default hash function in C++ doesn't handle pairs out of the box, so a custom hash function is needed to compute the hash value for `pair<long, long>`.

### Structure of `hash_pair`

Here's the `hash_pair` struct:

```cpp
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
```

### Explanation

1. **Template Definition:**
   - `template <class T1, class T2>`: This makes `hash_pair` a template struct, allowing it to handle pairs with any types `T1` and `T2`. In our case, `T1` and `T2` are both `long`.

2. **Function Operator:**
   - `size_t operator()(const pair<T1, T2>& p) const`: This defines the `operator()` function, which is called by `unordered_map` to compute the hash value for a given pair `p`.

3. **Hash Calculation:**
   - `auto hash1 = hash<T1>{}(p.first);`: Computes the hash value for the first element of the pair.
   - `auto hash2 = hash<T2>{}(p.second);`: Computes the hash value for the second element of the pair.

4. **Combining Hashes:**
   - `return hash1 ^ hash2;`: Combines the two hash values using the bitwise XOR operator (`^`). This is a simple way to mix the hash values of the two elements in the pair to generate a combined hash value.

### Why XOR?

The XOR operation is used here to combine the two hash values into a single hash value. It's a common technique because it provides a reasonable distribution of hash values for most cases. However, it's not the only method—other approaches include using prime numbers for combining hashes or other bitwise operations.

### Example

Let's say we have pairs `(2, 3)` and `(3, 2)`:

- **Hash for `(2, 3)`**
  - Compute `hash1` for `2` and `hash2` for `3`.
  - Combine them with XOR to get a single hash value.

- **Hash for `(3, 2)`**
  - Compute `hash1` for `3` and `hash2` for `2`.
  - Combine them with XOR to get a different hash value.

Using XOR ensures that `(2, 3)` and `(3, 2)` generally get different hash values, 
helping to maintain a good distribution in the `unordered_map`.

### Summary

The `hash_pair` struct provides a custom hash function for `pair<long, long>` that allows
 the `unordered_map` to handle pairs efficiently. By computing hash values for the individual
  elements and combining them using XOR, it ensures that each pair is hashed uniquely and 
  can be used effectively as a key in the hash map.
    */


//dry run
/*
### Simple Dry Run

Let's walk through the function with a sample input.

**Sample Input:**
```cpp
vector<vector<long>> sides = {{4, 6}, {2, 3}, {4, 8}, {6, 9}, {8, 12}};
```

**Step-by-Step Execution:**

1. **Initialization:**
   - `ratioCount` is an empty map.
   - `ans` is initialized to `0`.

2. **Processing Each Rectangle:**
   - For `{4, 6}`:
     - GCD of `4` and `6` is `2`.
     - Reduced ratio: `4 / 2 = 2`, `6 / 2 = 3`.
     - `ratioCount` becomes `{(2, 3): 1}`.
     
   - For `{2, 3}`:
     - GCD of `2` and `3` is `1`.
     - Reduced ratio: `2 / 1 = 2`, `3 / 1 = 3`.
     - `ratioCount` becomes `{(2, 3): 2}`.
     
   - For `{4, 8}`:
     - GCD of `4` and `8` is `4`.
     - Reduced ratio: `4 / 4 = 1`, `8 / 4 = 2`.
     - `ratioCount` becomes `{(2, 3): 2, (1, 2): 1}`.
     
   - For `{6, 9}`:
     - GCD of `6` and `9` is `3`.
     - Reduced ratio: `6 / 3 = 2`, `9 / 3 = 3`.
     - `ratioCount` becomes `{(2, 3): 3, (1, 2): 1}`.
     
   - For `{8, 12}`:
     - GCD of `8` and `12` is `4`.
     - Reduced ratio: `8 / 4 = 2`, `12 / 4 = 3`.
     - `ratioCount` becomes `{(2, 3): 4, (1, 2): 1}`.

3. **Counting Similar Pairs:**
   - For ratio `(2, 3)` with `4` rectangles:
     - Pairs: `4 * (4 - 1) / 2 = 6`.
   - For ratio `(1, 2)` with `1` rectangle:
     - Pairs: `1 * (1 - 1) / 2 = 0`.

   - Total pairs: `6 + 0 = 6`.

**Output:**
The function returns `6`, which is the number of pairs of rectangles with nearly similar ratios.

### Summary

The function efficiently determines the number of rectangle pairs with the same aspect ratio by:
1. Reducing each rectangle's ratio to its simplest form.
2. Counting occurrences of each ratio.
3. Calculating the number of pairs from these counts using combination formula.
*/

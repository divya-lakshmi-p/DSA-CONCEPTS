
## Arrays (Full Notes — Nothing Skipped)

### 1. What is an Array?

An **array** is a collection of elements of the **same data type**, stored in an ordered sequence and accessed using an index.

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

Conceptually:

```
Index:   0    1    2    3    4
Value:  10   20   30   40   50
```

**Why use an array?**

Without an array:

```cpp
int mark1 = 72;
int mark2 = 85;
int mark3 = 91;
int mark4 = 64;
```

With an array:

```cpp
int marks[4] = {72, 85, 91, 64};
```

Arrays allow us to store many related values under one name.

---

### 2. Why Does Array Indexing Start at 0?

The most useful way to understand this is:

**The index represents the offset (number of positions) from the beginning of the array.**

Suppose:

```
[10, 20, 30, 40, 50]
```

The first element is:

```
0 positions away from the beginning → index 0
```

The second:

```
1 position away → index 1
```

The third:

```
2 positions away → index 2
```

Therefore:

```
Index:   0    1    2    3    4
Value:  10   20   30   40   50
```

**Memory connection**

Memory is addressable in bytes.

If an `int` occupies 4 bytes and an array starts at address `1000`:

```
arr[0] → 1000
arr[1] → 1004
arr[2] → 1008
arr[3] → 1012
```

The general idea is:

```
address of arr[i]
=
base address + i × size of one element
```

For the first element:

```
base + 0 × element_size
= base
```

So zero-based indexing naturally represents **zero offset from the beginning**.

**Important**

For an array of size `n`:

```
Number of elements = n
First index        = 0
Last index         = n - 1
```

Example:

```
size = 5
indexes = 0,1,2,3,4
```

---

### 3. Contiguous Memory

Traditional arrays store their elements **contiguously**.

Contiguous means:

> The elements are stored in one continuous region of memory without gaps between their element-sized storage blocks.
> 

For:

```cpp
int arr[4] = {10,20,30,40};
```

Conceptually:

```
[ int ][ int ][ int ][ int ]
```

If each `int` takes 4 bytes:

```
1000 → 10
1004 → 20
1008 → 30
1012 → 40
```

This predictable layout is what allows direct index calculation.

---

### 4. Accessing an Array Element

```cpp
cout << arr[2];
```

This means: Access the element at index `2`.

Example:

```
arr = [10,20,30,40,50]

arr[2] = 30
```

**Time Complexity**

```
Access by index → O(1)
```

The computer can calculate the location directly.

---

### 5. Updating an Element

```cpp
arr[2] = 100;
```

Before:

```
[10,20,30,40,50]
```

After:

```
[10,20,100,40,50]
```

**Time Complexity**

```
Update by index → O(1)
```

---

### 6. Traversal

Traversal means visiting each element.

```cpp
for(int i = 0; i < n; i++)
{
    cout << arr[i] << " ";
}
```

Example:

```
i = 0 → arr[0]
i = 1 → arr[1]
i = 2 → arr[2]
...
i = n-1 → arr[n-1]
```

**Time Complexity**

```
O(n)
```

because every element is visited.

---

### 7. Search

**Linear Search**

If the array is unsorted:

```
[10, 20, 30, 40, 50]
```

To find `40`:

```
10 → no
20 → no
30 → no
40 → yes
```

**Complexity**

```
Worst case → O(n)
```

**Binary Search**

If the array is sorted, binary search can be used.

```
Time → O(log n)
```

---

### 8. Insertion

Suppose:

```
[10,20,30,40]
```

Insert `25` at index `2`.

Elements need to shift:

```
30 → right
40 → right
```

Result:

```
[10,20,25,30,40]
```

**Complexity**

```
Insert at beginning/middle → O(n)
Insert at end              → can be O(1) if space is available
```

---

### 9. Deletion

Suppose:

```
[10,20,30,40,50]
```

Delete `30`.

Elements after it shift left:

```
40 → left
50 → left
```

Result:

```
[10,20,40,50]
```

**Complexity**

```
Delete from beginning/middle → O(n)
```

because elements may need to shift.

---

### 10. Reverse

Example:

```
[1,2,3,4,5]
```

Result:

```
[5,4,3,2,1]
```

A common approach uses Two Pointers:

```cpp
int left = 0;
int right = n - 1;

while(left < right)
{
    swap(arr[left], arr[right]);
    left++;
    right--;
}
```

**Complexity**

```
Time  → O(n)
Space → O(1)
```

This is an **in-place** operation.

---

### 11. Swap

Swap means exchanging two values.

```cpp
swap(arr[i], arr[j]);
```

Conceptually:

```
A = 10
B = 20

After swap:
A = 20
B = 10
```

Swapping is commonly used in:

- Reverse
- Sorting
- Two Pointers
- Partitioning
- In-place algorithms

---

### 12. Find Maximum

Example:

```
[7,2,9,4,5]
```

Maintain:

```cpp
int maxi = arr[0];
```

Scan the array and update `maxi` whenever a larger value appears.

Result:

```
9
```

**Complexity**

```
O(n)
```

---

### 13. Find Minimum

Same idea as maximum.

```
[7,2,9,4,5]
```

Minimum:

```
2
```

**Complexity**

```
O(n)
```

---

### 14. Second Largest

Maintain two values:

```
largest
secondLargest
```

Example:

```
[10,5,20,8,15]
```

Final:

```
largest       = 20
secondLargest = 15
```

Important idea: When a new value becomes the largest, the old largest becomes the second largest.

**Complexity**

```
O(n)
```

A good implementation should also decide how duplicates are handled, depending on the problem statement.

---

### 15. Sum

Example:

```
[2,4,6,8]
```

```
sum = 2 + 4 + 6 + 8
    = 20
```

Typical implementation:

```cpp
int sum = 0;

for(int i = 0; i < n; i++)
{
    sum += arr[i];
}
```

**Complexity**

```
O(n)
```

---

### 16. Average

Formula:

```
average = sum / number of elements
```

Example:

```
[2,4,6,8]

sum = 20
count = 4

average = 20 / 4 = 5
```

In C++, use floating-point division when needed:

```cpp
double avg = (double)sum / n;
```

---

### 17. Frequency / Count

Frequency means: How many times each value appears?

Example:

```
[1,2,2,3,1,2]
```

Frequency:

```
1 → 2
2 → 3
3 → 1
```

Common approaches:

- Nested loops
- Sorting
- `map`
- `unordered_map`

Hashing is especially useful when frequent lookup/counting is required.

---

### 18. In-Place Modification

**In-place** means modifying the existing array instead of creating another array for the main operation.

Example:

```
[1,2,3,4]
```

Reverse directly:

```
[4,3,2,1]
```

No separate array is required.

Typical extra space:

```
O(1)
```

Examples you have practiced:

- Reverse Array
- Remove Duplicates
- Move Zeroes

---

### 19. Nested Loops

Example:

```cpp
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        // work
    }
}
```

The inner loop runs for each `i`.

Approximate work:

```
n × n = n²
```

Therefore:

```
O(n²)
```

Three nested loops:

```
O(n³)
```

Four nested loops:

```
O(n⁴)
```

Your brute-force solutions for **3Sum** and **4Sum** are examples.

---

### 20. Sorting + Arrays

Sorting can create useful structure.

Example:

```
[5,1,4,2,3]
```

After sorting:

```
[1,2,3,4,5]
```

Once sorted, we can use:

- Binary Search
- Two Pointers
- Duplicate skipping
- Greedy approaches

Important idea: Sorting is often used to make another algorithm possible or easier.

Examples:

- 2Sum using Two Pointers
- 3Sum
- 3Sum Closest
- 4Sum

---

### 21. Two Pointers

Two Pointers means using two moving positions according to a specific rule.

**Opposite-direction pattern**

```
left →       ← right
```

Examples:

- Reverse Array
- 2Sum on sorted array
- Container With Most Water
- 3Sum
- 4Sum

**Same-direction / Read-Write pattern**

```
slow →
fast  →
```

Examples:

- Remove Duplicates
- Move Zeroes

**Important rule**

Do not define Two Pointers as simply:

```
"left goes right and right goes left"
```

Instead ask:

1. What does each pointer represent?
2. What makes it move?
3. Why is that movement safe?
4. What possibilities does the movement eliminate?

---

### 22. Sliding Window

Sliding Window is a special use of moving pointers where the region between `left` and `right` represents a **contiguous window**.

```
left              right
 ↓                   ↓
[ 2 ][ 1 ][ 5 ][ 1 ][ 3 ]
 └─────────────────────┘
          WINDOW
```

Typical movement:

```
right++ → expand
left++  → shrink
```

The important idea: Maintain information about the current window instead of recalculating the entire subarray repeatedly.

Examples:

- Fixed-size window
- Maximum sum of K
- Minimum-size valid subarray
- Longest valid subarray
- String Sliding Window

---

### 23. Prefix Sum

Prefix Sum stores cumulative information from the beginning.

Example:

```
arr = [2,4,3,5]
```

Prefix sum:

```
[2,6,9,14]
```

Meaning:

```
prefix[0] = 2
prefix[1] = 2 + 4 = 6
prefix[2] = 2 + 4 + 3 = 9
prefix[3] = 2 + 4 + 3 + 5 = 14
```

For a range:

```
sum(l...r)
```

we can use:

```
prefix[r] - prefix[l-1]
```

with special handling when `l = 0`.

**Main idea**

Precompute cumulative information so repeated range queries become faster.

---

### 24. Suffix

Suffix means information accumulated from the end.

Example:

```
arr = [2,4,3,5]
```

A suffix-product representation could be:

```
[60,30,15,5]
```

Suffix information is useful when a problem asks about: Everything to the right of the current element.

Example: **Product Except Self** can be solved using:

```
prefix product × suffix product
```

---

### 25. Difference Array

Difference Array is useful for many range updates.

Suppose:

```
arr = [0,0,0,0,0]
```

Add `5` to indexes `1` through `3`.

Instead of immediately modifying all positions, mark the boundaries:

```
diff[1] += 5
diff[4] -= 5
```

Then prefix accumulation reconstructs the final values.

**Main idea**

> Mark where an effect starts and where it stops, then use prefix accumulation to spread the effect.
> 

---

### 26. Hashing

Hashing allows efficient lookup and frequency tracking.

Example:

```
arr = [2,7,2,5,7,2]
```

Frequency map:

```
2 → 3
7 → 2
5 → 1
```

With `unordered_map`, lookup is expected:

```
O(1)
```

Hashing is useful in:

- Two Sum
- Frequency Counting
- Longest Subarray Sum K
- Intersection of Arrays
- Sliding Window

---

### 27. 2D Arrays

A 2D array is naturally viewed as a **table of rows and columns**.

```cpp
int arr[3][4];
```

means:

```
3 rows
4 columns
```

Visual:

```
        Column
        0  1  2  3
      +--+--+--+--+
Row 0|  |  |  |  |
      +--+--+--+--+
Row 1|  |  |  |  |
      +--+--+--+--+
Row 2|  |  |  |  |
      +--+--+--+--+
```

Total elements:

```
3 × 4 = 12
```

---

### 28. 2D Indexing

```cpp
arr[i][j]
```

means:

```
i → row
j → column
```

Example:

```cpp
int arr[3][3] =
{
    {10,20,30},
    {40,50,60},
    {70,80,90}
};
```

Then:

```
arr[0][0] = 10
arr[0][1] = 20
arr[1][2] = 60
arr[2][1] = 80
```

Read:

```
arr[i][j]
= go to row i
  then column j
```

---

### 29. 2D Traversal

To visit every element:

```cpp
for(int i = 0; i < rows; i++)
{
    for(int j = 0; j < cols; j++)
    {
        cout << arr[i][j] << " ";
    }
}
```

Traversal order:

```
row 0 → all columns
row 1 → all columns
row 2 → all columns
```

**Complexity**

```
O(rows × cols)
```

---

### 30. Row Sum

To find the sum of a particular row:

```
Fix row
Change column
```

Example:

```
1 2 3
4 5 6
7 8 9
```

Row 1:

```
4 + 5 + 6 = 15
```

Code idea:

```cpp
for(int j = 0; j < cols; j++)
{
    sum += arr[1][j];
}
```

**Rule**

```
Row:
fix i
change j
```

---

### 31. Column Sum

To find a particular column:

```
Fix column
Change row
```

For column 1:

```
2
5
8
```

Sum:

```
15
```

Code idea:

```cpp
for(int i = 0; i < rows; i++)
{
    sum += arr[i][1];
}
```

**Rule**

```
Column:
fix j
change i
```

---

### 32. 2D Array Memory

C/C++ traditional 2D arrays use a contiguous memory layout in **row-major order**.

Example:

```
1 2 3
4 5 6
7 8 9
```

Conceptually the values are laid out as:

```
1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9
```

So logically it looks like a table, while its storage is organized sequentially.

---

### 33. 2D Array Using **`vector`**

Modern C++ often uses:

```cpp
vector<vector<int>> arr(3, vector<int>(4, 0));
```

This creates:

```
3 rows
4 columns
```

all initialized to `0`.

Conceptually:

```
[0,0,0,0]
[0,0,0,0]
[0,0,0,0]
```

Access remains:

```cpp
arr[i][j]
```

---

### 34. Matrix Transpose

Original:

```
1 2 3
4 5 6
```

Transpose:

```
1 4
2 5
3 6
```

Concept:

```
row becomes column
column becomes row
```

The relationship is:

```
arr[i][j] ↔ arr[j][i]
```

for a suitable square-matrix in-place transpose.

---

### 35. Matrix Rotation

A common 90° clockwise rotation strategy for a square matrix is:

```
Transpose
+
Reverse every row
```

Example:

```
Original:

1 2 3
4 5 6
7 8 9
```

After 90° clockwise rotation:

```
7 4 1
8 5 2
9 6 3
```

---

### 36. Multidimensional Arrays

A 3D array adds another dimension.

```cpp
int arr[2][3][4];
```

means:

```
2 layers
3 rows per layer
4 columns per row
```

Total elements:

```
2 × 3 × 4 = 24
```

Think of it as:

```
Layer 0

[ ][ ][ ][ ]
[ ][ ][ ][ ]
[ ][ ][ ][ ]

Layer 1

[ ][ ][ ][ ]
[ ][ ][ ][ ]
[ ][ ][ ][ ]
```

Access:

```cpp
arr[layer][row][column]
```

Example:

```cpp
arr[1][2][3]
```

means:

```
layer = 1
row   = 2
column = 3
```

---

### 37. Traversing a 3D Array

```cpp
for(int i = 0; i < x; i++)
{
    for(int j = 0; j < y; j++)
    {
        for(int k = 0; k < z; k++)
        {
            cout << arr[i][j][k];
        }
    }
}
```

**Complexity**

```
O(x × y × z)
```

General idea:

```
1D → arr[i]
2D → arr[i][j]
3D → arr[i][j][k]
4D → arr[i][j][k][l]
```

---

### 38. Static vs Dynamic Arrays

**Static / fixed-size array**

```cpp
int arr[5];
```

The size is fixed.

You cannot resize the built-in array itself.

**Dynamic array / `vector`**

```cpp
vector<int> arr;
```

It can grow and shrink.

Example:

```cpp
arr.push_back(10);
arr.push_back(20);
arr.push_back(30);
```

**C-style array vs vector**

```
C-style array:
int arr[5];

vector:
vector<int> arr;
```

C-style arrays do not provide:

```cpp
arr.begin()
arr.end()
arr.size()
```

A `vector` does.

Therefore:

```cpp
sort(arr, arr + n);          // C-style array

sort(arr.begin(), arr.end()); // vector
```

---

### 39. Important Array Complexities

Operation: Typical Complexity

- Access by index → O(1)
- Update by index → O(1)
- Traversal → O(n)
- Linear Search → O(n)
- Binary Search on sorted array → O(log n)
- Insert in middle → O(n)
- Delete in middle → O(n)
- Reverse → O(n)
- Find max/min → O(n)
- Sum → O(n)
- Sorting → O(n log n) for comparison-based sorting such as `std::sort`

---

### 40. Must-Know Array Problems

**Reverse Array**

Pattern:

```
Two Pointers
```

**Rotate Array**

Pattern:

```
Index manipulation
+
Reverse technique
```

**Move Zeroes**

Pattern:

```
Read/Write Two Pointers
```

**Remove Duplicates from Sorted Array**

Pattern:

```
Read/Write Two Pointers
```

**Missing Number**

Common ideas:

```
Sum
XOR
Index relationships
```

**Duplicate Number**

Possible approaches:

```
Hashing
Sorting
Fast/Slow Pointers
```

**Two Sum**

Possible approaches:

```
Brute Force
HashMap
Sorting + Two Pointers
```

**Best Time to Buy and Sell Stock**

Core idea:

```
Track minimum price seen so far
+
Track maximum profit
```

**Kadane's Algorithm**

Core idea:

```
Maintain current subarray sum
+
Maintain best sum so far
```

Conceptually: If the current accumulated sum becomes harmful, discard that previous contribution and start fresh from the current element.

---

### 41. Pattern Recognition

When you receive an array problem, don't immediately start coding.

Ask:

**Is it simply asking me to visit elements?**

```
Traversal
```

**Do I need every pair?**

```
Nested loops
or
Two Pointers
```

**Is the array sorted?**

```
Binary Search
Two Pointers
```

**Is it asking about a contiguous range?**

```
Subarray
Prefix Sum
Sliding Window
```

**Do I need cumulative information?**

```
Prefix / Suffix
```

**Are there repeated range updates?**

```
Difference Array
```

**Do I need frequencies or fast lookup?**

```
Hashing
```

**Is there an in-place requirement?**

```
Read/Write Two Pointers
Swapping
```

---

### 42. Important Mental Model

The goal of learning Arrays is not just: "I know array syntax."

The real goal is:

**"I can look at an array problem, recognize its structure, and choose the appropriate pattern."**

A useful mapping is:

```
Array
│
├── Simple scan
│   └── Traversal
│
├── Every pair
│   └── Nested loops / Two Pointers
│
├── Contiguous range
│   └── Subarray / Prefix Sum / Sliding Window
│
├── Cumulative information
│   └── Prefix / Suffix
│
├── Many range updates
│   └── Difference Array
│
├── Frequency / lookup
│   └── Hashing
│
├── Sorted structure
│   └── Binary Search / Two Pointers
│
└── In-place transformation
    └── Two Pointers / Swapping
```

---

### 43. Teach-Someone-Else Explanation

**What is an array?** An array is a collection of elements of the same type stored in an ordered sequence. Each element is accessed using an index, and indexing starts at 0 because the index represents the offset from the beginning of the array.

**Why is access O(1)?** Because array elements are stored in a predictable contiguous layout. The computer can calculate the address of element `i` directly using the base address and the element size.

**Why is insertion in the middle O(n)?** Because elements after the insertion point may need to shift to create space.

**Why is deletion in the middle O(n)?** Because elements after the deleted position may need to shift left to fill the gap.

**What is a 2D array?** A 2D array is a table-like structure with rows and columns. `arr[i][j]` means row `i`, column `j`.

**What is a 3D array?** A 3D array can be thought of as a collection of 2D tables. `arr[i][j][k]` represents a layer, row, and column.

**What is the most important DSA skill from Arrays?** Recognizing the structure of the problem and choosing a suitable pattern such as Two Pointers, Sliding Window, Prefix Sum, Difference Array, Sorting, or Hashing.

---

### 44. Final Revision Cheat Sheet

```
ARRAY
→ collection of same-type elements

INDEX
→ offset from beginning
→ starts at 0
→ last index = n-1

ACCESS
→ O(1)

TRAVERSAL
→ O(n)

SEARCH
→ linear O(n)
→ binary O(log n) if sorted

INSERT / DELETE IN MIDDLE
→ O(n)

REVERSE
→ Two Pointers
→ O(n), O(1) extra space

2D ARRAY
→ rows × columns
→ arr[i][j]
→ i = row
→ j = column

3D ARRAY
→ layer × row × column
→ arr[i][j][k]

ROW OPERATION
→ fix i, change j

COLUMN OPERATION
→ fix j, change i

PREFIX
→ cumulative information from left

SUFFIX
→ cumulative information from right

DIFFERENCE ARRAY
→ mark range start/end
→ prefix accumulation reconstructs result

HASHING
→ frequency / fast lookup

TWO POINTERS
→ two moving positions
→ movement must have a reason

SLIDING WINDOW
→ contiguous moving range

NESTED LOOPS
→ O(n²), O(n³), ...

SORTING
→ usually O(n log n)
→ often enables Two Pointers
```

</aside>

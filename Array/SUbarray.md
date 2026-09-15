# Subarray — Complete Interview Notes

## 1. What is a Subarray?

A **subarray** is a **contiguous part of an array**.

Contiguous means:

> Elements must be next to each other. We cannot skip elements.

Example:

```text
Array = [1, 2, 3, 4]
```

Valid subarrays:

```text
[1]
[1, 2]
[1, 2, 3]
[1, 2, 3, 4]

[2]
[2, 3]
[2, 3, 4]

[3]
[3, 4]

[4]
```

Invalid:

```text
[1, 3]      ❌
[1, 4]      ❌
[2, 4]      ❌
```

because elements were skipped.

---

# 2. Subarray vs Subsequence vs Subset

| Concept     | Contiguous? | Order matters? |
| ----------- | ----------- | -------------- |
| Subarray    | ✅ Yes       | ✅ Yes          |
| Subsequence | ❌ No        | ✅ Yes          |
| Subset      | ❌ No        | ❌ Usually no   |

Example:

```text
[1, 2, 3, 4]
```

`[2, 3]` → subarray ✅

`[1, 3]` → subsequence ✅ but not subarray

`{1, 4}` → subset ✅

---

# 3. How to Identify a Subarray

A subarray can always be represented using two boundaries:

```text
arr[left ... right]
```

Think of it as a highlighted portion of the array.

```text
[2  3  1  2  4  3]
    └────────┘
     subarray
```

Here:

```text
left = 1
right = 4
```

The subarray is:

```text
[3, 1, 2, 4]
```

This `left/right` idea becomes extremely important for:

* Brute force
* Prefix Sum
* Two Pointers
* Sliding Window

---

# 4. Number of Subarrays

For an array of size `n`:

```text
Number of subarrays = n(n + 1) / 2
```

Why?

For every starting position:

```text
start = 0 → n possible endings
start = 1 → n-1 possible endings
start = 2 → n-2 possible endings
...
```

So:

```text
n + (n-1) + (n-2) + ... + 1
```

Therefore:

```text
n(n+1)/2
```

Example:

```text
n = 4

4 × 5 / 2 = 10
```

There are exactly 10 subarrays.

---

# 5. Generate All Subarrays — Brute Force

Use two loops to **select** every subarray:

```cpp
for(int i = 0; i < n; i++)
{
    for(int j = i; j < n; j++)
    {
        // subarray is arr[i...j]
    }
}
```

Important:

```text
i → starting index
j → ending index
```

For:

```text
[1, 2, 3, 4]
```

we get:

```text
i = 0
    j = 0 → [1]
    j = 1 → [1,2]
    j = 2 → [1,2,3]
    j = 3 → [1,2,3,4]

i = 1
    j = 1 → [2]
    j = 2 → [2,3]
    j = 3 → [2,3,4]

...
```

---

# 6. Why Sometimes We Need a Third Loop

If we want to **print every element** of each subarray:

```cpp
for(int i = 0; i < n; i++)
{
    for(int j = i; j < n; j++)
    {
        for(int k = i; k <= j; k++)
        {
            cout << arr[k] << " ";
        }

        cout << endl;
    }
}
```

Think:

```text
i + j → select the subarray
k     → visit/print its elements
```

Important complexity distinction:

```text
Selecting all subarrays → O(n²)

Printing every element of every subarray → O(n³)
```

The fact that there are 3 loops does not automatically mean O(n³), but in this case the total work is indeed O(n³).

---

# 7. Running Sum — First Important Optimization

Suppose we want the sum of every subarray.

A bad approach is to calculate the entire sum again using another loop.

Instead:

```cpp
for(int i = 0; i < n; i++)
{
    int sum = 0;

    for(int j = i; j < n; j++)
    {
        sum += arr[j];

        cout << sum << endl;
    }
}
```

Why does this work?

For:

```text
[1, 2, 3, 4]
```

Starting at `i = 0`:

```text
j = 0 → sum = 1
j = 1 → sum = 1 + 2 = 3
j = 2 → sum = 3 + 3 = 6
j = 3 → sum = 6 + 4 = 10
```

We don't recalculate the previous elements.

This is the first important idea:

> When a subarray expands by one element, update the existing result instead of recalculating everything.

---

# 8. Common Subarray Questions

Before choosing an algorithm, identify exactly what the problem is asking.

### A. Generate / Print

Examples:

* Print all subarrays
* Count all subarrays

Usually:

```text
Two loops
```

---

### B. Maximum Sum

> Find the contiguous subarray with maximum sum.

Think:

```text
Kadane's Algorithm
```

---

### C. Minimum Sum

Can often be approached using a similar idea to Kadane, depending on the exact problem.

---

### D. Fixed Size K

Example:

> Find maximum sum of a subarray of size `K`.

Think:

```text
Fixed Sliding Window
```

Window:

```text
[left ... right]
```

with:

```text
window size = K
```

---

### E. Exact Sum K

Example:

> Find whether a subarray has sum exactly K.

The technique depends on the array.

For **positive numbers**:

```text
Sliding Window
```

For **positive + negative numbers**:

```text
Prefix Sum + HashMap
```

---

### F. Longest Subarray With Sum K

For positive numbers:

```text
Sliding Window
```

For arbitrary integers:

```text
Prefix Sum + HashMap
```

---

### G. Shortest Subarray

For positive numbers and suitable conditions:

```text
Sliding Window
```

For harder cases involving negative numbers:

```text
Prefix Sum + Deque
```

---

### H. Count Subarrays With Sum K

Usually:

```text
Prefix Sum + HashMap
```

---

# 9. Sliding Window

Sliding Window is basically a technique for maintaining a **contiguous range**.

We use:

```text
left
right
```

and maintain some information about:

```text
arr[left ... right]
```

For example:

```text
[2 3 1 2 4 3]
 ↑       ↑
left    right
```

The window is:

```text
[2, 3, 1, 2, 4]
```

---

## Sliding Window Mental Model

There are two basic actions:

```text
right → expand the window
left  → shrink the window
```

When expanding:

```cpp
sum += arr[right];
```

When shrinking:

```cpp
sum -= arr[left];
left++;
```

The key idea:

> Don't throw away the work already done. Adjust the existing window.

---

# 10. Fixed-Size Sliding Window

If the problem says:

> "Subarray of size K"

the window size must always be:

```text
right - left + 1 = K
```

Example:

```text
arr = [2, 1, 5, 1, 3, 2]
K = 3
```

Windows:

```text
[2, 1, 5]
[1, 5, 1]
[5, 1, 3]
[1, 3, 2]
```

Instead of recalculating each sum:

```text
2 + 1 + 5
1 + 5 + 1
5 + 1 + 3
...
```

we slide:

```text
old sum
- leaving element
+ entering element
= new sum
```

Example:

```text
[2,1,5] → sum = 8
```

Move one position:

```text
8 - 2 + 1 = 7
```

New window:

```text
[1,5,1]
```

---

# 11. Variable-Size Sliding Window

Here the window size changes.

General pattern:

```cpp
for(int right = 0; right < n; right++)
{
    // expand
    add arr[right];

    while(condition is invalid)
    {
        // shrink
        remove arr[left];
        left++;
    }

    // process valid window
}
```

For positive numbers and target sum `K`:

```text
sum < K → expand

sum > K → shrink

sum == K → valid answer
```

---

# 12. Why Sliding Window Works for Positive Numbers

This is extremely important.

With positive numbers:

```text
Adding an element → sum increases

Removing an element → sum decreases
```

Therefore we can safely reason:

```text
sum too small
    ↓
expand

sum too large
    ↓
shrink
```

Example:

```text
[2, 3, 1, 2]
sum = 8
K = 7
```

Since:

```text
8 > 7
```

remove from left:

```text
8 - 2 = 6
```

Now:

```text
6 < 7
```

So expand again.

---

# 13. Important Sliding Window Limitation

Do NOT automatically use Sliding Window for every subarray problem.

With negative numbers, the sum is no longer predictable.

Example:

```text
[5, -10, 8]
```

Adding an element can decrease the sum.

Therefore the simple rule:

```text
sum > K → shrink
sum < K → expand
```

is not generally safe.

For arbitrary integers and exact sum problems, think:

```text
Prefix Sum + HashMap
```

---

# 14. Prefix Sum

Prefix Sum stores cumulative sums.

Example:

```text
arr = [2, 3, 1, 4]
```

Prefix sums:

```text
0
2
5
6
10
```

Think of them as checkpoints:

```text
Start
  ↓
0 → 2 → 5 → 6 → 10
```

To find the sum of a subarray between two checkpoints:

```text
current prefix - previous prefix
```

Example:

```text
[3, 1]
```

The prefix before it is:

```text
2
```

The prefix after it is:

```text
6
```

Therefore:

```text
6 - 2 = 4
```

---

# 15. Prefix Sum + HashMap for Sum K

We want:

```text
subarray sum = K
```

We know:

```text
currentPrefix - previousPrefix = K
```

Rearrange:

```text
previousPrefix = currentPrefix - K
```

So at every position we ask:

> "Have I seen a previous prefix sum equal to `currentPrefix - K`?"

If yes, we found a subarray.

Important:

```text
HashMap does NOT store subarrays.

It stores previous prefix information.
```

---

# 16. Counting Subarrays With Sum K

For counting:

```cpp
unordered_map<int, int> mp;

mp[0] = 1;
```

Then:

```cpp
prefix += arr[i];

int need = prefix - K;

if(mp.find(need) != mp.end())
{
    count += mp[need];
}

mp[prefix]++;
```

Why `mp[0] = 1`?

Because before the array begins, the prefix sum is:

```text
0
```

There is one such prefix.

---

# 17. Counting Even-Sum Subarrays

This is a special Prefix Sum idea.

We don't care about the exact prefix sum.

We only care whether it is:

```text
Even
or
Odd
```

For a subarray to have an even sum:

```text
Even - Even = Even
Odd  - Odd  = Even
```

Therefore:

```text
same parity prefix + same parity prefix
                ↓
          even-sum subarray
```

So we count:

```text
number of even prefixes
number of odd prefixes
```

Important:

> We are NOT counting odd-sum subarrays when we use the odd-prefix count.

We are counting **pairs of odd prefixes**, whose difference is even.

---

# 18. Longest vs Shortest vs One

Always read the wording carefully.

### One valid subarray

```text
Find ONE
```

Once found:

```text
stop
```

---

### Longest valid subarray

```text
Find the maximum length
```

Keep searching.

Maintain:

```cpp
maxlength = max(maxlength, currentLength);
```

---

### Shortest valid subarray

```text
Find the minimum length
```

Keep searching.

Maintain:

```cpp
minlength = min(minlength, currentLength);
```

---

# 19. Window Length

If the window boundaries are inclusive:

```text
left ... right
```

then:

```text
length = right - left + 1
```

Why `+1`?

Example:

```text
left = 2
right = 4
```

Indexes:

```text
2, 3, 4
```

There are 3 elements.

```text
4 - 2 + 1 = 3
```

---

# 20. The Most Important Subarray Recognition Table

| Problem wording                                  | First technique to think about |
| ------------------------------------------------ | ------------------------------ |
| Print all subarrays                              | Two loops                      |
| Count all subarrays                              | `n(n+1)/2`                     |
| Sum every subarray                               | Running sum                    |
| Maximum subarray sum                             | Kadane                         |
| Minimum subarray sum                             | Kadane-style minimum           |
| Fixed size K                                     | Sliding Window                 |
| Maximum sum of size K                            | Fixed Sliding Window           |
| Minimum sum of size K                            | Fixed Sliding Window           |
| Positive numbers + sum K                         | Sliding Window                 |
| Positive numbers + longest sum K                 | Sliding Window                 |
| Positive numbers + shortest condition            | Sliding Window                 |
| Arbitrary integers + exact sum K                 | Prefix Sum + HashMap           |
| Count subarrays with sum K                       | Prefix Sum + HashMap           |
| Longest subarray with sum K + arbitrary integers | Prefix Sum + HashMap           |
| Difficult shortest subarray with negatives       | Prefix Sum + Deque             |

---

# 21. The Core Mental Model

When you see:

> **Subarray**

First think:

```text
CONTIGUOUS
```

Then ask:

### Question 1

What is the problem asking me to find?

```text
sum?
count?
maximum?
minimum?
length?
one valid range?
all ranges?
```

### Question 2

What are the constraints?

Especially:

```text
positive numbers?
negative numbers?
fixed K?
```

### Question 3

Choose the technique.

```text
Brute Force
    ↓
Running Sum
    ↓
Prefix Sum
    ↓
Sliding Window
    ↓
Prefix Sum + HashMap
    ↓
More advanced techniques
```

---

# 22. Most Important Things to Remember

Don't memorize solutions. Remember these ideas:

```text
1. Subarray = contiguous range.

2. Represent it using left and right boundaries.

3. i = start, j = end in basic brute force.

4. Running sum avoids recalculating a subarray's sum.

5. Sliding Window keeps a moving contiguous range.

6. right expands the window.

7. left shrinks the window.

8. Window length = right - left + 1.

9. Sliding Window is especially useful with positive numbers.

10. Prefix Sum converts a subarray sum into a difference
    between two prefix sums.

11. Sum K:
    currentPrefix - previousPrefix = K

12. Therefore:
    previousPrefix = currentPrefix - K

13. HashMap stores previous prefix information,
    not subarrays.

14. "ONE" answer → stop when found.

15. "LONGEST" → keep maximum length.

16. "SHORTEST" → keep minimum length.

17. Don't force Sliding Window onto problems where
    negative numbers destroy the needed monotonic behavior.
```

# Subarray Problem-Solving Formula

When you see a new subarray problem, ask:

```text
              SUBARRAY
                  ↓
          Is it contiguous?
                  ↓
                 YES
                  ↓
        What exactly is asked?
                  ↓
      ┌───────────┼───────────┐
      ↓           ↓           ↓
     SUM         COUNT       LENGTH
      ↓           ↓           ↓
   What are the constraints?
      ↓
 ┌────┴───────────────┐
 ↓                    ↓
Positive           Negative/
numbers            arbitrary
 ↓                    ↓
Sliding Window    Prefix Sum +
                  HashMap
```

The biggest skill is not memorizing:

```text
"Use Sliding Window here."
```

The skill is learning to recognize **why** Sliding Window is safe and **when it is not**.





































- An array is a subarray of itself
- An empty array is a sub array of all the arrays
- A single element is also a sub array

A **subarray** is a contiguous portion of an array.

**Contiguous = elements must be next to each other.**

Example:

```
A = [1, 2, 3, 4]
```

Valid subarrays:

```
[1]
[2]
[3]
[4]

[1,2]
[2,3]
[3,4]

[1,2,3]
[2,3,4]

[1,2,3,4]
```

**A subarray usually represents as start and end** 

### ⭐ Important Formula

```
length = end - start + 1
```

Number of subarrays = n(n+1)/2

# Generate All Subarrays

## C++

```
for(intstart =0;start<n;start++)
{for(intend =start;end<n;end++)
    {// subarray = arr[start ... end]
    }
}
```

## Java

```
for(intstart=0;start<n;start++)
{for(intend=start;end<n;end++)
    {// subarray = arr[start ... end]
    }
}
```

# Print Every Subarray

## C++

```
for(intstart =0;start<n;start++)
{for(intend =start;end<n;end++)
    {for(intk =start;k<=end;k++)
        {cout<<arr[k]<<" ";
        }cout<<endl;
    }
}
```

## Java

```
for(intstart=0;start<n;start++)
{for(intend=start;end<n;end++)
    {for(intk=start;k<=end;k++)
        {System.out.print(arr[k]+" ");
        }System.out.println();
    }
}
```

<aside>
📦

**In a fixed-size window of length k, if the start index is i, then the end index is i + k − 1.**

**For the window to fit in the array (last index = n − 1):**

i + k − 1 ≤ n − 1  ⇒  i ≤ n − k

**So the maximum valid start index is n − k.**

</aside>

how the i+k-1 come is , for example if k length is 5 array is having 10 elements 

if i is in 5th postion then we have remaing 5 elements only because k is 5 usua;lly array index will sop at n-1 which means in the 9th index itself , thats why i=5+k=5-1 which means 10-1=9 it will stop in the end of the array

# Sum of Every Subarray — Basic Approach

```
for(intstart =0;start<n;start++)
{intsum =0;for(intend =start;end<n;end++)
    {sum+=arr[end];cout<<sum<<endl;
    }
}
```

# Maximum Subarray Sum — Brute Force

```
intmaxi =INT_MIN;for(intstart =0;start<n;start++)
{intsum =0;for(intend =start;end<n;end++)
    {sum+=arr[end];maxi =max(maxi,sum);
    }
}
```

Java:

```
intmaxi=Integer.MIN_VALUE;for(intstart=0;start<n;start++)
{intsum=0;for(intend=start;end<n;end++)
    {sum+=arr[end];maxi=Math.max(maxi,sum);
    }
}
```

Complexity:

```
Time  = O(n²)
Space = O(1)
```

# Three Important Subarray Patterns

You should recognize these immediately.

### Pattern 1 — Generate subarrays

```
start
  ↓
end
```

```
for(start)
{for(end)
    {
    }
}
```

Usually:

```
O(n²)
```

---

### Pattern 2 — Generate + calculate incrementally

```
for(start)
{sum =0;for(end)
    {sum+=arr[end];
    }
}
```

Usually:

```
O(n²)
```

This is better than using a third loop.

---

### Pattern 3 — Fixed-size window

```
for(start =0;start<=n-k;start++)
{// window of length k
}
```

This leads directly to:

> **Sliding Window**
> 

# Your Subarray Formula Cheat Sheet

Put this at the **top of your Notion page** and `README.md`.

```
╔══════════════════════════════════════╗
║         SUBARRAY CHEAT SHEET         ║
╠══════════════════════════════════════╣
║ Subarray = contiguous elements       ║
║                                      ║
║ Start = i                             ║
║ End = j                               ║
║ Length = j - i + 1                   ║
║                                      ║
║ Given start i and length k:           ║
║ End = i + k - 1                      ║
║                                      ║
║ All subarrays:                       ║
║ n(n+1)/2                             ║
║                                      ║
║ Fixed length k:                      ║
║ Number = n-k+1                       ║
║                                      ║
║ Fixed-size start condition:          ║
║ i <= n-k                             ║
╚══════════════════════════════════════╝
```

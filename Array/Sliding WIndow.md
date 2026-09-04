SLIDING WINDOW

What?
A technique for maintaining a contiguous section
of an array/string using two pointers.

Window:
arr[left ... right]

Pointers:
left  = start of window
right = end of window

Expand:
right++

Shrink:
left++

Window size:
right - left + 1

Main idea:
Don't recalculate the whole window.
Reuse previous window's work.

Typical flow:

Expand
   ↓
add new right element
   ↓
check condition
   ↓
update answer when appropriate
   ↓
shrink if needed
   ↓
continue

Two major types:

1. Fixed-size window
   → window size = k

2. Variable-size window
   → size changes based on condition

Time:
Usually O(n)

Why?
left and right move forward at most O(n) times each.

Important:
Sliding Window = Two Pointers + contiguous window

1. What is Two Pointers?

        Two Pointers = use two indexes to scan/manage an array or string without repeatedly checking the same elements.

        int left = 0;
        int right = n - 1;

        The pointers can move:
          Opposite direction →  L →       ← R
          Same direction     →  L → R →
Main goal

        Reduce unnecessary/repeated work.

Usually:

        Brute force → O(n²)
        Two pointers → O(n)
2. Core idea

Do NOT remember only:

left++
right--

Remember:

Move a pointer only when you can justify that movement and safely eliminate some possibilities.

Ask:

What does this pointer represent?
Why am I moving it?
What possibilities become unnecessary after moving it?
3. Type 1 — Opposite-Direction Pointers
L →           ← R

Usually:

int left = 0;
int right = n - 1;

Pointers move toward each other.

Common problems
Two Sum in sorted array
Palindrome
Reverse array
Container With Most Water
Some partition problems
3Sum inner loop
4. Sorted Array + Two Pointers

This is the classic pattern.

Example:

[1, 2, 3, 4, 6, 8]
target = 10
sum = arr[left] + arr[right];
Movement rule
sum < target → left++
sum > target → right--
sum == target → found
WHY?

Because the array is sorted:

left++  → value increases
right-- → value decreases

Therefore:

Need larger sum → left++
Need smaller sum → right--
Important

The movement rule comes from sorting.

Without sorted order, this logic is usually not valid.

5. Type 2 — Same-Direction Pointers
L →
R →

Both generally move from left to right.

But they can have different jobs.

Main forms:

Same direction
│
├── Read / Write
├── Slow / Fast
└── Sliding Window
6. Read / Write Two Pointers

Example:

Remove duplicates from sorted array

fast → reads/scans
slow → writes/places valid elements

Think:

FAST = READ
SLOW = WRITE

Example:

[1, 1, 2, 2, 3]
 ↑
slow

    ↑
   fast

When fast finds a new valid element:

slow++;
arr[slow] = arr[fast];
Important

The region [slow...fast] is not necessarily a window.

Therefore:

Read/Write Two Pointers ≠ Sliding Window

7. Why slow + 1?

If:

slow = index of last valid element

then:

number of valid elements = slow + 1

Because indexes start at 0.

Example:

valid indexes = 0,1,2,3
slow = 3
length = 4
8. Move Zeroes Pattern

Example:

[1, 2, 0, 5, 6, 0, 8]

Use:

fast → scan every element
left → next position for non-zero

If:

arr[fast] != 0

then:

arr[left] = arr[fast];
left++;

After placing all non-zero values:

for(int i = left; i < n; i++)
    arr[i] = 0;
Important

Here we are keeping all n elements, so the zeroes must be filled at the end.

9. Type 3 — Sliding Window

Sliding Window is a special case of same-direction Two Pointers.

L → [ current window ] R →

Here [left...right] itself is important.

We are analyzing the current contiguous range.

Examples:

Longest substring satisfying a condition
Shortest subarray satisfying a condition
At most K distinct elements
Fixed/variable-size windows
10. Basic Sliding Window Pattern
int left = 0;

for(int right = 0; right < n; right++)
{
    // add arr[right]

    while(window_is_invalid)
    {
        // remove arr[left]
        left++;
    }

    // process window
}
Roles
right → EXPAND
left  → SHRINK
11. When do we move left?

Example:

Shortest subarray with sum ≥ target
when all elements are positive

If:

sum >= target

the current window is valid.

Since we want the shortest one:

while(sum >= target)
{
    answer = min(answer, right-left+1);

    sum -= arr[left];
    left++;
}
Why left++?

Because:

We already have a valid window
        ↓
We want a smaller window
        ↓
Moving left shrinks the window
        ↓
Positive numbers mean removing arr[left] decreases sum
        ↓
Keep shrinking while condition remains true
IMPORTANT
Positive numbers:
left++ → sum decreases
right++ → sum increases

This predictable behavior is why basic sum-based sliding window works.

12. Negative Numbers Warning ⚠️

With negative numbers:

left++ does NOT necessarily decrease sum
right++ does NOT necessarily increase sum

Example:

[-5, 10]

Removing -5 makes sum increase.

Therefore:

Do not blindly use a basic sliding window for arbitrary integers.

Example:

Longest Subarray With Sum K

With negative numbers, common solution:

Prefix Sum + HashMap

not basic sliding window.

13. Opposite vs Same Direction
Opposite Direction
L →           ← R

Typical use:

Sorted pair problems
Compare both ends
Palindrome
Same Direction
L →
R →

Typical use:

Read/Write
Sliding Window
Slow/Fast
14. Two Pointers vs Sliding Window
Two Pointers

General technique:

Use two indexes and move them intelligently.

Sliding Window

Specific Two Pointer pattern:

[left...right] represents the current contiguous window.

Therefore:

Sliding Window ⊂ Two Pointers

But:

Read/Write Two Pointers ≠ Sliding Window
15. When Two Pointers Works Well

Look for:

1. Sorted data
[1,2,3,4,6,8]
2. Comparing both ends
L ↔ R
3. Contiguous range/window
[left ... right]
4. Monotonic behavior

Example:

positive numbers
5. Read/write or compaction
fast = scan
slow = place
6. Two sorted arrays
i → A
j → B
16. When Two Pointers may NOT work

Be careful when:

Array is unsorted and ordering is required for the movement logic.
Negative numbers destroy monotonic behavior.
You cannot prove why a pointer can safely move.
Moving a pointer does not permanently eliminate any possibilities.
Golden question

“What am I eliminating by moving this pointer?”

If you cannot answer that, don't assume Two Pointers is correct.

17. Sorting + Two Pointers

Sometimes:

Unsorted array
      ↓
    sort
      ↓
Two pointers

Example:

[7,2,9,1,5]

After sorting:

[1,2,5,7,9]

Now opposite pointers can work.

Complexity
Sorting        → O(n log n)
Two pointers   → O(n)

Total          → O(n log n)
18. Time Complexity

Typical Two Pointer solution:

O(n)

Why?

Each pointer moves at most n times.

left  → at most n moves
right → at most n moves

Total:

2n → O(n)
Nested while can still be O(n)
for(int right = 0; right < n; right++)
{
    while(condition)
        left++;
}

Even though nested, if left never moves backward:

right → n times
left  → n times total

Therefore:

O(n)
19. Space Complexity

The Two Pointer variables themselves usually require:

O(1) auxiliary space

Example:

int left = 0;
int right = n - 1;

But total solution space depends on what else you use.

Examples:

Two pointers only → O(1)
HashMap           → O(n)
Extra array       → O(n)
20. Pointer Movement Cheat Sheet
Problem type	Pointer movement
Sorted Two Sum	sum < target → left++
Sorted Two Sum	sum > target → right--
Palindrome	If matched → left++, right--
Reverse array	Swap → left++, right--
Read/Write	fast scans, slow writes
Sliding Window	right expands
Sliding Window	left shrinks when needed

But: these are patterns, not universal rules. Always justify the movement.

21. Most important mental model

For every Two Pointer problem, write these five things before coding:

1. What does LEFT represent?
2. What does RIGHT represent?
3. What condition moves LEFT?
4. What condition moves RIGHT?
5. WHY is that movement safe?

Example — sorted Two Sum:

LEFT  = smaller candidate
RIGHT = larger candidate

sum < target → LEFT++
sum > target → RIGHT--

WHY?
Because array is sorted.

Example — Sliding Window:

LEFT  = window start
RIGHT = window end

RIGHT → expand
LEFT  → shrink when invalid/when optimizing

WHY?
Because the window condition changes predictably.
22. One-line definitions for revision

Two Pointers

Use two indexes and move them intelligently to eliminate unnecessary work.

Opposite pointers

Start from both ends and move toward each other.

Same-direction pointers

Both move generally left to right, often with different roles.

Read/Write

fast reads; slow writes/maintains the valid portion.

Sliding Window

Maintain a meaningful contiguous range [left...right].

Sorting

Often provides the ordering needed to make pointer movement safe.

Pointer movement

Move a pointer only when you can explain why the movement is safe.

Time

Usually O(n) when each pointer moves at most O(n) times.

Space

Usually O(1) auxiliary space unless extra structures are used.

23. The biggest rule ⭐

Don't memorize:

Two Pointers = left++ / right--

Memorize:

Two Pointers = two moving boundaries + a reason why each movement eliminates unnecessary work.

And for your learning, the best progression is:

Brute Force
   ↓
Notice repeated work
   ↓
Two Pointers
   ↓
Opposite Direction
   ↓
Same Direction
   ↓
Read/Write
   ↓
Sliding Window

That will give you a much stronger foundation than memorizing individual solutions.

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

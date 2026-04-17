# Google Test And Debugging Writeup

## Things I Thought To Test
### (from prompt delete after ) A list of the things that you thought to test BEFORE you looked at the actual test cases
1. In the parse_args function, I think we should test if it actually turns the string numbers to values by running the function and doing an expect equals. Also should we perhaps test for memory leaks?
2. In the parse_args function, we should test giving it no values.
3. In get_sorted, there can be a test to see if the sorted copy matches an array we manually sorted. 
4. In get_sorted, we can check that the copy of the array we get is the same length as the original array.
5. In make_sorted we can check that the function correctly sorted it by comparing it to an array we manually sorted.
6. In copy_array we can check that the array correctly copied, and the length is the same.
7. In swap, we should test simply swaping two numbers.
8. In swap, we should test what happens if we accidentaly gave it more than two numbers. 

## Bugs

### Bug 1

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix 

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 2

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 3

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```

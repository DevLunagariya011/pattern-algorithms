# Printing a Right Triangle Pattern Using a Single Loop in C

## Overview
This repository demonstrates an alternative approach to printing triangle patterns in C by leveraging triangular numbers. Instead of using nested loops, this implementation uses mathematical principles to flatten a two-dimensional pattern into a one-dimensional iteration.

## Problem Statement
Given a positive integer `n`, print a right-angled triangle of height `n` using asterisks.

**Example:** For `n = 4`
```
* 
* * 
* * * 
* * * * 
```

## Traditional Approach
The conventional solution uses nested loops:
```c
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        printf("* ");
    }
    printf("\n");
}
```

**Structure:**
- Outer loop: controls the rows
- Inner loop: prints stars for each row
- Time complexity: O(n²)

While intuitive, this approach treats the pattern as an inherently two-dimensional structure.

## Mathematical Foundation

### Triangular Numbers
The total number of stars in a triangle of height `n` equals the `n`th triangular number:
```
T(n) = 1 + 2 + 3 + ... + n = n(n + 1) / 2
```

**Pattern Analysis:**

| Row | Stars in Row | Cumulative Total (Triangular Number) |
|-----|--------------|-------------------------------------|
| 1   | 1            | 1                                   |
| 2   | 2            | 3                                   |
| 3   | 3            | 6                                   |
| 4   | 4            | 10                                  |
| n   | n            | n(n+1)/2                            |

The cumulative totals represent the exact positions where each row ends in a flattened sequence.

## Key Insight
By recognizing that triangular numbers mark row boundaries, we can:
1. Iterate through all stars sequentially (1 to `n(n+1)/2`)
2. Print a star on each iteration
3. Insert a newline when the current index matches a triangular number

This transforms the two-dimensional problem into a one-dimensional iteration with mathematical boundary detection.

## Single Loop Implementation
```c
#include <stdio.h>

/**
 * Prints a right triangle pattern using a single loop
 * 
 * @param n: Height of the triangle (number of rows)
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
void print_triangle(int n) {
    // Calculate total number of stars needed
    int total = n * (n + 1) / 2;
    
    // Track current row number
    int row = 1;
    
    // Single loop through all stars
    for (int i = 1; i <= total; i++) {
        printf("* ");
        
        // Check if current position is a triangular number
        if (i == row * (row + 1) / 2) {
            printf("\n");
            row++;
        }
    }
}

int main() {
    int n = 5;
    print_triangle(n);
    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** O(n²) — same as the nested loop approach, as we still print n(n+1)/2 stars
- **Space Complexity:** O(1) — only uses a constant amount of additional memory

## Why This Approach Matters

### Educational Value
This technique demonstrates:
- **Mathematical optimization:** Using number theory to simplify code structure
- **Dimensional reduction:** Converting 2D problems into 1D sequences
- **Alternative thinking:** Multiple valid solutions exist for the same problem

### Related Concepts
Similar indexing techniques appear in:
- **Pascal's triangle:** Mapping 2D coordinates to linear indices
- **Sparse matrix storage:** Converting matrix positions to array indices
- **Image processing:** Row-major or column-major order conversions
- **Memory management:** Multi-dimensional array flattening

### Practical Implications
While the nested loop approach is more readable for simple patterns, understanding single-loop implementations:
- Builds stronger mathematical intuition
- Prepares you for more complex indexing problems
- Demonstrates that code structure doesn't always mirror problem structure

## Comparison

| Aspect              | Nested Loops | Single Loop (Triangular Numbers) |
|---------------------|--------------|----------------------------------|
| Readability         | High         | Medium                           |
| Mathematical depth  | Low          | High                             |
| Loop variables      | 2            | 1                                |
| Conceptual approach | Structural   | Mathematical                     |
| Time complexity     | O(n²)        | O(n²)                            |

## Usage
```bash
# Compile
gcc triangle.c -o triangle

# Run
./triangle
```

## Extensions
This concept can be extended to:
- Inverted triangles (reversed triangular numbers)
- Centered triangles (symmetric padding)
- Other patterns with mathematical sequences (square numbers, Fibonacci)
- Multi-character patterns

## Contributing
Feel free to open issues or submit pull requests with improvements or alternative implementations.

## License
This project is open source and available under the [MIT License](LICENSE).

## References
- [Triangular Number - Wikipedia](https://en.wikipedia.org/wiki/Triangular_number)
- [OEIS A000217](https://oeis.org/A000217) - The triangular numbers sequence

---

**Author:** Dev Lunagariya  
**Date:** January 2026

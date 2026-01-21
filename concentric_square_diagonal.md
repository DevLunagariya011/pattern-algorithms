# Printing Concentric Square Patterns Using Diagonal Decomposition

## Overview
This repository presents an alternative approach to generating concentric square patterns in C. Instead of the traditional method of computing minimum distance from edges, this implementation uses diagonal decomposition to split the grid into two triangular regions, each with its own distance formula.

## Problem Statement
Given a positive integer `n`, print a concentric square pattern of size `(2n-1) × (2n-1)` where values decrease toward the center and increase toward the edges.

**Example:** For `n = 4`
```
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
```

## Traditional Approach
The conventional solution calculates the minimum distance from any cell to the four edges:
```c
int distance = min(min(i, j), min(m-1-i, m-1-j));
int value = n - distance;
```

**Characteristics:**
- Intuitive: literally measures distance to nearest boundary
- Requires 4 distance calculations per cell
- Uniform logic across entire grid
- Time complexity: O(n²)

While straightforward, this approach doesn't leverage the inherent symmetry of the pattern.

## Mathematical Foundation

### Grid Properties
For a given parameter `n`:
- **Grid dimensions:** `m = 2n - 1` (ensures odd dimensions)
- **Center position:** `(n-1, n-1)`
- **Total cells:** `(2n-1)²`

### Diagonal Decomposition
Consider the anti-diagonal line defined by:
```
i + j = m - 1
```

This diagonal divides the grid into two triangular regions with complementary properties:
```
Upper-Left Region (◣)    Lower-Right Region (◥)
i + j < m - 1            i + j ≥ m - 1

Example for m=7:
. . . . . . .            . . . . . . .
. . . . . . .            . . . . . . .
. . . . . . .            . . . . . . .
. . . . X . .    and     . . . X . . .
. . . X X X .            . X X X . . .
. . X X X X X            X X X X . . .
. X X X X X X            X X X X X . .
```

### Regional Formulas

**Upper-Left Triangle:**
```
value = max(n - i, n - j)
```
- Measures distance from top edge: `n - i`
- Measures distance from left edge: `n - j`
- Takes the maximum (farther from either edge)

**Lower-Right Triangle:**
```
value = max(i - n, j - n) + 2
```
- Measures distance past center: `i - n` and `j - n`
- `+2` offset ensures continuity with upper-left region

### Why It Works

**Proof of correctness:**

For any cell `(i, j)` in the upper-left region:
- If closer to top: value = `n - i` (row distance)
- If closer to left: value = `n - j` (column distance)
- Result matches traditional distance formula ✓

For any cell `(i, j)` in the lower-right region:
- Distance from bottom: `(2n-2) - i`
- Distance from right: `(2n-2) - j`
- After coordinate transformation: `max(i-n, j-n) + 2` ✓

The two formulas create complementary halves that align perfectly at the diagonal.

## Implementation
```c
#include <stdio.h>

// Macro for maximum of two values
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Prints concentric square pattern using diagonal decomposition
 * 
 * @param n: Size parameter (creates (2n-1) × (2n-1) grid)
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
void print_concentric_square(int n) {
    int m = 2 * n - 1;  // Grid dimension
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j < m) {
                // Upper-left triangular region
                // Distance from top or left edge
                printf("%d ", MAX(n - i, n - j));
            } else {
                // Lower-right triangular region
                // Distance from bottom or right edge (with offset)
                printf("%d ", MAX(i - n, j - n) + 2);
            }
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    
    printf("Concentric square pattern for n = %d:\n", n);
    print_concentric_square(n);
    
    return 0;
}
```

## Example Outputs

**n = 3:**
```
3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
```

**n = 5:**
```
5 5 5 5 5 5 5 5 5
5 4 4 4 4 4 4 4 5
5 4 3 3 3 3 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 3 3 3 3 4 5
5 4 4 4 4 4 4 4 5
5 5 5 5 5 5 5 5 5
```

## Complexity Analysis

| Metric | Value | Notes |
|--------|-------|-------|
| **Time Complexity** | O(n²) | Nested loops iterate through (2n-1)² cells |
| **Space Complexity** | O(1) | Only constant extra variables used |
| **Comparisons per cell** | 1 | Single diagonal check + one MAX operation |

## Why This Approach Matters

### Advantages
1. **Geometric insight:** Leverages diagonal symmetry rather than radial distance
2. **Fewer operations:** One diagonal check vs. four distance calculations
3. **Mathematical elegance:** Demonstrates coordinate transformation techniques
4. **Educational value:** Shows alternative problem decomposition

### Conceptual Differences

| Aspect | Traditional | Diagonal Decomposition |
|--------|-------------|------------------------|
| Mental model | Distance from edges | Regional formulas |
| Symmetry | 4-fold radial | 2-fold diagonal |
| Formula count | 1 (uniform) | 2 (regional) |
| Edge calculations | 4 per cell | 0 (implicit in formulas) |
| Intuitiveness | High | Medium |
| Mathematical depth | Low | High |

### Related Techniques
This diagonal decomposition approach relates to:
- **Coordinate transformations** in computer graphics
- **Region-based algorithms** in computational geometry
- **Triangular matrix storage** in linear algebra
- **Quadrant decomposition** in spatial indexing (quadtrees)

## Visual Explanation

For `n = 4`, the diagonal `i + j = 6` splits the grid:
```
Regions:              Diagonal Line:        Values:
U U U U U U U         . . . . . . X         4 4 4 4 4 4 4
U U U U U U L         . . . . . X .         4 3 3 3 3 3 4
U U U U U L L         . . . . X . .         4 3 2 2 2 3 4
U U U U L L L         . . . X . . .         4 3 2 1 2 3 4
U U U L L L L         . . X . . . .         4 3 2 2 2 3 4
U U L L L L L         . X . . . . .         4 3 3 3 3 3 4
U L L L L L L         X . . . . . .         4 4 4 4 4 4 4

U = Upper-left        X = Diagonal          Numbers show final output
L = Lower-right           (i+j = m-1)
```

## Usage
```bash
# Compile
gcc concentric_square.c -o concentric_square

# Run
./concentric_square
```

## Extensions and Variations

### Possible Modifications
1. **Hollow squares:** Modify formulas to skip internal values
2. **Different diagonals:** Use main diagonal (`i = j`) for different decomposition
3. **Custom characters:** Replace numbers with symbols or colors
4. **Gradient patterns:** Apply exponential or logarithmic transformations to values
5. **3D extension:** Extend concept to concentric cubes

### Code Variation: Diagonal Visualization
```c
// Print which region each cell belongs to
void visualize_regions(int n) {
    int m = 2 * n - 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", (i + j < m) ? 'U' : 'L');
        }
        printf("\n");
    }
}
```

## Performance Considerations

While the asymptotic complexity is identical to traditional methods (O(n²)), this approach:
- **Reduces branching:** Only one `if` statement vs. multiple `min` calls
- **Cache-friendly:** Sequential memory access pattern
- **Compiler-optimizable:** Simple arithmetic operations

For very large grids, the difference is negligible, but the code structure may be more maintainable.

## Contributing
Contributions are welcome! Feel free to:
- Submit bug reports or feature requests
- Propose alternative decomposition strategies
- Add visualizations or interactive demos
- Improve documentation

## License
This project is open source and available under the [MIT License](LICENSE).

## References
- [Taxicab Geometry](https://en.wikipedia.org/wiki/Taxicab_geometry) - Manhattan distance
- [Coordinate Systems](https://en.wikipedia.org/wiki/Coordinate_system) - Transformation principles
- [Pattern Programming](https://www.geeksforgeeks.org/pattern-programs-in-c/) - Traditional approaches

## Acknowledgments
This approach was developed as an exploration of alternative pattern generation techniques, demonstrating that mathematical creativity can lead to elegant solutions even for well-studied problems.

---

**Author:** Dev Lunagariya  
**Date:** January 2026  
**Version:** 1.0

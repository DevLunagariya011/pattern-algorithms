/**
 * concentric_square.c
 * 
 * Prints a concentric square pattern using diagonal decomposition
 * instead of the traditional minimum-distance-from-edges approach.
 * 
 * This implementation divides the grid along the anti-diagonal (i+j=m-1)
 * into two triangular regions, each using a different distance formula.
 * 
 * Compile: gcc concentric_square.c -o concentric_square
 * Run: ./concentric_square
 * 
 * Author: Dev Lunagariya
 * Date: January 2026
 * License: MIT
 */

#include <stdio.h>

// Macro to compute maximum of two values
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Prints a concentric square pattern using diagonal decomposition
 * 
 * Mathematical basis:
 * - Grid size: m = 2n-1 (ensures odd dimensions with center at (n-1, n-1))
 * - Anti-diagonal: i + j = m-1 divides grid into two triangular regions
 * - Upper-left region (i+j < m-1): value = max(n-i, n-j)
 * - Lower-right region (i+j >= m-1): value = max(i-n, j-n) + 2
 * 
 * Why it works:
 * - Upper-left: measures distance from top or left edge
 * - Lower-right: measures distance from center, offset to align with upper-left
 * - The +2 offset ensures values match correctly across the diagonal
 * 
 * Example for n=4 (7x7 grid):
 *   4 4 4 4 4 4 4
 *   4 3 3 3 3 3 4
 *   4 3 2 2 2 3 4
 *   4 3 2 1 2 3 4  <- center row
 *   4 3 2 2 2 3 4
 *   4 3 3 3 3 3 4
 *   4 4 4 4 4 4 4
 * 
 * The diagonal (marked with |) runs from top-right to bottom-left:
 *   Position (0,6), (1,5), (2,4), (3,3), (4,2), (5,1), (6,0)
 *   All satisfy i + j = 6 (which is m-1 for m=7)
 * 
 * @param n Size parameter (creates (2n-1)×(2n-1) grid)
 * 
 * Time Complexity: O(n²) - nested loops through (2n-1)² cells
 * Space Complexity: O(1) - only constant extra variables
 */
void print_concentric_square(int n) {
    // Validate input
    if (n <= 0) {
        printf("Error: n must be a positive integer\n");
        return;
    }
    
    // Calculate grid dimensions
    // For n=4: m = 2*4-1 = 7 (creates a 7×7 grid)
    int m = 2 * n - 1;
    
    // Iterate through each row
    for (int i = 0; i < m; i++) {
        // Iterate through each column in the current row
        for (int j = 0; j < m; j++) {
            
            // Diagonal decomposition: divide grid at anti-diagonal i+j = m-1
            // This creates two triangular regions with different formulas
            
            if (i + j < m) {
                // UPPER-LEFT TRIANGULAR REGION (and diagonal itself)
                // Includes all cells where i + j < m-1
                // 
                // Calculate value based on distance from top or left edge:
                // - (n - i) gives distance from top edge (row distance)
                // - (n - j) gives distance from left edge (column distance)
                // - MAX gives the larger value (farther from either edge)
                // 
                // Example: For n=4, position (1,1):
                //   n - i = 4 - 1 = 3
                //   n - j = 4 - 1 = 3
                //   MAX(3, 3) = 3 ✓
                // 
                // Example: For n=4, position (0,3):
                //   n - i = 4 - 0 = 4
                //   n - j = 4 - 3 = 1
                //   MAX(4, 1) = 4 ✓
                
                printf("%d ", MAX(n - i, n - j));
                
            } else {
                // LOWER-RIGHT TRIANGULAR REGION
                // Includes all cells where i + j >= m-1
                // 
                // Calculate value based on distance from center:
                // - (i - n) measures how far below center we are
                // - (j - n) measures how far right of center we are
                // - +2 offset aligns values with the upper-left region
                // 
                // The +2 compensates for the coordinate transformation:
                // - In upper-left, we count down from n
                // - In lower-right, we count up from 0 (i-n, j-n)
                // - Adding 2 shifts the range to match the pattern
                // 
                // Example: For n=4, position (5,5):
                //   i - n = 5 - 4 = 1
                //   j - n = 5 - 4 = 1
                //   MAX(1, 1) + 2 = 3 ✓
                // 
                // Example: For n=4, position (6,3):
                //   i - n = 6 - 4 = 2
                //   j - n = 3 - 4 = -1
                //   MAX(2, -1) + 2 = 4 ✓
                
                printf("%d ", MAX(i - n, j - n) + 2);
            }
        }
        
        // Move to next row after completing current row
        printf("\n");
    }
}

/**
 * Helper function to visualize which region each cell belongs to
 * Useful for understanding the diagonal decomposition
 */
void visualize_regions(int n) {
    int m = 2 * n - 1;
    
    printf("Region visualization (U = Upper-left, L = Lower-right):\n");
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            // Check which side of the diagonal we're on
            if (i + j < m) {
                printf("U ");
            } else {
                printf("L ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Main function - demonstrates the concentric square pattern
 */
int main() {
    int size;
    
    printf("Concentric Square Pattern - Diagonal Decomposition\n");
    printf("==================================================\n\n");
    
    // Get input from user
    printf("Enter the size parameter n: ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    
    printf("\n");
    
    // Show region decomposition for educational purposes
    if (size <= 7) {  // Only show for smaller sizes to avoid clutter
        visualize_regions(size);
    }
    
    // Print the concentric square
    printf("Concentric square pattern:\n");
    print_concentric_square(size);
    
    printf("\n");
    
    // Show additional examples
    printf("\nExamples of other sizes:\n");
    printf("------------------------\n\n");
    
    printf("n = 3:\n");
    print_concentric_square(3);
    
    printf("\nn = 5:\n");
    print_concentric_square(5);
    
    return 0;
}

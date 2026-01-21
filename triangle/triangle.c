/**
 * triangle.c
 * 
 * Prints a right-angled triangle pattern using a single loop
 * instead of the traditional nested loop approach.
 * 
 * This implementation leverages the mathematical concept of triangular
 * numbers to determine when to insert line breaks, effectively converting
 * a 2D pattern into a 1D iteration.
 * 
 * Compile: gcc triangle.c -o triangle
 * Run: ./triangle
 * 
 * Author: [Your Name]
 * Date: January 2026
 * License: MIT
 */

#include <stdio.h>

/**
 * Prints a right triangle pattern using a single loop
 * 
 * Mathematical basis:
 * - The nth triangular number T(n) = n(n+1)/2 represents the sum 1+2+3+...+n
 * - These numbers mark the cumulative total of stars up to each row
 * - By checking if current position equals a triangular number,
 *   we know when a row is complete and need to insert a newline
 * 
 * Algorithm:
 * 1. Calculate total stars needed: n(n+1)/2
 * 2. Loop through all stars sequentially
 * 3. Print a star on each iteration
 * 4. When position matches current row's triangular number, insert newline
 * 
 * Example for n=4:
 * Row 1: stars 1         (T(1) = 1)
 * Row 2: stars 2-3       (T(2) = 3)
 * Row 3: stars 4-6       (T(3) = 6)
 * Row 4: stars 7-10      (T(4) = 10)
 * 
 * @param n Height of the triangle (number of rows)
 * 
 * Time Complexity: O(n²) - prints n(n+1)/2 stars
 * Space Complexity: O(1) - uses constant extra space
 */
void print_triangle(int n) {
    // Validate input
    if (n <= 0) {
        printf("Error: n must be a positive integer\n");
        return;
    }
    
    // Calculate total number of stars needed using triangular number formula
    // For n=5: total = 5*6/2 = 15 stars
    int total = n * (n + 1) / 2;
    
    // Track which row we're currently on (starts at 1 for the first row)
    int row = 1;
    
    // Single loop iterates through all stars from 1 to total
    for (int i = 1; i <= total; i++) {
        // Print a star with trailing space
        printf("* ");
        
        // Check if we've completed the current row
        // The triangular number for row k is k(k+1)/2
        // When our position i equals this value, we've printed all stars for row k
        if (i == row * (row + 1) / 2) {
            printf("\n");  // Move to next line
            row++;         // Increment row counter for next iteration
        }
    }
}

/**
 * Main function - demonstrates the triangle printing
 */
int main() {
    int size;
    
    printf("Right Triangle Pattern - Single Loop Implementation\n");
    printf("===================================================\n\n");
    
    // Get input from user
    printf("Enter the height of the triangle: ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    
    printf("\n");
    
    // Print the triangle
    print_triangle(size);
    
    printf("\n");
    
    // Show some example outputs
    printf("\nExamples of other sizes:\n");
    printf("------------------------\n\n");
    
    printf("n = 3:\n");
    print_triangle(3);
    
    printf("\nn = 6:\n");
    print_triangle(6);
    
    return 0;
}

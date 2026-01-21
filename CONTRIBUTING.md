# Contributing to Pattern Algorithms

First off, thank you for considering contributing to Pattern Algorithms! It's people like you that make this project a valuable learning resource for the community.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [How Can I Contribute?](#how-can-i-contribute)
  - [Reporting Bugs](#reporting-bugs)
  - [Suggesting Enhancements](#suggesting-enhancements)
  - [Adding New Algorithms](#adding-new-algorithms)
  - [Improving Documentation](#improving-documentation)
- [Development Guidelines](#development-guidelines)
  - [Code Style](#code-style)
  - [Commit Messages](#commit-messages)
  - [Pull Request Process](#pull-request-process)
- [Project Structure](#project-structure)
- [Algorithm Submission Guidelines](#algorithm-submission-guidelines)

## Code of Conduct

This project and everyone participating in it is governed by our commitment to providing a welcoming and inspiring community for all. Please be respectful and constructive in your interactions.

### Our Standards

- Use welcoming and inclusive language
- Be respectful of differing viewpoints and experiences
- Gracefully accept constructive criticism
- Focus on what is best for the community
- Show empathy towards other community members

## How Can I Contribute?

### Reporting Bugs

If you find a bug in the code:

1. **Check if the bug has already been reported** by searching the [Issues](../../issues)
2. If not, **open a new issue** with:
   - A clear, descriptive title
   - Steps to reproduce the bug
   - Expected behavior vs actual behavior
   - Your environment (OS, compiler version, etc.)
   - Code snippets or screenshots if applicable

**Example:**
```
Title: Concentric square prints incorrect values for n=1

Description:
When running concentric_square with n=1, the output is incorrect.

Steps to reproduce:
1. Compile: gcc concentric_square.c -o concentric_square
2. Run with input n=1
3. Observe output

Expected: 1
Actual: 2

Environment: Ubuntu 22.04, GCC 11.3.0
```

### Suggesting Enhancements

Have an idea to make the project better?

1. **Search existing issues** to see if it's already been suggested
2. **Open a new issue** with the tag `enhancement`
3. Include:
   - Clear description of the enhancement
   - Why it would be useful
   - Examples or mockups if applicable
   - Any implementation ideas you have

### Adding New Algorithms

We welcome new pattern algorithms! Here's what we're looking for:

**Good candidates for inclusion:**
- ✅ Novel approaches to common patterns
- ✅ Mathematical or algorithmic insights
- ✅ Educational value (teaches a concept)
- ✅ Non-obvious solutions
- ✅ Clear advantage or interesting perspective over traditional methods

**What we're not looking for:**
- ❌ Trivial variations of existing algorithms
- ❌ Brute-force solutions without insight
- ❌ Code without clear documentation
- ❌ Algorithms that are just "different" without being "interesting"

### Improving Documentation

Documentation improvements are always welcome:
- Fixing typos or grammatical errors
- Clarifying explanations
- Adding examples or diagrams
- Improving code comments
- Translating documentation (future goal)

## Development Guidelines

### Code Style

Follow these conventions to maintain consistency:

#### C Code Standards
```c
// ✅ GOOD: Clear variable names, proper spacing
void print_triangle(int height) {
    int total_stars = height * (height + 1) / 2;
    int current_row = 1;
    
    for (int i = 1; i <= total_stars; i++) {
        printf("* ");
        if (i == current_row * (current_row + 1) / 2) {
            printf("\n");
            current_row++;
        }
    }
}

// ❌ BAD: Cryptic names, poor formatting
void pt(int h){int t=h*(h+1)/2;int r=1;for(int i=1;i<=t;i++){printf("* ");
if(i==r*(r+1)/2){printf("\n");r++;}}}
```

**Specific Guidelines:**

1. **Indentation**: 4 spaces (no tabs)
2. **Braces**: Opening brace on same line for functions and control structures
3. **Variables**: 
   - Use descriptive names (`total_stars` not `ts`)
   - Exception: loop counters (`i`, `j`) are acceptable
4. **Comments**:
   - File header with description, author, date
   - Function documentation before each function
   - Inline comments for complex logic
5. **Line Length**: Maximum 80 characters when practical
6. **Whitespace**: 
   - Space after keywords (`if (condition)` not `if(condition)`)
   - Space around operators (`a + b` not `a+b`)
   - Blank line between functions

#### Documentation Standards

**README.md files should include:**
- Clear problem statement
- Traditional approach explanation
- Mathematical foundation
- Your algorithm explanation
- Complete, compilable code
- Complexity analysis
- Examples with output
- Why the approach is interesting

**Code comments should:**
- Explain *why*, not just *what*
- Include examples for complex formulas
- Provide visual diagrams where helpful
- Reference mathematical concepts

### Commit Messages

Write clear, descriptive commit messages:

#### Format
```
<type>: <subject>

<body>

<footer>
```

#### Types
- `feat`: New feature or algorithm
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code formatting (no logic change)
- `refactor`: Code restructuring (no behavior change)
- `test`: Adding or updating tests
- `chore`: Maintenance tasks

#### Examples
```
✅ GOOD:
feat: add spiral matrix pattern using mathematical formula

Implements a spiral matrix pattern generator that uses arithmetic
sequences to determine positions instead of direction tracking.
The approach demonstrates coordinate transformation techniques.

Closes #15

---

fix: correct triangular number calculation for n=0

The triangle function now properly validates input and returns
early for n <= 0, preventing incorrect calculations.

Fixes #23

---

docs: improve explanation of diagonal decomposition

Added visual diagrams and step-by-step examples to clarify
how the anti-diagonal splits the concentric square grid.
```
```
❌ BAD:
- "fixed bug"
- "updated code"
- "changes"
- "idk lol"
```

### Pull Request Process

1. **Fork the repository** and create your branch from `main`
```bash
   git checkout -b feature/your-algorithm-name
```

2. **Make your changes** following the style guidelines

3. **Test your code** thoroughly
   - Compile without warnings: `gcc -Wall -Wextra your_code.c`
   - Test with various inputs
   - Verify output matches expectations

4. **Update documentation**
   - Add/update README.md in your algorithm's folder
   - Update main README.md if adding new algorithm
   - Ensure all examples work

5. **Commit your changes** with clear commit messages

6. **Push to your fork**
```bash
   git push origin feature/your-algorithm-name
```

7. **Open a Pull Request** with:
   - Clear title describing the change
   - Description of what and why
   - Reference any related issues
   - Screenshots/examples if applicable

8. **Respond to feedback** - maintainers may request changes

## Project Structure

When adding a new algorithm, follow this structure:
```
pattern-algorithms/
├── your-algorithm-name/
│   ├── README.md              # Complete documentation
│   ├── algorithm_name.c       # Implementation
│   └── examples/
│       └── output.txt         # Sample outputs (optional)
```

### Required Files

**README.md must include:**
- Overview section
- Problem statement
- Traditional approach
- Mathematical foundation
- Your algorithm explanation
- Complete code
- Complexity analysis
- Example outputs
- Why it's interesting
- Usage instructions

**C file must include:**
- File header comment
- Function documentation
- Inline comments for complex logic
- Input validation
- Example usage in main()

## Algorithm Submission Guidelines

### What Makes a Good Submission?

1. **Novel Approach**: Demonstrates a unique perspective or technique
2. **Educational Value**: Teaches a concept (math, CS, optimization)
3. **Well Documented**: Clear explanation with mathematical reasoning
4. **Clean Code**: Follows style guidelines, easy to read
5. **Tested**: Works correctly for various inputs
6. **Interesting**: Provides insight beyond "just different"

### Submission Checklist

Before submitting, ensure:

- [ ] Code compiles without warnings (`gcc -Wall -Wextra`)
- [ ] Code runs correctly for edge cases (n=0, n=1, large n)
- [ ] All functions have documentation comments
- [ ] Complex logic has inline comments
- [ ] README.md is complete and well-formatted
- [ ] Examples show expected output
- [ ] Mathematical formulas are explained
- [ ] Complexity analysis is included
- [ ] Code follows style guidelines
- [ ] No trailing whitespace or unnecessary files
- [ ] Commit messages are descriptive

### Review Process

1. **Initial Review** (1-3 days): Maintainer checks basic requirements
2. **Technical Review** (3-7 days): Evaluation of algorithm quality and documentation
3. **Feedback**: Suggested improvements or questions
4. **Revision**: Make requested changes
5. **Approval**: Once all criteria met, PR is merged

## Questions?

Feel free to:
- Open an issue with the `question` label
- Reach out to maintainers
- Start a discussion in the Discussions tab (if enabled)

## Recognition

Contributors will be:
- Listed in the project's contributors
- Credited in the README
- Acknowledged in release notes

Thank you for contributing to Pattern Algorithms! 🎉

---

**Remember**: Quality over quantity. One well-documented, interesting algorithm is better than ten trivial variations.

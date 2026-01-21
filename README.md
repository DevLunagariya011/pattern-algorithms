# Pattern Algorithms

A collection of mathematically elegant approaches to printing patterns in C, demonstrating alternative problem-solving techniques beyond traditional nested loops.

## Projects

### 1. [Single Loop Triangle](./triangle/)
Print right-angled triangles using triangular numbers instead of nested loops.
- **Concept:** Dimensional reduction via mathematical sequences
- **Key Formula:** T(n) = n(n+1)/2

[View Documentation](./triangle/README.md) | [View Code](./triangle/triangle.c)

### 2. [Concentric Squares via Diagonal Decomposition](./concentric-square/)
Generate concentric square patterns by splitting the grid along a diagonal.
- **Concept:** Regional formulas based on geometric decomposition
- **Key Innovation:** Two-region approach vs. four-edge distance

[View Documentation](./concentric-square/README.md) | [View Code](./concentric-square/concentric_square.c)

## Quick Start
```bash
# Clone the repository
git clone https://github.com/DevLunagariya011/pattern-algorithms.git
cd pattern-algorithms

# Compile and run triangle
cd triangle
gcc triangle.c -o triangle
./triangle

# Compile and run concentric square
cd ../concentric-square
gcc concentric_square.c -o concentric_square
./concentric_square
```

## Philosophy

This repository demonstrates that:
- Multiple valid solutions exist for the same problem
- Mathematical insight can simplify code structure
- Traditional approaches aren't always the only way

## Features

- ✅ Well-documented algorithms
- ✅ Mathematical proofs included
- ✅ Complexity analysis
- ✅ Clean, readable code
- ✅ Ready-to-compile examples

## Contributing

Contributions are welcome! Please read [CONTRIBUTING.md](./docs/contributing.md) for guidelines.

## License

This project is licensed under the MIT License - see [LICENSE](LICENSE) file for details.

## Author

Dev Lunagariya

## Acknowledgments

Inspired by exploring mathematical approaches to common programming patterns.
```

## Additional Files to Add

**`.gitignore`:**
```
# Compiled files
*.o
*.out
*.exe
triangle/triangle
concentric-square/concentric_square

# IDE files
.vscode/
.idea/
*.swp

# OS files
.DS_Store
Thumbs.db
```

**`LICENSE`** (if using MIT):
```
MIT License

Copyright (c) 2026 Dev Lunagariya

Permission is hereby granted, free of charge, to any person obtaining a copy...

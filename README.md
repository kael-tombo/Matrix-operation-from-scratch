# Matrix Operations from Scratch (C11)

[![C11](https://img.shields.io/badge/Language-C11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![CMake](https://img.shields.io/badge/Build-CMake%20%E2%89%A5%203.10-brightgreen.svg)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Zero Dependencies](https://img.shields.io/badge/Dependencies-Standard%20C%20Lib-orange.svg)](#)

> **A lightweight educational and numerical linear-algebra library in C, implementing matrix operations, decompositions, eigenvalue analysis, and linear-system solving.**

---

## 📌 Executive Summary

Matrix Operations from Scratch
This project is a simple C program created in 2017 during my second year of the Bachelor in Computer Science at the University of Toamasina (MIA). It was built as an educational exercise to better understand matrix operations and basic linear algebra concepts.

The goal was not to build a professional numerical library, but to practice:

dynamic memory allocation in C,
matrix manipulation,
algorithm implementation,
and console-based interaction.

This repository contains a pure **C** linear-algebra suite written from scratch without any external numerical dependencies (such as LAPACK, BLAS, or Eigen). Built upon classical matrix theory and numerical analysis, it provides both direct and iterative algorithms, interactive terminal workflows, and custom dynamic data structures for tracking spectral decomposition and convergence.

---

## 🗂️ Architectural Overview & Codebase Inventory

The project is structured into modular compilation units where each file implements a distinct mathematical operation or algorithm:

```
├── CMakeLists.txt                 # CMake configuration (C11, multi-file target)
├── PROTOTYPES.h                   # Global header: structs, stacks, allocation & math prototypes
├── main.c                         # Application entrypoint calling interactive MENU()
├── MENU.c                         # Terminal UI, menu loop, validation & dispatch
│
├── Arithmetic & Elementary Ops:
│   ├── ADDITION.c                 # Matrix addition (A + B)
│   ├── SOUSTRACTION.c             # Matrix subtraction (A - B)
│   ├── MULTIPLICATION.c           # Matrix product (A * B)
│   ├── MULTIPLICATION PAR SCALAIRE.c # Scalar multiplication (α * A)
│   ├── TRANSPOSE.c                # Matrix transposition (A^T)
│   ├── TRACE.c                    # Matrix trace: Tr(A) = sum(A_ii)
│   └── COMBINAISON LINEAIRE.c     # Linear combination: α * A + β * B
│
├── Elimination & Systems:
│   ├── DETERMINANT.c              # Determinant calculation via Gaussian elimination
│   ├── INVERSE.c                  # Gauss-Jordan matrix inversion [A | I] -> [I | A^-1]
│   ├── RANG.c                     # Rank calculation via row echelon reduction
│   ├── TRIANGULARISATION.c        # Upper triangularization (Gaussian reduction)
│   └── systeme d_equation.c       # Linear system solving (Gaussian & Gauss-Seidel) & Matrix Power A^p
│
└── Spectral Analysis & Decompositions:
    ├── hessenberg.c               # Householder reduction to Upper Hessenberg form
    ├── VALEUR PROPRE2.c           # QR algorithm with Householder reflectors & eigenspaces
    └── DIAGONALISATION.c          # Diagonalizability testing, modal matrix P, and diagonal form D
```

---

## 🔬 In-Depth Codebase Analysis

### 1. Unified Data Structures & Memory Model (`PROTOTYPES.h`)
- **`ValeurPropre` / `Stack`**:
  A singly-linked list tracking calculated eigenvalues $\lambda_i$, their algebraic multiplicity, and the dimension of the associated eigenspace $\dim \ker(A - \lambda_i I)$:
  ```c
  typedef struct VP {
      float value;
      int multipliciter;
      int Dim_espace_Vect_Associe;
      struct VP *next;
  } ValeurPropre, *Stack;
  ```
- **`Maille` / `Pile`**:
  A dynamic linked stack storing full 2D matrix snapshots (`float **Matrix`), utilized for tracking iteration sequences and evaluating convergence criteria in iterative algorithms.
- **Dynamic 2D/3D Allocators**:
  - `malloc2(int rows, int cols)`: Allocates contiguous pointer-to-row tables for flexible 2D matrices.
  - `malloc3(int dim1, int dim2)`: Allocates 3D tensors for multi-matrix transformations.
  - `liberer(float **mat, int rows)`: Safe cleanup utility.

### 2. Elementary Matrix Arithmetic
- **`ADDITION.c` & `SOUSTRACTION.c`**: Verifies dimensional conformity ($m \times n$ matching) and performs element-wise operations $C_{ij} = A_{ij} \pm B_{ij}$.
- **`MULTIPLICATION.c`**: Validates inner dimension equality ($cols(A) == rows(B)$) and computes the standard inner product $C_{ij} = \sum_{k=1}^p A_{ik} B_{kj}$ in $\mathcal{O}(m \cdot p \cdot n)$.
- **`MULTIPLICATION PAR SCALAIRE.c`**: Scales all entries $A_{ij} \leftarrow \alpha A_{ij}$.
- **`TRANSPOSE.c`**: Transforms an $m \times n$ matrix into an $n \times m$ matrix with $A^T_{ji} = A_{ij}$.
- **`TRACE.c`**: Computes $\operatorname{Tr}(A) = \sum_{i=1}^n A_{ii}$ for square matrices.
- **`COMBINAISON LINEAIRE.c`**: Computes $\alpha A + \beta B$ with user-defined scalars $\alpha, \beta \in \mathbb{R}$.

### 3. Decompositions, Inversion, and Rank
- **`DETERMINANT.c`**:
  Calculates $\det(A)$ using Gaussian elimination with partial row pivoting to transform $A$ into an upper triangular matrix $U$. Tracks row swap parity signs:
  $$\det(A) = (-1)^{\text{swaps}} \prod_{i=1}^n U_{ii}$$
- **`INVERSE.c`**:
  Implements the **Gauss-Jordan elimination method** on the augmented block matrix $[A \mid I_n]$. Applies row scaling and pivot substitutions until the left block becomes identity $[I_n \mid A^{-1}]$. Identifies singular/non-invertible matrices when a pivot cannot be found.
- **`RANG.c`**:
  Computes the matrix rank $\operatorname{rank}(A)$ by reducing $A$ to row echelon form using elementary row operations and counting the non-zero pivot rows.
- **`TRIANGULARISATION.c`**:
  Reduces any rectangular or square matrix into an upper triangular matrix using progressive row elimination.

### 4. Advanced Spectral Analysis & Eigenvalues
- **`hessenberg.c`**:
  Implements Householder similarity transformations to reduce a square matrix to **Upper Hessenberg form** ($H = Q^T A Q$, where $H_{ij} = 0$ for all $i > j + 1$). Uses Householder reflection vectors:
  $$v = x \pm \|x\|_2 e_1, \quad P = I - 2 \frac{v v^T}{\|v\|^2}$$
  Reducing to Hessenberg form is the critical first step before running QR iterations, reducing per-iteration computational cost from $\mathcal{O}(n^3)$ to $\mathcal{O}(n^2)$.
- **`VALEUR PROPRE2.c`**:
  Implements the **QR Algorithm with Householder transformations** for finding all real eigenvalues:
  1. Detects symmetry ($A = A^T$). If non-symmetric, applies Hessenberg reduction.
  2. Iteratively factorizes $A_k = Q_k R_k$ and forms $A_{k+1} = R_k Q_k$.
  3. Uses a matrix stack (`Pile`) to measure convergence $(\|A_{k+1} - A_k\| < \varepsilon)$.
  4. Extracts eigenvalues along the converged diagonal.
  5. Computes algebraic multiplicity and determines geometric multiplicity ($\dim \ker(A - \lambda I)$) using rank deficiency.
- **`DIAGONALISATION.c`**:
  Analyzes whether $A$ is diagonalizable:
  - Verifies if geometric multiplicity equals algebraic multiplicity for all eigenvalues.
  - Generates the transition matrix $P$ formed by the eigenvectors and the diagonal matrix $D$ satisfying $D = P^{-1} A P$ (or $D = P^T A P$ for orthogonal matrices).

### 5. Linear Systems & Power Iteration (`systeme d_equation.c`)
- **Direct Gaussian Elimination (`methode_de_gauss`)**:
  Solves $Ax = b$ via row reduction to an upper triangular system followed by backward substitution.
- **Iterative Gauss-Seidel Method (`resolution_systeme`)**:
  Iteratively solves $Ax = b$ by splitting $A = D - L - U$. Evaluates diagonal dominance and performs row permutations when needed to guarantee iterative convergence.
- **Matrix Exponentiation (`puissance`)**:
  Computes matrix powers $A^p$ for integer exponents $p \ge 2$.

---

## 🛠️ Build and Compilation

### Prerequisites
- Any standard C compiler: **GCC**, **Clang**, or **MSVC** supporting C99 / C11.
- **CMake** (v3.10 or higher recommended, minimum 4.3 as configured).

### Option 1: Building with CMake
```bash
# Clone the repository
git clone https://github.com/kael-tombo/Matrix-operation-from-scratch.git
cd Matrix-operation-from-scratch

# Generate build files
cmake -B build -S .

# Compile
cmake --build build
```

### Option 2: Direct Compilation with GCC / Clang
```bash
gcc -O2 -std=c11 *.c -lm -o matrix_ops
./matrix_ops
```

On Windows (MinGW / MSYS2 / Command Prompt):
```powershell
gcc -O2 -std=c11 *.c -o matrix_ops.exe
.\matrix_ops.exe
```

---

## 🚀 Interactive CLI Usage

When executed, the program presents an interactive French console menu:

```text
           ############################################ 
           #                                          #
           #       WELCOME TO MATRIX OPERATION        #
           #                                          # 
           ############################################

     Operations matricielles disponibles :

     >  1.  ADDITION DE DEUX MATRICES
     >  2.  SOUSTRACTION DE DEUX MATRICES
     >  3.  MULTIPLICATION DE DEUX MATRICES
     >  4.  MULTIPLICATION PAR SCALAIRE
     >  5.  DETERMINANT D'UNE MATRICE
     >  6.  TRANSPOSITION D'UNE MATRICE
     >  7.  TRACE D'UNE MATRICE
     >  8.  COMBINAISON LINEAIRE
     >  9.  INVERSION D'UNE MATRICE
     >  10. RANG D'UNE MATRICE
     >  11. VALEUR PROPRE D'UNE MATRICE
     >  12. DIAGONALISATION D'UNE MATRICE
     >  13. TRIANGULARISATION D'UNE MATRICE
     >  14. RESOLUTION SYSTEME LINEAIRE (GAUSS / GAUSS-SEIDEL)
     >  15. PUISSANCE D'UNE MATRICE
     >  16. QUITTER LE PROGRAMME
```

Each operation features input validation for dimensions and floats, interactive input prompts, formatted tabular display of input and resulting matrices, and step-by-step intermediate messages.

---

## 🗺️ Roadmap & Modernization Strategy

What would you like to do with it now?

* [ ] Modernize and improve the C program
* [ ] Review or debug the source code
* [ ] Convert it into a professional project for GitHub
* [ ] Rewrite it in Java, Python, or C++
* [ ] Add a graphical user interface (GUI)
* [ ] Add advanced numerical methods and validation
* [ ] Create documentation, README, and technical report
* [ ] Turn it into a modern Matrix / Linear Algebra library

### Potential Extensions & Serious Enhancements
- **Memory Safety & Allocations**:
  - Replace raw `float**` pointer-to-pointer layouts with contiguous 1D array row-major representations (`float* data` with `stride = cols`).
  - Introduce an opaque struct `Matrix { size_t rows; size_t cols; float *data; }`.
- **Advanced Decompositions**:
  - Full **LU** decomposition with partial pivoting ($PA = LU$).
  - Explicit **QR** decomposition ($A = QR$) exposing orthogonal $Q$ and upper triangular $R$.
  - **Singular Value Decomposition (SVD)** ($A = U \Sigma V^T$).
  - **Cholesky** decomposition ($A = L L^T$) for symmetric positive-definite matrices.
- **Numerical Stability**:
  - Configurable precision (`double` / `long double`).
  - Machine epsilon-aware tolerances instead of hardcoded zero comparisons.
  - Condition number estimation ($\kappa(A) = \|A\| \cdot \|A^{-1}\|$).
- **Complex Matrices**:
  - Support for complex entries $\mathbb{C}$ and complex conjugate eigenvalues.
- **Least Squares & Overdetermined Systems**:
  - Solve $\min \|Ax - b\|_2$ using QR or SVD for data fitting and regression.
- **Testing & Benchmarks**:
  - Unit test suite (CTest / Unity / Criterion) testing against known analytic matrices.
  - Performance benchmarks comparing against OpenBLAS / LAPACK.
- **I/O & Formats**:
  - Import / export matrices from CSV, Matrix Market, and JSON.
- **Multi-language Bindings**:
  - Python wrapper via `ctypes` or `pybind11` / C-API.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.

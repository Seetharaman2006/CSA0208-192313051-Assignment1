# Rural Electricity Co-operative Billing Program

## Student Details

* **Name:** Seetharaman S
* **Register Number:** 192313051
* **Department:** Electrical and Electronics Engineering
* **Subject:** C Programming
* **Assignment:** Design, Implement and Validate a Reliable Billing Program for a Rural Electricity Co-operative

## Project Description

This assignment demonstrates C programming concepts through meter rollover calculations, slab-based electricity billing, and safe use of macros.

## Task 2: Meter Rollover

**File:** `Task02_meter_rollover.c`

This program calculates electricity consumption from previous and current meter readings. It demonstrates how unsigned arithmetic handles a single meter-register rollover.

**Test cases:**

* Previous reading: 1200; current reading: 1530; consumption: 330 units.
* Previous reading: 65400; current reading: 120; consumption: 256 units.

## Task 3: Electricity Billing

**File:** `Task03_electricity_billing.c`

This program calculates electricity bills using the specified tariff slabs.

| Consumption slab |           Rate |
| ---------------- | -------------: |
| First 100 units  |           Free |
| Units 101–200    | ₹2.25 per unit |
| Units above 200  | ₹4.50 per unit |
| Fixed charge     |            ₹50 |

The program stores monetary amounts in integer paise to avoid floating-point representation errors.

**Expected test results:**

| Units consumed | Total bill |
| -------------: | ---------: |
|              0 |     ₹50.00 |
|            100 |     ₹50.00 |
|            150 |    ₹162.50 |
|            200 |    ₹275.00 |
|            350 |    ₹950.00 |

## Task 4: Safe Macros

**File:** `Task04_safe_macros.c`

This program demonstrates:

* `SQUARE(x)` for calculating a square.
* `MAX(a, b)` for finding the larger value.
* Parentheses in macros to avoid operator-precedence errors.
* Why arguments with side effects, such as `i++`, should not be passed to macros that may evaluate arguments multiple times.

## Software and Compiler

* **Language:** C
* **Compiler:** GCC
* **Standard:** C11

Record the actual GCC version used to compile and execute the programs.

## Compilation Commands

Run these commands from the repository's root directory:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic Task02_meter_rollover.c -o Task02
gcc -std=c11 -Wall -Wextra -Wpedantic Task03_electricity_billing.c -o Task03
gcc -std=c11 -Wall -Wextra -Wpedantic Task04_safe_macros.c -o Task04
```

## Execution

On Windows PowerShell:

```powershell
.\Task02.exe
.\Task03.exe
.\Task04.exe
```

On Linux or macOS:

```bash
./Task02
./Task03
./Task04
```

## Complexity Analysis

Each meter consumption calculation and each electricity bill calculation takes O(1) time and O(1) auxiliary space for a single household, assuming the input fits the selected data types.

Processing n households sequentially takes O(n) time.

## Validation and Evidence

The programs should be compiled and executed using the commands above. Actual execution screenshots and any required input files should be included in the repository as specified by the assignment instructions.

## Repository

This repository contains the source code for Tasks 2, 3, and 4 of the C programming assignment.

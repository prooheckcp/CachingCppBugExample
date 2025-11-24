# Game State Corruption Demonstrator

This project is a minimal C++ program designed to simulate a simple game state interaction and demonstrate a common class of memory corruption bug: **the buffer overflow and subsequent data corruption of adjacent memory.**

It was developed as a supplementary resource for my assignment in "Advanced Topics in Software Engineering" at Ritsumeikan University.

The primary purpose of this repository is to provide a reproducible and traceable example for advanced debugging techniques, specifically the use of **Watchpoints** (Data Breakpoints) to identify the root cause of an unexpected variable modification.

## 💾 File Structure

| File         | Description |
|:-------------| :--- |
| `Health.h`   | Defines the `Health` class, which manages player health and the `AttackersList` array. |
| `Health.cpp` | Implementation of the `Health` component. |
| `Player.h`   | Defines the `Player` class, which contains the `Health` component. |
| `Player.cpp` | Implementation of the damage logic, which contains the intentional bug. |
| `main.cpp`   | The application entry point, which initializes two players and triggers the buggy function. |

## 🛠️ How to Build and Run

This project can be built using any standard C++ compiler (like GCC or Clang) or within an IDE like CLion. I was built in C++ 23 but earlier versions should work as well.


## 💥 The Expected vs. Observed Output

The `main.cpp` file initializes Player 1's health to 100 and then applies 10 points of damage.

* **Expected Final Health:** 90
* **Observed Final Health:** 0

This discrepancy is the **symptom** of the underlying memory bug. The program behaves incorrectly without crashing, making the error difficult to find by simple code review or line-by-line stepping.

## ⚠️ The Intentional Bug

The corruption occurs in the `Player::Damage(int amount, Player source)` method, which is intended to log the attacking player's ID into the `Health::AttackersList` array.

1.  The `AttackersList` is declared with a fixed size of 3 elements.
2.  The buggy code intended to "shift" the array elements to make room for a new attacker accidentally writes to an index that is **out-of-bounds** (`[3]`).
3.  Due to the memory layout of the `Health` structure, this out-of-bounds write overwrites the memory address of the immediately adjacent `CurrentHealth` variable, setting its value to 0, regardless of the intended damage amount.

This scenario is designed to showcase the power of **Watchpoints** in immediately identifying the specific line of code that corrupted the health variable, thereby facilitating rapid **root cause analysis**.
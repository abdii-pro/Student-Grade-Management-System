# Student Grade Management System

A C++ console application that manages student records, calculates grades, and handles dynamic memory allocation for efficient storage.

## Features
* **Dynamic Data Handling:** Uses pointers and dynamic arrays to grow/shrink storage as needed.
* **Grade Calculation:** Automatically calculates percentages and assigns grades (A-F).
* **Sorting:** Sorts students based on performance (percentage).
* **File Handling:** Exports the final report to `output.txt`.
* **CRUD Operations:** Add, Update, and Delete specific student records.

## How to Run

### Prerequisites
* A C++ Compiler (G++, Clang, or MSVC)

### Compilation
1.  Clone the repository:
    ```bash
    git clone https://github.com/abdii-pro/Student-Grade-Management-System/
    ```
2.  Compile the source code:
    ```bash
    g++ main.cpp -o student_system
    ```
3.  Run the executable:
    * **Windows:** `student_system.exe`
    * **Linux/Mac:** `./student_system`

## Note on Compatibility
This project uses `system("cls")` and `system("pause")`, which are Windows-specific commands. 
* If running on **Linux/MacOS**, you may need to replace `system("cls")` with `system("clear")`.

## Project Structure
* `main.cpp`: Contains the source code and logic.
* `output.txt`: Generated report (created after running the program).

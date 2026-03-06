# GPA & CGPA Calculator – C++ Project

## 1. Project Overview

The **GPA & CGPA Calculator** is a console-based C++ application designed to calculate:

* Semester Grade Point Average (GPA)
* Overall Cumulative Grade Point Average (CGPA)

The program accepts course grades and credit hours as input, computes total grade points, and displays both semester-wise GPA and final CGPA.

This project demonstrates the use of core C++ concepts such as functions, loops, conditionals, arithmetic operations, and formatted output.


## 2. Objectives

* To implement grade-to-grade point conversion logic.
* To calculate semester GPA based on course data.
* To compute overall CGPA across multiple semesters.
* To apply structured programming principles in C++.

## 3. Grading System Used

| Grade | Grade Point |
| ----- | ----------- |
| A     | 10.0        |
| B     | 8.0         |
| C     | 6.0         |
| D     | 4.0         |
| F     | 0.0         |

## 4. Formulae Used

### Total Grade Points (Per Semester)

Total Grade Points = Σ (Grade Point × Credit Hours)

### Semester GPA

GPA = Total Grade Points / Total Credits

### Overall CGPA

CGPA = Overall Grade Points (All Semesters) / Overall Credits (All Semesters)

## 5. Program Features

* Supports multiple semesters
* Accepts multiple courses per semester
* Calculates semester GPA
* Computes final overall CGPA
* Displays results with formatted precision
* Simple and user-friendly console interaction

## 6. How to Compile and Run

### Step 1: Compile the Program

```bash
g++ filename.cpp -o cgpa
```

### Step 2: Execute the Program

```bash
./cgpa
```

## 7. Sample Execution

**Input:**

```
Enter number of semesters: 2
Enter number of courses in Semester 1: 3
Enter grade and credit hours for each course...
```

**Output:**

```
Semester 1 GPA: 8.44
Semester 2 GPA: 8.86
Final Overall CGPA: 8.63
```



## 8. Technologies Used

* C++
* Standard Library (iostream, iomanip)



## 9. Learning Outcomes

Through this project, you will gain practical experience in:

* Function implementation
* Loop structures (for loops)
* Switch-case statements
* Floating-point calculations
* Code structuring and modular design



## 10. Future Enhancements

* Support for 4-point grading system
* Percentage conversion feature
* File handling for data storage
* Graphical User Interface (GUI) version
* Menu-driven program structure



## 11. Conclusion

The GPA & CGPA Calculator is a foundational academic project that strengthens understanding of core C++ programming concepts while solving a practical problem in academic evaluation systems.



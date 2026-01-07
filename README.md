# Student Record Management System
A C++ console-based Student Record Management System developed as part of the Foundation Track Internship.
This project focuses on strengthening programming fundamentals using Object-Oriented Programming (OOP) and binary file handling to maintain persistent student records.

# Project Overview
The application provides a menu-driven command-line interface that allows users to manage student records efficiently.Student data is stored in a binary file, ensuring that records remain available even after the program terminates.The project simulates a basic real-world data management workflow suitable for beginner-to-intermediate learners.

# Features
* Add new student records
* View all stored student records
* Search student records by Roll Number or Name
* Modify existing student records
* Delete student records
* Persistent data storage using a binary file (students.dat)
* Menu-driven CLI interface

# Technologies and Concepts Used
Language: C++
Programming Paradigm: Object-Oriented Programming (Classes & Objects)
File Handling: Binary file I/O using fstream
Core Concepts: CRUD Operations, File Persistence, Basic Input Validation, Modular Code Design

# Project Structure
Student Record Management System/
│
├── main.cpp        # Program entry point
├── Student.h      # Student class declaration
├── Student.cpp    # Student class implementation
├── students.dat   # Binary data file (auto-generated)

## How to Compile and Run
g++ main.cpp Student.cpp -o student
./student

## Data Storage
Student records are stored in a binary file named students.dat. The file is automatically created when the program runs and data remains intact across multiple executions of the program.

## Project Phase
Phase 2 – Project 1 Execution  
Foundation Track Internship

## Developer
Developed by Divya Garg



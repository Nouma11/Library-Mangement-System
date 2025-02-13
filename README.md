# Library Management System

![C++](https://img.shields.io/badge/C++-Programming-blue)
![OOP](https://img.shields.io/badge/OOP-Object%20Oriented%20Programming-green)
![File Handling](https://img.shields.io/badge/File%20Handling-File%20I%2FO-orange)
![Data Structures](https://img.shields.io/badge/Data%20Structures-Linked%20List%20%26%20Map-yellow)

A **Library Management System** built using **C++** that allows users to manage books, members, and transactions. This project demonstrates the use of **Object-Oriented Programming (OOP)**, **file handling**, and **data structures** such as **linked lists** and **maps**.

---

## Table of Contents

1. [Features](#features)
2. [Technologies Used](#technologies-used)
3. [Installation](#installation)
4. [Usage](#usage)
5. [File Structure](#file-structure)
6. [Data Structures](#data-structures)
7. [Contributing](#contributing)
8. [License](#license)
9. [Acknowledgments](#acknowledgments)
10. [Contact](#contact)

---

## Features

- **Add Books**: Add new books to the library with details like title, author, and genre.
- **Add Members**: Register new members with their name and contact information.
- **Issue Books**: Issue books to members and track due dates.
- **Return Books**: Return books and update their availability.
- **Search Books**: Search for books by ID or title using fast map lookups.
- **Display All Books/Members**: View a list of all books and members in the library.
- **File Persistence**: Data is saved to files (`books.txt`, `members.txt`, `transactions.txt`) for persistence.
- **Waiting List**: Manage a waiting list for unavailable books using linked lists.

---

## Technologies Used

- **Programming Language**: C++
- **Concepts**:
  - Object-Oriented Programming (OOP)
  - File Handling (`fstream`)
  - Data Structures (Linked List, Map, Vector)
- **Tools**:
  - Visual Studio Code (or any C++ IDE)
  - Git & GitHub (for version control)

---

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/library-management-system.git
   cd library-management-system

library-management-system/
├── books.txt                # Stores book data
├── members.txt              # Stores member data
├── transactions.txt         # Stores transaction data
├── main.cpp                 # Main program file
├── clsBook.h                # Book class definition
├── clsMember.h              # Member class definition
├── clsTransaction.h         # Transaction class definition
├── clsScreen.h              # Screen utility class
├── clsInputValidation.h     # Input validation utility
└── README.md                # Project documentation
   

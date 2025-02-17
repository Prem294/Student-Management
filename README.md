#Student Management System

📌 Project Overview

The Student Management System is a C++ console-based application designed to efficiently manage student records. It allows users to add, modify, search, display, and delete student information, ensuring data integrity with proper validation. The records are stored in a text file (studentRecord.txt) for future access.

✨ Features

✅ Add New Student Record (with email & contact number validation)
✅ Modify Existing Student Details
✅ View All Student Records
✅ Search for a Student by Roll Number
✅ Delete Student Records
✅ User-Friendly Menu Interface

🛠️ Technologies Used

C++ for core functionality

File Handling (fstream) for data storage

Regular Expressions (regex) for email validation

Basic Input Validation for ensuring correct contact numbers


📖 How to Use

1️⃣ Compile the Code

Use a C++ compiler like g++:

g++ student_management.cpp -o student_management

2️⃣ Run the Program

./student_management

3️⃣ Choose an Option from the Menu

Simply follow the on-screen instructions to add, modify, search, display, or delete records.

📂 File Storage Format

Student data is stored in studentRecord.txt in the following structure:

<Name> <Roll_No> <Course> <Email> <Contact_No> <Address>

🔍 Validation Rules

✔ Email Format: Must follow name@example.com pattern (Checked using regex)
✔ Contact Number: Must be exactly 10 digits
✔ No Duplicate Roll Numbers (Recommended for better data integrity)

🚀 Future Enhancements

🔹 Graphical User Interface (GUI) Integration
🔹 Database Support (MySQL/PostgreSQL)
🔹 Student Attendance & Grade Management
🔹 Login Authentication for Secure Access

👨‍💻 Author

📌 Prem294
📩 prempiyush29@gmail.com

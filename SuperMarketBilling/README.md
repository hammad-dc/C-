# 🛒 Supermarket Billing System in C++

This is a simple console-based C++ application that simulates a supermarket billing system using 
**Object-Oriented Programming (OOP)** and **file handling**.

It allows you to:
- Add new items to the inventory
- Generate a bill based on item and quantity
- Update stock in a file (`Bill.txt`)

---

## 📁 Files Included

- `main.cpp` – Main source code file containing the billing system
- `Bill.txt` – Stores the inventory (item name, rate, and quantity). Created/updated by the program.

---

## ⚙️ Features

✅ Add items with name, rate, and quantity  
✅ Save items persistently in `Bill.txt` using `ofstream`  
✅ Generate bills and subtract quantity from file  
✅ Uses OOP (`Bill` class) to manage item data  
✅ Simple and beginner-friendly CLI menu

---

## 🧪 Sample `Bill.txt` Format
Maggi : 15 : 10
Soap : 30 : 5

Each line stores:
- Item name
- Item rate
- Available quantity

---

## 📦 How to Run

1. Make sure you have a C++ compiler (like g++) installed.
2. Compile the code:
   ```bash
   g++ main.cpp -o billing
Run the executable:

bash
Copy
Edit
./billing   # or billing.exe on Windows
🧠 Concepts Used
Classes and objects

Constructor and getter/setter methods

File handling with ifstream, ofstream

String parsing with stringstream

Basic input/output

Loop-based menu and control flow

Temporary file creation and renaming for safe updates

📌 Notes
If Bill.txt does not exist, the program will create it automatically when adding items.

Make sure your terminal supports system("cls") and Sleep() (Windows only).

You can manually edit Bill.txt for testing purposes.

🙌 Author
👤 Hammad Siddique
C++ Beginner | Exploring OOP and Real-World Projects

💬 Feedback & Contributions
Feel free to fork this project, try it out, and improve it!
If you spot bugs or want new features, open an issue or PR.

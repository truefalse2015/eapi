# 📚 Effort API (eAPI) — Documentation Draft  
*Version 1.0 | Build 01062026 | MIT License*  
*⚠️ This documentation was generated with AI assistance and may contain inaccuracies. Please review and verify before use. Also, final version checked and fixed by developer.*

---

## 🚀 Quick Start

```c
#include "eapi.h"  // Just one line to start!

int main() {
    EapiInitialization();  // Optional: shows system info
    
    eapi_green("Hello, beginner! 👋\n");
    eapi_RESET();  // Always reset styles after colored text
    return 0;
}
```

---

## 🎨 Console Colors & Styles (CNSEDIT)

### ✨ Basic Colors
| Function | What it does | Example |
|----------|-------------|---------|
| `eapi_red("text")` | Prints red text | `eapi_red("Error!")` |
| `eapi_green("text")` | Prints green text | `eapi_green("Success!")` |
| `eapi_blue("text")` | Prints blue text | `eapi_blue("Info")` |
| `eapi_yellow("text")` | Prints yellow text | `eapi_yellow("Warning")` |
| `eapi_purple("text")` | Prints purple text | `eapi_purple("Magic")` |
| `eapi_cyan("text")` | Prints cyan text | `eapi_cyan("Cool!")` |
| `eapi_white("text")` | Prints white text | `eapi_white("Normal")` |
| `eapi_black("text")` | Prints black text | `eapi_black("Hidden?")` |

### 🌈 Background Colors
Just call the function without text to change background:
```c
eapi_redBG();  // Sets red background
printf("Text on red background");
eapi_RESET();  // Don't forget to reset!
```

### 💪 Text Styles
| Function | Effect |
|----------|--------|
| `eapi_BOLDSET()` | Makes text bold |
| `eapi_ULINESET()` | Underlines text |
| `eapi_FLASHING("text")` | Makes text blink ✨ |
| `eapi_red_BOLD("text")` | Red + Bold together |
| `eapi_green_HINT("text")` | Bright/high-intensity green |

### 🔁 Reset Everything
```c
eapi_RESET();  // Use this after any style to return to normal
```

### 🖱️ Cursor Control (Simple)
```c
eapi_cursor_UP(2);      // Move cursor up 2 lines
eapi_cursor_RIGHT(5);   // Move right 5 characters
eapi_cursor_HOME();     // Go to top-left corner
eapi_cursor_CUSTOM(10, 20); // Go to row 10, column 20
eapi_CLEAR();           // Clear the whole screen
```

### 👁️ Cursor Control (Professional)
Add `'h'` as second parameter to hide cursor while moving:
```c
eapi_cursor_DOWN_P(3, 'h');  // Move down + hide cursor
```

---

## 📁 Working with Files (FS)

### 🔍 Check if File Exists
```c
if (object_exists("config.txt")) {
    eapi_green("File found! ✓\n");
} else {
    eapi_red("File not found ✗\n");
}
```

### ➕ Create New File
```c
if (eapi_newObject("notes.txt")) {
    printf("File created!\n");
}
```

### 🗑️ Delete File or Folder
```c
// Delete a file
eapi_remove("old_file.txt", FILE_TYPE);

// Delete an empty folder
eapi_remove("temp_folder", DIR_TYPE);
```

### 📂 Create Folder (Cross-Platform)
```c
mkdir_os("my_new_folder");  // Works on Windows, Linux, macOS
```

---

## 🔢 Math & Utilities

### ⏱️ Delays (Pause Your Program)
```c
eapi_systemDelay_ms(500);   // Wait 500 milliseconds
eapi_systemDelay_sec(2);    // Wait 2 seconds
eapi_systemDelay_min(1);    // Wait 1 minute
// Linux/macOS also has: eapi_systemDelay_us(1000); // microseconds
```

### 🎲 Random Numbers
```c
eapi_srandInitialization();  // Call once at start
int num = eapi_rand(100);    // Gets number from 0 to 99
```

### ➕➖✖️➗ Basic Math
```c
int sum = eapi_math_add(5, 3);           // 8
double avg = eapi_math_division_double(10.0, 2.0);  // 5.0
int power = eapi_math_pow(2, 3);         // 8 (2³)
int root = eapi_math_sqrt(16);           // 4 (√16)
```

### ⚠️ Safe Division (No Crashes!)
```c
int error = 0;
int result = eapi_math_division_professional(10, 0, &error);
if (error) {
    printf("Oops! Can't divide by zero!\n");
}
```

### 🔁 Swap Two Values
```c
int a = 10, b = 20;
eapi_swap(&a, &b);  // Now a=20, b=10

// Also works for double and float:
// eapi_swap_double(&x, &y);
// eapi_swap_float(&p, &q);
```

---

## 🌍 Cross-Platform Notes

✅ Works on: **Windows**, **Linux**, **macOS**  
✅ Header-only: just `#include "eapi.h"` — no compiling needed  
✅ MIT License: use freely, just keep the author credit  

⚠️ **Windows Tip**: ANSI colors work best on Windows 10 (build 10586+) or newer. On older Windows, colors may show as plain text.

---

## 🧭 Function Naming Guide

All functions start with:
- `eapi_` → main functions
- `_eapi_` → internal helpers (you don't need to call these)

Examples:
- `eapi_green()` → you use this ✅  
- `_eapi_cnsedit_win_init()` → library uses this internally ❌

---

## 💡 Pro Tips for Beginners

1. 🎯 Always call `eapi_RESET()` after colored/styled text
2. 🔒 Check return values for file functions (they return `1` = success, `0` = error)
3. 🧪 Test small pieces first — don't write 100 lines before running!
4. 📝 Keep this doc handy — copy/paste examples to learn faster
5. ❤️ It's okay to make mistakes — that's how we learn!

---

## 📬 Support & Community

- 📧 Email: `wolfzoneteam@gmail@gmail.com`  
- 🌐 Languages: English + Русский

*Made with ❤️ by Elkin Mathey*

License: MIT — Use, modify, share. Just give credit!*  

---

🛠️ **Draft Notice**: This documentation is a work in progress. If you find errors or have ideas to improve it — thank you! Every contribution helps beginners like you and me grow.

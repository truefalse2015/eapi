# Effort API (eAPI) — Documentation 📚

> **Version:** 0.99 (Build 27052026)  
> **License:** MIT  
> **Author:** Elkin Matvey  
> **Repository:** `truefalse2015/eAPI`  
> **Language:** Pure C, Header-Only, Cross-Platform  

---

## 📋 Table of Contents

1. [Overview](#-overview)
2. [Features](#-features)
3. [Quick Start](#-quick-start)
4. [Module: CNSEDIT (Console)](#-module-cnsedit-console)
5. [Module: FS (Filesystem)](#-module-fs-filesystem)
6. [Module: MATH (Mathematics)](#-module-math-mathematics)
7. [Platform Notes](#-platform-notes)
8. [Best Practices](#-best-practices)
9. [Troubleshooting](#-troubleshooting)
10. [License](#-license)

---

## ✨ Overview

**Effort API (eAPI)** is a lightweight, header-only C library designed to simplify common development tasks for beginners and experienced programmers alike.

eAPI follows three core principles:
- 🔹 **Nothing breaks** — Simple, predictable functions with minimal dependencies
- 🔹 **Just `#include`** — No build system, no linking, no configuration
- 🔹 **Cross-platform by design** — Works on Windows, Linux, and macOS

### What eAPI Provides

| Module | Purpose |
|--------|---------|
| 🔹 **CNSEDIT** | Console output: colors, formatting, cursor control |
| 🔹 **FS** | Filesystem utilities: check if file/directory exists |
| 🔹 **MATH** | Basic arithmetic and math functions for `int` and `double` |

---

## 🚀 Features

✅ **Header-only** — Single file: `eapi.h`. Just copy and include.  
✅ **No external dependencies** — Uses only standard C library + platform APIs.  
✅ **Cross-platform** — Automatic detection: `_WIN32`, `__linux__`, `__APPLE__`.  
✅ **Static inline functions** — Zero runtime overhead, no linking issues.  
✅ **Beginner-friendly API** — Clear function names, consistent patterns.  
✅ **Safe by default** — Buffer limits (`%.99s`, `%.499s`), error checks.  

---

## ⚡ Quick Start

### 1. Download
Save `eapi.h` to your project folder.

### 2. Include
```c
#include "eapi.h"
```

### 3. Compile
```bash
# Linux/macOS
gcc main.c -o main -lm

# Windows (MinGW)
gcc main.c -o main.exe
```

### 4. Hello, Colored World!
```c
#include "eapi.h"

int main(void) {
    CNSEDIT_ANSI_GREEN("Hello, ");
    CNSEDIT_ANSI_RED_BOLD("World!");
    CNSEDIT_ANSI_RESET();
    printf("\n");
    return 0;
}
```

**Output:**  
`Hello, `**`World!`** (in green + red bold)

---

## 🎨 Module: CNSEDIT (Console)

> Signal: *"Now we will work with the console."*

### 🔹 Text Colors (Normal)

| Function | Description | Example |
|----------|-------------|---------|
| `CNSEDIT_ANSI_BLACK(const char *text)` | Print black text | `CNSEDIT_ANSI_BLACK("Error");` |
| `CNSEDIT_ANSI_RED(const char *text)` | Print red text | `CNSEDIT_ANSI_RED("Warning!");` |
| `CNSEDIT_ANSI_GREEN(const char *text)` | Print green text | `CNSEDIT_ANSI_GREEN("OK");` |
| `CNSEDIT_ANSI_BLUE(const char *text)` | Print blue text | `CNSEDIT_ANSI_BLUE("Info");` |
| `CNSEDIT_ANSI_YELLOW(const char *text)` | Print yellow text | `CNSEDIT_ANSI_YELLOW("Notice");` |
| `CNSEDIT_ANSI_PURPLE(const char *text)` | Print purple text | `CNSEDIT_ANSI_PURPLE("Debug");` |
| `CNSEDIT_ANSI_CYAN(const char *text)` | Print cyan text | `CNSEDIT_ANSI_CYAN("Tip");` |
| `CNSEDIT_ANSI_WHITE(const char *text)` | Print white text | `CNSEDIT_ANSI_WHITE("Normal");` |

### 🔹 Background Colors

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_BLACKBG(void)` | Set black background |
| `CNSEDIT_ANSI_REDBG(void)` | Set red background |
| `CNSEDIT_ANSI_GREENBG(void)` | Set green background |
| `CNSEDIT_ANSI_BLUEBG(void)` | Set blue background |
| `CNSEDIT_ANSI_YELLOWBG(void)` | Set yellow background |
| `CNSEDIT_ANSI_PURPLEBG(void)` | Set purple background |
| `CNSEDIT_ANSI_CYANBG(void)` | Set cyan background |
| `CNSEDIT_ANSI_WHITEBG(void)` | Set white background |

### 🔹 Formatting: Bold

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_RED_BOLD(const char *text)` | Bold red text |
| `CNSEDIT_ANSI_GREEN_BOLD(const char *text)` | Bold green text |
| `...` | *(Same pattern for all 8 colors)* |
| `CNSEDIT_ANSI_BOLDSET(void)` | Enable bold mode (without text) |

### 🔹 Formatting: Underline

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_RED_ULINE(const char *text)` | Underlined red text |
| `...` | *(Same pattern for all 8 colors)* |
| `CNSEDIT_ANSI_ULINESET(void)` | Enable underline mode |

### 🔹 High Intensity (Bright) Colors

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_RED_HINT(const char *text)` | Bright red text |
| `...` | *(Same pattern for all 8 colors)* |

### 🔹 Bold + High Intensity

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_RED_BHI(const char *text)` | Bold + bright red |
| `...` | *(Same pattern for all 8 colors)* |

### 🔹 Special Formatting

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_FLASHING(const char *text)` | Flashing text (terminal-dependent) |
| `CNSEDIT_ANSI_RESET(void)` | **Reset all styles** — always call after colored output |
| `CNSEDIT_IO_OUTPUT(const char *text)` | Safe print with 499-char limit |

### 🔹 Cursor Control (SIMPLE)

| Function | Description | Example |
|----------|-------------|---------|
| `CNSEDIT_ANSI_CURSOR_LEFT(int sym)` | Move cursor left N positions | `CNSEDIT_ANSI_CURSOR_LEFT(5);` |
| `CNSEDIT_ANSI_CURSOR_RIGHT(int sym)` | Move cursor right N positions | `CNSEDIT_ANSI_CURSOR_RIGHT(3);` |
| `CNSEDIT_ANSI_CURSOR_UP(int column)` | Move cursor up N lines | `CNSEDIT_ANSI_CURSOR_UP(2);` |
| `CNSEDIT_ANSI_CURSOR_DOWN(int column)` | Move cursor down N lines | `CNSEDIT_ANSI_CURSOR_DOWN(1);` |
| `CNSEDIT_ANSI_CURSOR_HOME(void)` | Move cursor to top-left (0,0) | `CNSEDIT_ANSI_CURSOR_HOME();` |
| `CNSEDIT_ANSI_CURSOR_CUSTOM(int row, int col)` | Move to specific position | `CNSEDIT_ANSI_CURSOR_CUSTOM(10, 20);` |
| `CNSEDIT_ANSI_CURSOR_SAVE(void)` | Save current cursor position | `CNSEDIT_ANSI_CURSOR_SAVE();` |
| `CNSEDIT_ANSI_CURSOR_PREVIOUS(void)` | Restore saved position | `CNSEDIT_ANSI_CURSOR_PREVIOUS();` |
| `CNSEDIT_ANSI_CLEAR(void)` | Clear entire screen | `CNSEDIT_ANSI_CLEAR();` |
| `CNEDIT_ANSI_LINECURSCLEAR(void)` | Clear from cursor to end of line | `CNEDIT_ANSI_LINECURSCLEAR();` |
| `CNEDIT_ANSI_CURSOR_FLASHING_ON(void)` | Enable cursor blinking | `CNEDIT_ANSI_CURSOR_FLASHING_ON();` |
| `CNEDIT_ANSI_CURSOR_FLASHING_OFF(void)` | Disable cursor blinking | `CNEDIT_ANSI_CURSOR_FLASHING_OFF();` |

### 🔹 Cursor Control (PROFESSIONAL)

Same functions as SIMPLE, but with `_P` suffix and extra `hide_or_show` parameter:

```c
// Hide cursor while moving
CNSEDIT_ANSI_CURSOR_LEFT_P(5, 'h');  // 'h' = hide
CNSEDIT_ANSI_CURSOR_LEFT_P(5, 'x');  // any other char = keep visibility
```

| Function | Extra Parameter |
|----------|----------------|
| `CNSEDIT_ANSI_CURSOR_LEFT_P(int sym, char hide_or_show)` | `'h'` to hide cursor |
| `CNSEDIT_ANSI_CURSOR_RIGHT_P(...)` | Same pattern |
| `...` | *(All cursor functions have `_P` variants)* |

---

## 📁 Module: FS (Filesystem)

> Signal: *"Attention! Now we will work with the filesystem."*

### 🔹 Check if File/Directory Exists

```c
int FS_OBJ_EXISTS(const char *filename);
```

| Parameter | Description |
|-----------|-------------|
| `filename` | Path to file or directory (max 499 chars) |

**Returns:**
- `1` (true) — object exists and is accessible
- `0` (false) — object does not exist or access denied

**Example:**
```c
if (FS_OBJ_EXISTS("config.txt")) {
    CNSEDIT_ANSI_GREEN("Config found!\n");
} else {
    CNSEDIT_ANSI_RED("Config missing!\n");
}
```

**Safety Notes:**
- ✅ Uses `snprintf` with size limit to prevent buffer overflow
- ✅ On Windows: uses `fopen()` check
- ✅ On Unix: uses `access(path, F_OK)`

---

## 🔢 Module: MATH (Mathematics)

> Simple arithmetic for `int` and `double` types.

### 🔹 Basic Operations (int)

| Function | Description | Example | Returns |
|----------|-------------|---------|---------|
| `MATH_BASE_PLUS(int a, int b)` | Addition | `MATH_BASE_PLUS(2, 3)` | `5` |
| `MATH_BASE_MINUS(int a, int b)` | Subtraction | `MATH_BASE_MINUS(10, 4)` | `6` |
| `MATH_BASE_MULTIPLY(int a, int b)` | Multiplication | `MATH_BASE_MULTIPLY(3, 4)` | `12` |
| `MATH_BASE_DIVISION(int a, int b)` | Division | `MATH_BASE_DIVISION(20, 5)` | `4` |

### 🔹 Basic Operations (double)

| Function | Description | Example | Returns |
|----------|-------------|---------|---------|
| `MATH_BASE_PLUS_DOUBLE(double a, double b)` | Addition | `MATH_BASE_PLUS_DOUBLE(2.5, 1.5)` | `4.0` |
| `MATH_BASE_MINUS_DOUBLE(double a, double b)` | Subtraction | `MATH_BASE_MINUS_DOUBLE(10.0, 3.2)` | `6.8` |
| `MATH_BASE_MULTIPLY_DOUBLE(double a, double b)` | Multiplication | `MATH_BASE_MULTIPLY_DOUBLE(2.0, 3.5)` | `7.0` |
| `MATH_BASE_DIVISION_DOUBLE(double a, double b)` | Division | `MATH_BASE_DIVISION_DOUBLE(10.0, 4.0)` | `2.5` |

### 🔹 Advanced Functions (NS = "Not Standard")

| Function | Description | Example | Returns |
|----------|-------------|---------|---------|
| `MATH_NS_SQRT(int num)` | Square root (int) | `MATH_NS_SQRT(16)` | `4` |
| `MATH_NS_SQRT_DOUBLE(double num)` | Square root (double) | `MATH_NS_SQRT_DOUBLE(2.0)` | `~1.414` |
| `MATH_NS_POWER(int num, int power)` | Exponentiation (int) | `MATH_NS_POWER(2, 3)` | `8` |
| `MATH_NS_POWER_DOUBLE(double num, double power)` | Exponentiation (double) | `MATH_NS_POWER_DOUBLE(2.0, 0.5)` | `~1.414` |

> ⚠️ **Note:** These functions use `sqrt()` and `pow()` from `<math.h>`. Link with `-lm` on Linux/macOS.

---

## 🖥️ Platform Notes

### Windows
- ✅ ANSI colors work on **Windows 10 (build 10586+)** and later
- ⚠️ On Windows 7/8: ANSI codes may display as plain text
- 🔧 eAPI auto-enables `ENABLE_VIRTUAL_TERMINAL_PROCESSING` via `_eapi_cnsedit_win_init()`
- 📦 No extra libraries needed — uses `windows.h`

### Linux / macOS
- ✅ ANSI codes work in most modern terminals (GNOME Terminal, iTerm2, etc.)
- 📦 Requires `<unistd.h>` for `access()` function
- 🔗 Compile with `-lm` to link math library:  
  ```bash
  gcc main.c -o main -lm
  ```

### Cross-Platform Tips
```c
// Always reset styles after colored output
CNSEDIT_ANSI_RED("Error");
CNSEDIT_ANSI_RESET();

// Use FS_OBJ_EXISTS instead of platform-specific checks
if (FS_OBJ_EXISTS("data.txt")) { /* ... */ }

// For math functions, remember to link -lm on Unix
```

---

## 🛡️ Best Practices

### ✅ Do
```c
// 1. Always reset after colored output
CNSEDIT_ANSI_GREEN("Success");
CNSEDIT_ANSI_RESET();

// 2. Check return values for FS functions
if (FS_OBJ_EXISTS("file.txt") == 1) { /* ... */ }

// 3. Use const char* for string literals
CNSEDIT_ANSI_BLUE("Hello");  // OK

// 4. Link math library on Unix
// gcc main.c -lm
```

### ❌ Avoid
```c
// 1. Forgetting to reset (text stays colored)
CNSEDIT_ANSI_RED("Warning");
printf("This will also be red!\n");  // Oops!

// 2. Passing NULL to text functions
CNSEDIT_ANSI_GREEN(NULL);  // Undefined behavior

// 3. Using MATH_BASE_DIVISION with zero
MATH_BASE_DIVISION(10, 0);  // Crash!

// 4. Assuming ANSI works everywhere
// Test on target platform!
```

### 🔁 Consistency Pattern
All CNSEDIT functions follow this pattern:
```c
// 1. Initialize platform-specific settings (Windows only)
_eapi_cnsedit_win_init();

// 2. Print ANSI code + formatted text
printf("\033[0;31m%.99s", text);  // Red, max 99 chars
```

---

## 🐛 Troubleshooting

| Problem | Possible Cause | Solution |
|---------|---------------|----------|
| 🔹 Colors show as plain text on Windows | Old Windows version or terminal | Use Windows Terminal / Update to Win10 10586+ |
| 🔹 `undefined reference to 'sqrt'` | Missing math library link | Add `-lm` to gcc command |
| 🔹 Cursor doesn't move | Terminal doesn't support ANSI | Try different terminal (xterm, gnome-terminal) |
| 🔹 Buffer overflow warning | Text > 99/499 chars | Use shorter strings or split output |
| 🔹 `FS_OBJ_EXISTS` returns false for existing file | Permission issue | Check file permissions / run as admin |

### Debug Mode (Optional)
Add this to your code to see platform detection:
```c
#ifdef _WIN32
    printf("Running on Windows\n");
#elif __linux__
    printf("Running on Linux\n");
#elif __APPLE__
    printf("Running on macOS\n");
#endif
```

---

## 📜 License

```
MIT License

Copyright (c) 2026 Elkin Matvey

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

### Attribution
If you use eAPI in your project, please include:
```
This project uses Effort API (eAPI) by Elkin Matvey.
https://github.com/truefalse2015/eAPI
```

---

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/my-idea`
3. Commit changes: `git commit -m "Add: new feature"`
4. Push: `git push origin feature/my-idea`
5. Open a Pull Request

### Code Style
- 🔹 Use `static inline` for all functions
- 🔹 Prefix internal functions with `_eapi_`
- 🔹 Document public functions with comments
- 🔹 Keep buffer limits consistent (`%.99s`, `%.499s`)

---

## 📬 Contact

| Method | Details |
|--------|---------|
| 🔹 **GitHub** | [`truefalse2015/eAPI`](https://github.com/truefalse2015/eAPI) |
| 🔹 **Email** | `truefalsesofts@gmail.com` |

> 💡 **Note:** No phone / VK due to spam and international audience.

---

*Documentation generated for eAPI v0.99 (Build 27052026)*  
*Last updated: 27 May 2026*  
*Made by Elkin Matvey*

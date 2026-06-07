# Effort API — Documentation Draft  
Version 1.1 | Build 06062026   

## Quick Start

```c
#include "eapi.h"  // Main header

int main() {
    eapi_init(); // optional on Unix systems, needed in Windows
    
    eapi_printf(EAPI_GREEN, "Hello, world!\n"); // print the our first line
    return 0;
}
```

---

### Basic Colors
In EAPI color defined in enum
| constant | value |
| :--- | ---: |
| EAPI_RED | ANSI Red color |
| EAPI_GREEN | ANSI Green color |
| EAPI_YELLOW | ANSI Yellow color |
| EAPI_BLUE | ANSI Blue color |
| EAPI_MAGENTA | ANSI Magenta color |
| EAPI_CYAN | ANSI Cyan color |
| EAPI_WHITE | ANSI White color |
| EAPI_BLACK | ANSI Black color |
| EAPI_RESET | Return to default state |
| EAPI_BOLD | ANSI __Bold__ |
| EAPI_DIM | ANSI Dim |
| EAPI_ITALIC | ANSI _Italic_ |
| EAPI_UNDERLINE | ANSI Underline |
| EAPI_BR_RED | ANSI Bright Red color |
| EAPI_BR_YELLOW | ANSI Bright Yellow color |
| EAPI_BR_GREEN | ANSI Bright Green color |
| EAPI_BR_BLACK | ANSI Bright Black color |
| EAPI_BR_BLUE | ANSI Bright Blue color |
| EAPI_BR_CYAN | ANSI Bright Cyan color |
| EAPI_BR_MAGENTA | ANSI Bright Magenta color |
| EAPI_BR_WHITE | ANSI Bright White color |

---

## FS 
FS or IO is functions that can create or remove files
### Check is file exists
```c
if (is_file_exists("config.txt")) {
    eapi_printf(EAPI_GREEN, "File found! ✓\n");
} else {
    eapi_printf(EAPI_RED, "File not found ✗\n");
}
```

### Create new file
```c
if (eapi_new_object("Apikey")) {
    eapi_printf(EAPI_GREEN, "File created!\n");
}
```

### Delete file or folder
Eapi remove function has 2 types, FILE_TYPE and DIR_TYPE
```c
// Delete a file
eapi_remove("old_file.txt", FILE_TYPE);

// Delete an empty folder
eapi_remove("temp_folder", DIR_TYPE);
```

### Create folder
```c
mkdir_os("my_new_folder");
```

---

### Delay
Eapi's delay function requires delay in milliseconds, so for seconds or minute needed to multiply the value
```c
eapi_delay(500);   // Wait 500 milliseconds
eapi_delay(2 * 1000);    // Wait 2 seconds
eapi_delay(1 * 60000);    // Wait 1 minute
```

### Random numbers
```c
eapi_rand_init();  // Call once at start
int rando = eapi_rand_range(10, 20);    // Gets number from 10 to 20
```

### Swap two values
```c
int a = 10, b = 20;
eapi_swap(a, b);  // Now a=20, b=10
```

### Gen random strings
```c
char *str = eapi_gen_random_string_element(32); // Gen the string, function returns pointer on this string

eapi_printf(EAPI_CYAN, str);

free(str); // don't forget to freed buffer 
```
you can also use this macro to fill all your buffer: EAPI_RANDOM_ALL_BUFFER(buffer)

---

## Cross-Platform 

Eapi is small cross-platform single-header library, provides small functions for comfortable work with C

**Windows Tip**: ANSI colors work best on Windows 10 (build 10586+) or newer. On older Windows, colors may show as plain text.

---

## Function Naming Guide

All functions start with:
- `eapi_` → main functions
- `_eapi_` → internal helpers (you don't need to call these)

Examples:
- `eapi_printf(EAPI_CYAN, "Hello")` → you use this   
- `_eapi_cnsedit_win_init()` → library uses this internally 

---


## 📬 Support & Community

- 📧 Email: `wolfzoneteam@gmail@gmail.com`  
- 🌐 Languages: English + Русский

*Made with ❤️ by Elkin Mathey*

License: MIT — Use, modify, share. Just give credit!

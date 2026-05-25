# eAPI Documentation

**Effort API (eAPI)** — a lightweight, header-only C library providing cross-platform console styling and basic file system utilities.

---

## Table of Contents

- [Overview](#overview)
- [License](#license)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [API Reference](#api-reference)
  - [Console Module (CNSEDIT)](#console-module-cnsedit)
  - [File System Module (FS)](#file-system-module-fs)
- [Platform Notes](#platform-notes)
- [Contributing](#contributing)

---

## Overview

eAPI is designed for developers who need simple, portable console output formatting and file existence checks without external dependencies. The library uses `static inline` functions for zero-linkage overhead and follows a "nothing breaks" philosophy.

**Key features:**
- Header-only distribution (`eapi.h`)
- Cross-platform ANSI color support (Windows 10+, Linux, macOS)
- Safe string handling with bounded output functions
- C++ compatibility via `extern "C"`

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

> Copyright (c) 2026 Elkin Matvey  
> Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  
> The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

---

## Requirements

- C99 or later
- Standard library headers: `<stdio.h>`, `<string.h>`
- Platform-specific headers (included automatically):
  - Windows: `<windows.h>`
  - Linux/macOS: `<unistd.h>`, `<sys/stat.h>`

**Compiler support:** GCC, Clang, MSVC (Windows 10 SDK or later)

---

## Installation

1. Download or clone `eapi.h` from the repository.
2. Place the file in your project directory or include path.
3. Include the header in your source file:

```c
#include "eapi.h"
```

No compilation or linking steps are required.

---

## Usage

### Basic Example

```c
#include <stdio.h>
#include "eapi.h"

int main(void) {
    // Print colored text
    CNSEDIT_ANSI_GREEN_BOLD("Success: Operation completed.");
    CNSEDIT_ANSI_RESET();
    printf("\n");

    // Check file existence
    if (FS_OBJ_EXISTS("config.txt")) {
        CNSEDIT_IO_OUTPUT("Configuration file found.");
    } else {
        CNSEDIT_ANSI_RED("Error: config.txt not found.");
        CNSEDIT_ANSI_RESET();
    }

    return 0;
}
```

### Compilation

```bash
# Linux/macOS
gcc -std=c99 -Wall -Wextra main.c -o app

# Windows (MinGW)
gcc -std=c99 -Wall -Wextra main.c -o app.exe

# Windows (MSVC)
cl /std:c11 main.c
```

---

## API Reference

### Console Module (CNSEDIT)

All console functions accept a `const char *text` parameter and output formatted text to `stdout`. Most functions automatically limit output to 99 characters for safety.

#### Color Functions

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_BLACK(const char *text)` | Print text in black foreground |
| `CNSEDIT_ANSI_RED(const char *text)` | Print text in red foreground |
| `CNSEDIT_ANSI_GREEN(const char *text)` | Print text in green foreground |
| `CNSEDIT_ANSI_BLUE(const char *text)` | Print text in blue foreground |
| `CNSEDIT_ANSI_YELLOW(const char *text)` | Print text in yellow foreground |
| `CNSEDIT_ANSI_PURPLE(const char *text)` | Print text in purple (magenta) foreground |
| `CNSEDIT_ANSI_CYAN(const char *text)` | Print text in cyan foreground |
| `CNSEDIT_ANSI_WHITE(const char *text)` | Print text in white foreground |

#### Background Color Functions

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_BLACKBG(void)` | Set black background (affects subsequent output) |
| `CNSEDIT_ANSI_REDBG(void)` | Set red background |
| `CNSEDIT_ANSI_GREENBG(void)` | Set green background |
| `CNSEDIT_ANSI_BLUEBG(void)` | Set blue background |
| `CNSEDIT_ANSI_YELLOWBG(void)` | Set yellow background |
| `CNSEDIT_ANSI_PURPLEBG(void)` | Set purple background |
| `CNSEDIT_ANSI_CYANBG(void)` | Set cyan background |
| `CNSEDIT_ANSI_WHITEBG(void)` | Set white background |

#### Formatting Functions

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_<COLOR>_BOLD(const char *text)` | Print text in bold with specified color |
| `CNSEDIT_ANSI_<COLOR>_ULINE(const char *text)` | Print text underlined with specified color |
| `CNSEDIT_ANSI_<COLOR>_HINT(const char *text)` | Print text in high-intensity (bright) color |
| `CNSEDIT_ANSI_<COLOR>_BHI(const char *text)` | Print text in bold high-intensity color |
| `CNSEDIT_ANSI_BOLDSET(void)` | Enable bold formatting for subsequent output |
| `CNSEDIT_ANSI_ULINESET(void)` | Enable underline formatting for subsequent output |
| `CNSEDIT_ANSI_FLASHING(const char *text)` | Print text with flashing attribute (terminal-dependent) |

#### Utility Functions

| Function | Description |
|----------|-------------|
| `CNSEDIT_ANSI_RESET(void)` | Reset all text attributes to default |
| `CNSEDIT_IO_OUTPUT(const char *text)` | Print text safely (max 499 characters) without formatting |

**Note:** Replace `<COLOR>` with one of: `BLACK`, `RED`, `GREEN`, `BLUE`, `YELLOW`, `PURPLE`, `CYAN`, `WHITE`.

---

### File System Module (FS)

| Function | Signature | Description |
|----------|-----------|-------------|
| `FS_OBJ_EXISTS` | `static inline int FS_OBJ_EXISTS(const char *filename)` | Checks if a file exists and is accessible. Returns `1` if the file exists, `0` otherwise. Uses `fopen` on Windows and `access` on POSIX systems. |

**Parameters:**
- `filename` — Path to the file (null-terminated string). Maximum effective length: 499 characters.

**Return value:**
- `1` — File exists and is readable.
- `0` — File does not exist or cannot be accessed.

**Example:**
```c
if (FS_OBJ_EXISTS("data.log")) {
    // Proceed with file operations
}
```

---

## Platform Notes

### Windows

- ANSI color support requires Windows 10 version 1511 (build 10586) or later.
- The function `_eapi_cnsedit_win_init()` enables Virtual Terminal Processing automatically on first use.
- On older Windows versions, ANSI escape sequences may be printed as plain text. No runtime error occurs.

### Linux / macOS

- ANSI escape sequences are supported by default in most terminal emulators.
- The `<unistd.h>` header is required for `access()` in the `FS_OBJ_EXISTS` function.

### C++ Compatibility

The library uses `extern "C"` guards to allow inclusion in C++ projects without name mangling.

---

## Contributing

Contributions are welcome. To report issues or suggest improvements:

1. Open an issue on the [GitHub repository](https://github.com/truefalse2015/eapi).
2. Provide a clear description and, if applicable, a minimal reproducible example.
3. For code contributions, ensure changes are compatible with C99 and do not introduce external dependencies.

---

## Version

**eAPI Beta-250526** — Initial public release.

---

## Author

Elkin Matvey ([truefalse2015](https://github.com/truefalse2015))

---

*Documentation generated for eAPI Beta-250526. Subject to change in future releases.*

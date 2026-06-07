/* ****************************************
 * It is terrible, but at least it works
 * I don't just think it helps beginners — I'm sure of it <3
 **************************************** */

// Copyright (c) 2026 Elkin Matvey
/***
 * LICENSE:
 * THIS PROJECT HAS A MIT LICENSE, WHICH MEANS THAT THE SOURCE CODE OF THE
 * PROJECT CAN BE STUDIED, MODIFIED, AND EVEN SOLD, BUT WITH MANDATORY
 * ATTRIBUTATION (AUTHOR: ELKIN MATVEY).
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ====== THE EFFORT API PROJECT ======
 
 /* Effort API 1 (1.1) Build 01062026 */

#ifndef EAPI_H
#define EAPI_H

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
	#define EAPI_PLATFORM_WINDOWS
	#include <windows.h>
	#include <direct.h>
	#define mkdir_os(path) _mkdir(path)
	#define rmdir_cp(path) _rmdir(path)
	#define EAPI_CURRENT_PLATFORM "Windows"
#elif defined(__linux__)
	#define EAPI_PLATFORM_LINUX
	#include <sys/stat.h> 
	#include <sys/types.h>
	#include <unistd.h>
	#define mkdir_os(path) mkdir(path, 0755)
	#define rmdir_cp(path) rmdir(path)
	#define EAPI_CURRENT_PLATFORM "Linux"
#elif defined(__APPLE__)
	#define EAPI_PLATFROM_APPLE
	#include <sys/stat.h> 
	#include <sys/types.h>
	#include <unistd.h>
	#define rmdir_cp(path) rmdir(path)
	#define mkdir_os(path) mkdir(path, 0755)
	#define EAPI_CURRENT_PLATFORM "Apple"
#elif defined(__unix__) 
	#define EAPI_PLATFORM_UNIX
	#include <sys/stat.h> 
	#include <sys/types.h>
	#include <unistd.h>
	#define rmdir_cp(path) rmdir(path)
	#define mkdir_os(path) mkdir(path, 0755)
	#define EAPI_CURRENT_PLATFORM "Unix"
#elif defined(__GNU__) || defined(__gnu_hurd__)
	#define EAPI_PLATFORM_GNU
	#include <sys/stat.h> 
	#include <sys/types.h>
	#include <unistd.h>
	#define rmdir_cp(path) rmdir(path)
	#define mkdir_os(path) mkdir(path, 0755)
	#define EAPI_CURRENT_PLATFORM "GNU Hurd"
#else
	#error "Unknown system"
#endif

typedef enum {
	EAPI_RESET = 0,
	EAPI_RED,
	EAPI_GREEN,
	EAPI_YELLOW,
	EAPI_BLUE, 
	EAPI_MAGENTA,
	EAPI_CYAN,
	EAPI_WHITE,
	EAPI_BOLD,
	EAPI_BLACK,
	EAPI_DIM,
	EAPI_ITALIC,
	EAPI_UNDERLINE,
	EAPI_BR_RED,
	EAPI_BR_YELLOW,
	EAPI_BR_GREEN,
	EAPI_BR_BLACK,
	EAPI_BR_BLUE,
	EAPI_BR_CYAN,
	EAPI_BR_MAGENTA,
	EAPI_BR_WHITE,
	EAPI_COLOR_COUNT
} eapi_color_tab;

static const char *const _eapi_ansi_array[EAPI_COLOR_COUNT] = {
	[EAPI_RESET] = "\033[0m",
	[EAPI_RED] = "\033[31m",
	[EAPI_GREEN] = "\033[32m",
	[EAPI_YELLOW] = "\033[33m",
	[EAPI_BLUE] = "\033[34m",
	[EAPI_MAGENTA] = "\033[35m",
	[EAPI_CYAN] = "\033[36m",
	[EAPI_WHITE] = "\033[37m",
	[EAPI_BOLD] = "\033[1m",
	[EAPI_BLACK] = "\033[30m",
	[EAPI_DIM] = "\033[2m",
	[EAPI_ITALIC] = "\033[3m",
	[EAPI_UNDERLINE] = "\033[4m",
	[EAPI_BR_RED] = "\033[91m",
	[EAPI_BR_YELLOW] = "\033[93m",
	[EAPI_BR_GREEN] = "\033[92m",
	[EAPI_BR_BLACK] = "\033[90m",
	[EAPI_BR_BLUE] = "\033[94m",
	[EAPI_BR_CYAN] = "\033[96m",
	[EAPI_BR_MAGENTA] = "\033[95m",
	[EAPI_BR_WHITE] = "\033[97m"
};
#ifdef EAPI_PLATFORM_WINDOWS
static inline void _eapi_cnsedit_win_init(void) {	
	static int _eapi_win_ansi_enabled = 0;
	if (_eapi_win_ansi_enabled) return;

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE) return;
		
	DWORD dwMode = 0;
	if (GetConsoleMode(hOut, &dwMode)) {
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}
	_eapi_win_ansi_enabled = 1;
}

static inline void _eapi_ensure_init(void)
{
	static int is_initialized = 0;
	if (!is_initialized) { _eapi_cnsedit_win_init(); is_initialized = 1; }
	
}
#endif

static inline void eapi_init(void)
{
	#ifdef EAPI_PLATFORM_WINDOWS
		_eapi_ensure_init();
	#endif
	#ifndef __eapi_disable_init_text__
		printf ("Checking your system...\n");
		printf("Host OS: %s\n", EAPI_CURRENT_PLATFORM);
		printf("[EffortAPI] Effort API 1 (1.1) Build 06062026\n");
	#endif
}

static inline void eapi_printf(eapi_color_tab color, const char *fmt, ...)
{
	#ifdef EAPI_PLATFORM_WINDOWS
		_eapi_ensure_init();
	#endif

	if (color >= 0 && color < EAPI_COLOR_COUNT) printf("%s", _eapi_ansi_array[color]);

	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	printf("\033[0m");
}

/*===== FS ======*/
/**
 * @brief check file on existing. 
 * Opens file, if open return true, if not false
 * @param[in] filename
 * @return true if file exists
 * @return false if file not exists
 */
static inline bool is_file_exists(const char *filename) {
	if (filename == NULL) return false;		
	FILE *file = fopen(filename, "r");
	if (file != NULL) {	fclose(file); return true; }
	return false;
}

typedef enum {
	FILE_TYPE,
	DIR_TYPE
} eapi_type;

static inline bool eapi_remove(const char *filename, eapi_type type) {

	if (filename == NULL) { errno = EINVAL; return false;}

	if (type == FILE_TYPE) return remove(filename) == 0;
	else if (type == DIR_TYPE) return rmdir_cp(filename) == 0;

	return false;
}

static inline bool eapi_new_object(const char *objname) {
	if (objname == NULL) { return false; }

	FILE *file = fopen(objname, "a");
	if (file == NULL) {
		printf("[EffortAPI] Error: unable to create file.");
		return false;
	}
	fclose(file);
	return true; 
}

/**
 * @brief Delay
 * idk js Cross-Platform delay
 * @param[in] ms 
 */
static inline void eapi_delay(unsigned int ms) 
{
	#ifdef EAPI_PLATFORM_WINDOWS
		Sleep(ms);
	#else 
		struct timespec tsp;
		tsp.tv_sec = ms / 1000;
		tsp.tv_nsec = (ms % 1000) * 1000000;
		nanosleep(&tsp, NULL);
	#endif
}

static inline void eapi_rand_init(void) { srand((unsigned int)time(NULL)); }

static inline int eapi_rand_range(int min, int max){
	if (min > max) return 0;
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

#define eapi_swap(a, b) do { typeof(a) _tmp = (a); (a) = (b); (b) = _tmp; } while(0)


#define EAPI_RANDOM_ALL_BUFFER(buffer) sizeof(buffer)
/**
	@brief Generate random string by specified length
	WARNING need free after this function
	@param a Length of generated string 
	@return pointer on string or NULL.
*/
static inline char *eapi_gen_random_string_element(size_t num){
	char *str = (char*)malloc(num + 1);
	if (str == NULL) return NULL;
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	size_t charset_sz = sizeof(charset) - 1;
	for (size_t i = 0; i < num; i++) str[i] = charset[eapi_rand_range(0, (int)charset_sz - 1)];
	str[num] = '\0';
	return str;
}


#ifdef __cplusplus
}
#endif

#endif // EAPI_H
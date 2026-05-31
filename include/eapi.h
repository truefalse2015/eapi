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
*/

/* Effort API 1 (1.0) Build 01062026 */

#ifndef EAPI_H
#define EAPI_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
	#include <windows.h>

	// Support ANSI-codes for Windows Terminal
	/* P.S. Important note: On Windows 7/8 and earlier versions, this
	*      feature may not work and ANSI codes may display as plain text.
	*      Recommended: Windows 10 (build 10586+) or later. */

	/* P.P.S. I didn't use SetConsoleTextAttribute from the Windows API
	*        because it would complicate the code significantly.
	*        Sorry. =( */


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

	static inline void EapiInitialization() {
		printf("Check your system...\n");
		#ifdef _WIN32
			printf("Windows");
		#else
			printf("Linux/MacOS or other");
		#endif
		printf("[EffortAPI] Effort API 1 (1.0) Build 01062026");
	}

	/* ====== CNSEDIT ====== */
	/* CNSEDIT - signal "Now we will work with the console." */

	// Normal text and background commands
	static inline void eapi_RESET(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0m");
	}

	static inline void eapi_black(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;30m%.99s", text);
	}

	static inline void eapi_blackBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;40m");
	}

	static inline void eapi_red(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;31m%.99s", text);
	}

	static inline void eapi_redBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;41m");
	}

	static inline void eapi_green(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;32m%.99s", text);
	}

	static inline void eapi_greenBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;42m");
	}

	static inline void eapi_blue(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;34m%.99s", text);
	}

	static inline void eapi_blueBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;44m");
	}

	static inline void eapi_yellow(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;33m%.99s", text);
	}

	static inline void eapi_yellowBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;43m");
	}

	static inline void eapi_purple(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;35m%.99s", text);
	}

	static inline void eapi_purpleBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;45m");
	}

	static inline void eapi_cyan(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;36m%.99s", text);
	}

	static inline void eapi_cyanBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;46m");
	}

	static inline void eapi_white(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;37m%.99s", text);
	}

	static inline void eapi_whiteBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;47m");
	}

	// Formatting: Bold
	static inline void eapi_black_BOLD(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;30m%.99s", text);
	}

	static inline void eapi_red_BOLD(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;31m%.99s", text);
	}

	static inline void eapi_green_BOLD(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;32m%.99s", text);
	}

	static inline void eapi_blue_BOLD(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;34m%.99s", text);
	}

	static inline void eapi_yellow_BOLD(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;33m%.99s", text);
	}

	static inline void eapi_purple_BOLD(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;35m%.99s", text);
	}

	static inline void eapi_cyan_BOLD(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;36m%.99s", text);
	}

	static inline void eapi_white_BOLD(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;37m%.99s", text);
	}

	static inline void eapi_BOLDSET(void) {
		_eapi_cnsedit_win_init();
		printf("\033[1m");
	}

	// Formatting: Underline
	static inline void eapi_black_ULINE(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;30m%.99s", text);
	}

	static inline void eapi_red_ULINE(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;31m%.99s", text);
	}

	static inline void eapi_green_ULINE(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;32m%.99s", text);
	}

	static inline void eapi_blue_ULINE(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;34m%.99s", text);
	}

	static inline void eapi_yellow_ULINE(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;33m%.99s", text);
	}

	static inline void eapi_purple_ULINE(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;35m%.99s", text);
	}

	static inline void eapi_cyan_ULINE(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;36m%.99s", text);
	}

	static inline void eapi_white_ULINE(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;37m%.99s", text);
	}

	static inline void eapi_ULINESET(void) {
		_eapi_cnsedit_win_init();
		printf("\033[4m");
	}

	// Formatting: High Intensity
	static inline void eapi_black_HINT(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;90m%.99s", text);
	}

	static inline void eapi_red_HINT(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;91m%.99s", text);
	}

	static inline void eapi_green_HINT(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;92m%.99s", text);
	}

	static inline void eapi_blue_HINT(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;94m%.99s", text);
	}

	static inline void eapi_yellow_HINT(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;93m%.99s", text);
	}

	static inline void eapi_purple_HINT(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;95m%.99s", text);
	}

	static inline void eapi_cyan_HINT(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;96m%.99s", text);
	}

	static inline void eapi_white_HINT(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;97m%.99s", text);
	}

	// Formatting: Bold High Intensity
	static inline void eapi_black_BHI(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;90m%.99s", text);
	}

	static inline void eapi_red_BHI(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;91m%.99s", text);
	}

	static inline void eapi_green_BHI(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;92m%.99s", text);
	}

	static inline void eapi_blue_BHI(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;94m%.99s", text);
	}

	static inline void eapi_yellow_BHI(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;93m%.99s", text);
	}

	static inline void eapi_purple_BHI(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;95m%.99s", text);
	}

	static inline void eapi_cyan_BHI(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;96m%.99s", text);
	}

	static inline void eapi_white_BHI(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;97m%.99s", text);
	}

	// Formatting: Flashing
	static inline void eapi_FLASHING(const char* text) {
		_eapi_cnsedit_win_init();
		printf("\033[5m%.99s", text);
	}

	// Simple text print
	static inline void CNSEDIT_IO_OUTPUT(char text[500]) {
		_eapi_cnsedit_win_init();
		printf("%.499s", text);
	}

	/* cursor (SIMPLE) */
	static inline void eapi_cursor_LEFT(int sym) {
		_eapi_cnsedit_win_init();
		printf("\033[%dD", sym);
	}
	
	static inline void eapi_cursor_RIGHT(int sym) {
		_eapi_cnsedit_win_init();
		printf("\033[%dC", sym);
	}

	static inline void eapi_cursor_UP(int column) {
		_eapi_cnsedit_win_init();
		printf("\033[%dA", column);
	}

	static inline void eapi_cursor_DOWN(int column) {
		_eapi_cnsedit_win_init();
		printf("\033[%dB", column);
	}

	static inline void eapi_cursor_HOME() {
		_eapi_cnsedit_win_init();
		printf("\033[H");
	}

	static inline void eapi_cursor_CUSTOM(int column, int sym) {
		_eapi_cnsedit_win_init();
		printf("\033[%d;%dH", column, sym);
	}

	static inline void eapi_cursor_SAVE() {
		_eapi_cnsedit_win_init();
		printf("\033[s");
	}

	static inline void eapi_cursor_PREVIOUS() {
		_eapi_cnsedit_win_init();
		printf("\033[u");
	}

	static inline void eapi_CLEAR() {
		_eapi_cnsedit_win_init();
		printf("\x1b[2J");
	}

	static inline void eapi_LINECURSCLEAR() {
		_eapi_cnsedit_win_init();
		printf("\x1b[K");
	}

	static inline void eapi_cursor_FLASHING_ON() {
		_eapi_cnsedit_win_init();
		printf("\x1b[?12h");
	}

	static inline void eapi_cursor_FLASHING_OFF() {
		_eapi_cnsedit_win_init();
		printf("\x1b[?12l");
	}

	/* cursor (PROFESSIONAL) */
	static inline void eapi_cursor_LEFT_P(int sym, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%dD", sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else { /* Leaving the current visibility */ }
	}
	
	static inline void eapi_cursor_RIGHT_P(int sym, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%dC", sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_UP_P(int column, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%dA", column);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_DOWN_P(int column, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%dB", column);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_HOME_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[H");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_CUSTOM_P(int column, int sym, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%d;%dH", column, sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_SAVE_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[s");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_PREVIOUS_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[u");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_CLEAR_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\x1b[2J");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_LINECURSCLEAR_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\x1b[K");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_FLASHING_ON_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\x1b[?12h");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_FLASHING_OFF_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\x1b[?12l");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	/* ====== FS ======= */
	/* FS - signal "Attention! Now we will work with the filesystem. */

		static inline int object_exists(const char *filename) {
			_eapi_cnsedit_win_init();
			char path[500];
			snprintf(path, sizeof(path), "%.499s", filename);
			
			FILE *file = fopen(path, "r");
			if (file) {
				fclose(file); // ABSOLUTELY!! Close file
				return 1; // Return value '1' (true)
			}

			return 0; // If file doesn't exists or unable to access, return value '0' (false)
		}

	/* ====== MATH ====== */
	static inline void eapi_systemDelay_ms(int delay) {
        Sleep(delay * 1);
    }
    static inline void eapi_systemDelay_sec(int delay) {
        Sleep(delay * 1000);
    }
    static inline void eapi_systemDelay_min(int delay) {
        Sleep(delay * 60000);
    }
	
	static inline void eapi_srandInitialization() {
		srand(time(nullptr));
	}

	static inline int eapi_rand(int max) {
		int result;
		result = rand() % max;
		return result;
	}

	static inline int eapi_math_add(int one, int two) {
		int result = one + two;
		return result;
	}

	static inline double eapi_math_add_double(double one, double two) {
		double DOUBLE_MODULE_result = one + two;
		return DOUBLE_MODULE_result;
	}

	static inline int eapi_math_subtraction(int one, int two) {
		int result = one - two;
		return result;
	}

	static inline double eapi_math_subtraction_double(double one, double two) {
		double DOUBLE_MODULE_result = one - two;
		return DOUBLE_MODULE_result;
	}

	static inline int eapi_math_mpl(int one, int two) {
		int result = one * two;
		return result;
	}

	static inline double eapi_math_mpl_double(double one, double two) {
		double DOUBLE_MODULE_result = one * two;
		return DOUBLE_MODULE_result;
	}

	static inline int eapi_math_division(int one, int two) {
		if (two == 0) {
			printf("[eAPI] Error: division by zero!");
			return 0;
		}
		int result = one / two;
		return result;
	}
	static inline int eapi_math_division_professional(int one, int two, int *error) {
		if (two == 0) {
			if (error) *error = 1;
			fprintf(stderr, "[eAPI] Error: division by zero!\n");
			return 0;
		}
		if (error) *error = 0;
		return one / two;
	}

	static inline double eapi_math_division_double(double one, double two) {
		if (two == 0.0) {
			printf("[eAPI] Error: division by zero!");
			return 0.0;
		}
		double DOUBLE_MODULE_result = one / two;
		return DOUBLE_MODULE_result;
	}

	static inline double eapi_math_division_double_professional(double one, double two, int *error) {
		if (two == 0.0) {
			if (error) *error = 1;
			fprintf(stderr, "[eAPI] Error: division by zero!\n");
			return 0.0;
		}
		if (error) *error = 0;
		return one / two;
	}

	static inline int eapi_math_sqrt(int num) {
		int result = sqrt(num);
		return result;
	} // NS - Not a Standart

	static inline double eapi_math_sqrt_double(double num) {
		double DOUBLE_MODULE_result = sqrt(num);
		return DOUBLE_MODULE_result;
	}

	static inline int eapi_math_pow(int num, int power) {
		int result = pow(num, power);
		return result;
	}

	static inline double eapi_math_pow_double(double num, double power) {
		double DOUBLE_MODULE_result = pow(num, power);
		return DOUBLE_MODULE_result;
	}
	
	/* ====== OTHER ====== */
	
	/**
		 * Swaps the values of two integers.
		 * @param a Pointer to the first integer
		 * @param b Pointer to the second integer
		 *
		 * If either pointer is NULL or both pointers are the same,
		 * the function does nothing.
	*/
	static inline void eapi_swap(int *a, int *b) {
		// Protection against NULL values or identical numbers
		if (a == NULL || b == NULL || a == b) {
			return;
		}
		int swapped_value = *a;
		*a = *b;
		*b = swapped_value;
	}

	/**
		 * Swaps the values of two integers.
		 * @param a Pointer to the first integer
		 * @param b Pointer to the second integer
		 *
		 * If either pointer is NULL or both pointers are the same,
		 * the function does nothing.
	*/
	static inline void eapi_swap_double(double *a, double *b) {
		// Protection against NULL values or identical numbers
		if (a == NULL || b == NULL || a == b) {
			return;
		}
		double swapped_value = *a;
		*a = *b;
		*b = swapped_value;
	}

	/**
		 * Swaps the values of two integers.
		 * @param a Pointer to the first integer
		 * @param b Pointer to the second integer
		 *
		 * If either pointer is NULL or both pointers are the same,
		 * the function does nothing.
	*/
	static inline void eapi_swap_float(float *a, float *b) {
		// Protection against NULL values or identical numbers
		if (a == NULL || b == NULL || a == b) {
			return;
		}
		float swapped_value = *a;
		*a = *b;
		*b = swapped_value;
	}

#else /* NOTE: this defines all systems except Windows. It primarily uses Unix/Linux/MacOS syntax.
	   * Unfortunately, there is no code for other systems. */

	#include <unistd.h> // For Linux and MacOS (if MacOS - "from box")

	static inline void EapiInitialization() {
		printf("Check your system...\n");
		#ifdef _WIN32
			printf("Windows");
		#else
			printf("Linux/MacOS or other");
		#endif
		printf("[EffortAPI] Effort API 1 (1.0) Build 01062026");
	}
	
	/* ====== CNSEDIT ======= */
	/* CNSEDIT - signal "Attention! Now we will work with the console." */

	// Normal text and background commands
	static inline void eapi_RESET() { // Reset all ANSI-styles
		printf("\033[0m");
	}

	static inline void eapi_black(const char* text) {
		printf("\033[0;30m%.99s", text);
	}

	static inline void eapi_blackBG() {
		printf("\033[0;40m");	
	}

	static inline void eapi_red(const char* text) {
		printf("\033[0;31m%.99s", text);
	}

	static inline void eapi_redBG() {
		printf("\033[0;41m");
	}

	static inline void eapi_green(const char* text) {
		printf("\033[0;32m%.99s", text);
	}

	static inline void eapi_greenBG() {
		printf("\033[0;42m");
	}

	static inline void eapi_blue(const char* text) {
		printf("\033[0;34m%.99s", text);
	}

	static inline void eapi_blueBG() {
		printf("\033[0;44m");
	}

	static inline void eapi_yellow(const char* text) {
		printf("\033[0;33m%.99s", text);
	}

	static inline void eapi_yellowBG() {
		printf("\033[0;43m");
	}

	static inline void eapi_purple(const char* text) {
		printf("\e[0;35m%.99s", text);
	}

	static inline void eapi_purpleBG() {
		printf("\e[0;45m");
	}

	static inline void eapi_cyan(const char* text) {
		printf("\e[0;36m%.99s", text);
	}

	static inline void eapi_cyanBG() {
		printf("\e[0;46m");
	}

	static inline void eapi_white(const char* text) {
		printf("\e[0;37m%.99s", text);
	}

	static inline void eapi_whiteBG() {
		printf("\e[0;47m");
	}

	// Formatting: Bold
	static inline void eapi_black_BOLD(const char* text) {
		printf("\033[1;30m%.99s", text);
	}

	static inline void eapi_red_BOLD(const char* text) {
		printf("\033[1;31m%.99s", text);
	}

	static inline void eapi_green_BOLD(const char* text) {
		printf("\033[1;32m%.99s", text);
	}

	static inline void eapi_blue_BOLD(const char* text) {
		printf("\033[1;34m%.99s", text);
	}

	static inline void eapi_yellow_BOLD(const char* text) {
		printf("\033[1;33m%.99s", text);
	}

	static inline void eapi_purple_BOLD(const char* text) {
		printf("\033[1;35m%.99s", text);
	}

	static inline void eapi_cyan_BOLD(const char* text) {
		printf("\033[1;36m%.99s", text);
	}

	static inline void eapi_white_BOLD(const char* text) {
		printf("\033[1;37m%.99s", text);
	}

	static inline void eapi_BOLDSET() {
		printf("\033[1m");
	}
	
	// Formatting: Underline
	static inline void eapi_black_ULINE(const char* text) {
		printf("\033[4;30m%.99s", text);
	}

	static inline void eapi_red_ULINE(const char* text) {
		printf("\033[4;31m%.99s", text);
	}

	static inline void eapi_green_ULINE(const char* text) {
		printf("\033[4;32m%.99s", text);
	}

	static inline void eapi_blue_ULINE(const char* text) {
		printf("\033[4;34m%.99s", text);
	}
	
	static inline void eapi_yellow_ULINE(const char* text) {
		printf("\033[4;33m%.99s", text);
	}

	static inline void eapi_purple_ULINE(const char* text) {
		printf("\033[4;35m%.99s", text);
	}

	static inline void eapi_cyan_ULINE(const char* text) {
		printf("\033[4;36m%.99s", text);
	}

	static inline void eapi_white_ULINE(const char* text) {
		printf("\033[4;37m%.99s", text);
	}

	static inline void eapi_ULINESET() {
		printf("\033[4m");
	}

	// Formatting: High Intensity
	static inline void eapi_black_HINT(const char* text) {
		printf("\033[0;90m%.99s", text);
	}

	static inline void eapi_red_HINT(const char* text) {
		printf("\033[0;91m%.99s", text);
	}

	static inline void eapi_green_HINT(const char* text) {
		printf("\033[0;92m%.99s", text);
	}

	static inline void eapi_blue_HINT(const char* text) {
		printf("\033[0;94m%.99s", text);
	}

	static inline void eapi_yellow_HINT(const char* text) {
		printf("\033[0;93m%.99s", text);
	}

	static inline void eapi_purple_HINT(const char* text) {
		printf("\033[0;95m%.99s", text);
	}

	static inline void eapi_cyan_HINT(const char* text) {
		printf("\033[0;96m%.99s", text);
	}

	static inline void eapi_white_HINT(const char* text) {
		printf("\033[0;97m%.99s", text);
	}

	// Formatting: Bold High Intensity
	static inline void eapi_black_BHI(const char* text) {
		printf("\033[1;90m%.99s", text);
	}

	static inline void eapi_red_BHI(const char* text) {
		printf("\033[1;91m%.99s", text);
	}

	static inline void eapi_green_BHI(const char* text) {
		printf("\033[1;92m%.99s", text);
	}

	static inline void eapi_blue_BHI(const char* text) {
		printf("\033[1;94m%.99s", text);
	}

	static inline void eapi_yellow_BHI(const char* text) {
		printf("\033[1;93m%.99s", text);
	}

	static inline void eapi_purple_BHI(const char* text) {
		printf("\033[1;95m%.99s", text);
	}

	static inline void eapi_cyan_BHI(const char* text) {
		printf("\033[1;96m%.99s", text);
	}
	
	static inline void eapi_white_BHI(const char* text) {
		printf("\033[1;97m%.99s", text);
	}

	// Formatting: Flashing
	static inline void eapi_FLASHING(const char* text) {
		printf("\x1b[5m%.99s", text);
	}

	// Simple text print
	static inline void CNSEDIT_IO_OUTPUT(char text[500]) {
		printf("%.499s", text);
	}

	/* cursor (SIMPLE) */
	static inline void eapi_cursor_LEFT(int sym) {
		printf("\033[%dD", sym);
	}
	
	static inline void eapi_cursor_RIGHT(int sym) {
		printf("\033[%dC", sym);
	}

	static inline void eapi_cursor_UP(int column) {
		printf("\033[%dA", column);
	}

	static inline void eapi_cursor_DOWN(int column) {
		printf("\033[%dB", column);
	}

	static inline void eapi_cursor_HOME() {
		printf("\033[H");
	}

	static inline void eapi_cursor_CUSTOM(int column, int sym) {
		printf("\033[%d;%dH", column, sym);
	}

	static inline void eapi_cursor_SAVE() {
		printf("\033[s");
	}

	static inline void eapi_cursor_PREVIOUS() {
		printf("\033[u");
	}

	static inline void eapi_CLEAR() {
		printf("\x1b[2J");
	}

	static inline void eapi_cursor_clearline() {
		printf("\x1b[K");
	}

	static inline void eapi_cursor_flashing() {
		printf("\x1b[?12h");
	}

	static inline void eapi_cursor_flashing_off() {
		printf("\x1b[?12l");
	}

	/* cursor (PROFESSIONAL) */
	static inline void eapi_cursor_LEFT_P(int sym, char hide_or_show) {
		printf("\033[%dD", sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else { /* Leaving the current visibility */ }
	}
	
	static inline void eapi_cursor_RIGHT_P(int sym, char hide_or_show) {
		printf("\033[%dC", sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_UP_P(int column, char hide_or_show) {
		printf("\033[%dA", column);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_DOWN_P(int column, char hide_or_show) {
		printf("\033[%dB", column);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_HOME_P(char hide_or_show) {
		printf("\033[H");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_CUSTOM_P(int column, int sym, char hide_or_show) {
		printf("\033[%d;%dH", column, sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_SAVE_P(char hide_or_show) {
		printf("\033[s");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_PREVIOUS_P(char hide_or_show) {
		printf("\033[u");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_CLEAR_P(char hide_or_show) {
		printf("\x1b[2J");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_LINECURSCLEAR_P(char hide_or_show) {
		printf("\x1b[K");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_FLASHING_ON_P(char hide_or_show) {
		printf("\x1b[?12h");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void eapi_cursor_FLASHING_OFF_P(char hide_or_show) {
		printf("\x1b[?12l");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	/* ====== FS ======= */
	/* FS - signal "Attention! Now we will work with the filesystem. */
	static inline int object_exists(const char *filename) {
		char path[500];
		
		snprintf(path, sizeof(path), "%.499s", filename); /* sizeof takes into account the array size,
														 * thus preventing buffer overflow: very useful. */

		return (access(path, F_OK) == 0) ? 1 : 0;
	}

	#if defined(_WIN32) || defined(_WIN64)
		#include <direct.h>
		#define mkdir_os(path) _mkdir(path)
	#else
		#include <sys/stat.h> // Для mkdir на Linux/macOS
		#include <sys/types.h>
		#define mkdir_os(path) mkdir(path, 0777)
	#endif
	#include <stdio.h>
	#include <stdlib.h>

	typedef enum {
		FILE_TYPE,
		DIR_TYPE
	} EapiType;

	static inline int eapi_remove(const char *objname, EapiType type) {
		char path[500];

		if (objname == NULL) {
			errno = EINVAL;
			return 0;
		}

		int written = snprintf(path, sizeof(path), "%s", objname);
		if (written < 0 || written >= (int)sizeof(path)) {
			errno = ENAMETOOLONG;
			return 0;
		}

		switch (type) {
			case FILE_TYPE:
				if (remove(path) != 0) {
					return 0;
				}
				return 1;

			case DIR_TYPE:
				// Удаляем директорию
				if (rmdir(path) != 0) {
					return 0;
				}
				return 1;

			default:
				return 0;
		}
	}

	static inline int eapi_newObject(const char *objname) {
		char path[500];
		if (objname == NULL) { return 0; }
		int written = snprintf(path, sizeof(path), "%s", objname);
		if (written < 0 || (size_t)written >= sizeof(path)) {
			return 0;
		}

		FILE *file = fopen(path, "w");
		if (file == NULL) {
			printf("[EffortAPI] Error: unable to create file.");
			return 0; // Error
		}
		fclose(file);
		return 1; // 
	}

	/* ====== MATH ====== */
	static inline void eapi_systemDelay_ms(int delay) {
		usleep(delay * 1000); // 1 ms = 1000 us
	}

	static inline void eapi_systemDelay_sec(int delay) {
		usleep(delay * 1000000); // 1 sec = 1000000 us
	}

	static inline void eapi_systemDelay_us(int delay) {
		usleep(delay * 1); // 1 us = 1 us
	}

	static inline void eapi_systemDelay_min(int delay) {
		usleep(delay * 60000000); // 1 min = 60000000 us
	}
	
	static inline void eapi_srandInitialization() {
		srand(time(nullptr));
	}

	static inline int eapi_rand(int max) {
		int result;
		result = rand() % max;
		return result;
	}

	static inline int eapi_math_add(int one, int two) {
		int result = one + two;
		return result;
	}

	static inline double eapi_math_add_double(double one, double two) {
		double DOUBLE_MODULE_result = one + two;
		return DOUBLE_MODULE_result;
	}

	static inline int eapi_math_subtraction(int one, int two) {
		int result = one - two;
		return result;
	}

	static inline double eapi_math_subtraction_double(double one, double two) {
		double DOUBLE_MODULE_result = one - two;
		return DOUBLE_MODULE_result;
	}

	static inline int eapi_math_mpl(int one, int two) {
		int result = one * two;
		return result;
	}

	static inline double eapi_math_mpl_double(double one, double two) {
		double DOUBLE_MODULE_result = one * two;
		return DOUBLE_MODULE_result;
	}

	static inline int eapi_math_division(int one, int two) {
		if (two == 0) {
			printf("[eAPI] Error: division by zero!");
			return 0;
		}
		int result = one / two;
		return result;
	}
	static inline int eapi_math_division_professional(int one, int two, int *error) {
		if (two == 0) {
			if (error) *error = 1;
			fprintf(stderr, "[eAPI] Error: division by zero!\n");
			return 0;
		}
		if (error) *error = 0;
		return one / two;
	}

	static inline double eapi_math_division_double(double one, double two) {
		if (two == 0.0) {
			printf("[eAPI] Error: division by zero!");
			return 0.0;
		}
		double DOUBLE_MODULE_result = one / two;
		return DOUBLE_MODULE_result;
	}

	static inline double eapi_math_division_double_professional(double one, double two, int *error) {
		if (two == 0.0) {
			if (error) *error = 1;
			fprintf(stderr, "[eAPI] Error: division by zero!\n");
			return 0.0;
		}
		if (error) *error = 0;
		return one / two;
	}

	static inline int eapi_math_sqrt(int num) {
		int result = sqrt(num);
		return result;
	} // NS - Not a Standart

	static inline double eapi_math_sqrt_double(double num) {
		double DOUBLE_MODULE_result = sqrt(num);
		return DOUBLE_MODULE_result;
	}

	static inline int eapi_math_pow(int num, int power) {
		int result = pow(num, power);
		return result;
	}

	static inline double eapi_math_pow_double(double num, double power) {
		double DOUBLE_MODULE_result = pow(num, power);
		return DOUBLE_MODULE_result;
	}
	
	/* ====== OTHER ====== */
	
	/**
		 * Swaps the values of two integers.
		 * @param a Pointer to the first integer
		 * @param b Pointer to the second integer
		 *
		 * If either pointer is NULL or both pointers are the same,
		 * the function does nothing.
	*/
	static inline void eapi_swap(int *a, int *b) {
		// Protection against NULL values or identical numbers
		if (a == NULL || b == NULL || a == b) {
			return;
		}
		int swapped_value = *a;
		*a = *b;
		*b = swapped_value;
	}

	/**
		 * Swaps the values of two doubles.
		 * @param a Pointer to the first double
		 * @param b Pointer to the second double
		 *
		 * If either pointer is NULL or both pointers are the same,
		 * the function does nothing.
	*/
	static inline void eapi_swap_double(double *a, double *b) {
		// Protection against NULL values or identical numbers
		if (a == NULL || b == NULL || a == b) {
			return;
		}
		double swapped_value = *a;
		*a = *b;
		*b = swapped_value;
	}

	/**
		 * Swaps the values of two floats.
		 * @param a Pointer to the first float
		 * @param b Pointer to the second float
		 *
		 * If either pointer is NULL or both pointers are the same,
		 * the function does nothing.
	*/
	static inline void eapi_swap_float(float *a, float *b) {
		// Protection against NULL values or identical numbers
		if (a == NULL || b == NULL || a == b) {
			return;
		}
		float swapped_value = *a;
		*a = *b;
		*b = swapped_value;
	}

#endif


#ifdef __cplusplus
}
#endif

#endif // EAPI_H
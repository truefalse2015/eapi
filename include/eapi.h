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

/* Effort API v1.0 (Build 29052026) */

#ifndef EAPI_H
#define EAPI_H

#include <stdio.h>
#include <string.h>
#include <math.h> // New! Math in library

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

	/* ====== CNSEDIT ====== */
	/* CNSEDIT - signal "Now we will work with the console." */

	// Normal text and background commands
	static inline void CNSEDIT_ANSI_RESET(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0m");
	}

	static inline void CNSEDIT_ANSI_BLACK(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLACKBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;40m");
	}

	static inline void CNSEDIT_ANSI_RED(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_REDBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;41m");
	}

	static inline void CNSEDIT_ANSI_GREEN(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREENBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;42m");
	}

	static inline void CNSEDIT_ANSI_BLUE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;34m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUEBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;44m");
	}

	static inline void CNSEDIT_ANSI_YELLOW(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOWBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;43m");
	}

	static inline void CNSEDIT_ANSI_PURPLE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLEBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;45m");
	}

	static inline void CNSEDIT_ANSI_CYAN(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYANBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;46m");
	}

	static inline void CNSEDIT_ANSI_WHITE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITEBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;47m");
	}

	// Formatting: Bold
	static inline void CNSEDIT_ANSI_BLACK_BOLD(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_BOLD(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_BOLD(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_BOLD(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;34m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_BOLD(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_BOLD(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_BOLD(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_BOLD(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BOLDSET(void) {
		_eapi_cnsedit_win_init();
		printf("\033[1m");
	}

	// Formatting: Underline
	static inline void CNSEDIT_ANSI_BLACK_ULINE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[4;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_ULINE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[4;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_ULINE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[4;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_ULINE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[4;34m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_ULINE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[4;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_ULINE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[4;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_ULINE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[4;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_ULINE(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[4;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_ULINESET(void) {
		_eapi_cnsedit_win_init();
		printf("\033[4m");
	}

	// Formatting: High Intensity
	static inline void CNSEDIT_ANSI_BLACK_HINT(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;90m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_HINT(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;91m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_HINT(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;92m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_HINT(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;94m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_HINT(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;93m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_HINT(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;95m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_HINT(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;96m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_HINT(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[0;97m%.99s", text);
	}

	// Formatting: Bold High Intensity
	static inline void CNSEDIT_ANSI_BLACK_BHI(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;90m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_BHI(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;91m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_BHI(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;92m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_BHI(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;94m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_BHI(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;93m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_BHI(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;95m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_BHI(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;96m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_BHI(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[1;97m%.99s", text);
	}

	// Formatting: Flashing
	static inline void CNSEDIT_ANSI_FLASHING(char text[100]) {
		_eapi_cnsedit_win_init();
		printf("\033[5m%.99s", text);
	}

	// Simple text print
	static inline void CNSEDIT_IO_OUTPUT(char text[500]) {
		_eapi_cnsedit_win_init();
		printf("%.499s", text);
	}

	/* CURSOR (SIMPLE) */
	static inline void CNSEDIT_ANSI_CURSOR_LEFT(int sym) {
		_eapi_cnsedit_win_init();
		printf("\033[%dD", sym);
	}
	
	static inline void CNSEDIT_ANSI_CURSOR_RIGHT(int sym) {
		_eapi_cnsedit_win_init();
		printf("\033[%dC", sym);
	}

	static inline void CNSEDIT_ANSI_CURSOR_UP(int column) {
		_eapi_cnsedit_win_init();
		printf("\033[%dA", column);
	}

	static inline void CNSEDIT_ANSI_CURSOR_DOWN(int column) {
		_eapi_cnsedit_win_init();
		printf("\033[%dB", column);
	}

	static inline void CNSEDIT_ANSI_CURSOR_HOME() {
		_eapi_cnsedit_win_init();
		printf("\033[H");
	}

	static inline void CNSEDIT_ANSI_CURSOR_CUSTOM(int column, int sym) {
		_eapi_cnsedit_win_init();
		printf("\033[%d;%dH", column, sym);
	}

	static inline void CNSEDIT_ANSI_CURSOR_SAVE() {
		_eapi_cnsedit_win_init();
		printf("\033[s");
	}

	static inline void CNSEDIT_ANSI_CURSOR_PREVIOUS() {
		_eapi_cnsedit_win_init();
		printf("\033[u");
	}

	static inline void CNSEDIT_ANSI_CLEAR() {
		_eapi_cnsedit_win_init();
		printf("\x1b[2J");
	}

	static inline void CNEDIT_ANSI_LINECURSCLEAR() {
		_eapi_cnsedit_win_init();
		printf("\x1b[K");
	}

	static inline void CNEDIT_ANSI_CURSOR_FLASHING_ON() {
		_eapi_cnsedit_win_init();
		printf("\x1b[?12h");
	}

	static inline void CNEDIT_ANSI_CURSOR_FLASHING_OFF() {
		_eapi_cnsedit_win_init();
		printf("\x1b[?12l");
	}

	/* CURSOR (PROFESSIONAL) */
	static inline void CNSEDIT_ANSI_CURSOR_LEFT_P(int sym, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%dD", sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else { /* Leaving the current visibility */ }
	}
	
	static inline void CNSEDIT_ANSI_CURSOR_RIGHT_P(int sym, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%dC", sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_UP_P(int column, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%dA", column);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_DOWN_P(int column, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%dB", column);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_HOME_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[H");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_CUSTOM_P(int column, int sym, char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[%d;%dH", column, sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_SAVE_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[s");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_PREVIOUS_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\033[u");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CLEAR_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\x1b[2J");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNEDIT_ANSI_LINECURSCLEAR_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\x1b[K");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNEDIT_ANSI_CURSOR_FLASHING_ON_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\x1b[?12h");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNEDIT_ANSI_CURSOR_FLASHING_OFF_P(char hide_or_show) {
		_eapi_cnsedit_win_init();

		printf("\x1b[?12l");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	/* ====== FS ======= */
	/* FS - signal "Attention! Now we will work with the filesystem. */

		static inline int FS_OBJ_EXISTS(const char *filename) {
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
	static inline int MATH_BASE_PLUS(int one, int two) {
		int result = one + two;
		return result;
	}

	static inline double MATH_BASE_PLUS_DOUBLE(double one, double two) {
		double DOUBLE_MODULE_result = one + two;
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_BASE_MINUS(int one, int two) {
		int result = one - two;
		return result;
	}

	static inline double MATH_BASE_MINUS_DOUBLE(double one, double two) {
		double DOUBLE_MODULE_result = one - two;
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_BASE_MULTIPLY(int one, int two) {
		int result = one * two;
		return result;
	}

	static inline double MATH_BASE_MULTIPLY_DOUBLE(double one, double two) {
		double DOUBLE_MODULE_result = one * two;
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_BASE_DIVISION(int one, int two) {
		int result = one / two;
		return result;
	}

	static inline double MATH_BASE_DIVISION_DOUBLE(double one, double two) {
		double DOUBLE_MODULE_result = one / two;
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_NS_SQRT(int num) {
		int result = sqrt(num);
		return result;
	} // NS - Not a Standart

	static inline double MATH_NS_SQRT_DOUBLE(double num) {
		double DOUBLE_MODULE_result = sqrt(num);
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_NS_POWER(int num, int power) {
		int result = pow(num, power);
		return result;
	}

	static inline double MATH_NS_POWER_DOUBLE(double num, double power) {
		double result = pow(num, power);
		return result;
	}	

#else /* NOTE: this defines all systems except Windows. It primarily uses Unix/Linux/MacOS syntax.
	   * Unfortunately, there is no code for other systems. */

	#include <unistd.h> // For Linux and MacOS (if MacOS - "from box")
	
	/* ====== CNSEDIT ======= */
	/* CNSEDIT - signal "Attention! Now we will work with the console." */

	// Normal text and background commands
	static inline void CNSEDIT_ANSI_RESET() { // Reset all ANSI-styles
		printf("\033[0m");
	}

	static inline void CNSEDIT_ANSI_BLACK(char text[100]) {
		printf("\033[0;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLACKBG() {
		printf("\033[0;40m");	
	}

	static inline void CNSEDIT_ANSI_RED(char text[100]) {
		printf("\033[0;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_REDBG() {
		printf("\033[0;41m");
	}

	static inline void CNSEDIT_ANSI_GREEN(char text[100]) {
		printf("\033[0;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREENBG() {
		printf("\033[0;42m");
	}

	static inline void CNSEDIT_ANSI_BLUE(char text[100]) {
		printf("\033[0;34m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUEBG() {
		printf("\033[0;44m");
	}

	static inline void CNSEDIT_ANSI_YELLOW(char text[100]) {
		printf("\033[0;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOWBG() {
		printf("\033[0;43m");
	}

	static inline void CNSEDIT_ANSI_PURPLE(char text[100]) {
		printf("\e[0;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLEBG() {
		printf("\e[0;45m");
	}

	static inline void CNSEDIT_ANSI_CYAN(char text[100]) {
		printf("\e[0;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYANBG() {
		printf("\e[0;46m");
	}

	static inline void CNSEDIT_ANSI_WHITE(char text[100]) {
		printf("\e[0;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITEBG() {
		printf("\e[0;47m");
	}

	// Formatting: Bold
	static inline void CNSEDIT_ANSI_BLACK_BOLD(char text[100]) {
		printf("\033[1;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_BOLD(char text[100]) {
		printf("\033[1;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_BOLD(char text[100]) {
		printf("\033[1;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_BOLD(char text[100]) {
		printf("\033[1;34m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_BOLD(char text[100]) {
		printf("\033[1;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_BOLD(char text[100]) {
		printf("\033[1;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_BOLD(char text[100]) {
		printf("\033[1;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_BOLD(char text[100]) {
		printf("\033[1;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BOLDSET() {
		printf("\033[1m");
	}
	
	// Formatting: Underline
	static inline void CNSEDIT_ANSI_BLACK_ULINE(char text[100]) {
		printf("\033[4;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_ULINE(char text[100]) {
		printf("\033[4;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_ULINE(char text[100]) {
		printf("\033[4;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_ULINE(char text[100]) {
		printf("\033[4;34m%.99s", text);
	}
	
	static inline void CNSEDIT_ANSI_YELLOW_ULINE(char text[100]) {
		printf("\033[4;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_ULINE(char text[100]) {
		printf("\033[4;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_ULINE(char text[100]) {
		printf("\033[4;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_ULINE(char text[100]) {
		printf("\033[4;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_ULINESET() {
		printf("\033[4m");
	}

	// Formatting: High Intensity
	static inline void CNSEDIT_ANSI_BLACK_HINT(char text[100]) {
		printf("\033[0;90m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_HINT(char text[100]) {
		printf("\033[0;91m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_HINT(char text[100]) {
		printf("\033[0;92m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_HINT(char text[100]) {
		printf("\033[0;94m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_HINT(char text[100]) {
		printf("\033[0;93m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_HINT(char text[100]) {
		printf("\033[0;95m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_HINT(char text[100]) {
		printf("\033[0;96m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_HINT(char text[100]) {
		printf("\033[0;97m%.99s", text);
	}

	// Formatting: Bold High Intensity
	static inline void CNSEDIT_ANSI_BLACK_BHI(char text[100]) {
		printf("\033[1;90m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_BHI(char text[100]) {
		printf("\033[1;91m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_BHI(char text[100]) {
		printf("\033[1;92m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_BHI(char text[100]) {
		printf("\033[1;94m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_BHI(char text[100]) {
		printf("\033[1;93m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_BHI(char text[100]) {
		printf("\033[1;95m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_BHI(char text[100]) {
		printf("\033[1;96m%.99s", text);
	}
	
	static inline void CNSEDIT_ANSI_WHITE_BHI(char text[100]) {
		printf("\033[1;97m%.99s", text);
	}

	// Formatting: Flashing
	static inline void CNSEDIT_ANSI_FLASHING(char text[100]) {
		printf("\x1b[5m%.99s", text);
	}

	// Simple text print
	static inline void CNSEDIT_IO_OUTPUT(char text[500]) {
		printf("%.499s", text);
	}

	/* CURSOR (SIMPLE) */
	static inline void CNSEDIT_ANSI_CURSOR_LEFT(int sym) {
		printf("\033[%dD", sym);
	}
	
	static inline void CNSEDIT_ANSI_CURSOR_RIGHT(int sym) {
		printf("\033[%dC", sym);
	}

	static inline void CNSEDIT_ANSI_CURSOR_UP(int column) {
		printf("\033[%dA", column);
	}

	static inline void CNSEDIT_ANSI_CURSOR_DOWN(int column) {
		printf("\033[%dB", column);
	}

	static inline void CNSEDIT_ANSI_CURSOR_HOME() {
		printf("\033[H");
	}

	static inline void CNSEDIT_ANSI_CURSOR_CUSTOM(int column, int sym) {
		printf("\033[%d;%dH", column, sym);
	}

	static inline void CNSEDIT_ANSI_CURSOR_SAVE() {
		printf("\033[s");
	}

	static inline void CNSEDIT_ANSI_CURSOR_PREVIOUS() {
		printf("\033[u");
	}

	static inline void CNSEDIT_ANSI_CLEAR() {
		printf("\x1b[2J");
	}

	static inline void CNEDIT_ANSI_LINECURSCLEAR() {
		printf("\x1b[K");
	}

	static inline void CNEDIT_ANSI_CURSOR_FLASHING_ON() {
		printf("\x1b[?12h");
	}

	static inline void CNEDIT_ANSI_CURSOR_FLASHING_OFF() {
		printf("\x1b[?12l");
	}

	/* CURSOR (PROFESSIONAL) */
	static inline void CNSEDIT_ANSI_CURSOR_LEFT_P(int sym, char hide_or_show) {
		printf("\033[%dD", sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else { /* Leaving the current visibility */ }
	}
	
	static inline void CNSEDIT_ANSI_CURSOR_RIGHT_P(int sym, char hide_or_show) {
		printf("\033[%dC", sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_UP_P(int column, char hide_or_show) {
		printf("\033[%dA", column);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_DOWN_P(int column, char hide_or_show) {
		printf("\033[%dB", column);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_HOME_P(char hide_or_show) {
		printf("\033[H");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_CUSTOM_P(int column, int sym, char hide_or_show) {
		printf("\033[%d;%dH", column, sym);
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_SAVE_P(char hide_or_show) {
		printf("\033[s");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CURSOR_PREVIOUS_P(char hide_or_show) {
		printf("\033[u");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNSEDIT_ANSI_CLEAR_P(char hide_or_show) {
		printf("\x1b[2J");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNEDIT_ANSI_LINECURSCLEAR_P(char hide_or_show) {
		printf("\x1b[K");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNEDIT_ANSI_CURSOR_FLASHING_ON_P(char hide_or_show) {
		printf("\x1b[?12h");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	static inline void CNEDIT_ANSI_CURSOR_FLASHING_OFF_P(char hide_or_show) {
		printf("\x1b[?12l");
		if (hide_or_show == 'h') {
			printf("\x1b[?25l");
		} else {}
	}

	/* ====== FS ======= */
	/* FS - signal "Attention! Now we will work with the filesystem. */
	static inline int FS_OBJ_EXISTS(const char *filename) {
		char path[500];
		
		snprintf(path, sizeof(path), "%.499s", filename); /* sizeof takes into account the array size,
														 * thus preventing buffer overflow: very useful. */

		return (access(path, F_OK) == 0) ? 1 : 0;
	}

	/* ====== MATH ====== */
	static inline int MATH_BASE_PLUS(int one, int two) {
		int result = one + two;
		return result;
	}

	static inline double MATH_BASE_PLUS_DOUBLE(double one, double two) {
		double DOUBLE_MODULE_result = one + two;
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_BASE_MINUS(int one, int two) {
		int result = one - two;
		return result;
	}

	static inline double MATH_BASE_MINUS_DOUBLE(double one, double two) {
		double DOUBLE_MODULE_result = one - two;
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_BASE_MULTIPLY(int one, int two) {
		int result = one * two;
		return result;
	}

	static inline double MATH_BASE_MULTIPLY_DOUBLE(double one, double two) {
		double DOUBLE_MODULE_result = one * two;
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_BASE_DIVISION(int one, int two) {
		int result = one / two;
		return result;
	}

	static inline double MATH_BASE_DIVISION_DOUBLE(double one, double two) {
		double DOUBLE_MODULE_result = one / two;
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_NS_SQRT(int num) {
		int result = sqrt(num);
		return result;
	} // NS - Not a Standart

	static inline double MATH_NS_SQRT_DOUBLE(double num) {
		double DOUBLE_MODULE_result = sqrt(num);
		return DOUBLE_MODULE_result;
	}

	static inline int MATH_NS_POWER(int num, int power) {
		int result = pow(num, power);
		return result;
	}

	static inline double MATH_NS_POWER_DOUBLE(double num, double power) {
		double DOUBLE_MODULE_result = pow(num, power);
		return DOUBLE_MODULE_result;
	}

#endif

#ifdef __cplusplus
extern "C" }
#endif

#endif // EAPI_H
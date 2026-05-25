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

#ifndef EAPI_H
#define EAPI_H

#include <stdio.h>
#include <string.h>

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

	static inline void CNSEDIT_ANSI_BLACK(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLACKBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;40m");
	}

	static inline void CNSEDIT_ANSI_RED(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_REDBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;41m");
	}

	static inline void CNSEDIT_ANSI_GREEN(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREENBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;42m");
	}

	static inline void CNSEDIT_ANSI_BLUE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;34m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUEBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;44m");
	}

	static inline void CNSEDIT_ANSI_YELLOW(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOWBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;43m");
	}

	static inline void CNSEDIT_ANSI_PURPLE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLEBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;45m");
	}

	static inline void CNSEDIT_ANSI_CYAN(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYANBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;46m");
	}

	static inline void CNSEDIT_ANSI_WHITE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITEBG(void) {
		_eapi_cnsedit_win_init();
		printf("\033[0;47m");
	}

	// Formatting: Bold
	static inline void CNSEDIT_ANSI_BLACK_BOLD(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_BOLD(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_BOLD(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_BOLD(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;34m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_BOLD(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_BOLD(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_BOLD(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_BOLD(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BOLDSET(void) {
		_eapi_cnsedit_win_init();
		printf("\033[1m");
	}

	// Formatting: Underline
	static inline void CNSEDIT_ANSI_BLACK_ULINE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;30m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_ULINE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;31m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_ULINE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;32m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_ULINE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;34m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_ULINE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;33m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_ULINE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;35m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_ULINE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;36m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_ULINE(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[4;37m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_ULINESET(void) {
		_eapi_cnsedit_win_init();
		printf("\033[4m");
	}

	// Formatting: High Intensity
	static inline void CNSEDIT_ANSI_BLACK_HINT(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;90m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_HINT(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;91m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_HINT(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;92m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_HINT(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;94m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_HINT(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;93m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_HINT(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;95m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_HINT(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;96m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_HINT(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[0;97m%.99s", text);
	}

	// Formatting: Bold High Intensity
	static inline void CNSEDIT_ANSI_BLACK_BHI(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;90m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_RED_BHI(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;91m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_GREEN_BHI(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;92m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_BLUE_BHI(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;94m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_YELLOW_BHI(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;93m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_PURPLE_BHI(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;95m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_CYAN_BHI(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;96m%.99s", text);
	}

	static inline void CNSEDIT_ANSI_WHITE_BHI(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[1;97m%.99s", text);
	}

	// Formatting: Flashing
	static inline void CNSEDIT_ANSI_FLASHING(const char *text) {
		_eapi_cnsedit_win_init();
		printf("\033[5m%.99s", text);
	}

	// Simple text print
	static inline void CNSEDIT_IO_OUTPUT(const char *text) {
		printf("%.499s", text);
	}

	/* ====== FS ======= */
	/* FS - signal "Attention! Now we will work with the filesystem. */

		static inline int FS_OBJ_EXISTS(const char *filename) {
			char path[500];
			snprintf(path, sizeof(path), "%.499s", filename);
			
			FILE *file = fopen(path, "r");
			if (file) {
				fclose(file); // ABSOLUTELY!! Close file
				return 1; // Return value '1' (true)
			}

			return 0; // If file doesn't exists or unable to access, return value '0' (false)
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
	static inline void CNSEDIT_IO_OUTPUT(const char text[500]) {
		printf("%.499s", text);
	}

	/* ====== FS ======= */
	/* FS - signal "Attention! Now we will work with the filesystem. */
	static inline int FS_OBJ_EXISTS(const char *filename) {
		char path[500];
		
		snprintf(path, sizeof(path), "%.499s", filename); /* sizeof takes into account the array size,
														 * thus preventing buffer overflow: very useful. */

		return (access(path, F_OK) == 0) ? 1 : 0; // C-style
	}

#ifdef __cplusplus
extern "C" }
#endif

#endif

#endif // EAPI_H

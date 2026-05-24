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
*/

#ifndef EAPI_H
#define EAPI_H

#include <stdio.h>

#ifdef _WIN32
	#include <windows.h>
	// Add code for Windows later
#else /* NOTE: this defines all systems except Windows. It primarily uses Unix/Linux/MacOS syntax.
	   * Unfortunately, there is no code for other systems. */
	
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
		printf("\033[0;33%.99s", text);
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

	// Formating: Bold
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
		printf("\033[1;33%.99s", text);
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
		printf("\033[1m%");
	}

#endif

#endif // EAPI_H

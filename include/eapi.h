/* ****************************************
 * It is terrible, but at least it works =D
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
	static inline void CNSEDIT_ANSI_RESET() { // Reset all ANSI-styles
		printf("\033[0m");
	}
	static inline void CNSEDIT_ANSI_RED(char text[100]) {
		printf("\033[0;31m%.99c", text);
	}
	static inline void CNSEDIT_ANSI_REDBG() {
		printf("\033[0;41m");
	}
	static inline void CNSEDIT_ANSI_GREEN(char text[100]) {
		printf("\033[0;32m%.99c", text);
	}
	static inline void CNSEDIT_ANSI_GREENBG() {
		printf("\033[0;42m");
	}
	static inline void CNSEDIT_ANSI_BLUE(char text[100]) {
		printf("\033[0;34m%.99c", text);
	}
	static inline void CNSEDIT_ANSI_BLUEBG() {
		printf("\033[0;44m");
	}

#endif

#endif // EAPI_H

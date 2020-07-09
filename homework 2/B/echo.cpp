#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	bool newLine = true, interpret = false;
	int start = 1;
	if (!strcmp(argv[1], "-n") || !strcmp(argv[1], "-nE") || !strcmp(argv[1], "-En")) {
		newLine = false;
		start = 2;
	}
	if (!strcmp(argv[1], "-e")) {
		interpret = true;
		start = 2;
	}
	if (!strcmp(argv[1], "-E")) {
		start = 2;
	}
	if (!strcmp(argv[1], "-ne") || !strcmp(argv[1], "-en")) {
		newLine = false, interpret = true;
		start = 2;
	}
	for (int i = start; i < argc; ++i) {
		for (char *p = argv[i]; *p; ++p) {
			if (*p != '\"' && *p != '\'') {
				if (*p == '\\' && interpret) {
					switch (*(p+1)) {
						case 't': putchar('\t'); ++p; break;
						case 'e': case 'E': putchar('\x1B'); ++p; break;
						case 'n': putchar('\n'); ++p; break;
						case 'c': return 0;
						case 'a': putchar('\n'); ++p; break;
						case 'b': putchar('\b'); ++p; break;
						case 'f': putchar('\f'); ++p; break;
						case 'r': putchar('\r'); ++p; break;
						case 'v': putchar('\v'); ++p; break;
						case '\\': putchar('\\'); ++p; break;
						default: putchar('\\'); break;
					}
				} else {
					putchar(*p);
				}
			}
		}
		if (i == argc-1) {
			if (newLine) {
				putchar('\n');
			}
		} else {
			putchar(' ');
		}
	}
	return 0;
}

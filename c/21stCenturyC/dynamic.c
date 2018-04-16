#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

void get_a_function() {
	FILE *f = fopen("fn.c", "w");
	fprintf(f,
			"#include <math.h>\n"
			"double fn(double in) {\n");
	char *a_line = NULL;
	char *prompt = ">>double fn(double in) {\n";
	do {
		free(a_line);
		a_line = readline(prompt);
		fprintf(f, "%s\n", a_line);
		prompt = ">> ";
	} while (strcmp(a_line, "}"));
	fclose(f);
}

void compile_and_run() {
	if (system("c99 -fPIC -shared fn.c -o fn.so") != 0) {
		printf("compliation error");
		return;
	}
	
	void *handle = dlopen("./fn.so", RTLD_LAZY);
	if (!handle) printf("failed to load fn.so: %s\n", dlerror());
	
	typedef double (*fn_type)(double);
	fn_type f = dlsym(handle, "fn");
	printf("f(1) = %g\n", f(1));
	printf("f(2) = %g\n", f(2));
	printf("f(27) = %g\n", f(27));
}

int main() {
	printf("Wanna write and run a function on the fly?\n"
			"Here's the beginning of the function, write the\n"
			"body and end with a '}' on its own line.\n\n");
	get_a_function();
	compile_and_run();
}

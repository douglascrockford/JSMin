/* Copyright 2002 Douglas Crockford <http://www.crockford.com>
 * Copyright 2011 Michael Steinert
 */

#include "jsmin/jsmin.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * \brief Output command line arguments as comments and minify the input.
 *
 * \param [in] argc The argument count
 * \param [in] argv The argument vector
 *
 * \return The program returns EXIT_SUCCESS or EXIT_FAILURE.
 */
int
main(int argc, char* argv[])
{
	int i;
	Jsmin *jsmin;
	for (i = 1; i < argc; ++i) {
		fprintf(stdout, "// %s\n", argv[i]);
	}
	jsmin = jsmin_create();
	if (!jsmin) {
		return EXIT_FAILURE;
	}
	jsmin_minify(jsmin);
	jsmin_destroy(jsmin);
	return EXIT_SUCCESS;
}

/* Copyright 2002 Douglas Crockford <http://www.crockford.com>
 * Copyright 2011 Michael Steinert
 */

/**
 * \brief Minify JavaScript source code
 */

#ifndef JSMIN_H
#define JSMIN_H

#ifdef __cplusplus
extern "C" {
#endif

#if __GNUC__ >= 4
#define JSMIN_PUBLIC __attribute__ ((visibility ("default")))
#define JSMIN_PRIVATE __attribute__ ((visibility ("hidden")))
#else
#define JSMIN_PUBLIC
#define JSMIN_PRIVATE
#endif

#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#define JSMIN_WARN_UNUSED_RESULT __attribute__ ((warn_unused_result))
#else
#define JSMIN_WARN_UNUSED_RESULT
#endif

typedef struct Jsmin_ Jsmin;

/**
 * \brief Create a new Jsmin object.
 *
 * \return A new Jsmin object or NULL if an error occurred.
 */
JSMIN_PUBLIC Jsmin *
jsmin_create(void)
	JSMIN_WARN_UNUSED_RESULT;

/**
 * \brief Free resources used by a Jsmin object.
 *
 * \param [in] self A Jsmin object
 */
JSMIN_PUBLIC void
jsmin_destroy(Jsmin *self);

/**
 * \brief Minify input from STDIN.
 *
 * Copy the input to the output, deleting the characters which are
 * insignificant to JavaScript. Comments will be removed. Tabs will be
 * replaced with spaces. Carriage returns will be replaced with linefeeds.
 * Most spaces and linefeeds will be removed.
 *
 * \param [in] self A Jsmin object.
 */
JSMIN_PUBLIC void
jsmin_minify(Jsmin *self);

#ifdef __cplusplus
}
#endif

#endif /* JSMIN_H */

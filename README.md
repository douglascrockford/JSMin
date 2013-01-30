# JSMIN, The JavaScript Minifier

_Douglas Crockford_
<douglas@crockford.com>

__2012-07-02__

JSMin is a filter which removes comments and unnecessary whitespace from
JavaScript files. It typically reduces filesize by half, resulting in faster
downloads. It also encourages a more expressive programming style because it
eliminates the download cost of clean, literate self-documentation.

## What JSMin Does

JSMin is a filter that omits or modifies some characters. This does not change
the behavior of the program that it is minifying. The result may be harder to
debug. It will definitely be harder to read.

JSMin first replaces carriage returns ('\r') with linefeeds ('\n'). It replaces
all other control characters (including tab) with spaces. It replaces comments
in the // form with linefeeds. It replaces comments in the /* */ form with
spaces. All runs of spaces are replaced with a single space. All runs of
linefeeds are replaced with a single linefeed.

It omits spaces except when a space is preceded and followed by a non-ASCII
character or by an ASCII letter or digit, or by one of these characters:

    \ $ _

It is more conservative in omitting linefeeds, because linefeeds are sometimes
treated as semicolons. A linefeed is not omitted if it precedes a non-ASCII
character or an ASCII letter or digit or one of these characters:

    \ $ _ { [ ( + -

and if it follows a non-ASCII character or an ASCII letter or digit or one of
these characters:

    \ $ _ } ] ) + - " '

No other characters are omitted or modified.

_JSMin_ knows to not modify quoted strings and regular expression literals.

_JSMin_ does not obfuscate, but it does uglify.

##Example

Before:

    // is.js
    // (c) 2001 Douglas Crockford
    // 2001 June 3
    // is
    // The -is- object is used to identify the browser.  Every browser edition
    // identifies itself, but there is no standard way of doing it, and some of
    // the identification is deceptive. This is because the authors of web
    // browsers are liars. For example, Microsoft's IE browsers claim to be
    // Mozilla 4. Netscape 6 claims to be version 5.

    // Warning: Do not use this awful, awful code.

    var is = {
        ie:      navigator.appName == 'Microsoft Internet Explorer',
        java:    navigator.javaEnabled(),
        ns:      navigator.appName == 'Netscape',
        ua:      navigator.userAgent.toLowerCase(),
        version: parseFloat(navigator.appVersion.substr(21)) ||
                 parseFloat(navigator.appVersion),
        win:    navigator.platform == 'Win32'
    }

    is.mac = is.ua.indexOf('mac') >= 0;

    if (is.ua.indexOf('opera') >= 0) {
        is.ie = is.ns = false;
        is.opera = true;
    }

    if (is.ua.indexOf('gecko') >= 0) {
        is.ie = is.ns = false;
        is.gecko = true;
    }
After:

    var is={ie:navigator.appName=='Microsoft Internet Explorer',java:navigator.javaEnabled(),ns:navigator.appName=='Netscape',ua:navigator.userAgent.toLowerCase(),version:parseFloat(navigator.appVersion.substr(21))||parseFloat(navigator.appVersion),win:navigator.platform=='Win32'}
    is.mac=is.ua.indexOf('mac')>=0;if(is.ua.indexOf('opera')>=0){is.ie=is.ns=false;is.opera=true;}
    if(is.ua.indexOf('gecko')>=0){is.ie=is.ns=false;is.gecko=true;}

## Character Set

JSMin requires, but does not verify, that the character set encoding of the
input program is either ASCII or UTF-8. It might not work correctly with other
encodings.

## Caution

Be sure to retain your original source file. JSMin is a one-way trip: Once done,
it cannot be undone.

Do not put raw control characters inside a quoted string. That is an extremely
bad practice. Use \x<i>hh</i> notation instead. JSMin will replace control
characters with spaces or linefeeds.

## Command Line Options

Optional parameters will be listed at the beginning of the output as comments.
This is a convenient way of replacing copyright messages and other documentation.

### Example:

    jsmin <fulljslint.js >jslint.js "(c)2002 Douglas Crockford"

## Errors

JSMin can produce three error messages to stderr:

- Unterminated comment.
- Unterminated string constant.
- Unterminated regular expression.

It ignores all other errors that may be present in your source program.

__Use of [JSLint](https://github.com/douglascrockford/JSLint) is strongly recommended.__

## License
_Copyright 2001 Douglas Crockford. All Rights Reserved Wrrrldwide._

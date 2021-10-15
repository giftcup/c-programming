#ifndef READLINE_H
#define READLINE_H

/*
 * read_line: Skips leading white-space characters, then
 *            reads the remainder of the inpt line and
 *            stores it in air. Truncates the line if its
 *            length exceedsa n. Returns the number of 
 *            characters stored.
 */
int read_line(char str[], int n);

#endif


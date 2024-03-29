**GDB**

set disassembly-flavor intel

set  disassemble-next-line on
show disassemble-next-line


h[elp]	Get help on gdb commands

h[elp] $ <$ cmd$ >$	Get help on a specific gdb command

r[un]	Run to next breakpoint or to end

s[tep]	Single-step, descending into functions

n[ext]	Single-step without descending into functions

fin[ish]	Finish current function, loop, etc. (useful!)

c[ontinue]	Continue to next breakpoint or end

up	Go up one context level on stack (to caller)

do[wn]	Go down one level (only possible after up)

l[ist]	Show lines of code surrounding the current point

p[rint] $ <$ name$ >$	Print value of variable called $ <$ name$ >$

p $ \ast<$ name$ >$	Print what is pointed to by $ <$ name$ >$

p/x $ <$ name$ >$	Print value of $ <$ name$ >$ in hex format

p $ <$ name$ >$ @$ <$ n$ >$	print $ <$ n$ >$ values starting at $ <$ name$ >$

p $ <$ chars$ >$ $ <$ tab$ >$	List all variables starting with $ <$ chars$ >$

b[reak] $ <$ name$ >$	Set a breakpoint at function $ <$ name$ >$

b $ <$ class$ >$ ::$ <$ name$ >$	Set a breakpoint at $ <$ name$ >$ in $ <$ class$ >$

b $ <$ class$ >$ ::$ <$ tab$ >$	List all members in $ <$ class$ >$

h[elp] b	Documentation for setting breakpoints

i[nfo] b	List breakpoints

i	List all info commands

i r shows all the registers

i r eax shos reg eax

dis[able] 1	Disable breakpoint 1

en[able] 1	Enable breakpoint 1

d[elete] 1	Delete breakpoint 1

d 1 2	Delete breakpoints 1 and 2

d	Delete all breakpoints

cond[ition] 1 $ <$ expr$ >$	Stop at breakpoint 1 only if $ <$ expr$ >$ is true

cond 1	Make breakpoint 1 unconditional

comm[ands] 1	Add a list of gdb commands to execute
				each time breakpoint 1 is hit
				(usually just print <var>)

bt - backtrace: show stack functions and args
info frame - show stack start/end/args/locals pointers
x/100x $sp - show stack memory (par words: 4 bytes)
x/20s $esp - show stack memory (par strings)

l	To see source code if debuging symbol

info functions - to check all functions in executable

********************************

**Examining memory**
https://web.archive.org/web/20080922034557/http://www.caf.dk/cafonly/gnu/gdb/gdb_56.html

You can use the command x (for "examine") to examine memory in any of several formats, independently of your program's data types.

x/nfu addr
x addr
x
Use the x command to examine memory.
n, f, and u are all optional parameters that specify how much memory to display and how to format it; addr is an expression giving the address where you want to start displaying memory. If you use defaults for nfu, you need not type the slash `/'. Several commands set convenient defaults for addr.

n, the repeat count
The repeat count is a decimal integer; the default is 1. It specifies how much memory (counting by units u) to display.
f, the display format
The display format is one of the formats used by print, `s' (null-terminated string), or `i' (machine instruction). The default is `x' (hexadecimal) initially. The default changes each time you use either x or print.
u, the unit size
The unit size is any of
b
Bytes.
h
Halfwords (two bytes).
w
Words (four bytes). This is the initial default.
g
Giant words (eight bytes).
Each time you specify a unit size with x, that size becomes the default unit the next time you use x. (For the `s' and `i' formats, the unit size is ignored and is normally not written.)
addr, starting display address
addr is the address where you want GDB to begin displaying memory. The expression need not have a pointer value (though it may); it is always interpreted as an integer address of a byte of memory. See section Expressions, for more information on expressions. The default for addr is usually just after the last address examined--but several other commands also set the default address: info breakpoints (to the address of the last breakpoint listed), info line (to the starting address of a line), and print (if you use it to display a value from memory).
For example, `x/3uh 0x54320' is a request to display three halfwords (h) of memory, formatted as unsigned decimal integers (`u'), starting at address 0x54320. `x/4xw $sp' prints the four words (`w') of memory above the stack pointer (here, `$sp'; see section Registers) in hexadecimal (`x').

Since the letters indicating unit sizes are all distinct from the letters specifying output formats, you do not have to remember whether unit size or format comes first; either order works. The output specifications `4xw' and `4wx' mean exactly the same thing. (However, the count n must come first; `wx4' does not work.)

Even though the unit size u is ignored for the formats `s' and `i', you might still want to use a count n; for example, `3i' specifies that you want to see three machine instructions, including any operands. The command disassemble gives an alternative way of inspecting machine instructions; see section Source and machine code.

All the defaults for the arguments to x are designed to make it easy to continue scanning memory with minimal specifications each time you use x. For example, after you have inspected three machine instructions with `x/3i addr', you can inspect the next seven with just `x/7'. If you use RET to repeat the x command, the repeat count n is used again; the other arguments default as for successive uses of x.

The addresses and contents printed by the x command are not saved in the value history because there is often too much of them and they would get in the way. Instead, GDB makes these values available for subsequent use in expressions as values of the convenience variables $_ and $__. After an x command, the last address examined is available for use in expressions in the convenience variable $_. The contents of that address, as examined, are available in the convenience variable $__.

If the x command has a repeat count, the address and contents saved are from the last memory unit printed; this is not the same as the last address printed if several units were printed on the last line of output.

********************************

(gdb) find 0x80048000, 0xc0000000, "/bin/sh" 

Another way to get the memory mapping of your process is using the gdb's embedded command :

(gdb) info proc map
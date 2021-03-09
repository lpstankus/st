/*┌──────────────────────────────────────────────────────────────────┐*/
/*│                                    __                            │*/
/*│                              _____/ /_                           │*/
/*│                             / ___/ __/                           │*/
/*│                            (__  ) /_                             │*/
/*│                           /____/\__/                             │*/
/*│                                                                  │*/
/*└──────────────────────────────────────────────────────────────────┘*/
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/* ======= See LICENSE file for copyright and license details ======= */
/*--------------------------------------------------------------------*/

/* ===== Border ===================================================== */
static int borderpx = 0;

/* ===== Fonts and cursor ======-==================================== */
static char *font = "JetBrainsMono:pixelsize=12:antialias=true:autohint=true";
static char *font2[] = {
	"inconsolata nerd font:pixelsize=12:antialias=true:autohint=true"
};

/*
 * https://invisible-island.net/xterm/ctlseqs/ctlseqs.html#h4-Functions-using-CSI-_-ordered-by-the-final-character-lparen-s-rparen:CSI-Ps-SP-q.1D81
 * Default style of cursor
 * 0: Blinking block
 * 1: Blinking block (default)
 * 2: Steady block ("█")
 * 3: Blinking underline
 * 4: Steady underline ("_")
 * 5: Blinking bar
 * 6: Steady bar ("|")
 * 7: Blinking st cursor
 * 8: Steady st cursor
 */
static unsigned int cursorstyle = 1;
static Rune stcursor = 0x2603; /* snowman (U+2603) */

/*
 * thickness of underline and bar cursors
 */
static unsigned int cursorthickness = 1;

/*
 * Default colour and shape of the mouse cursor
 */
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;

/*
 * blinking timeout for the terminal blinking attribute.
 */
static unsigned int blinktimeout = 800;

/* ===== Visual bell ================================================ */
/*
 * bell volume. It must be a value between -100 and 100. Use 0 for disabling it
 */
static int bellvolume = 0;

/*
 * visual-bell timeout in ms (0 to disable visual-bell)
 */
static int vbelltimeout = 100;

/*
 * cell selection logic
 */
#define VBCELL x <= 1 || x >= right - 1 || y == 0 || y == bottom

/* ===== Boxdraw ==================================================== */
/*
 * 1: render most of the lines/blocks characters without using the font for
 *    perfect alignment between cells (U2500 - U259F except dashes/diagonals).
 *    Bold affects lines thickness if boxdraw_bold is not 0. Italic is ignored.
 * 0: disable (render all U25XX glyphs normally from the font).
 */
const int boxdraw = 1;
const int boxdraw_bold = 1;

/*
 * braille (U28XX):  1: render as adjacent "pixels",  0: use font
 */
const int boxdraw_braille = 0;

/* ===== Colors ===================================================== */
/*
 * bg opacity
 */
float alpha = 0.7;

/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {
	/* 8 normal colors */
	"#000000", /* black   */
	"#FF3333", /* red     */
	"#B8CC52", /* green   */
	"#FF8F40", /* yellow  */
	"#59C2FF", /* blue    */
	"#D4BFFF", /* magenta */
	"#95E6CB", /* cyan    */
	"#cccccc", /* white   */

	/* 8 bright colors */
	"#303030", /* black   */
	"#FF3333", /* red     */
	"#B8CC52", /* green   */
	"#FF8F40", /* yellow  */
	"#59C2FF", /* blue    */
	"#D4BFFF", /* magenta */
	"#95E6CB", /* cyan    */
	"#F0F0F0", /* white   */

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#0A0E14", /* background */
	"#B3B1AD", /* foreground */
	"black",
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 257;
unsigned int defaultbg = 256;
static unsigned int defaultcs = 257;
static unsigned int defaultrcs = 256;

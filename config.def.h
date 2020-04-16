/*     _                      */
/*  __| |_      ___ __ ___     riddle00 */
/* / _` \ \ /\ / / '_ ` _ \    https://www.github.com/00riddle00/ */
/*| (_| |\ V  V /| | | | | |  */
/* \__,_| \_/\_/ |_| |_| |_|  */

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[]          = { "SauceCodePro Nerd Font:size=9:antialias=true:autohint=true" };

static const char dmenufont[]       = "SauceCodePro Nerd Font:size=10";

static const char arch_blue[]         = "#1793d1";
static const char pretty_blue[]       = "#268bd2";
static const char another_blue[]      = "#47afdf";
static const char light_blue[]        = "#79bac1";
static const char pretty_light_blue[] = "#00afd7";
static const char aquamarine[]        = "#06989a";
static const char sea[]               = "#bdced3";
static const char bar_bg[]            = "#002b36";
static const char col_white[]         = "#ffffff";

static const char *colors[][3]        = {
	/*               fg          bg         border    */
	[SchemeNorm] = { light_blue, bar_bg,    bar_bg    },
	[SchemeSel]  = { col_white,  arch_blue, arch_blue },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "♫", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(cmd)   { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]  = { "dmenu_run", "-p", "Run: ", NULL };
static const char *termcmd[]   = { "urxvt", NULL };

static Key keys[] = {
    /* ========================================================================= */
    /*  Basic Bindings                                                           */
    /* ========================================================================= */

	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ ALTKEY,                       XK_j,      rotatestack,    {.i = +1 } },
	{ ALTKEY,                       XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask,           XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ ALTKEY,                       XK_Escape, killclient,     {0} },
	{ MODKEY,                       XK_q,  	   quit,		   {0} },
    { ALTKEY,                       XK_F12,    quit,           {1} }, 
    { ALTKEY,                       XK_r,      quit,           {1} }, 
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

    /* Layout manipulation */
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },

     /* Switch to specific layouts */
	//{ MODKEY,               XK_t,      setlayout,      {.v = &layouts[0]} },
	//{ MODKEY,               XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,               XK_x,      setlayout,      {.v = &layouts[2]} },

    /* Switching between monitors */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

    /* ========================================================================= */
    /*  Letter Bindings                                                          */
    /* ========================================================================= */

	{ MODKEY,              XK_c,            spawn,           CMD("activate spotify") },
    { MODKEY,              XK_p,            spawn,           CMD("dmenu-pastes") },
    { MODKEY,              XK_q,            spawn,           CMD("activate emacs") },
    { MODKEY,              XK_o,            spawn,           CMD("keepass $DROPBOX/sync/keepass/8gb.kdbx") },
    { MODKEY,              XK_f,            spawn,           CMD("activate filezilla") },
    { ALTKEY,              XK_e,            spawn,           CMD("thunar") },
    { MODKEY,              XK_e,            spawn,           CMD("activate \"File Manager\"") },
    { MODKEY,              XK_g,            spawn,           CMD("smartgit") },
    { MODKEY,              XK_semicolon,    spawn,           CMD("libreoffice") },
    { MODKEY,              XK_t,            spawn,           CMD("qutebrowser-wall") },
    { MODKEY,              XK_r,            spawn,           CMD("urxvt -e ranger") },
    { MODKEY,              XK_y,            spawn,           CMD("urxvt -e calcurse -D ~/.config/calcurse") },
    { MODKEY,              XK_i,            spawn,           CMD("urxvt -e htop") },
    { MODKEY,              XK_s,            spawn,           CMD("betterlockscreen -t \"\" -l") },
    { MODKEY,              XK_b,            spawn,           CMD("gimp") },

    /* ========================================================================= */
    /*  Function Buttons                                                         */
    /* ========================================================================= */

	{ MODKEY,              XK_F1,           spawn,           CMD("urxvt -e killall picom && picom -b") },
	{ ALTKEY,              XK_F2,           spawn,           CMD("urxvt -name t2") },
    { MODKEY,              XK_F2,           spawn,           CMD("wmctrl -x -a t2.URxvt") },
	{ ALTKEY,              XK_F3,           spawn,           CMD("urxvt -e i3-vimnotes") },
    { MODKEY,              XK_F3,           spawn,           CMD("wmctrl -x -a notes.URxvt") },
	{ ALTKEY,              XK_F4,           spawn,           CMD("activate firefox") },
	{ ALTKEY,              XK_F5,           spawn,           CMD("subl3") },
	{ ALTKEY,              XK_F7,           spawn,           CMD("activate thunderbird") },
	{ MODKEY,              XK_F9,           spawn,           CMD("activate brave") },
	{ ALTKEY,              XK_F10,          spawn,           CMD("activate qalculate-gtk") },

	{ MODKEY,              XK_Insert,       spawn,           {.v = dmenucmd } },
	{ MODKEY|ShiftMask,    XK_Insert,       spawn,           CMD("dmenu-surfraw") },

	{ MODKEY,              XK_F5,           spawn,           CMD("light -U 10") },
	{ MODKEY,              XK_F6,           spawn,           CMD("light -A 10") },
	{ MODKEY,              XK_F11,          spawn,           CMD("amixer set Master 10%-") },
	{ MODKEY,              XK_F12,          spawn,           CMD("amixer set Master 10%+") },
	{ MODKEY|ShiftMask,    XK_Delete,       spawn,           CMD("amixer -q sset Master toggle") },

	{ MODKEY,              XK_Return,       spawn,          {.v = termcmd } },

    { MODKEY,              XK_Prior,        spawn,           CMD("$SHELL_SCRIPTS_DIR/reactivate_xkbmap.sh") },
    { MODKEY,              XK_Next,         spawn,           CMD("$SHELL_SCRIPTS_DIR/deactivate_xkbmap.sh") },

/* crashes */	{ MODKEY,              XK_Print,        spawn,           CMD("flameshot gui -p /home/riddle/Screenshots") },
	{ MODKEY|ShiftMask,    XK_Print,        spawn,           CMD("scrot /home/riddle/Screenshots/screenshot-%F-%H%M%S.png") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

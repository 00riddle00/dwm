/*     _                      */
/*  __| |_      ___ __ ___     riddle00 */
/* / _` \ \ /\ / / '_ ` _ \    https://www.github.com/00riddle00/ */
/*| (_| |\ V  V /| | | | | |  */
/* \__,_| \_/\_/ |_| |_| |_|  */
/*                            */
/* vim:fenc=utf-8:nu:ai:si:et:ts=4:sw=4:tw=80 */

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;  /* border pixel of windows    */
static const unsigned int gappx     = 2;  /* gaps between windows       */
static const unsigned int snap      = 32; /* snap pixel                 */
static const unsigned int showbar   = 1;  /* 0 means no bar             */
static const unsigned int topbar    = 1;  /* 0 means bottom bar         */
static const unsigned int viewontag = 0;  /* switch view on tag switch  */
static const unsigned int user_bh   = 24; /* 0 - calculate bar height,  */
                                          /* >= 1 user_bh as bar height */

static const char *fonts[]    = { "SauceCodePro Nerd Font:size=9:antialias=true:autohint=true" };
static const char dmenufont[] = "SauceCodePro Nerd Font:size=10";

static const char arch_blue[]         = "#1793d1";
static const char pretty_blue[]       = "#268bd2";
static const char another_blue[]      = "#47afdf";
static const char light_blue[]        = "#79bac1";
static const char pretty_light_blue[] = "#00afd7";
static const char aquamarine[]        = "#06989a";
static const char sea[]               = "#bdced3";
static const char bar_bg[]            = "#002b36";
static const char col_white[]         = "#ffffff";

static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[]  = "#005577";

static const char *colors[][3]        = {
    /*                   fg           bg          border   */
    [SchemeNorm]     = { light_blue,  bar_bg,     bar_bg    },
    [SchemeSel]      = { col_white,   arch_blue,  arch_blue },
    [SchemeStatus]   = { arch_blue,   bar_bg,     "#000000" }, /* Statusbar right           {text, bg, not used but cannot be empty} */
    [SchemeTagsSel]  = { col_white,   arch_blue,  "#000000" }, /* Tagbar left selected      {text, bg, not used but cannot be empty} */
    [SchemeTagsNorm] = { light_blue,  bar_bg,     "#000000" }, /* Tagbar left unselected    {text, bg, not used but cannot be empty} */
    [SchemeInfoSel]  = { arch_blue,   bar_bg,     "#000000" }, /* infobar middle selected   {text, bg, not used but cannot be empty} */
    [SchemeInfoNorm] = { col_white,   bar_bg,     "#000000" }, /* infobar middle unselected {text, bg, not used but cannot be empty} */
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "♫" };

static const Rule rules[] = {
    /* xprop(1):
     *     WM_CLASS(STRING) = instance, class
     *     WM_NAME(STRING)  = title
     */
    /* class              instance  title  tags mask  switchtotag  isfloating  monitor  float x,y,w,h   floatborderpx */
    { "Thunar",           NULL,     NULL,  0,         0,           0,          -1 },
    { "Brave",            NULL,     NULL,  1 << 1,    0,           0,          -1 },
    { "firefox",          NULL,     NULL,  1 << 3,    0,           0,          -1 },
    { "Gimp",             NULL,     NULL,  1 << 4,    0,           0,          -1 },
    { "Inkscape",         NULL,     NULL,  1 << 4,    0,           0,          -1 },
    { "SmartGit",         NULL,     NULL,  1 << 5,    0,           0,          -1 },
    { "Thunderbird",      NULL,     NULL,  1 << 6,    0,           0,          -1 },
    { "discord",          NULL,     NULL,  1 << 7,    0,           0,          -1 },
    { "kdenlive",         NULL,     NULL,  1 << 7,    0,           0,          -1 },
    { "Microsoft Teams",  NULL,     NULL,  1 << 7,    0,           0,          -1 },
    { "obs",              NULL,     NULL,  1 << 7,    0,           0,          -1 },
    { "Steam",            NULL,     NULL,  1 << 7,    0,           0,          -1 },
    { "Clementine",       NULL,     NULL,  1 << 8,    0,           0,          -1 },
    { "Spotify",          NULL,     NULL,  1 << 8,    0,           0,          -1 },
    { "KeePass2",         NULL,     NULL,  0,         0,           1,          -1,      1100,220,730,700,  1 },
    { "Lxappearance",     NULL,     NULL,  0,         0,           1,          -1,      1187,295,625,450,  2 },
    { "Pavucontrol",      NULL,     NULL,  0,         0,           1,          -1,      1187,295,625,450,  2 },
    { "Qalculate-gtk",    NULL,     NULL,  0,         0,           1,          -1,      1187,295,625,450,  2 },
};

/* layout(s) */
static const float mfact       = 0.50; /* factor of master area size [0.05..0.95]      */
static const int   nmaster     =    1; /* number of clients in master area             */
static const int   resizehints =    1; /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
#include "layouts.c"
static const Layout layouts[] = {
    /* symbol  arrange function */
    { "[|]",   tile },    /* first entry is default                     */
    { "~~",    NULL },    /* no layout function means floating behavior */
    { "[M]",   monocle },
    { "[@]",   dwindle },
    { "HHH",   grid },
    { NULL,    NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                        KEY,  view,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,            KEY,  toggleview,  {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,              KEY,  tag,         {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask,  KEY,  toggletag,   {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static       char dmenumon[2]      = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = { "dmenu_run", "-p", "run: ", NULL };
static const char *termcmd[]       = { "urxvt", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "urxvt", "-title", scratchpadname, "-geometry", "95x30", NULL };
/*                                 = { "st", "-t", scratchpadname, "-g", "95x30", NULL };            */

#include "shiftview.c"
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click          event mask  button    function         argument */
    { ClkLtSymbol,    0,          Button1,  setlayout,       {0} },
    { ClkLtSymbol,    0,          Button3,  setlayout,       {.v = &layouts[2]} },
    { ClkWinTitle,    0,          Button2,  zoom,            {0} },
    { ClkStatusText,  0,          Button2,  spawn,           {.v = termcmd } },
    { ClkClientWin,   ALTKEY,     Button1,  movemouse,       {0} },
    { ClkClientWin,   ALTKEY,     Button2,  togglefloating,  {0} },
    { ClkClientWin,   ALTKEY,     Button3,  resizemouse,     {0} },
    { ClkTagBar,      0,          Button1,  view,            {0} },
    { ClkTagBar,      0,          Button3,  toggleview,      {0} },
    { ClkTagBar,      ALTKEY,     Button1,  tag,             {0} },
    { ClkTagBar,      ALTKEY,     Button3,  toggletag,       {0} },
};

#include <X11/XF86keysym.h>
static Key keys[] = {
    /* ============================================================================================================================== */
    /*  Basic bindings                                                                                                                */
    /* ============================================================================================================================== */

    /* modifier            key                        function         argument */
    { MODKEY,              XK_grave,                  togglebar,       {0} },
    { MODKEY,              XK_l,                      focusstack,      {.i = +1 } },
    { MODKEY,              XK_j,                      focusstack,      {.i = +1 } },
    { MODKEY,              XK_h,                      focusstack,      {.i = -1 } },
    { MODKEY,              XK_k,                      focusstack,      {.i = -1 } },
    { MODKEY|ShiftMask,    XK_l,                      rotatestack,     {.i = +1 } },
    { MODKEY|ShiftMask,    XK_j,                      rotatestack,     {.i = +1 } },
    { MODKEY|ShiftMask,    XK_h,                      rotatestack,     {.i = -1 } },
    { MODKEY|ShiftMask,    XK_k,                      rotatestack,     {.i = -1 } },
    { MODKEY,              XK_i,                      incnmaster,      {.i = +1 } },
    { MODKEY,              XK_d,                      incnmaster,      {.i = -1 } },
/*  { MODKEY,              XK_h,                      setmfact,        {.f = -0.05} }, */
/*  { MODKEY,              XK_l,                      setmfact,        {.f = +0.05} }, */
    { MODKEY|ControlMask,  XK_Return,                 zoom,            {0} },
    { ALTKEY,              XK_Tab,                    view,            {0} },          
    { ALTKEY,              XK_Escape,                 killclient,      {0} },
/*  { MODKEY,              XK_q,                      quit,            {0} },          */
    { ALTKEY,              XK_F12,                    quit,            {1} }, 
    { ALTKEY,              XK_r,                      quit,            {1} }, 
    { MODKEY,              XK_0,                      view,            {.ui = ~0 } },
    { MODKEY|ShiftMask,    XK_0,                      tag,             {.ui = ~0 } },
    TAGKEYS(               XK_1,                                       0)
    TAGKEYS(               XK_2,                                       1)
    TAGKEYS(               XK_3,                                       2)
    TAGKEYS(               XK_4,                                       3)
    TAGKEYS(               XK_5,                                       4)
    TAGKEYS(               XK_6,                                       5)
    TAGKEYS(               XK_7,                                       6)
    TAGKEYS(               XK_8,                                       7)
    TAGKEYS(               XK_9,                                       8)
    TAGKEYS(               XK_d,                                       8)

    /* Layout manipulation */
    { MODKEY,              XK_space,                  setlayout,       {0} },
    { MODKEY|ShiftMask,    XK_space,                  togglefloating,  {0} },

    { ALTKEY,              XK_z,                      togglesticky,    {0} },

    { MODKEY,              XK_Tab,                    shiftview,       { .i = 1 } },
    { MODKEY|ShiftMask,    XK_Tab,                    shiftview,       { .i = -1 } },

    /* Switch to specific layouts */
/*  { MODKEY,              XK_t,                      setlayout,       {.v = &layouts[0]} }, */
/*  { MODKEY,              XK_f,                      setlayout,       {.v = &layouts[1]} }, */
    { MODKEY,              XK_x,                      togglefullscr,   {0} },
/*                                                    setlayout,       {.v = &layouts[2]} }, */
    { MODKEY,              XK_y,                      setlayout,       {.v = &layouts[3]} },
/*  { MODKEY,              XK_u,                      setlayout,       {.v = &layouts[4]} }, */
    { MODKEY|ControlMask,  XK_comma,                  cyclelayout,     {.i = -1 } },
    { MODKEY|ControlMask,  XK_period,                 cyclelayout,     {.i = +1 } },

    /* Switching between monitors */
/*  { MODKEY,              XK_comma,                  focusmon,        {.i = -1 } }, */
/*  { MODKEY,              XK_period,                 focusmon,        {.i = +1 } }, */
    { MODKEY|ShiftMask,    XK_comma,                  tagmon,          {.i = -1 } },
    { MODKEY|ShiftMask,    XK_period,                 tagmon,          {.i = +1 } },

    /* ============================================================================================================================== */
    /*  Letter bindings                                                                                                               */
    /* ============================================================================================================================== */

    { MODKEY,              XK_c,                      spawn,           CMD("activate spotify") },
    { MODKEY,              XK_p,                      spawn,           CMD("pavucontrol") },
    { MODKEY|ShiftMask,    XK_p,                      spawn,           CMD("dmenu-pastes") },
    { ALTKEY,              XK_p,                      spawn,           {.v = dmenucmd } },
    { ALTKEY|ShiftMask,    XK_p,                      spawn,           CMD("dmenu-surfraw") },
    { MODKEY,              XK_q,                      spawn,           CMD("activate emacs") },
    { MODKEY,              XK_o,                      spawn,           CMD("keepass $DROPBOX/keepass/8gb.kdbx") },
    { MODKEY,              XK_f,                      spawn,           CMD("activate filezilla") },
    { ALTKEY,              XK_e,                      spawn,           CMD("thunar") },
    { MODKEY,              XK_e,                      spawn,           CMD("wmctrl -x -a thunar") },
    { MODKEY,              XK_g,                      spawn,           CMD("activate smartgit") },
    { MODKEY,              XK_semicolon,              spawn,           CMD("libreoffice") },
    { MODKEY,              XK_t,                      spawn,           CMD("qutebrowser-wall") },
    { MODKEY,              XK_r,                      spawn,           CMD("urxvt -e ranger") },
    { MODKEY,              XK_y,                      spawn,           CMD("urxvt -e calcurse -D ~/.config/calcurse") },
    { MODKEY,              XK_i,                      spawn,           CMD("urxvt -e htop") },
    { MODKEY,              XK_s,                      spawn,           CMD("betterlockscreen -t \"\" -l") },
/*                                                                     CMD("xscreensaver-command --lock") },          */
    { MODKEY,              XK_b,                      spawn,           CMD("gimp") },
    { MODKEY,              XK_n,                      spawn,           CMD("brave") },

    /* ============================================================================================================================== */
    /*  Function keys                                                                                                                 */
    /* ============================================================================================================================== */

    { MODKEY,              XK_F1,                     spawn,           CMD("urxvt -e killall picom && picom -b") },
    { ALTKEY,              XK_F2,                     spawn,           CMD("urxvt -name t2") },
    { 0,                   XK_F2,                     spawn,           CMD("wmctrl -x -a t2.URxvt") },
    { ALTKEY,              XK_F3,                     spawn,           CMD("dwm-vimnotes") },
    { 0,                   XK_F3,                     spawn,           CMD("wmctrl -x -a notes.URxvt") },
    { 0,                   XK_F4,                     spawn,           CMD("activate firefox") },
    { 0,                   XK_F5,                     spawn,           CMD("subl3") },
    { 0,                   XK_F7,                     spawn,           CMD("activate thunderbird") },
    { 0,                   XK_F8,                     spawn,           CMD("activate teams") },
    { 0,                   XK_F9,                     spawn,           CMD("activate brave") },
    { 0,                   XK_F10,                    spawn,           CMD("activate qalculate-gtk") },

    { 0,                   XK_Insert,                 spawn,           CMD("rofi -show") },
    { MODKEY,              XK_Insert,                 spawn,           CMD("rofi -show run") },
    { MODKEY,              XK_End,                    spawn,           CMD("rofi -show Power -modi Power:$BIN/rofi-power") },
    { MODKEY,              XK_Delete,                 spawn,           CMD("rofi -show Kill -modi Kill:$BIN/rofi-kill") },

    { MODKEY,              XK_F5,                     spawn,           CMD("light -U 10") },
    { MODKEY,              XK_F6,                     spawn,           CMD("light -A 10") },
    { MODKEY,              XK_F11,                    spawn,           CMD("amixer set Master 10%-") },
    { MODKEY,              XK_F12,                    spawn,           CMD("amixer set Master 10%+") },
    { MODKEY|ShiftMask,    XK_Delete,                 spawn,           CMD("amixer -q sset Master toggle") },

    { 0,                   XK_F12,                    spawn,           CMD("dmenu-dwm.rebuild") },

    { MODKEY,              XK_Return,                 spawn,           {.v = termcmd } },
    { MODKEY,              XK_u,                      togglescratch,   {.v = scratchpadcmd } },
    { ALTKEY,              XK_q,                      togglescratch,   {.v = scratchpadcmd } },

    { MODKEY,              XK_Prior,                  spawn,           CMD("redshift -P -O 6500") },
    { MODKEY,              XK_Next,                   spawn,           CMD("redshift -P -O 5000") },

    { 0,                   XK_Print,                  spawn,           CMD("flameshot gui -p /home/riddle/Screenshots") },
    { 0|ShiftMask,         XK_Print,                  spawn,           CMD("scrot /home/riddle/Screenshots/screenshot-%F-%H%M%S.png") },

    /* ============================================================================================================================== */
    /*  Media keys                                                                                                                    */
    /* ============================================================================================================================== */

    { MODKEY,              XK_equal,                  spawn,           CMD("amixer sset Master 5%+") },
    { MODKEY|ShiftMask,    XK_equal,                  spawn,           CMD("amixer sset Master 15%+") },
    { MODKEY,              XK_minus,                  spawn,           CMD("amixer sset Master 5%-") },
    { MODKEY|ShiftMask,    XK_minus,                  spawn,           CMD("amixer sset Master 15%-") },
 
    { MODKEY,              XK_comma,                  spawn,           CMD("mpc prev") },
    { MODKEY|ShiftMask,    XK_comma,                  spawn,           CMD("mpc seek 0%") },
    { MODKEY,              XK_period,                 spawn,           CMD("mpc next") },
    { MODKEY|ShiftMask,    XK_period,                 spawn,           CMD("mpc next") },

    { MODKEY,              XK_bracketleft,            spawn,           CMD("mpc seek -10") },
    { MODKEY|ShiftMask,    XK_bracketleft,            spawn,           CMD("mpc seek -120") },
    { MODKEY,              XK_bracketright,           spawn,           CMD("mpc seek +10") },
    { MODKEY|ShiftMask,    XK_bracketright,           spawn,           CMD("mpc seek +120") },

    /* ============================================================================================================================== */
    /*  Extra XF86 Keys                                                                                                               */
    /* ============================================================================================================================== */

    /* Caution: Airplane mode button turns off internet! */
    { 0,                   XF86XK_AudioRaiseVolume,   spawn,           CMD("amixer set Master 10%+") },
    { 0,                   XF86XK_AudioLowerVolume,   spawn,           CMD("amixer set Master 10%-") },
    { 0,                   XF86XK_MonBrightnessUp,    spawn,           CMD("light -A 10") },
    { 0,                   XF86XK_MonBrightnessDown,  spawn,           CMD("light -U 10") },
};


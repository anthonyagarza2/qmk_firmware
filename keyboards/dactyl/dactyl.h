#ifndef DACTYL_H
#define DACTYL_H

#include "quantum.h"

void promicro_bootloader_jmp(bool program);

//TODO: fix
#define KEYMAP( \
	k00, k01, k02, k03, k04, k05, k40, k41, k42, k43, k44, k45, \
	k10, k11, k12, k13, k14, k15, k50, k51, k52, k53, k54, k55, \
	k20, k21, k22, k23, k24, k25, k60, k61, k62, k63, k64, k65, \
	k30, k31, k32, k33, k34, k35, k70, k71, k72, k73, k74, k75 \
	) \
	{ \
		{ k00, k01, k02, k03, k04, k05 }, \
		{ k10, k11, k12, k13, k14, k15 }, \
		{ k20, k21, k22, k23, k24, k25 }, \
		{ k30, k31, k32, k33, k34, k35 }, \
		{ k40, k41, k42, k43, k44, k45 }, \
		{ k50, k51, k52, k53, k54, k55 }, \
		{ k60, k61, k62, k63, k64, k65 }, \
		{ k70, k71, k72, k73, k74, k75 } \
	}

#define DACTYL(\
	k00, k01, k02, k03, k04, k05, k60, k61, k62, k63, k64, k65, \
	k10, k11, k12, k13, k14, k15, k70, k71, k72, k73, k74, k75, \
	k20, k21, k22, k23, k24, k25, k80, k81, k82, k83, k84, k85, \
	k30, k31, k32, k33, k34, k35, k90, k91, k92, k93, k94, k95, \
	k40, k41, k42, k43, k44, k45, kA0, kA1, kA2, kA3, kA4, kA5, \
	k50, k51, k52, k53, k54, k55, kB0, kB1, kB2, kB3, kB4, kB5 \
	) \
	{ \
		{ k60, k61, k62, k63, k64, k65 }, \
		{ k70, k71, k72, k73, k74, k75 }, \
		{ k80, k81, k82, k83, k84, k85 }, \
		{ k90, k91, k92, k93, k94, k95 }, \
		{ kA0, kA1, kA2, kA3, kA4, kA5 }, \
		{ kB0, kB1, kB2, kB3, kB4, kB5 }, \
		{ k05, k04, k03, k02, k01, k00 }, \
		{ k15, k14, k13, k12, k11, k10 }, \
		{ k25, k24, k23, k22, k21, k20 }, \
		{ k35, k34, k33, k32, k31, k30 }, \
		{ k45, k44, k43, k42, k41, k40 }, \
		{ k55, k54, k53, k52, k51, k50 } \
	}

#endif
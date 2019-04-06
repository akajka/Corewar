.name "Sherlok"
.comment "Elementary, my dear Watson"

wall_prep:
		sti r1, %:wall, %1
		ld %0, r2
		live %1
		fork %:start

wall: 	live %1
		st   r2, -17
		st   r2, -18
		st   r2, -27
		st   r2, -36
		st   r2, -45
		st   r2, -54
		st   r2, -63
		st   r2, -72
		st   r2, -81
		st   r2, -90
		st   r2, -99
		st   r2, -108
		st   r2, -117
		st   r2, -126
		st   r2, -135
		st   r2, -144
		st   r2, -153
		st   r2, -162
		st   r2, -171
		st   r2, -180
		st   r2, -189
		st   r2, -198
		st   r2, -207
		st   r2, -216
		st   r2, -225
		st   r2, -234
		st   r2, -243
		st   r2, -252
		st   r2, -261
		st   r2, -270
		st   r2, -279
		st   r2, -288
		st   r2, -297
		st   r2, -306
		st   r2, -315
		st   r2, -324
		st   r2, -333
		st   r2, -342
		st   r2, -351
		st   r2, -360
		st   r2, -369
		st   r2, -378
		st   r2, -387
		st   r2, -396
		st   r2, -405
		st   r2, -414
		st   r2, -423
		st   r2, -432
		st   r2, -441
		st   r2, -450
		st   r2, -459
		st   r2, -468
		st   r2, -477
		add r3, r3, r3
		zjmp  %:wall
start:
	fork	%:labe1
	st		r1, 6
	live	%42
	fork	%:labe2

labe1:
	st		r1, 6

live:
	live	%985341
	live	%985341
	live	%985341
	live	%985341
	zjmp	%:live

labe2:
	st		r1, 6

pfork:
	live	%96824
	fork	%:pfork

init:
	ld		%0, r2
	ld		%4, r3
	ld		%96, r5
	sti		r1, %:labe3, %1
	st		r1, 6

labe:
	live	%8008135
	ldi		%:init, r2, r4
	sti		r4, %400, r2
	add		r2, r3, r2
	ldi		%:init, r2, r4
	sti		r4, %383, r2
	add		r2, r3, r2
labe3:
	live	%89523
	xor		r2, r5, r15	
	zjmp	%80
loop:
	ld  	%0, r15
	zjmp	%:labe


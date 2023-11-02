
all: rpl vortaro

rpl:
	gcc src/rpl.c -o src/rpl

vortaro:
	gcc src/vortaro.c -o src/vortaro

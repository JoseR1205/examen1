

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "salon.h"
#include "arcade.h"
#define LEN_SALA 100
#define LEN_ARCADE 1000
int main(void) {
	setbuf(stdout,NULL);
	Salon sala[LEN_SALA];
	Arcade arcade[LEN_ARCADE];
	initSalon(sala, LEN_SALA);
	initArcade(arcade, LEN_ARCADE);
	menu(sala, arcade,LEN_SALA,LEN_ARCADE);
	return 0;
}

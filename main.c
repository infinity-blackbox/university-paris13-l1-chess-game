 /**
                        `@@@                                                                                                      @@@
                       @@@@@@@@                                                                                                @@@@@@@@
                      @@@@@@@@@@@@                                                                                          @@@@@@@@@@@@
                      @@@@@@@@@@@@@@@                                                                                    @@@@@@@@@@@@@@@
                      @@@@@@@@@@@@@@@@@@                                                                              @@@@@@@,@@@@@@@@@@
                      @@@@  .@@@@@@@@,,;@@@                                                                        @@@@@@@,@@@@@@`  @@@@
                       @@@    @@@@@@@@@,,:@,:@                                                                 `@@@@,;;,@,@@@@@@    @@@
                       .@@@       @@@@@@,,@#,,@;,,,:;                                                    ;@@,#,@,:.@@@@@@@@@       @@@`
                        @@@        @@@@@,+,'@:,,,,,+@,',:                                             @@;,@,@,,@@@@@@@@@@@@        @@@
                        @@@          @@@@@#,@@+,'@#@@@@@@@       ;#@@@@@@@@@@@@@@@@@@@@@@@@@+.      @@@@,@,#@@:,',@@@@@@@          @@@
                         @@@           #@@@@@#.@@@@+,'@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,@@@@@,:@@@#           @@@
                         @@@             @@@@@@,,#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+@@@@@             @@@
                         ;@@@              @@@@@@@@@@@@@@@@@@@@@@@@@@@+:               '#@@@@@@@@@@@@@@@@@@@@@@@@@@              @@@:
                          @@@              #@@@@@@@@@@@@@@;                                         @@@@@@@@@@@@@@@             `@@@
                          @@@@           @@@@@@@@@@@@@                                                   @@@@@@@@@@@@@          @@@@
                          :@@@        +@@@@@@@@@@@                                                          `@@@@@@@@@@@        @@@,
                           @@@@     ,@@@@@@@@@@                                                                .@@@@@@@@@@.    @@@@
                           @@@@    @@@@@@@@@                                                                      +@@@@@@@@@   @@@@
                           @@@@@ @@@@@@@@@                                                                          '@@@@@@@@ @@@@@
                            @@@@@@@@@@@@                                                                              @@@@@@@@@@@@
                            @@@@@@@@@                                                                                   @@@@@@@@@@
                             @@@@@@,                                 MEIKA THE BLACK NEKO                                 :@@@@@@@
                             @@@@@                                      THE SWEETNESS                                       @@@@@@
                             @@@                                                                                             @@@@#
                             @@                                                                                               @@@@
                            ,                                                                                                   @@
																		 CHESS GAME
																	    version 5.0

																	    CONTRUBUTORS:
															         William Phetsinorath
															             Rakib Sheikh
																      Sabri Rezak Salem

																		    2016
 */

#include<stdio.h>
#include<stdlib.h>
#include"src/loader.h"

int main()
{
	//======================================================================
	// Variables
	//======================================================================
    game_t * game_new;

    /* Initialize */
    game_new = partie_nouvelle();

	//======================================================================
	// Main
	//======================================================================
    partie_jouer(game_new);
    return EXIT_SUCCESS;
}

;/*=========== Summer Begin ===========;*/

	{"*****SUMMER SOVIET GRASS*****"
		{models
			{"dummygrass"}
		}
		{density 0.01}
	}
	{"grass_lawn"
		{models
			{"mirco_grass"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"grass_lawn_dry"
		{models
			{"mirco_grass" "dry"}
			{"grass_empty"}	
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"twigs_summer"
		{models
			{"gem2_brush_grass_brushed_1" "brush3" 0.5}
			{"gem2_brush_grass_brushed_2" "brush3" 0.5}
			{"gem2_brush_grass_brushed_1" "brush4" 0.5}
			{"gem2_brush_grass_brushed_2" "brush4" 0.5}
			{"grass_filler" "twigs" 0.5}
			{"gem2_brush_grass_dense_2" "brush3" 0.5}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"small_grass_summer"					;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_small_sum_1" "1" 0.4}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"small_grass_steppe"					;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_small_dry_1" "1" 0.4}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"bush_grass_summer"					;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_2" "dense2_sum2"}
			{"grass_empty"}
			{"grass_empty"}	
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"bush_grass_steppe"					;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_2" "dense2_sum1"}
			{"grass_empty"}
			{"grass_empty"}	
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"medium_grass_summer"					;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_medium_sum_1" "1" 0.7}
			{"grass_empty"}	
			{"grass_empty"}	
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"medium_grass_summer2"					;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_medium_aut_2" "1" 0.7}
			{"grass_empty"}	
			{"grass_empty"}	
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"medium_grass_steppe"					;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_medium_dry_2" "1" 0.7}
			{"grass_empty"}
			{"grass_empty"}	
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"tall_grass_summer"					;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_tall_sum_2" "1" 0.5}
			{"gem2_brush_grass_dense_tall_sum_2" "2" 0.5}
			{"grass_empty"}
			{"grass_empty"}
		}
		{density 0.05}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"summer_flowers"
		{models
			{"gem2_brush_grass_1" "2" 0.7}
			{"gem2_brush_grass_3" "2" 0.7}
			{"gem2_brush_grass_4" "2" 0.7}
			{"gem2_brush_grass_5" "2" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"tall_grass_steppe"
		{models
			{"gem2_brush_grass_3" "aut" 0.7}
			{"gem2_brush_grass_4" "aut" 0.7}
			{"gem2_brush_grass_5" "aut" 0.7}
			{"gem2_brush_grass_1" "aut1" 0.7}
			{"gem2_brush_grass_3" "aut1" 0.7}
			{"gem2_brush_grass_4" "aut1" 0.7}
			{"gem2_brush_grass_5" "aut1" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"fern_summer"
		{models
			{"gem2_brush_fern_1" 0.7}
			{"gem2_brush_fern_2" 0.7}
			{"gem2_brush_fern_3" 0.7}
			{"gem2_brush_fern_4" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"wheat_field"
		{models
			{"gem2_wheat"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"wheat_field_small"
		{models
			{"gem2_brush_grass_1" "wheat" 0.7}
			{"gem2_brush_grass_3" "wheat" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}

;/*=========== Summer End ===========;*/

	{"	"
		{models
			{"dummygrass"}
		}
		{density 0.01}
	}

;/*=========== Autumn Begin ===========;*/

	{"*****AUTUMN GRASS*****"
		{models
			{"dummygrass"}
		}
	}
	{"brushed_grass"
		{models
			{"gem2_brush_grass_brushed_1" "brush" 0.5}
			{"gem2_brush_grass_brushed_1" "brush2" 0.5}
			{"grass_filler" 0.65}
			{"gem2_brush_grass_dense_2" "brush" 0.5}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"grass_lawn_autumn"
		{models
			{"mirco_grass" "autumn"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"short-grass_aut"
		{models
			{"gem2_brush_grass_1" "aut" 0.7}
			{"gem2_brush_grass_1" "aut1" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"small_grass_autumn_1_new"				;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_small_aut_1" "1"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"small_grass_autumn_2_new"				;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_small_aut_2" "1"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"grass_dense_aut"						;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_1" "aut" 0.7}
			{"gem2_brush_grass_dense_2" "aut1" 0.7}
			{"gem2_brush_grass_dense_2" "dense2aut" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"grass_dense_aut2"						;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_1" "dense2_aut2" 0.7}
			{"gem2_brush_grass_dense_2" "aut2" 0.7}
			{"gem2_brush_grass_dense_2" "dense2_aut3" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"bush_dense_aut"						;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_2" "dense2aut"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"bush_dense_aut2"						;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_2" "dense2_aut3"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"medium_grass_autumn_1_new"			;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_medium_aut_1" "1"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"tall_grass_autumn_1_new"				;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_tall_aut_1" "1"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"tall-grass_feather_aut"
		{models
			{"grass_filler" 0.7}
			{"gem2_brush_grass_1" "aut1" 0.7}
			{"gem2_brush_grass_1" "aut" 0.7}
			{"gem2_brush_grass_1" "autlate" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"tall-grass_autlate"
		{models
			{"gem2_brush_grass_1" "autlate" 0.7}
			{"gem2_brush_grass_3" "autlate" 0.7}
			{"gem2_brush_grass_4" "autlate" 0.7}
			{"gem2_brush_grass_5" "autlate" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"tall-grass_reeds_aut"
		{models
			{"gem2_brush_grass_1" "reed2aut"}
			{"gem2_brush_grass_3" "reed2aut"}
			{"gem2_brush_grass_2" "reed2aut"}
			{"gem2_brush_grass_5" "reed2aut"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"fern_autumn"
		{models
			{"gem2_brush_fern_1" "aut" 0.7}
			{"gem2_brush_fern_2" "aut" 0.7}
			{"gem2_brush_fern_3" "aut" 0.7}
			{"gem2_brush_fern_4" "aut" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}

;/*=========== Autumn End ===========;*/

	{"	 "
		{models
			{"dummygrass"}
		}
		{density 0.01}
	}

;/*=========== Winter Begin ===========;*/

	{"*****WINTER GRASS*****"
		{models
			{"dummygrass"}
		}
		{density 0.01}
	}
	{"grass_lawn_winter"
		{models
			{"mirco_grass" "win"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"bush_dense_win1"						;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_2" "dense2_win2"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"tall_grass_winter_1_new"				;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_tall_win_1" "1" 0.5}
			{"grass_empty"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"tall-grass_feather_win"
		{models
			{"gem2_brush_grass_1" "win4" 0.7}
			{"gem2_brush_grass_1" "win5" 0.7}
			{"gem2_brush_grass_1" "win2" 0.7}
			{"gem2_brush_grass_3" "win2" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"medium_grass_winter_1_new"			;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_medium_win_1" "1" 0.5}
			{"grass_empty"}
			{"grass_empty"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"small_grass_winter_1_new"				;// name
		{models								;// list of models (equal probability)
 			{"gem2_brush_grass_dense_small_win_1" "1" 0.7}
			{"grass_empty"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"brushed_grass_winter"
		{models
			{"gem2_brush_grass_brushed_1" "brush_win" 0.7}
			{"gem2_brush_grass_brushed_1" "brush2_win" 0.7}
			{"grass_filler" "win" 0.7}
			{"gem2_brush_grass_dense_2" "brush_win" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"fern_winter"
		{models
			{"gem2_brush_fern_1" "win" 0.7}
			{"gem2_brush_fern_2" "win" 0.7}
			{"gem2_brush_fern_3" "win" 0.7}
			{"gem2_brush_fern_4" "win" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"wheat_win"
		{models
			{"gem2_wheat" "win"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"wheat_win_small"
		{models
			{"gem2_brush_grass_1" "wheat_win" 0.7}
			{"gem2_brush_grass_3" "wheat_win" 0.7}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	
;/*=========== Winter End ===========;*/

	{"	  "
		{models
			{"dummygrass"}
		}
		{density 0.01}
	}

;/*=========== Spring Begin ===========;*/

	{"*****SPRING GRASS*****"
		{models
			{"dummygrass"}
		}
		{density 0.01}
	}

;/*=========== Spring Begin ===========;*/

	{"	   "
		{models
			{"dummygrass"}
		}
		{density 0.01}
	}
	{"brushed_grass_spring"
		{models
			{"gem2_brush_grass_brushed_1" "brush_spring" 0.7}
			{"gem2_brush_grass_brushed_2" "brush_spring" 0.7}
			{"gem2_brush_grass_brushed_1" "brush2_spring" 0.7}
			{"gem2_brush_grass_brushed_2" "brush2_spring" 0.7}
			{"grass_filler" "spring" 0.7}
			{"gem2_brush_grass_dense_2" "brush_spring" 0.7}
			{"grass_empty"}
		}
		{density 0.05}
		{positionOffset 0.8}
	}

;/*=========== Dry Grass Begin ===========;*/

	{"*****DRY GRASS*****"
		{models
			{"dummygrass"}
		}
		{density 0.01}
	}
	{"branch_grass"
		{models
			{"branch_paint" "branch_bare"}
			{"branch_paint2" "branch_bare"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"branch_grass_brown"
		{models
			{"branch_paint" "brown"}
			{"branch_paint2" "brown"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"branch_grass_burned"
		{models
			{"branch_paint" "burned"}
			{"branch_paint2" "burned"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}
	}
	{"grass_dense_dry"						;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_1" "dense2_dry1"}
			{"gem2_brush_grass_dense_2" "dense2_dry2"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"bush_dense_dry"						;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_2" "dense2_dry2"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"small_grass_dry"						;// name
		{models								;// list of models (equal probability)
			{"gem2_brush_grass_dense_small_dry_2" "1"}
			{"grass_empty"}
		}
		{density 0.25}
		{positionOffset 0.8}				;// density of units per square meter
	}
	{"fern_decayed"
		{models
			{"gem2_brush_fern_1" "decayed" 0.7}
			{"gem2_brush_fern_2" "decayed" 0.7}
			{"gem2_brush_fern_3" "decayed" 0.7}
			{"gem2_brush_fern_4" "decayed" 0.7}
			{"grass_empty" 0.7}	
		}
		{density 0.25}
		{positionOffset 0.8}
	}

;/*=========== Dry Grass End ===========;*/
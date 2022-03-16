(define "cut_pieces"
	("cut_piece" args 0)	("cut_piece" args 1)
	("cut_piece" args 2)	("cut_piece" args 3)
	("cut_piece" args 4)	("cut_piece" args 5)
	("cut_piece" args 6)	("cut_piece" args 7)
	("cut_piece" args 8)	("cut_piece" args 9)
	("cut_piece" args 00)	("cut_piece" args 01)
	("cut_piece" args 02)	("cut_piece" args 03)
	("cut_piece" args 04)	("cut_piece" args 05)
	("cut_piece" args 06)	("cut_piece" args 07)
	("cut_piece" args 08)	("cut_piece" args 09)
	("cut_piece" args 10)	("cut_piece" args 11)
	("cut_piece" args 12)	("cut_piece" args 13)
	("cut_piece" args 14)	("cut_piece" args 15)
	("cut_piece" args 16)	("cut_piece" args 17)
	("cut_piece" args 18)	("cut_piece" args 19)
	("cut_piece" args 20) 	("cut_piece" args 21)
	("cut_piece" args 22) 	("cut_piece" args 23)
	("cut_piece" args 24) 
)

(define "cut_subpieces"
	("cut_subpiece" args 0)	("cut_subpiece" args 1)
	("cut_subpiece" args 2)	("cut_subpiece" args 3)
	("cut_subpiece" args 4)	("cut_subpiece" args 5)
	("cut_subpiece" args 6)	("cut_subpiece" args 7)
	("cut_subpiece" args 8)	("cut_subpiece" args 9)
	("cut_subpiece" args 00)("cut_subpiece" args 01)
	("cut_subpiece" args 02)("cut_subpiece" args 03)
	("cut_subpiece" args 04)("cut_subpiece" args 05)
	("cut_subpiece" args 06)("cut_subpiece" args 07)
	("cut_subpiece" args 08)("cut_subpiece" args 09)
	("cut_subpiece" args 10)("cut_subpiece" args 11)
	("cut_subpiece" args 12)("cut_subpiece" args 13)
	("cut_subpiece" args 14)("cut_subpiece" args 15)
	("cut_subpiece" args 16)("cut_subpiece" args 17)
)

{"parts construction"
	{on break_armor
		{if volume "body"
			{if name "blast"
				{set "blast" 1}
				{##if not "blast_disable"		;// disabled. caused parts of buildings that were broken to not fall
					{if min_energy 350
						{set "blast_one" 0}
					else
						{set "blast_one" 1}
					}
					{call "change_model"}
				}
				{call "change_model"}
			else
				;{set "blast" 0}
				;{call "change_model"}
			}
		}
	}
	{on bullet_hit
		{if volume "body"
			{if stuff "shell"
				{call "break_windows"}
			}
		}
	}
	{on contact
		{set "blast" 0}
		{if effector "airborne"
			{call "change_model"}
		else effector "air_part"
			{if min_speed 5
				{call "change_model"}
			}
		}
	}
	{on "change_model"
		{if not "sliced"
			{tags add "crushed"}
			{set "sliced" 1}
			{call "disable_volumes"}
			{call "check_structure"}
			{delay_ex 0.1
				{call_synced "change_model_synced"}
			}
		}
	}
	{on "change_model_synced"
		{call "set_skeleton_local"}
		{call "disable_volumes"}
		{call "update_fx"}
		{set "first_stage" 1}
		{set "last_stage" 1}
		{call "effects"}
		{call "cut_pieces"}
		{ani_play "crush"}
		{delay 0.1
			{volumes "body" enable contact bullet blast visible}
			{restore_volume_states} ; restore volume ables from .def file
			{update_visibility_patch}
		}
	}
	{on "set_skeleton_local"
		{if not "x_skeleton_set"
			{set_skeleton "_x" local}
			{set "sliced" 0}
			{set "x_skeleton_set" 1}
		else
			{set_skeleton "_xx"}
		}
	}
	{on "break"
		{call "change_model"}
	}
	{on "burn_end"
		{bone hide "roof_hide"}
		{tex_mod "burned"}
	}
}
{"parts jettison_bricks"
	{on "change_model"
		{if not "brick_crush"
			{spawn "brick_crush" "fxbrick1"}
			{set "brick_crush" 1}
		}
	}
}

{"no_xx parts construction"
	{on "set_skeleton_local" overload
		{if not "x_skeleton_set"
			{set_skeleton "_x" local}
			{set "x_skeleton_set" 1}
		}
	}
}

{"break_on_burn parts construction"
	{on "burn_end"
		{call "break"}
	}
}

{"small parts construction"
	{on contact
		{set "blast" 0}
		{if can_crush
			{call "change_model"}
		}
	}
}

{"crushable parts construction"
	{on contact
		{if can_crush
			{set "blast" 0}
			{call "change_model"}
		}
	}
}

{"concrete small parts construction"
	{on "cut_pieces" overload
		{if "blast"
			{volumes disable contact}
			(define "cut_piece"
				{tear "piece_small_concrete" bone "piece%0"
					{volumes enable contact}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{volumes disable contact}
			(define "cut_piece"
				{tear "piece_small_concrete" bone "piece%0"
					{volumes enable contact}
					{impulse up 0.5 0.25 dir 2.5 0.3 no_position}
				}
			)
			("cut_pieces")
		}
	}
}


{"big steel parts construction"
	{on "cut_pieces"
		{if "blast"
			(define "cut_piece"
				{tear "piece_large_steel" bone "piece%0"
					{volumes enable contact}
					{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
				}
			)
			("cut_pieces")
			(define "cut_subpiece"
				{tear "piece_medium_steel" bone "sub_piece%0"
					{volumes enable contact}
					{spawn "spheredust_norm" "sub_piece%0"}
					{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
				}
			)
			("cut_subpieces")
		else
			(define "cut_piece"
				{tear "piece_large_steel" bone "piece%0"
					{volumes enable contact}
					{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
				}
			)
			("cut_pieces")
			(define "cut_subpiece"
				{tear "piece_medium_steel" bone "sub_piece%0"
					{volumes enable contact}
					{spawn "spheredust_norm" "sub_piece%0"}
					{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
				}
			)
			("cut_subpieces")
		}
	}
	{on "effects"
		{start_sound "crush/medium/metal"}
	}
}

{"small steel parts construction"
	{on "cut_pieces"
		{volumes disable contact}
		{if "blast"
			(define "cut_piece"
				{tear "piece_medium_steel_construction" bone "piece%0"
					{volumes enable contact}
					{impulse up 4 2 dir 2.5 1.3 no_position}
				}
			)
			("cut_pieces")
		else
			(define "cut_piece"
				{tear "piece_medium_steel_construction" bone "piece%0"
					{volumes enable contact}
					{impulse up 0.5 0.25 dir -4.5 0.3 no_position}
				}
			)
			("cut_pieces")
		}
	}
	{on "effects"
		{start_sound "crush/medium/metal"}
	}
}

{"wood parts construction"
	{on "cut_pieces"
		{if "blast"
			(define "cut_piece"
				{tear "building_part_wood" bone "piece%0"
					{volumes enable contact float bullet blast}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			(define "cut_piece"
				{tear "building_part_wood" bone "piece%0"
					{volumes enable contact float bullet blast}
					{impulse up 0.5 0.25 dir 2.5 0.3 no_position}
				}
			)
			("cut_pieces")
		}
	}
	{on "effects"
		{start_sound "crush/medium/wood"} ;// insert custom wood crush sounds folder here
	}
}

{"medium wood parts construction"
	{on "cut_pieces" overload
		{if "blast"
			{volumes disable contact blast}
			(define "cut_piece"
				{tear "piece_medium_wood" bone "piece%0"
					{volumes enable contact float}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{volumes disable contact blast}
			(define "cut_piece"
				{tear "piece_medium_wood" bone "piece%0"
					{volumes enable contact float}
					{impulse up 1 0.7 dir 2.5 0.3 no_position}
				}
			)
			("cut_pieces")
		}
	}
}

{"small wood parts construction"
	{on "cut_pieces" overload
		{if "blast"
			{volumes disable contact blast}
			(define "cut_piece"
				{tear "piece_small_wood" bone "piece%0"
					{volumes enable contact float}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{volumes disable contact blast}
			(define "cut_piece"
				{tear "piece_small_wood" bone "piece%0"
					{volumes enable contact float}
					{impulse up 1 0.7 dir 2.5 0.3 no_position}
				}
			)
			("cut_pieces")
		}
	}
}

{"small sand parts construction"
	{on "cut_pieces" overload
		{volumes disable contact blast}
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"piece_large_concrete"
	{on spawn
		;{if rand 0.9
			{set "crush" 1}
		;}
	}
	{on ground_hit
		{if "crush"
			{spawn "piece_crush"}
			{delete}
		}
	}
	{on contact
		{if can_crush
			{spawn "piece_crush"}
			{delete}
		}
	}
}

{"building_part"
	{on spawn
		{if rand 1
			{set "crush" 1}
		}
	}
	{on ground_hit
		{if not "sliced"
;			{spawn "spheredust_big_short"}
;			{call "cut_subpieces"}
		}
	}
	{on contact
		{if not "sliced"
;			{spawn "spheredust_big_short"}
;			{call "cut_subpieces"}
		}
	}
}


{"building_part concrete"
	{on ground_hit
		{if "crush"
			{spawn "piece_crush_big"}
			{delete}
		}
		{set "ground_hit" 1}
	}
	{on contact
		{if can_crush
			{if "ground_hit"
				{spawn "piece_crush_big"}
				{delete}
			else "crush"
				{spawn "piece_crush_big"}
				{delete}
			}
		}
	}
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "building_part_concrete_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 1 0.5 "stop"}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "building_part_concrete_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"building_part wood"
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_big_wood" bone "sub_piece%0" id "building_part_wood_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 5 3 "stop"}
			}
		)
		("cut_subpieces")
	}
	{on ground_hit
		{if "crush"
			{spawn "spheredust_wood"}
			;{delete}
		}
		{set "ground_hit" 1}
	}
	{on contact
		{if can_crush
			{if "ground_hit"
				{spawn "wood_crush_piece"}
				;{delete}
			else "crush"
				{spawn "wood_crush_piece"}
				;{delete}
			}
		}
	}
	{on blast
		{if min_energy 2
			{spawn "wood_crush_piece"}
			;{delete}
		}
	}
	{on "slice_load"
		{if name "building_part_wood_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"cornered parts construction"
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_concrete" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir -5 1.3 no_position}
				{spawn "spheredust_norm" "piece%0"}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "cornered_parts_construction_piece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "cornered_parts_construction_piece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
	{on "destroyed_stamp" overload
		{if rand 0.20
			{spawn "crash_brick3"	random_position 20}
		else rand 0.20
			{spawn "stonechip1"		random_position 20}
		else rand 0.20
			{spawn "crash_build2"	random_position 20}
		else rand 0.20
			{spawn "crash_brick3b"	random_position 20}
		else
			{spawn "crash_brick3a"	random_position 20}
		}
	}
	{on "effects"
		{start_sound "crush/medium/concrete"}
	}
}

{"unbreakable parts construction"
	{on break_armor overload}
	{on "destroyed_stamp" overload}
}

{"ice parts construction"
	{on overlap begin
		{if not tagged "strong"
			{set "blast" 0}
			{if effector "tank"
				{call "delayed_change_model"}
			else effector "car"
				{call "delayed_change_model"}
			}
		}
	}
	{on "delayed_change_model"
		{if not "delayed_change_model"
			{set "delayed_change_model" 1}
			{delay 2
				{call "change_model"}
			}
		}
	}
	{on contact overload}
	{on "cut_pieces"
		{volumes "body" disable overlap blast}
		{spawn "iceblock_hit01"}
		{##delay 0.5
			{spawn "ex_size1_water"}
		}
		(define "cut_piece"
			{tear "piece_medium_ice" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}


;/*=========== Old References Begin ===========*/

{"entanglement parts construction" ;// old reference. used in 2 models from MoW beam_omaha_01 & 02
	{on contact
		{set "blast" 0}
		{if can_crush
			{call "change_model"}
		}
	}
}

{"cornered wall parts construction" ;// old reference. used in trash barricade models from MoW. Update structures to use "crushable"
	{on contact
		{if can_crush
			{set "blast" 0}
			{call "change_model"}
		}
	}
}

;/*=========== Old References End ===========*/

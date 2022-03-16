{"tree"
	{inflammation_time 10}
	{on spawn
		{mtl_enable_skin 0}
		{view hide "shadow_fall"}
		{call "update_texmod"}
	}
	(define "stir"
		{if not tagged "bare"
			{if not "started"
				{mtl_enable_skin 1}
				{ani_play "stir" 1.0 %params}
				{set "started" 1}
			}
			{if not burned
				{start_sound "push/tree_crown"}
			}
		}
	)
	{on "stir"
		{if effector "human"
			;do nothing
		else effector "cannon"
			;do nothing
		else
			{call "snow_fall"}
		}
		("stir" params(loop resume callback))
	}
	{on overlap begin
		{if not fallen
			{set "overlap" 1}
			{call "stir"}
		}
	}
	{on overlap end
		{set "overlap" 0}
		{delay 0.2 0.2
			{call "stir_end"}
		}
	}
	{on animation_end "stir"
		{call "stir_end"}
	}
	{on "stir_end"
		{if not "overlap"
			{if "started"
				{set "started" 0}
				{ani_stop "stir"}
				{mtl_enable_skin 0}
			}
		}
	}
	{on bullet_hit overload
		{if volume "crown"
			{spawn "tree_hit_small"}
		}
		{inherited}
		{if volume "bole"
			{if stuff "bullet_fx"
				; do nothing
			else stuff "flame"
				; do nothing
			else stuff "flare"
				; do nothing
			else
				{call "stir"}
			}
		}
	}
	{on blast
		{if volume "crown"
			{call "stir"}
		else min_energy 1.6
			{call "start_fall"}
		else min_energy 1
			{call "snow_fall"}
		}
	}
	{on contact
		{call "stir"}
		;//{call "snow_fall"}

		{if effector "tank"
			{call "start_fall"}
		else effector "airborne"
			{call "start_fall"}
		}

	}
	{on "snow_fall"
		;//{if "snow"
		{if tagged "snow"
			;//{if not "snow_fall"
				;//{set "snow_fall" 1}
				{tags remove "snow"}
				{burn volume "crown" fx "snow_fir" time 0.5 fake even_law}
				{tex_morph "_win0" 2}
			;//}
		}
	}
	{on "start_fall"
		{start_sound "push/tree_bole"}
		{volumes "bole" disable contact blast}
		{volumes "crown" enable blast}
		{pillar_fall}
		{call "regenerate"}
	}
	{on "fallen"
		{tags add "fallen"}
		{volumes "crown" enable overlap visible}
		{volumes "crown" disable contact}
		;{start_sound "crush/medium/tree"}
		{call "update_wind"}
	}
	{on "burn"
		{if not burned
			{fire volume "crown" radius 1.5 time 30 heating 0.5}
			{burn volume "crown" fx "smoke_dead_tree" time 32 1}
			{fire volume "bole" time 30 heating 0.5}
			{burn volume "bole" fx "smoke_dead_tree_center" time 32 1}
			{start_sound "fire/tree/"}
			{tags add "burned"}
			{if tagged "bare"
				{tex_morph "_burned1" 16 "_burned3" 16}
			else
				{tex_morph "_burned0" 11 "_burned1" 11 "_burned3" 10}
			}
			{call "update_crown_visibility"}
		}
		{call "regenerate"}
	}
	(define "set_crown_visible"
		{volumes "crown" %0 visible}
		{update_visibility_patch}
	)
	{on "update_crown_visibility"
		{if burned
			("set_crown_visible" args disable)
		else tagged "bare"
			("set_crown_visible" args disable)
		else fallen
			("set_crown_visible" args enable)
		}
	}
	{on "update_wind"
		{if tagged "bare"
			{depend_on_wind 1}
		else fallen
			{depend_on_wind 1}
		else
			{depend_on_wind 1}
		}
	}
	{on "update_texmod"
		{call "update_crown_visibility"}
		{call "update_wind"}
	}
	{on "texmod_changed"
		{call "update_texmod"}
	}
	{on "regenerate"
		{if flora_regenerate
			{delay 140
				{set "crown_fall" 0}
				{burn stop_retry}
				{volumes "bole" enable contact blast}
				{volumes "crown" disable contact}
				{tex_mod reset}
				{pillar_up}
				{scale from 0.1 to 1 time 10}
				{call "update_visibility_10_sec"}
			}
		}
	}
	{on "plant"
		{scale from 0.1 to 1 time 10}
		{call "update_visibility_10_sec"}
	}
	{on "update_visibility_10_sec"
		{delay 4	{update_visibility_patch}}
		{delay 7	{update_visibility_patch}}
		{delay 10	{update_visibility_patch}}
	}
	{on "flora_tags_setup"
		{tags remove "bare"}
		{tags remove "snow"}
		{if tex_mod "bare" "bare1" "broken" "_burned1" "_burned3" "win3"
			{tags add "bare"}
		else tex_mod "win" "win1" "win2"
			{tags add "snow"}
		}
	}
}

{"tree bare"
	{inflammation_time 6}
	{on spawn
		{tags add "bare"}
	}
	{on "flora_tags_setup" overload}
}

{"tree large"
	{on blast overload
		{if volume "crown"
			{call "stir"}
		else min_energy 13
			{call "start_fall"}
		else min_energy 2
			{call "snow_fall"}
		}
	}
	{on contact overload
		{call "stir"}
		{call "snow_fall"}
	}
}

{"bush"
	{inflammation_time 5}
	{on "burn" overload
		{if not burned
			{fire volume "crown" radius 1.0 time 20 heating 0.25}
			{burn volume "crown" fx "smoke_dead_tree" time 22 1}
			{start_sound "fire/bush/"}
			{tags add "burned"}
			{if prop "corn"
				{spawn "fire_mark_2" random_orientation}
			}
			{if tagged "bare"
				{tex_morph "_burned1" 10 "_burned3" 10}
			else tagged "snow"
				{tex_morph "_burned1" 10 "_burned3" 10}
			else
				{tex_morph "_burned0" 6 "_burned1" 6 "_burned3" 6}
			}
			{delay 22
				{call "burn_end"}
			}
			{call "update_crown_visibility"}
			{call "regenerate"}
		}
	}
	{on "stir" overload
		{if effector "vehicle"
			{call "snow_fall"}
		}
		{if fogged
			("stir" params(loop resume fake callback))
		else
			("stir" params(loop resume callback))
		}
	}
	{on blast
		{if min_energy 1.75
			{if not "crown_fall"
				{if not burned
					{set "crown_fall" 1}
					{if tagged "bare"
						{tex_morph "_burned1" 0.3 "_burned3" 0.3}
					else tagged "snow"
						{tex_morph "_win0" 2}
					else
						{tex_morph "_burned0" 0.2 "_burned1" 0.2 "_burned3" 0.2}
					}
					{if tagged "snow"
						{spawn "snow_hit_small" no_position}
					else not tagged "bare"
						{spawn "tree_hit_big"}
					}
					{call "regenerate"}
				}
			}
		}
	}
}

{"wheat"
	{inflammation_time 3}
	{on "burn" overload
		{if not burned
			{fire radius 1.0 time 6 heating 0.3}
			{burn volume "crown" fx "smoke_dead_tree" time 6 1}
			{start_sound "fire/bush/"}
			{tags add "burned"}
			{if tagged "bare"
				{tex_morph "_burned1" 3 "_burned3" 3}
			else
				{tex_morph "_burned0" 2 "_burned1" 2 "_burned3" 2}
			}
			{delay 6
				{call "burn_end"}
			}
			{call "update_crown_visibility"}
		}
		{call "regenerate"}
	}
}

{"cornfield"
	{on overlap begin
		{if effector "tank"
			{call "crush"}
		else effector "armored_car"
			{call "crush"}
		else effector "car"
			{call "crush"}
		else effector "airborne"
			{call "crush"}
		}
	}
	{on "crush" overload
		{if not tagged "crushed"
			{set_skeleton "_x"}
			{tags add "crushed"}
			{spawn "tree_hit_big" "root"}
			{start_sound "push/tree_crown"}
			;{tex_mod "dead"}
			{volumes disable visible bullet contact blast touch overlap}
		}
	}
}


;{"delete_after_burn"
;	{on "burn_end"
;		{hide 2}
;	}
;}

{"delete_after_burn stamp"
	{on "burn_end"
		{spawn "burn_grass1"}
	}
}

{"delete_after_blast"
	{on blast
		{if min_energy 0.8
			{hide 0.6}
		}
	}
}

{"no_wind"
	{on "update_wind" overload
		{depend_on_wind 0}
	}
}

{"invisible_crown"
	{on "update_crown_visibility" overload
		("set_crown_visible" args disable)
	}
}

{"cabbage"
	{inflammation_time 10000}
	{on bullet_hit overload
		{if rand 0.2
			{call "crush"}
		else
			{if rand 0.3
				{spawn "tree_hit_small"}
			}
		}
	}
	{on blast_hit
		{if min_energy 1
			{call "crush"}
		else
			{impulse up 2 1 dir 2 1}
		}
	}
	{on contact
		{if effector "human"
			{volumes "crown" disable contact}
			{if rand 0.3
				{call "crush"}
			}
			{delay 0.5
				{volumes "crown" enable contact}
			}
		else
			{call "crush"}
		}
	}
	{on "crush"
		{spawn "tree_hit_small"}
		{delay 0.2
			{spawn "cabbage_destroy1" no_position no_normal}
		}
		{hide 0.3}
	}
}

{"tree normal_light"
	{on spawn
		{use_local_light 0}
	}
}

{"stack_bush"
	{on spawn
		{use_local_light 0}
	}
}

{"wind_has_foliage"
	{on spawn
		{depend_on_wind 1}
		{wind_detail_bending}
	}
}

{"tree foliage"
	(define "foliage"
		{add_view "foliage" "foliage" "foliage%0"}
	)
	{on spawn
		("foliage" args 00) ("foliage" args 01) ("foliage" args 02) ("foliage" args 03) ("foliage" args 04)
		("foliage" args 05) ("foliage" args 06) ("foliage" args 07) ("foliage" args 08) ("foliage" args 09)
		("foliage" args 10) ("foliage" args 11) ("foliage" args 12) ("foliage" args 13) ("foliage" args 14)
		("foliage" args 15) ("foliage" args 16) ("foliage" args 17) ("foliage" args 18) ("foliage" args 19)
		("foliage" args 20) ("foliage" args 21) ("foliage" args 22) ("foliage" args 23) ("foliage" args 24)
		("foliage" args 25) ("foliage" args 26) ("foliage" args 27) ("foliage" args 28) ("foliage" args 29)
		("foliage" args 30) ("foliage" args 31) ("foliage" args 32) ("foliage" args 33) ("foliage" args 34)
		("foliage" args 35) ("foliage" args 36) ("foliage" args 37) ("foliage" args 38) ("foliage" args 39)
		("foliage" args 40) ("foliage" args 41) ("foliage" args 42) ("foliage" args 43) ("foliage" args 44)
		("foliage" args 45) ("foliage" args 46) ("foliage" args 47) ("foliage" args 48) ("foliage" args 49)
	}
}

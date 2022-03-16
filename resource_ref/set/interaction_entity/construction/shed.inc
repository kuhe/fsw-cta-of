{"shed"
	{inflammation_time 4}
	{on spawn
		{link_sound "burn_large" "fire/loops/big"}
	}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on break_armor
		{if not volume "window"
			{if name "blast"
				{call "break"}
			}
		}
	}
	{on contact
		{if can_crush
			{call "break"}
		else effector "air_part"
			{call "break"}
		else effector "big part"
			{call "break"}
		}
	}
	{on "break"
		{call "disable_volumes"}
		{call "crush_fx"}
		{call "check_structure"}
		{delay 0.2 {delete}}
		{stop_sound "burn_large"}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{play_sound "burn_large" 1}
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8 "break_delay" {call "break"}}
			}
		}
	}
	{on "disable_volumes"
		{volumes disable visible bullet contact blast touch}
	}
}
{"shed_with_x"
	{inflammation_time 4}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on break_armor
		{call "break"}
	}
	{on contact
		{if can_crush
			{call "break"}
		else effector "air_part"
			{call "break"}
		else effector "big part"
			{call "break"}
		}
	}
	{on "break"
		{call "disable_volumes"}
		{call "check_structure"}
		{call "crush_fx"}
		{call "change_model"}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8 "break_delay" {call "break"}}
			}
		}
	}
	{on "disable_volumes"
		{volumes disable visible bullet contact blast touch}
	}
	{on "change_model"
		{if not "sliced"
			{tags add "crushed"}
			{set "sliced" 1}
			{call "disable_volumes"}
			{call "check_structure"}
			{delay_ex 0.1
				{set_skeleton "_x"}
				{call "disable_volumes"}
				{call "update_fx"}
				{set "first_stage" 1}
				{set "last_stage" 1}
				{call "effects"}
				{ani_play "crush"}
				{delay 0.1
					{update_visibility_patch}
				}
			}
		}
	}
}
{"shed no_crush"
	{on contact overload
		{if can_crush
			; do nothing
		else effector "air_part"
			{call "break"}
		else effector "big part"
			{call "break"}
		}
	}
}

{"break_on_burn shed"
	{on "burn_end"
		{call "break"}
		{spawn "burned_spot01"		no_position}
	}
}
{"wood shed"
	{on "crush_fx"
		{spawn "wood_crush_big" "root"}								;// dust fx
		{call "destroyed_stamp"}
	}
	{on "destroyed_stamp" overload
		{spawn "crash_wood"		no_position random_orientation}		;// stamp
	}
}

{"wood shed small"
	{on "crush_fx" overload
		{spawn "wood_crush_small" "root"}							;// dust fx
		{call "destroyed_stamp"}
	}
	{on "destroyed_stamp" overload
		{spawn "crash_wood"		no_position random_orientation}		;// stamp
	}
}

{"concrete shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "stone_crush_big" "root"}
		{spawn "debris" "root"}
	}
}

{"steel shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "spheredust_norm" "root"}
	}
}

{"shed cellar1"
	{on "crush_fx"
		{spawn "trash_1" "root"}
	}
}

{"wood shed_with_x"
	{on "crush_fx"
		{spawn "wood_crush_big" "root"}
	}
}

{"wood shed_with_x small"
	{on "crush_fx" overload
		{spawn "wood_crush_small" "root"}
	}
}

{"concrete shed_with_x"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "stone_crush_big" "root"}
		{spawn "debris" "root"}
	}
	{on "effects"
		{start_sound "crush/medium/concrete"}
	}
}

{"steel shed_with_x"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "spheredust_norm" "root"}
	}
}

{"shed shed_with_x"
	{on "crush_fx"
		{spawn "trash_1" "root"}
	}
}

{"misc shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "spheredust_big" "root"}
	}
}

{"water_capacity shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "drops_water_big" "root"}
	}
}

{"fence"
	{inflammation_time 4}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		else stuff "heat_shell"
			{bullet_detonate}
		}
		{if stuff "auto he"
			{call "break"}
		else stuff "auto size2"
			{call "break"}
		}
	}
	{on break_armor
		{if name "blast"
			{call "break"}
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
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8 "break_delay" {call "break"}}
				{if not tagged "burning"
					{play_sound "burn_small" 1}
				}
				{tags add "burning"}
			}
		}
	}
	{on "disable_volumes"
		{volumes disable visible bullet contact blast touch}
	}
}

{"wood fence"
	{on spawn
		{link_sound "burn_small" "fire/loops/medium"}
	}
	{on "break"
		{call "disable_volumes"}
		{spawn "wood_crush_small" "root"}
		{delay 0.2 {delete}}
	}
}

{"wood fence big"
	{on spawn
		{link_sound "burn_small" "fire/loops/medium"}
	}
	{on "break" overload
		{stop_sound "burn_small"}
		{call "disable_volumes"}
		{spawn "wood_crush_big" "root"}
		{delay 0.2 {delete}}
	}
}

{"concrete fence"
	{inflammation_time 10000}
	{on "break"
		{call "disable_volumes"}
		{spawn "stone_hit_small" "root"}
		{spawn "concrete_fence_destroy" "root" x} ;//doesn't exist
		{delay 0.2 {delete}}
	}
}

{"steel fence"
	{inflammation_time 10000}
	{on "break"
		{call "disable_volumes"}
		{spawn "car_die_particle" "root"}
		{delay 0.2 {delete}}
	}
}

{"animated_crush"
	{on "break" overload
		{kill_delay "break_delay"}
		{burn stop}
		{call "disable_volumes"}
		{area disable}
		{tex_mod "x"}
		{ani_play "crush" callback}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
	}
}

{"animated_crush_gate"
	{on break_armor
		{if name "pierce"
			{call "break"}
		}
	}
	{on "break" overload
		{kill_delay "break_delay"}
		{burn stop}
		{call "disable_volumes"}
		{area disable}
		{ani_play "crush" callback}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
	}
}

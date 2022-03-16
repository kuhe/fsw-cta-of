{"mill staged construction" ; worked with staged animated construction
	{on "set_skeleton" overload
		{set_skeleton "_x" sync}
	}
	{on "effects"
		{if "last_stage"
			{call "cut_parts"}
		}
	}
	{on "cut_parts"
		(define "cut_piece"
			{tear "building_part_wood" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{spawn "spheredust_norm" "piece%0"}
			}
		)
		("cut_piece" args 0)	("cut_piece" args 1)
		("cut_piece" args 2)	("cut_piece" args 3)
		{delay 0.1
			{bone cut "sweep"}
		}
	}
}

{"mill_water"
	{on spawn
		{burn volume "fx1" fx "drops_water_mill" time 1000000 fake even_law}
		{burn volume "fx2" fx "drops_water_mill" time 1000000 fake even_law}
		{burn volume "fx3" fx "drops_water_mill" time 1000000 fake even_law}
		{burn volume "fx4" fx "drops_water_mill" time 1000000 fake even_law}
	
		{add_view "wash_ship_stop" "water" "fx_wash1"}
		{add_view "wash_ship_stop" "water" "fx_wash2"}

		{view start "water"}
	}
}

{"crane_port staged construction"
	{on "set_skeleton" overload
		{for_each_link
			{call "break"}
		}
		{set_skeleton "_x" sync}
	}
	{on "break"
		{call "next_stage"}
	}
	{on "effects"
		{if "last_stage"
			{call "cut_parts"}
		}
	}
	{on "cut_parts"
		{delay 3
			{ani_play "piece" callback}
			{ani_play "turret"}
			{ani_play "hook"}
			{delay 0.4 0.1
				{spawn "metal_hit_fg" "fx_spark"}
			}
			{delay 0.4 0.1
				{spawn "metal_hit_fg" "fx_spark1"}
			}
			{spawn "metal_hit_fg" "fx_spark2"}
			{spawn "metal_hit_fg" "fx_spark3"}
	
			{delay 1
				{spawn "spheredust_small" "fx_water_hook"}
			}
			{delay 5
				{spawn "spheredust_small" "fx_waterr3"}
				{spawn "spheredust_small" "fx_waterl3"}
			}
		}
	}
	{on animation_end "piece"
		{delay 0
			{spawn "metal_hit_fg" "fx_spark"}
			{spawn "metal_hit_fg" "fx_spark1"}
			(define "cut_piece"
				{tear "piece_large_steel" bone "piece%0"
					{volumes enable contact}
					{impulse up -5 no_position}
				}
			)
			("cut_piece" args 1)
		}
	}
}

{"sand medium part"
	{on spawn
		{delay 20 7
			{hide 5}
		}
	}
	{on ground_hit
		{if velocity 34
			{spawn "circledust_norm"}
			{delete}
		}
	}
}

{"water_capacity"
	{on bullet_hit
		{if stuff "bullet"
			{if volume "water"
				{burn fx "drops_water_small_long" fake}
			}
		else stuff "zenite"
			{if volume "water"
				{burn fx "drops_water_small_long" fake}
			}
		}
	}
	{on "change_model"
		{burn stop}
	}
}

{"wire_fall construction"
	{inflammation_time 0.1}
	{on spawn
		{link_sound "cable_snap" "crush/small/wire"}
	}
	{on break_armor
		{call "change_model"}
	}
	{on contact
		{if can_crush
			{call "change_model"}
		}
	}
	{on "change_model" overload
		{volumes disable all}
		{delay_ex 0.1
			{call "set_skeleton"}
			{play_sound "cable_snap"}
			{ani_play "fall"}
		}
		{delay 4
			{delete}
		}
	}
}

{"tower_metal"
	{on contact
		{if can_crush
			{call "change_model"}
		}
	}
	{on "effects"
		{add_view "drops_water_big" "water" "fx_water1"}
		{add_view "drops_water_big" "water" "fx_water1a"}
		{view start "water"}
		{spawn "ex_size3_water" no_position}
	}
	{on "destroyed_stamp" overload
		{delay 0.5
			{spawn "waterpool" no_position}
		}
	}
}

{"tower_wood"
	{on contact
		{if can_crush
			{call "change_model"}
		}
	}
	{on "effects"
; do nothing
	}
	{on "destroyed_stamp" overload
		{delay 0.9
			{spawn "crash_wood1" no_position}
		}
	}
}

{"stone_landslip"
	{on break_armor
		{if volume "support"
			{call "crush"}
		}
	}
	{on contact
		{if effector "vehicle"
			{if volume "support"
				{call "crush"}
			}
		}
	}
	{on "crush"
		{if not "sliced"
			{set "sliced" 1}
			{tags add "crushed"}
			{volumes "support" disable contact bullet blast}
			{ani_play "crush1"}
			(define "cut_stone"
				{tear "piece_big_stone" bone "part%0"
					{volumes enable contact}
					{impulse up 0.2 0.1 cx 3 6 cy 3 6 fx 10 no_position}
				}
			)
			("cut_stone" args 0)	("cut_stone" args 1)
			("cut_stone" args 2)	("cut_stone" args 3)
			("cut_stone" args 4)	("cut_stone" args 5)
			("cut_stone" args 6)	("cut_stone" args 7)
			("cut_stone" args 8)	("cut_stone" args 9)
			("cut_stone" args 10)	("cut_stone" args 11)
		}
	}
}

{"bonfire"
	{on spawn
		{add_view "smoke_grey" "smoke" "hut_bonfire"}
		{view start "smoke"}
	}
}

{"barrel_fuel"
	{on "effects"
		{spawn "shockwave_sphere" "fx_expfuel"}
		{add_view "exhaust_dark_big" "burn_fire" "fxfire"}
		{view start "burn_fire"}
		{spawn "crater_big" "basis" terrain_texmod}
		{spawn "shellhole_big_dead" "basis"}
		{blastwave c4 15 r0 6 r1 20}
		{fire radius 15 time 5 heating 10}
	}
}

{"barrel_small"
	{on "effects"
		{spawn "shockwave_sphere" "fx_expfuel"}
		{blastwave c4 7 r0 3 r1 12}
		{fire radius 10 time 5 heating 10}
	}
}

{"barrels_big1"
	{on "effects"
		{blastwave c4 5 r0 3 r1 9}
		{fire radius 8 time 5 heating 10}
	}
}

{"fuel_scaled"
	{on "effects"
		{blastwave c4 7 r0 5 r1 15}
		{fire radius 12 time 5 heating 10}
	}
}

{"fuel"
	{on "effects"
		{blastwave c4 5 r0 3 r1 12}
		{fire radius 9 time 5 heating 10}
	}
}

{"mts-fuel"
	{on "effects"
		{blastwave c4 5 r0 3 r1 7}
		{fire radius 5 time 5 heating 10}
	}
}

{"nuke"
	{on "effects"
		{spawn "shellhole_super"}
		{fire radius 230 time 10 heating 1000}
		{blastwave c4 1000000 r0 50 r1 200 offset 0 0 50}
	}
}

{"antitank_hedgehog"
	{on contact
		{if effector "vehicle"
			{if min_speed 2
				{if not "fx_delay"
					{set "fx_delay" 1}
					{delay 2 "fx_delay"
						{set "fx_delay" 0}
					}
					{spawn "metal_crush" "root"}
				}
			}
		}
	}
	{on "cut_pieces" overload
		(define "cut_piece"
			{tear "piece_medium_steel" bone "piece%0"
				{volumes enable contact}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"antitank_rock"
	{on contact sync
		{if effector "vehicle"
			{if min_speed 2
				{if not "fx_delay"
					{set "fx_delay" 1}
					{delay 2 "fx_delay"
						{set "fx_delay" 0}
					}
					{spawn "spheredust_tiny" "root"}
				}
			}
		}
		{if not impregnable
			{if effector "tank heavy"
				{call "break"}
			}
		}
	}
	{on break_armor
		{call "break"}
	}
	{on "break"
		{set "blast" 0}
		{call "change_model"}
	}
	{on "cut_pieces" overload
		(define "cut_piece"
			{tear "piece_medium_concrete" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir -5 1.3 no_position}
				{spawn "spheredust_norm" "piece%0"}
			}
		)
		("cut_pieces")
	}
}

{"lighthouse parts construction"
	{on "change_model"
		{drop_orders}
	}
}

{"barbed_wire"
	{on "cut_pieces"
		{start_sound "crush/small/wire"}
	}
}

{"red_destroyed_stamp"
	{on "destroyed_stamp" overload
		{spawn "crash_brick4se" "root" x no_position}
	}
}

{"backwall_stairs6_secret"
	{on "enable_touch"
		{volumes "attach" enable touch}
	}
	{on "disable_touch"
		{volumes "attach" disable touch}
	}
}

{"tent_fuel_take_off"
	{on "open"
		{volumes "switch" disable touch}
	}
}

{"dummygun"
	{on spawn
		{delay 0.1
			{spawn "building_smoke" "bait"}
			{link_sound "deploy"		"vehicle/construction/wood_deploy"}
			{play_sound "deploy"}
			{tags add "dummygun"}
			{add_view	"bait" "bait" "bait"}
			{view start "bait"}
		}
	}
	{on "break"
		{tags remove "dummygun"}
		{view stop "bait"}
	}
}


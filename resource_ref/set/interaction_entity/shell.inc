{"shell_smoke_wp_small" ;// props from shell_smoke service entity; light mortar, rifle grenade
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder" 
			{add_view "smoke_wp_small" "smoke1" "root"}
			{view start "smoke1"}
			{delay 56
				{view stop "smoke1"}
			}
			{delay 60 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 100 0 59)
			("spawn_volume" args cylinder -100 0 59)
			("spawn_volume" args cylinder 0 100 59)
			("spawn_volume" args cylinder 0 -100 59)
			("spawn_volume" args cylinder 75 75 59)
			("spawn_volume" args cylinder -75 -75 59)
			("spawn_volume" args cylinder -75 75 59)
			("spawn_volume" args cylinder 75 -75 59)
		}
		{delay 65
			{hide 1}
		}
	}
}
{"shell_smoke_wp_medium" ;// props from shell_smoke service entity; 75mm, 81mm mortar
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder"
			{add_view "smoke_wp_medium" "smoke1" "root"}
			{view start "smoke1"}
			{delay 71
				{view stop "smoke1"}
			}
			{delay 75 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 100 0 74)
			("spawn_volume" args cylinder -100 0 74)
			("spawn_volume" args cylinder 0 100 74)
			("spawn_volume" args cylinder 0 -100 74)
			("spawn_volume" args cylinder 69 69 74)
			("spawn_volume" args cylinder -69 -69 74)
			("spawn_volume" args cylinder -69 69 74)
			("spawn_volume" args cylinder 69 -69 74)
		}
		{delay 5
			("spawn_volume" args cylinder_sm 160 0 72)
			("spawn_volume" args cylinder_sm -160 0 72)
			("spawn_volume" args cylinder_sm 0 160 72)
			("spawn_volume" args cylinder_sm 0 -160 72)
		}
		{delay 80
			{hide 1}
		}
	}
}
{"shell_smoke_wp_big" ;// props from shell_smoke service entity; 105-122, 107-120mm mortar
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder" 
			{add_view "smoke_wp_big" "smoke1" "root"}
			{view start "smoke1"}
			{delay 81
				{view stop "smoke1"}
			}
			{delay 85 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 120 0 84)
			("spawn_volume" args cylinder -120 0 84)
			("spawn_volume" args cylinder 0 120 84)
			("spawn_volume" args cylinder 0 -120 84)
			("spawn_volume" args cylinder 83 83 84)
			("spawn_volume" args cylinder -83 -83 84)
			("spawn_volume" args cylinder -83 83 84)
			("spawn_volume" args cylinder 83 -83 84)
		}
		{delay 5
			("spawn_volume" args cylinder_sm 180 0 82)
			("spawn_volume" args cylinder_sm -180 0 82)
			("spawn_volume" args cylinder_sm 0 180 82)
			("spawn_volume" args cylinder_sm 0 -180 82)
		}
		{delay 90
			{hide 1}
		}
	}
}
{"shell_smoke" ;// props from shell_smoke service entity
	{on spawn
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{view start "smoke3"}
		{spawn "smoke_volume_cylinder" {delay 85 {hide 1}}}
		{delay 2
			("spawn_volume" args cylinder 120 0 84)
			("spawn_volume" args cylinder -120 0 84)
			("spawn_volume" args cylinder 0 120 84)
			("spawn_volume" args cylinder 0 -120 84)
			("spawn_volume" args cylinder 83 83 84)
			("spawn_volume" args cylinder -83 -83 84)
			("spawn_volume" args cylinder -83 83 84)
			("spawn_volume" args cylinder 83 -83 84)
		}
		{delay 5
			("spawn_volume" args cylinder_sm 220 0 82)
			("spawn_volume" args cylinder_sm -220 0 82)
			("spawn_volume" args cylinder_sm 0 220 82)
			("spawn_volume" args cylinder_sm 0 -220 82)
		}
		{delay 85
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 90
			{hide 1}
		}
	}
}
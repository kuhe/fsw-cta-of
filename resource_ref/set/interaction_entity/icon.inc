

(define "at_weapon_icon"
	{on "link_human"
		{if difficulty "easy"
			{call "show"}
			{delay 1
				{view start "wp_view"}
			}
		else difficulty "normal"
			{call "show"}
			{delay 1
				{view start "wp_view"}
			}
		}
	}	
	{on "unlink_human"
		{if difficulty "easy"
			{view hide "wp_view"}
		else difficulty "normal"
			{view hide "wp_view"}
		}
	}
	{on "show" overload
		{add_view "%icon" "wp_view" "root" not_manual not_scenario}
	}
)


{"k98_antitank"
	("at_weapon_icon" icon(icon_k98at))
}
{"panzershreck_54"
	("at_weapon_icon" icon(icon_panzerschreck))
}
{"panzershreck_43"
	("at_weapon_icon" icon(icon_panzerschreck))
}
{"bazooka_m1a1"
	("at_weapon_icon" icon(icon_m1bazooka))
}
{"k98_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}
{"mosin_grenade_launcher"
	("at_weapon_icon" icon(icon_k98at))
}
{"mosin_antitank"
	("at_weapon_icon" icon(icon_k98at))
}
{"ptrd"
	("at_weapon_icon" icon(icon_ptrd))
}
{"ptrs"
	("at_weapon_icon" icon(icon_ptrs))
}
{"pzb_39"
	("at_weapon_icon" icon(icon_pzb_39))
}
{"faustpatrone_30"
	("at_weapon_icon" icon(icon_panzerfaust))
	{on "fire"
		{delay 1
			{view stop "wp_view"}
		}
	}	
}
{"panzerfaust_100"
	("at_weapon_icon" icon(icon_panzerfaust))
	{on "fire"
		{delay 1
			{view stop "wp_view"}
		}
	}
}
{"panzerfaust_60"
	("at_weapon_icon" icon(icon_panzerfaust))
	{on "fire"
		{delay 1
			{view stop "wp_view"}
		}
	}
}

{"skirmish_cap_1_ataa"
	{on spawn
		{call "add_number"}
		{delay 1
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "skirmish_cap_1" "fx" "fx_number" not_scenario}
	}
}


{"skirmish_cap_2_inf"
	{on spawn
		{call "add_number"}
		{delay 1
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "skirmish_cap_2" "fx" "fx_number" not_scenario}
	}
}


{"skirmish_cap_3_lttank"
	{on spawn
		{call "add_number"}
		{delay 1
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "skirmish_cap_3" "fx" "fx_number" not_scenario}
	}
}


{"skirmish_cap_4_hvtank"
	{on spawn
		{call "add_number"}
		{delay 1
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "skirmish_cap_4" "fx" "fx_number" not_scenario}
	}
}


{"skirmish_cap_5_arty"
	{on spawn
		{call "add_number"}
		{delay 1
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "skirmish_cap_5" "fx" "fx_number" not_scenario}
	}
}


{"skirmish_cap_6_bonus"
	{on spawn
		{call "add_number"}
		{delay 1
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "skirmish_cap_6" "fx" "fx_number" not_scenario}
	}
}


{"skirmish_cap_7_enemyhq"
	{on spawn
		{call "add_number"}
		{delay 1
			{view start "fx"}
		}
	}
	{on "add_number" overload
		{add_view "skirmish_cap_7" "fx" "fx_number" not_scenario}
	}
}


;{"skirmish_fx_base"
;    {on spawn
;        {call "add_number"}
;        {delay 1
;            {view start "fx"}
;        }
;    }
;	{on "add_number" overload
;		{add_view "skirmish_flag_border" "fx" "fx_number"}
;	}
;}


;{"skirmish_fx_30_defence"
;    {on spawn
;        {call "add_number"}
;        {delay 1
;            {view start "fx"}
;        }
;    }
;	{on "add_number" overload
;		{add_view "30_defence" "fx" "fx_number"}
;		{add_view "skirmish_flag_border" "fx" "fx_number"}
;	}
;}

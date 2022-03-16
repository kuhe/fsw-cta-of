{"target"
	{on spawn
		{if tagged "up"
			{volumes enable contact bullet blast visible touch}
			{area enable}
			{ani_wind "crush" begin}
			{set "broken" 0}
			{auto_operatable 1}
		else
			{volumes disable contact bullet blast visible touch}
			{area disable}
			{ani_wind "crush" end}
			{set "broken" 1}
			{auto_operatable 0}
		}
	}
	{on bullet_hit
		{call "break"}
	}
	{on blast_hit
		{if min_energy 0.75
			{call "break"}
		}
	}
	{on "break"
		{tags add "crushed"}
		{set "broken" 1}
		{auto_operatable 0}
	}
	{on "up"
		{tags remove "crushed"}
		{tags add "up"}
		{set "broken" 0}
		{volumes enable contact bullet blast visible touch}
		{area enable}
		{ani_play "crush" -1}
		{auto_operatable 1}
	}
	{on "down"
		{if not "broken"
			{call "break"}
		}
		{tags remove "crushed"}
	}
	{on break_armor overload
		{if tagged "grenade"
			{call "break"}
		}
	}
}

{"armor_plate"
	{on pierce
		{tags add "pierced"}			;// mission script helper
		{impulse up 0.2 0.1 dir 1 0.1}	;// causes entity to fall down when pierced. 
	}
}
